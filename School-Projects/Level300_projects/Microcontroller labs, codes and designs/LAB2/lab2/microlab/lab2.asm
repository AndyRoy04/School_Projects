
_main:

;lab2.c,1 :: 		void main() {
;lab2.c,2 :: 		TRISB = 0X00;
	CLRF       TRISB+0
;lab2.c,3 :: 		while(1){
L_main0:
;lab2.c,4 :: 		unsigned char numbers[10]={0x3F,0x06,0x5B,0X4F,0X66,0X6D,0X7D,0X07,0XFF,0X6F};
	MOVLW      63
	MOVWF      main_numbers_L1+0
	MOVLW      6
	MOVWF      main_numbers_L1+1
	MOVLW      91
	MOVWF      main_numbers_L1+2
	MOVLW      79
	MOVWF      main_numbers_L1+3
	MOVLW      102
	MOVWF      main_numbers_L1+4
	MOVLW      109
	MOVWF      main_numbers_L1+5
	MOVLW      125
	MOVWF      main_numbers_L1+6
	MOVLW      7
	MOVWF      main_numbers_L1+7
	MOVLW      255
	MOVWF      main_numbers_L1+8
	MOVLW      111
	MOVWF      main_numbers_L1+9
	CLRF       main_i_L1+0
	CLRF       main_i_L1+1
;lab2.c,6 :: 		while(i<10){
L_main2:
	MOVLW      128
	XORWF      main_i_L1+1, 0
	MOVWF      R0+0
	MOVLW      128
	SUBWF      R0+0, 0
	BTFSS      STATUS+0, 2
	GOTO       L__main6
	MOVLW      10
	SUBWF      main_i_L1+0, 0
L__main6:
	BTFSC      STATUS+0, 0
	GOTO       L_main3
;lab2.c,7 :: 		PORTB=numbers[i];
	MOVF       main_i_L1+0, 0
	ADDLW      main_numbers_L1+0
	MOVWF      FSR
	MOVF       INDF+0, 0
	MOVWF      PORTB+0
;lab2.c,8 :: 		delay_ms(1000);
	MOVLW      2
	MOVWF      R11+0
	MOVLW      69
	MOVWF      R12+0
	MOVLW      169
	MOVWF      R13+0
L_main4:
	DECFSZ     R13+0, 1
	GOTO       L_main4
	DECFSZ     R12+0, 1
	GOTO       L_main4
	DECFSZ     R11+0, 1
	GOTO       L_main4
	NOP
	NOP
;lab2.c,9 :: 		i++;
	INCF       main_i_L1+0, 1
	BTFSC      STATUS+0, 2
	INCF       main_i_L1+1, 1
;lab2.c,10 :: 		}
	GOTO       L_main2
L_main3:
;lab2.c,11 :: 		}
	GOTO       L_main0
;lab2.c,12 :: 		}
L_end_main:
	GOTO       $+0
; end of _main
