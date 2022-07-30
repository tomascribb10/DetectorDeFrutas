from ast import If
import cv2
import time
import numpy as np

import serial
import time
import serial.tools.list_ports as port_list
serial_device = "COM4"


ports = list(port_list.comports())
for p in ports:
    if p.device == serial_device:
        serialPort = serial.Serial(
            port=serial_device, baudrate=9600, bytesize=8, timeout=2, stopbits=serial.STOPBITS_ONE
        )
        serialPort.flushInput() #flush input buffer, discarding all its contents
        serialPort.flushOutput()#flush output buffer, aborting current output 
                        #and discard all that is in buffer

for x in range(1):
    serialPort.write(b"a\r\n")
    time.sleep(1)
    serialPort.write(b"b\r\n")
    time.sleep(1)
    serialPort.write(b"c\r\n")
    time.sleep(1)
    serialPort.write(b"d\r\n")
    time.sleep(1)
    serialPort.write(b"e\r\n")
    time.sleep(1)
    serialPort.write(b"f\r\n")
    time.sleep(1)

# load the COCO class names
with open('../model/object_detection_classes_coco.txt', 'r') as f:
    class_names = f.read().split('\n')

# get a different color array for each of the classes
COLORS = np.random.uniform(0, 255, size=(len(class_names), 3))

# load the DNN model
model = cv2.dnn.readNet(model='../model/frozen_inference_graph.pb',
                        config='../model/ssd_mobilenet_v2_coco_2018_03_29.pbtxt.txt', 
                        framework='TensorFlow')

# capture the video
#cap = cv2.VideoCapture('./input/video_1.mp4')
cap = cv2.VideoCapture(0)
# get the video frames' width and height for proper saving of videos
frame_width = int(cap.get(3))
frame_height = int(cap.get(4))
# create the `VideoWriter()` object
#out = cv2.VideoWriter('./outputs/video_result.mp4', cv2.VideoWriter_fourcc(*'mp4v'), 30, 
#                      (frame_width, frame_height))

# detect objects in each frame of the video
#while cap.isOpened():
led_prendido1 = True
led_prendido2 = True
led_prendido3 = True
banana_on = 0
apple_on = 0
orange_on = 0
while True:
    #time.sleep(1)
    ret, frame = cap.read()
    if ret:
        image = frame
        image_height, image_width, _ = image.shape
        # create blob from image
        blob = cv2.dnn.blobFromImage(image=image, size=(300, 300), mean=(104, 117, 123), 
                                     swapRB=True)
        # start time to calculate FPS
        start = time.time()
        model.setInput(blob)
        output = model.forward()        
        # end time after detection
        end = time.time()
        # calculate the FPS for current frame detection
        fps = 1 / (end-start)
        # loop over each of the detections
        for detection in output[0, 0, :, :]:
            # extract the confidence of the detection
            confidence = detection[2]
            # draw bounding boxes only if the detection confidence is above...
            # ... a certain threshold, else skip 
            if confidence > .4:
                # get the class id
                class_id = detection[1]
                
                # map the class id to the class 
                class_name = class_names[int(class_id)-1]
                if class_name == 'cup':
                    banana_on = 5
                if class_name == 'apple':
                    apple_on = 5
                if class_name == 'orange':
                    orange_on = 5

                color = COLORS[int(class_id)]
                # get the bounding box coordinates
                box_x = detection[3] * image_width
                box_y = detection[4] * image_height
                # get the bounding box width and height
                box_width = detection[5] * image_width
                box_height = detection[6] * image_height
                # draw a rectangle around each detected object
                cv2.rectangle(image, (int(box_x), int(box_y)), (int(box_width), int(box_height)), color, thickness=2)
                # put the class name text on the detected object
                cv2.putText(image, class_name, (int(box_x), int(box_y - 5)), cv2.FONT_HERSHEY_SIMPLEX, 1, color, 2)
                # put the FPS text on top of the frame
                cv2.putText(image, f"{fps:.2f} FPS", (20, 30), cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 255, 0), 2) 
        
        #Manejo led banana          
        if banana_on > 0 and led_prendido1 == False:
            led_prendido1 = True
            if serialPort:
                serialPort.write(b"a\r\n")
                time.sleep(.5)         
        elif banana_on == 0 and led_prendido1 == True:
            led_prendido1 = False
            if serialPort:
                serialPort.write(b"b\r\n")
                time.sleep(.5)
        else: 
            banana_on = banana_on - 1
        if led_prendido1 == True:
            cv2.circle(img=image, center = (25,60), radius =12, color =(0,255,255), thickness=-1)
            
        else:
            cv2.circle(img=image, center = (25,60), radius =12, color =(0,255,255), thickness=2)
            
                

        #Manejo led manzana         
        if apple_on > 0 and led_prendido2 == False:
            led_prendido2 = True    
            if serialPort:
                serialPort.write(b"c\r\n")
                time.sleep(.5)       
        elif apple_on == 0 and led_prendido2 == True:
            led_prendido2 = False
            if serialPort:
                serialPort.write(b"d\r\n")
                time.sleep(.5)
        else: 
            apple_on = apple_on - 1
        if led_prendido2 == True:
            cv2.circle(img=image, center = (55,60), radius =12, color =(0,0,255), thickness=-1)
        else:
            cv2.circle(img=image, center = (55,60), radius =12, color =(0,0,255), thickness=2)
            

        #Manejo led naranja         
        if orange_on > 0 and led_prendido3 == False:
            led_prendido3 = True 
            if serialPort:
                serialPort.write(b"e\r\n")
                time.sleep(.5)          
        elif orange_on == 0 and led_prendido3 == True:
            led_prendido3 = False
            if serialPort:
                serialPort.write(b"f\r\n")
                time.sleep(.5)
        else: 
            orange_on = orange_on - 1
        if led_prendido3 == True:
            cv2.circle(img=image, center = (85,60), radius =12, color =(26, 127, 239), thickness=-1)
        else:
            cv2.circle(img=image, center = (85,60), radius =12, color =(26, 127, 239), thickness=2)
            

        cv2.imshow('image', image)
        #out.write(image)
        
        if cv2.waitKey(10) & 0xFF == ord('q'):
            break
    else:
        break

cap.release()
cv2.destroyAllWindows()
#Cerramos el puerto serie si esta abierto.
try:
    if  serialPort.is_open:
        serialPort.close()
except:
    print('No se abrio el puerto COM')