opt subtitle "HI-TECH Software Omniscient Code Generator (PRO mode) build 10920"

opt pagewidth 120

	opt pm

	processor	16F628A
clrc	macro
	bcf	3,0
	endm
clrz	macro
	bcf	3,2
	endm
setc	macro
	bsf	3,0
	endm
setz	macro
	bsf	3,2
	endm
skipc	macro
	btfss	3,0
	endm
skipz	macro
	btfss	3,2
	endm
skipnc	macro
	btfsc	3,0
	endm
skipnz	macro
	btfsc	3,2
	endm
indf	equ	0
indf0	equ	0
pc	equ	2
pcl	equ	2
status	equ	3
fsr	equ	4
fsr0	equ	4
c	equ	1
z	equ	0
pclath	equ	10
# 11 "C:\Users\Saeed\Desktop\PIC16F628A UART Code\Code\Main.c"
	psect config,class=CONFIG,delta=2 ;#
# 11 "C:\Users\Saeed\Desktop\PIC16F628A UART Code\Code\Main.c"
	dw 0xFFEE & 0xFFFB & 0xFFF7 & 0xFFFF & 0xFFFF & 0xFF7F & 0xFFFF & 0xFFFF ;#
	FNCALL	_main,_InitUART
	FNCALL	_main,_SendStringSerially
	FNCALL	_SendStringSerially,_SendByteSerially
	FNROOT	_main
	FNCALL	_ISR,i1_SendByteSerially
	FNCALL	intlevel1,_ISR
	global	intlevel1
	FNROOT	intlevel1
	global	_RCREG
psect	text128,local,class=CODE,delta=2
global __ptext128
__ptext128:
_RCREG	set	26
	global	_TXREG
_TXREG	set	25
	global	_CREN
_CREN	set	196
	global	_GIE
_GIE	set	95
	global	_OERR
_OERR	set	193
	global	_PEIE
_PEIE	set	94
	global	_RCIF
_RCIF	set	101
	global	_RX9
_RX9	set	198
	global	_SPEN
_SPEN	set	199
	global	_SREN
_SREN	set	197
	global	_TXIF
_TXIF	set	100
	global	_SPBRG
_SPBRG	set	153
	global	_BRGH
_BRGH	set	1218
	global	_RCIE
_RCIE	set	1125
	global	_SYNC
_SYNC	set	1220
	global	_TRISB1
_TRISB1	set	1073
	global	_TRISB2
_TRISB2	set	1074
	global	_TX9
_TX9	set	1222
	global	_TXEN
_TXEN	set	1221
	global	_TXIE
_TXIE	set	1124
psect	strings,class=STRING,delta=2
global __pstrings
__pstrings:
;	global	stringdir,stringtab,__stringbase
stringtab:
;	String table - string pointers are 1 byte each
stringcode:stringdir:
movlw high(stringdir)
movwf pclath
movf fsr,w
incf fsr
	addwf pc
__stringbase:
	retlw	0
psect	strings
	
STR_1:	
	retlw	72	;'H'
	retlw	101	;'e'
	retlw	108	;'l'
	retlw	108	;'l'
	retlw	111	;'o'
	retlw	32	;' '
	retlw	87	;'W'
	retlw	111	;'o'
	retlw	114	;'r'
	retlw	108	;'l'
	retlw	100	;'d'
	retlw	33	;'!'
	retlw	0
psect	strings
	file	"UART.as"
	line	#
psect cinit,class=CODE,delta=2
global start_initialization
start_initialization:

psect cinit,class=CODE,delta=2
global end_of_initialization

;End of C runtime variable initialization code

end_of_initialization:
clrf status
ljmp _main	;jump to C main() function
psect	cstackCOMMON,class=COMMON,space=1
global __pcstackCOMMON
__pcstackCOMMON:
	global	?_SendByteSerially
?_SendByteSerially:	; 0 bytes @ 0x0
	global	?_InitUART
?_InitUART:	; 0 bytes @ 0x0
	global	?_SendStringSerially
?_SendStringSerially:	; 0 bytes @ 0x0
	global	?_ISR
?_ISR:	; 0 bytes @ 0x0
	global	?_main
?_main:	; 0 bytes @ 0x0
	global	?i1_SendByteSerially
?i1_SendByteSerially:	; 0 bytes @ 0x0
	global	??i1_SendByteSerially
??i1_SendByteSerially:	; 0 bytes @ 0x0
	global	i1SendByteSerially@Byte
