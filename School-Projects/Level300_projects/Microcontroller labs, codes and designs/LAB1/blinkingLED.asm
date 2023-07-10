
_main:

;blinkingLED.c,1 :: 		void main() {
;blinkingLED.c,2 :: 		TRISB = 0b01111111;
	MOVLW      127
	MOVWF      TRISB+0
;blinkingLED.c,4 :: 		while(1){
L_main0:
;blinkingLED.c,5 :: 		PORTB.F7 = 1;
	BSF        PORTB+0, 7
;blinkingLED.c,6 :: 		Delay_ms(500);
	MOVLW      6
	MOVWF      R11+0
	MOVLW      19
	MOVWF      R12+0
	MOVLW      173
	MOVWF      R13+0
L_main2:
	DECFSZ     R13+0, 1
	GOTO       L_main2
	DECFSZ     R12+0, 1
	GOTO       L_main2
	DECFSZ     R11+0, 1
	GOTO       L_main2
	NOP
	NOP
;blinkingLED.c,7 :: 		PORTB.F7 = 0;
	BCF        PORTB+0, 7
;blinkingLED.c,8 :: 		Delay_ms(500);
	MOVLW      6
	MOVWF      R11+0
	MOVLW      19
	MOVWF      R12+0
	MOVLW      173
	MOVWF      R13+0
L_main3:
	DECFSZ     R13+0, 1
	GOTO       L_main3
	DECFSZ     R12+0, 1
	GOTO       L_main3
	DECFSZ     R11+0, 1
	GOTO       L_main3
	NOP
	NOP
;blinkingLED.c,9 :: 		}
	GOTO       L_main0
;blinkingLED.c,10 :: 		}
L_end_main:
	GOTO       $+0
; end of _main
