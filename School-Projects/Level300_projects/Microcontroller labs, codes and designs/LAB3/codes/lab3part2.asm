
_main:

;lab3part2.c,19 :: 		void main() {
;lab3part2.c,20 :: 		PORTA = 0;
	CLRF       PORTA+0
;lab3part2.c,21 :: 		TRISA = 0X01;
	MOVLW      1
	MOVWF      TRISA+0
;lab3part2.c,22 :: 		PORTC = 0;
	CLRF       PORTC+0
;lab3part2.c,23 :: 		TRISC = 0;
	CLRF       TRISC+0
;lab3part2.c,25 :: 		Lcd_Init();    // Initialize the LCD
	CALL       _Lcd_Init+0
;lab3part2.c,26 :: 		ADC_Init();
	CALL       _ADC_Init+0
;lab3part2.c,27 :: 		LCD_Cmd(_LCD_CURSOR_OFF);
	MOVLW      12
	MOVWF      FARG_Lcd_Cmd_out_char+0
	CALL       _Lcd_Cmd+0
;lab3part2.c,28 :: 		LCD_Cmd(_LCD_CLEAR);
	MOVLW      1
	MOVWF      FARG_Lcd_Cmd_out_char+0
	CALL       _Lcd_Cmd+0
;lab3part2.c,30 :: 		delay_ms(1000);
	MOVLW      6
	MOVWF      R11+0
	MOVLW      19
	MOVWF      R12+0
	MOVLW      173
	MOVWF      R13+0
L_main0:
	DECFSZ     R13+0, 1
	GOTO       L_main0
	DECFSZ     R12+0, 1
	GOTO       L_main0
	DECFSZ     R11+0, 1
	GOTO       L_main0
	NOP
	NOP
;lab3part2.c,32 :: 		while (1) {
L_main1:
;lab3part2.c,33 :: 		voltage = ADC_Read(0);
	CLRF       FARG_ADC_Read_channel+0
	CALL       _ADC_Read+0
	CALL       _word2double+0
	MOVF       R0+0, 0
	MOVWF      _voltage+0
	MOVF       R0+1, 0
	MOVWF      _voltage+1
	MOVF       R0+2, 0
	MOVWF      _voltage+2
	MOVF       R0+3, 0
	MOVWF      _voltage+3
;lab3part2.c,35 :: 		inttostr(voltage,volt); // it converts integer value into string
	CALL       _double2int+0
	MOVF       R0+0, 0
	MOVWF      FARG_IntToStr_input+0
	MOVF       R0+1, 0
	MOVWF      FARG_IntToStr_input+1
	MOVLW      _volt+0
	MOVWF      FARG_IntToStr_output+0
	CALL       _IntToStr+0
;lab3part2.c,36 :: 		Lcd_Out(2,1,"Voltage = ");
	MOVLW      2
	MOVWF      FARG_Lcd_Out_row+0
	MOVLW      1
	MOVWF      FARG_Lcd_Out_column+0
	MOVLW      ?lstr1_lab3part2+0
	MOVWF      FARG_Lcd_Out_text+0
	CALL       _Lcd_Out+0
;lab3part2.c,37 :: 		Lcd_Out(2,11,Ltrim(volt));
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
;lab3part2.c,38 :: 		Lcd_Out(2,13,"V");
	MOVLW      2
	MOVWF      FARG_Lcd_Out_row+0
	MOVLW      13
	MOVWF      FARG_Lcd_Out_column+0
	MOVLW      ?lstr2_lab3part2+0
	MOVWF      FARG_Lcd_Out_text+0
	CALL       _Lcd_Out+0
;lab3part2.c,40 :: 		}
	GOTO       L_main1
;lab3part2.c,41 :: 		}
L_end_main:
	GOTO       $+0
; end of _main