i1SendByteSerially@Byte:	; 1 bytes @ 0x0
	ds	1
	global	??_ISR
??_ISR:	; 0 bytes @ 0x1
	ds	2
	global	??_SendByteSerially
??_SendByteSerially:	; 0 bytes @ 0x3
	global	??_InitUART
??_InitUART:	; 0 bytes @ 0x3
	global	SendByteSerially@Byte
SendByteSerially@Byte:	; 1 bytes @ 0x3
	ds	1
	global	??_SendStringSerially
??_SendStringSerially:	; 0 bytes @ 0x4
	global	SendStringSerially@st
SendStringSerially@st:	; 1 bytes @ 0x4
	ds	1
	global	??_main
??_main:	; 0 bytes @ 0x5
;;Data sizes: Strings 13, constant 0, data 0, bss 0, persistent 0 stack 0
;;Auto spaces:   Size  Autos    Used
;; COMMON          14      5       5
;; BANK0           80      0       0
;; BANK1           80      0       0
;; BANK2           48      0       0

;;
;; Pointer list with targets:

;; SendStringSerially@st	PTR const unsigned char  size(1) Largest target is 13
;;		 -> STR_1(CODE[13]), 
;;


;;
;; Critical Paths under _main in COMMON
;;
;;   _main->_SendStringSerially
;;   _SendStringSerially->_SendByteSerially
;;
;; Critical Paths under _ISR in COMMON
;;
;;   _ISR->i1_SendByteSerially
;;
;; Critical Paths under _main in BANK0
;;
;;   None.
;;
;; Critical Paths under _ISR in BANK0
;;
;;   None.
;;
;; Critical Paths under _main in BANK1
;;
;;   None.
;;
;; Critical Paths under _ISR in BANK1
;;
;;   None.
;;
;; Critical Paths under _main in BANK2
;;
;;   None.
;;
;; Critical Paths under _ISR in BANK2
;;
;;   None.

;;
;;Main: autosize = 0, tempsize = 0, incstack = 0, save=0
;;

;;
;;Call Graph Tables:
;;
;; ---------------------------------------------------------------------------------
;; (Depth) Function   	        Calls       Base Space   Used Autos Params    Refs
;; ---------------------------------------------------------------------------------
;; (0) _main                                                 0     0      0      45
;;                           _InitUART
;;                 _SendStringSerially
;; ---------------------------------------------------------------------------------
;; (1) _SendStringSerially                                   1     1      0      45
;;                                              4 COMMON     1     1      0
;;                   _SendByteSerially
;; ---------------------------------------------------------------------------------
;; (1) _InitUART                                             0     0      0       0
;; ---------------------------------------------------------------------------------
;; (2) _SendByteSerially                                     1     1      0      15
;;                                              3 COMMON     1     1      0
;; ---------------------------------------------------------------------------------
;; Estimated maximum stack depth 2
;; ---------------------------------------------------------------------------------
;; (Depth) Function   	        Calls       Base Space   Used Autos Params    Refs
;; ---------------------------------------------------------------------------------
;; (3) _ISR                                                  2     2      0      73
;;                                              1 COMMON     2     2      0
;;                 i1_SendByteSerially
;; ---------------------------------------------------------------------------------
;; (4) i1_SendByteSerially                                   1     1      0      73
;;                                              0 COMMON     1     1      0
;; ---------------------------------------------------------------------------------
;; Estimated maximum stack depth 4
;; ---------------------------------------------------------------------------------

;; Call Graph Graphs:

;; _main (ROOT)
;;   _InitUART
;;   _SendStringSerially
;;     _SendByteSerially
;;
;; _ISR (ROOT)
;;   i1_SendByteSerially
;;

;; Address spaces:

;;Name               Size   Autos  Total    Cost      Usage
;;BITCOMMON            E      0       0       0        0.0%
;;EEDATA              80      0       0       0        0.0%
;;NULL                 0      0       0       0        0.0%
;;CODE                 0      0       0       0        0.0%
;;COMMON               E      5       5       1       35.7%
;;BITSFR0              0      0       0       1        0.0%
;;SFR0                 0      0       0       1        0.0%
;;BITSFR1              0      0       0       2        0.0%
;;SFR1                 0      0       0       2        0.0%
;;STACK                0      0       6       2        0.0%
;;BANK0               50      0       0       3        0.0%
;;BITSFR3              0      0       0       4        0.0%
;;SFR3                 0      0       0       4        0.0%
;;ABS                  0      0       0       4        0.0%
;;BITBANK0            50      0       0       5        0.0%
;;BITSFR2              0      0       0       5        0.0%
;;SFR2                 0      0       0       5        0.0%
;;BITBANK1            50      0       0       6        0.0%
;;BANK1               50      0       0       7        0.0%
;;BITBANK2            30      0       0       8        0.0%
;;BANK2               30      0       0       9        0.0%
;;DATA                 0      0       0      10        0.0%

	global	_main
