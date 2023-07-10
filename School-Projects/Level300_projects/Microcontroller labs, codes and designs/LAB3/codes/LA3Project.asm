
_main:

;LA3Project.c,25 :: 		void main() {
;LA3Project.c,26 :: 		int i = 0;
	CLRF       main_i_L0+0
	CLRF       main_i_L0+1
;LA3Project.c,30 :: 		Lcd_Init();
	CALL       _Lcd_Init+0
;LA3Project.c,31 :: 		Lcd_Cmd(_LCD_CURSOR_OFF);
	MOVLW      12
	MOVWF      FARG_Lcd_Cmd_out_char+0
	CALL       _Lcd_Cmd+0
;LA3Project.c,32 :: 		while (1) {
L_main0:
;LA3Project.c,34 :: 		Lcd_Out(1, 1, members[i][0]);
	MOVLW      1
	MOVWF      FARG_Lcd_Out_row+0
	MOVLW      1
	MOVWF      FARG_Lcd_Out_column+0
	MOVF       main_i_L0+0, 0
	MOVWF      R0+0
	MOVF       main_i_L0+1, 0
	MOVWF      R0+1
	RLF        R0+0, 1
	RLF        R0+1, 1
	BCF        R0+0, 0
	MOVF       R0+0, 0
	ADDLW      _members+0
	MOVWF      FSR
	MOVF       INDF+0, 0
	MOVWF      FARG_Lcd_Out_text+0
	CALL       _Lcd_Out+0
;LA3Project.c,35 :: 		Lcd_Out(2, 1, members[i][1]);
	MOVLW      2
	MOVWF      FARG_Lcd_Out_row+0
	MOVLW      1
	MOVWF      FARG_Lcd_Out_column+0
	MOVF       main_i_L0+0, 0
	MOVWF      R0+0
	MOVF       main_i_L0+1, 0
	MOVWF      R0+1
	RLF        R0+0, 1
	RLF        R0+1, 1
	BCF        R0+0, 0
	MOVLW      _members+0
	ADDWF      R0+0, 1
	INCF       R0+0, 0
	MOVWF      FSR
	MOVF       INDF+0, 0
	MOVWF      FARG_Lcd_Out_text+0
	CALL       _Lcd_Out+0
;LA3Project.c,36 :: 		Delay_ms(1000); // Wait for 1 second
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
;LA3Project.c,37 :: 		Lcd_Cmd(_LCD_CLEAR); // Clear the LCD after Display
	MOVLW      1
	MOVWF      FARG_Lcd_Cmd_out_char+0
	CALL       _Lcd_Cmd+0
;LA3Project.c,38 :: 		i++; // Increment the group member index
	INCF       main_i_L0+0, 1
	BTFSC      STATUS+0, 2
	INCF       main_i_L0+1, 1
;LA3Project.c,39 :: 		if (i >= 4) {
	MOVLW      128
	XORWF      main_i_L0+1, 0
	MOVWF      R0+0
	MOVLW      128
	SUBWF      R0+0, 0
	BTFSS      STATUS+0, 2
	GOTO       L__main5
	MOVLW      4
	SUBWF      main_i_L0+0, 0
L__main5:
	BTFSS      STATUS+0, 0
	GOTO       L_main3
;LA3Project.c,40 :: 		i = 0;
	CLRF       main_i_L0+0
	CLRF       main_i_L0+1
;LA3Project.c,41 :: 		}
L_main3:
;LA3Project.c,42 :: 		}
	GOTO       L_main0
;LA3Project.c,43 :: 		}
L_end_main:
	GOTO       $+0
; end of _main
