
_main:

;MyPrelab3.c,19 :: 		void main() {
;MyPrelab3.c,20 :: 		PORTA = 0;
	CLRF       PORTA+0
;MyPrelab3.c,21 :: 		TRISA = 0X01;
	MOVLW      1
	MOVWF      TRISA+0
;MyPrelab3.c,22 :: 		PORTC = 0;
	CLRF       PORTC+0
;MyPrelab3.c,23 :: 		TRISC = 0;
	CLRF       TRISC+0
;MyPrelab3.c,25 :: 		Lcd_Init();    // Initialize the LCD
	CALL       _Lcd_Init+0
;MyPrelab3.c,26 :: 		ADC_Init();
	CALL       _ADC_Init+0
;MyPrelab3.c,27 :: 		LCD_Cmd(_LCD_CURSOR_OFF);
	MOVLW      12
	MOVWF      FARG_Lcd_Cmd_out_char+0
	CALL       _Lcd_Cmd+0
;MyPrelab3.c,28 :: 		LCD_Cmd(_LCD_CLEAR);
	MOVLW      1
	MOVWF      FARG_Lcd_Cmd_out_char+0
	CALL       _Lcd_Cmd+0
;MyPrelab3.c,32 :: 		while (1) {
L_main0:
;MyPrelab3.c,33 :: 		voltage = (float)ADC_Read(0)/(100);
	CLRF       FARG_ADC_Read_channel+0
	CALL       _ADC_Read+0
	CALL       _word2double+0
	MOVLW      0
	MOVWF      R4+0
	MOVLW      0
	MOVWF      R4+1
	MOVLW      72
	MOVWF      R4+2
	MOVLW      133
	MOVWF      R4+3
	CALL       _Div_32x32_FP+0
	MOVF       R0+0, 0
	MOVWF      _voltage+0
	MOVF       R0+1, 0
	MOVWF      _voltage+1
	MOVF       R0+2, 0
	MOVWF      _voltage+2
	MOVF       R0+3, 0
	MOVWF      _voltage+3
;MyPrelab3.c,36 :: 		floattostr(voltage,volt); // it converts integer value into string
	MOVF       R0+0, 0
	MOVWF      FARG_FloatToStr_fnum+0
	MOVF       R0+1, 0
	MOVWF      FARG_FloatToStr_fnum+1
	MOVF       R0+2, 0
	MOVWF      FARG_FloatToStr_fnum+2
	MOVF       R0+3, 0
	MOVWF      FARG_FloatToStr_fnum+3
	MOVLW      _volt+0
	MOVWF      FARG_FloatToStr_str+0
	CALL       _FloatToStr+0
;MyPrelab3.c,37 :: 		Lcd_Out(2,1,"Voltage = ");
	MOVLW      2
	MOVWF      FARG_Lcd_Out_row+0
	MOVLW      1
	MOVWF      FARG_Lcd_Out_column+0
	MOVLW      ?lstr1_MyPrelab3+0
	MOVWF      FARG_Lcd_Out_text+0
	CALL       _Lcd_Out+0
;MyPrelab3.c,38 :: 		Lcd_Out(2,11,Ltrim(volt));
	MOVLW      _volt+0
	MOVWF      FARG_Ltrim_string+0
	CALL       _Ltrim+0
	MOVF       R0+0, 0
	MOVWF      FARG_Lcd_Out_text+0
	MOVLW      2
	MOVWF      FARG_Lcd_Out_row+0
	MOVLW      11
	MOVWF      FARG_Lcd_Out_column+0
	CALL       _Lcd_Out+0
;MyPrelab3.c,39 :: 		Lcd_Out(2,22," V");
	MOVLW      2
	MOVWF      FARG_Lcd_Out_row+0
	MOVLW      22
	MOVWF      FARG_Lcd_Out_column+0
	MOVLW      ?lstr2_MyPrelab3+0
	MOVWF      FARG_Lcd_Out_text+0
	CALL       _Lcd_Out+0
;MyPrelab3.c,41 :: 		}
	GOTO       L_main0
;MyPrelab3.c,42 :: 		}
L_end_main:
	GOTO       $+0
; end of _main