psect	maintext,global,class=CODE,delta=2
global __pmaintext
__pmaintext:

;; *************** function _main *****************
;; Defined at:
;;		line 16 in file "C:\Users\Saeed\Desktop\PIC16F628A UART Code\Code\Main.c"
;; Parameters:    Size  Location     Type
;;		None
;; Auto vars:     Size  Location     Type
;;		None
;; Return value:  Size  Location     Type
;;		None               void
;; Registers used:
;;		wreg, fsr0l, fsr0h, status,2, status,0, pclath, cstack
;; Tracked objects:
;;		On entry : 17F/0
;;		On exit  : 15F/0
;;		Unchanged: FFE80/0
;; Data sizes:     COMMON   BANK0   BANK1   BANK2
;;      Params:         0       0       0       0
;;      Locals:         0       0       0       0
;;      Temps:          0       0       0       0
;;      Totals:         0       0       0       0
;;Total ram usage:        0 bytes
;; Hardware stack levels required when called:    4
;; This function calls:
;;		_InitUART
;;		_SendStringSerially
;; This function is called by:
;;		Startup code after reset
;; This function uses a non-reentrant model
;;
psect	maintext
	file	"C:\Users\Saeed\Desktop\PIC16F628A UART Code\Code\Main.c"
	line	16
	global	__size_of_main
	__size_of_main	equ	__end_of_main-_main
	
_main:	
	opt	stack 4
; Regs used in _main: [wreg-fsr0h+status,2+status,0+pclath+cstack]
	line	17
	
l1986:	
;Main.c: 17: InitUART();
	fcall	_InitUART
	line	19
	
l1988:	
;Main.c: 19: SendStringSerially("Hello World!");
	movlw	((STR_1-__stringbase))&0ffh
	fcall	_SendStringSerially
	line	21
	
l1990:	
;Main.c: 21: GIE = 1;
	bsf	(95/8),(95)&7
	line	22
	
l1992:	
;Main.c: 22: PEIE = 1;
	bsf	(94/8),(94)&7
	line	30
