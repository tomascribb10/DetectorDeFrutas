#from ast import If
import cv2
import time
import numpy as np

import serial


# load the COCO class names
with open('./model/object_detection_classes_coco.txt', 'r') as f:
    class_names = f.read().split('\n')

# get a different color array for each of the classes
COLORS = np.random.uniform(0, 255, size=(len(class_names), 3))

# load the DNN model
model = cv2.dnn.readNet(model='./model/frozen_inference_graph.pb',
                        config='./model/ssd_mobilenet_v2_coco_2018_03_29.pbtxt.txt', 
                        framework='TensorFlow')

# capture the video
#cap = cv2.VideoCapture('./input/video_1.mp4')
cap = cv2.VideoCapture(0)
# get the video frames' width and height for proper saving of videos
frame_width = int(cap.get(3))
frame_height = int(cap.get(4))
# create the `VideoWriter()` object
out = cv2.VideoWriter('./outputs/video_result.mp4', cv2.VideoWriter_fourcc(*'mp4v'), 30, 
                      (frame_width, frame_height))
"""
#Inicio el puerto serie
serialPort = serial.Serial(
    port="COM4", baudrate=9600, bytesize=8, timeout=2, stopbits=serial.STOPBITS_ONE
)

serialPort.flushInput() #flush input buffer, discarding all its contents
serialPort.flushOutput()#flush output buffer, aborting current output 
                 #and discard all that is in buffer
"""
# detect objects in each frame of the video
#while cap.isOpened():
led_prendido1 = True
led_prendido2 = True
led_prendido3 = True
while True:
    #Podriamos poner un sleep, no hace falta tanta velocidad de respuesta.
    time.sleep(1)
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
        """
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
        """
        
        #Busco objetos con confidence > que .4 y que el ID de objeto sea el deseado.
        #Aparentemente la opción del np.where es menos eficiente que la del if.
        #Explicacion de output, es un ndarray de numpy. El shape es (1,1,100,7) Quiere decir que devuelve 100 arrays con 7 Float cada uno.
        #Estos 7 elementos son la clase, la probabilidad y las coordenadas dentro del frame.
        resultado = np.where((output[0, 0, :, 2] > .4) & (output[0, 0, :, 1] == 52))
        if resultado[0].size > 0 :
            print(output[0,0, (resultado[0]),1])
            class_id = (output[0,0, (resultado[0]),1])
                
            # map the class id to the class 
            class_name = class_names[int(class_id)-1]
            color = COLORS[int(class_id)]
            # get the bounding box coordinates
            box_x = (output[0,0, (resultado[0]),3]) * image_width
            box_y = (output[0,0, (resultado[0]),4]) * image_height
            # get the bounding box width and height
            box_width = (output[0,0, (resultado[0]),5]) * image_width
            box_height = (output[0,0, (resultado[0]),6]) * image_height
            # draw a rectangle around each detected object
            cv2.rectangle(image, (int(box_x), int(box_y)), (int(box_width), int(box_height)), color, thickness=2)
            # put the class name text on the detected object
            cv2.putText(image, class_name, (int(box_x), int(box_y - 5)), cv2.FONT_HERSHEY_SIMPLEX, 1, color, 2)
            # put the FPS text on top of the frame
            cv2.putText(image, f"{fps:.2f} FPS", (20, 30), cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 255, 0), 2) 
        

        cv2.imshow('image', image)
        out.write(image)
        
        if cv2.waitKey(10) & 0xFF == ord('q'):
            break
    else:
        break

cap.release()
cv2.destroyAllWindows()
serialPort.close()