;Main.c: 25: {
	
l763:	
	line	24
	goto	l763
	global	start
	ljmp	start
	opt stack 0
psect	maintext
	line	31
GLOBAL	__end_of_main
	__end_of_main:
;; =============== function _main ends ============

	signat	_main,88
	global	_SendStringSerially
psect	text129,local,class=CODE,delta=2
global __ptext129
__ptext129:

;; *************** function _SendStringSerially *****************
;; Defined at:
;;		line 47 in file "C:\Users\Saeed\Desktop\PIC16F628A UART Code\Code\UART.c"
;; Parameters:    Size  Location     Type
;;  st              1    wreg     PTR const unsigned char 
;;		 -> STR_1(13), 
;; Auto vars:     Size  Location     Type
;;  st              1    4[COMMON] PTR const unsigned char 
;;		 -> STR_1(13), 
;; Return value:  Size  Location     Type
;;		None               void
;; Registers used:
;;		wreg, fsr0l, fsr0h, status,2, status,0, pclath, cstack
;; Tracked objects:
;;		On entry : 17F/20
;;		On exit  : 15F/0
;;		Unchanged: FFE80/0
;; Data sizes:     COMMON   BANK0   BANK1   BANK2
;;      Params:         0       0       0       0
;;      Locals:         1       0       0       0
;;      Temps:          0       0       0       0
;;      Totals:         1       0       0       0
;;Total ram usage:        1 bytes
;; Hardware stack levels used:    1
;; Hardware stack levels required when called:    3
;; This function calls:
;;		_SendByteSerially
;; This function is called by:
;;		_main
;; This function uses a non-reentrant model
;;
psect	text129
	file	"C:\Users\Saeed\Desktop\PIC16F628A UART Code\Code\UART.c"
	line	47
	global	__size_of_SendStringSerially
	__size_of_SendStringSerially	equ	__end_of_SendStringSerially-_SendStringSerially
	
_SendStringSerially:	
	opt	stack 4
; Regs used in _SendStringSerially: [wreg-fsr0h+status,2+status,0+pclath+cstack]
;SendStringSerially@st stored from wreg
	movwf	(SendStringSerially@st)
	line	48
	
l1978:	
;UART.c: 48: while(*st)
	goto	l1984
	line	49
	
l1980:	
;UART.c: 49: SendByteSerially(*st++);
	movf	(SendStringSerially@st),w
	movwf	fsr0
	fcall	stringdir
	fcall	_SendByteSerially
	
l1982:	
	incf	(SendStringSerially@st),f
	line	48
	
l1984:	
	movf	(SendStringSerially@st),w
	movwf	fsr0
	fcall	stringdir
	iorlw	0
	skipz
	goto	u61
	goto	u60
u61:
	goto	l1980
u60:
	line	50
	
l1161:	
	return
	opt stack 0
GLOBAL	__end_of_SendStringSerially
	__end_of_SendStringSerially:
;; =============== function _SendStringSerially ends ============

	signat	_SendStringSerially,4216
	global	_InitUART
psect	text130,local,class=CODE,delta=2
global __ptext130
__ptext130:

;; *************** function _InitUART *****************
;; Defined at:
;;		line 8 in file "C:\Users\Saeed\Desktop\PIC16F628A UART Code\Code\UART.c"
;; Parameters:    Size  Location     Type
;;		None
;; Auto vars:     Size  Location     Type
;;		None
;; Return value:  Size  Location     Type
;;		None               void
;; Registers used:
;;		wreg
;; Tracked objects:
;;		On entry : 17F/0
;;		On exit  : 17F/20
;;		Unchanged: FFE80/0
;; Data sizes:     COMMON   BANK0   BANK1   BANK2
;;      Params:         0       0       0       0
;;      Locals:         0       0       0       0
;;      Temps:          0       0       0       0
;;      Totals:         0       0       0       0
;;Total ram usage:        0 bytes
;; Hardware stack levels used:    1
;; Hardware stack levels required when called:    2
;; This function calls:
;;		Nothing
;; This function is called by:
;;		_main
;; This function uses a non-reentrant model
;;
psect	text130
	file	"C:\Users\Saeed\Desktop\PIC16F628A UART Code\Code\UART.c"
	line	8
	global	__size_of_InitUART
	__size_of_InitUART	equ	__end_of_InitUART-_InitUART
	
_InitUART:	
	opt	stack 5
; Regs used in _InitUART: [wreg]
	line	9
	
l1944:	
;UART.c: 9: TRISB2 = 0;
	bsf	status, 5	;RP0=1, select bank1
	bcf	(1074/8)^080h,(1074)&7
	line	10
;UART.c: 10: TRISB1 = 1;
	bsf	(1073/8)^080h,(1073)&7
	line	12
	
l1946:	
;UART.c: 12: SPBRG = ((20000000/16)/9600) - 1;
	movlw	(081h)
	movwf	(153)^080h	;volatile
	line	13
	
l1948:	
;UART.c: 13: BRGH = 1;
	bsf	(1218/8)^080h,(1218)&7
	line	14
	
l1950:	
;UART.c: 14: SYNC = 0;
	bcf	(1220/8)^080h,(1220)&7
	line	15
	
l1952:	
;UART.c: 15: SPEN = 1;
	bcf	status, 5	;RP0=0, select bank0
	bsf	(199/8),(199)&7
	line	16
	
l1954:	
;UART.c: 16: CREN = 1;
	bsf	(196/8),(196)&7
	line	17
	
l1956:	
;UART.c: 17: SREN = 0;
	bcf	(197/8),(197)&7
	line	18
	
l1958:	
;UART.c: 18: TXIE = 0;
	bsf	status, 5	;RP0=1, select bank1
	bcf	(1124/8)^080h,(1124)&7
	line	19
	
l1960:	
;UART.c: 19: RCIE = 1;
	bsf	(1125/8)^080h,(1125)&7
	line	20
	
l1962:	
;UART.c: 20: TX9 = 0;
	bcf	(1222/8)^080h,(1222)&7
	line	21
	
l1964:	
;UART.c: 21: RX9 = 0;
	bcf	status, 5	;RP0=0, select bank0
	bcf	(198/8),(198)&7
	line	22
	
l1966:	
;UART.c: 22: TXEN = 0;
	bsf	status, 5	;RP0=1, select bank1
	bcf	(1221/8)^080h,(1221)&7
	line	23
	
l1968:	
;UART.c: 23: TXEN = 1;
	bsf	(1221/8)^080h,(1221)&7
	line	24
	
l1142:	
	return
	opt stack 0
GLOBAL	__end_of_InitUART
	__end_of_InitUART:
;; =============== function _InitUART ends ============

	signat	_InitUART,88
	global	_SendByteSerially
psect	text131,local,class=CODE,delta=2
global __ptext131
__ptext131:

;; *************** function _SendByteSerially *****************
;; Defined at:
;;		line 28 in file "C:\Users\Saeed\Desktop\PIC16F628A UART Code\Code\UART.c"
;; Parameters:    Size  Location     Type
;;  Byte            1    wreg     unsigned char 
;; Auto vars:     Size  Location     Type
;;  Byte            1    3[COMMON] unsigned char 
;; Return value:  Size  Location     Type
;;		None               void
;; Registers used:
;;		wreg
;; Tracked objects:
;;		On entry : 15F/20
;;		On exit  : 17F/0
;;		Unchanged: FFE80/0
;; Data sizes:     COMMON   BANK0   BANK1   BANK2
;;      Params:         0       0       0       0
;;      Locals:         1       0       0       0
;;      Temps:          0       0       0       0
;;      Totals:         1       0       0       0
;;Total ram usage:        1 bytes
;; Hardware stack levels used:    1
;; Hardware stack levels required when called:    2
;; This function calls:
;;		Nothing
;; This function is called by:
;;		_SendStringSerially
;; This function uses a non-reentrant model
;;
psect	text131
	file	"C:\Users\Saeed\Desktop\PIC16F628A UART Code\Code\UART.c"
	line	28
	global	__size_of_SendByteSerially
	__size_of_SendByteSerially	equ	__end_of_SendByteSerially-_SendByteSerially
	
_SendByteSerially:	
	opt	stack 4
; Regs used in _SendByteSerially: [wreg]
;SendByteSerially@Byte stored from wreg
	movwf	(SendByteSerially@Byte)
	line	29
	
l1940:	
;UART.c: 29: while(!TXIF);
	
l1145:	
	bcf	status, 5	;RP0=0, select bank0
	btfss	(100/8),(100)&7
	goto	u31
	goto	u30
u31:
	goto	l1145
u30:
	line	30
	
l1942:	
;UART.c: 30: TXREG = Byte;
	movf	(SendByteSerially@Byte),w
	movwf	(25)	;volatile
	line	31
	
l1148:	
	return
	opt stack 0
GLOBAL	__end_of_SendByteSerially
	__end_of_SendByteSerially:
;; =============== function _SendByteSerially ends ============

	signat	_SendByteSerially,4216
	global	_ISR
psect	text132,local,class=CODE,delta=2
global __ptext132
__ptext132:

;; *************** function _ISR *****************
;; Defined at:
;;		line 6 in file "C:\Users\Saeed\Desktop\PIC16F628A UART Code\Code\ISR.c"
;; Parameters:    Size  Location     Type
;;		None
;; Auto vars:     Size  Location     Type
;;		None
;; Return value:  Size  Location     Type
;;		None               void
;; Registers used:
;;		wreg, status,2, status,0, pclath, cstack
;; Tracked objects:
;;		On entry : 0/0
;;		On exit  : 60/0
;;		Unchanged: FFF9F/0
;; Data sizes:     COMMON   BANK0   BANK1   BANK2
;;      Params:         0       0       0       0
;;      Locals:         0       0       0       0
;;      Temps:          2       0       0       0
;;      Totals:         2       0       0       0
;;Total ram usage:        2 bytes
;; Hardware stack levels used:    1
;; Hardware stack levels required when called:    1
;; This function calls:
;;		i1_SendByteSerially
;; This function is called by:
;;		Interrupt level 1
;; This function uses a non-reentrant model
;;
psect	text132
	file	"C:\Users\Saeed\Desktop\PIC16F628A UART Code\Code\ISR.c"
	line	6
	global	__size_of_ISR
	__size_of_ISR	equ	__end_of_ISR-_ISR
	
_ISR:	
	opt	stack 4
; Regs used in _ISR: [wreg+status,2+status,0+pclath+cstack]
psect	intentry,class=CODE,delta=2
global __pintentry
__pintentry:
global interrupt_function
interrupt_function:
	global saved_w
	saved_w	set	btemp+0
	movwf	saved_w
	swapf	status,w
	movwf	(??_ISR+0)
	movf	pclath,w
	movwf	(??_ISR+1)
	ljmp	_ISR
psect	text132
	line	7
	
i1l1994:	
;ISR.c: 7: if(RCIF)
	bcf	status, 5	;RP0=0, select bank0
	bcf	status, 6	;RP1=0, select bank0
	btfss	(101/8),(101)&7
	goto	u7_21
	goto	u7_20
u7_21:
	goto	i1l381
u7_20:
	line	9
	
i1l1996:	
;ISR.c: 8: {
;ISR.c: 9: if(OERR)
	btfss	(193/8),(193)&7
	goto	u8_21
	goto	u8_20
u8_21:
	goto	i1l2000
u8_20:
	line	11
	
i1l1998:	
;ISR.c: 10: {
;ISR.c: 11: CREN = 0;
	bcf	(196/8),(196)&7
	line	12
;ISR.c: 12: CREN = 1;
	bsf	(196/8),(196)&7
	line	15
	
i1l2000:	
;ISR.c: 13: }
;ISR.c: 15: SendByteSerially(RCREG);
	movf	(26),w	;volatile
	fcall	i1_SendByteSerially
	line	17
	
i1l381:	
	movf	(??_ISR+1),w
	movwf	pclath
	swapf	(??_ISR+0)^0FFFFFF80h,w
	movwf	status
	swapf	saved_w,f
	swapf	saved_w,w
	retfie
	opt stack 0
GLOBAL	__end_of_ISR
	__end_of_ISR:
;; =============== function _ISR ends ============

	signat	_ISR,88
	global	i1_SendByteSerially
psect	text133,local,class=CODE,delta=2
global __ptext133
__ptext133:

;; *************** function i1_SendByteSerially *****************
;; Defined at:
;;		line 28 in file "C:\Users\Saeed\Desktop\PIC16F628A UART Code\Code\UART.c"
;; Parameters:    Size  Location     Type
;;  SendByteSeri    1    wreg     unsigned char 
;; Auto vars:     Size  Location     Type
;;  SendByteSeri    1    0[COMMON] unsigned char 
;; Return value:  Size  Location     Type
;;		None               void
;; Registers used:
;;		wreg
;; Tracked objects:
;;		On entry : 60/0
;;		On exit  : 60/0
;;		Unchanged: FFF9F/0
;; Data sizes:     COMMON   BANK0   BANK1   BANK2
;;      Params:         0       0       0       0
;;      Locals:         1       0       0       0
;;      Temps:          0       0       0       0
;;      Totals:         1       0       0       0
;;Total ram usage:        1 bytes
;; Hardware stack levels used:    1
;; This function calls:
;;		Nothing
;; This function is called by:
;;		_ISR
;; This function uses a non-reentrant model
;;
psect	text133
	file	"C:\Users\Saeed\Desktop\PIC16F628A UART Code\Code\UART.c"
	line	28
	global	__size_ofi1_SendByteSerially
	__size_ofi1_SendByteSerially	equ	__end_ofi1_SendByteSerially-i1_SendByteSerially
	
i1_SendByteSerially:	
	opt	stack 4
; Regs used in i1_SendByteSerially: [wreg]
;i1SendByteSerially@Byte stored from wreg
	movwf	(i1SendByteSerially@Byte)
	line	29
	
i1l2002:	
;UART.c: 29: while(!TXIF);
	
i1l1145:	
	btfss	(100/8),(100)&7
	goto	u9_21
	goto	u9_20
u9_21:
	goto	i1l1145
u9_20:
	line	30
	
i1l2004:	
;UART.c: 30: TXREG = Byte;
	movf	(i1SendByteSerially@Byte),w
	movwf	(25)	;volatile
	line	31
	
i1l1148:	
	return
	opt stack 0
GLOBAL	__end_ofi1_SendByteSerially
	__end_ofi1_SendByteSerially:
;; =============== function i1_SendByteSerially ends ============

	signat	i1_SendByteSerially,88
psect	text134,local,class=CODE,delta=2
global __ptext134
__ptext134:
	global	btemp
	btemp set 07Eh

	DABS	1,126,2	;btemp
	global	wtemp0
	wtemp0 set btemp
	end
