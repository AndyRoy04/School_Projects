
_READ_temp:

;LAB4.c,27 :: 		void READ_temp(void)
;LAB4.c,29 :: 		temp = ADC_Read(0);
	CLRF       FARG_ADC_Read_channel+0
	CALL       _ADC_Read+0
	CALL       _word2double+0
	MOVF       R0+0, 0
	MOVWF      _temp+0
	MOVF       R0+1, 0
	MOVWF      _temp+1
	MOVF       R0+2, 0
	MOVWF      _temp+2
	MOVF       R0+3, 0
	MOVWF      _temp+3
;LAB4.c,30 :: 		temp = temp * 5/1023;                                                                                                                                                                       temp = temp * 100;
	MOVLW      0
	MOVWF      R4+0
	MOVLW      0
	MOVWF      R4+1
	MOVLW      32
	MOVWF      R4+2
	MOVLW      129
	MOVWF      R4+3
	CALL       _Mul_32x32_FP+0
	MOVLW      0
	MOVWF      R4+0
	MOVLW      192
	MOVWF      R4+1
	MOVLW      127
	MOVWF      R4+2
	MOVLW      136
	MOVWF      R4+3
	CALL       _Div_32x32_FP+0
	MOVF       R0+0, 0
	MOVWF      _temp+0
	MOVF       R0+1, 0
	MOVWF      _temp+1
	MOVF       R0+2, 0
	MOVWF      _temp+2
	MOVF       R0+3, 0
	MOVWF      _temp+3
	MOVLW      0
	MOVWF      R4+0
	MOVLW      0
	MOVWF      R4+1
	MOVLW      72
	MOVWF      R4+2
	MOVLW      133
	MOVWF      R4+3
	CALL       _Mul_32x32_FP+0
	MOVF       R0+0, 0
	MOVWF      _temp+0
	MOVF       R0+1, 0
	MOVWF      _temp+1
	MOVF       R0+2, 0
	MOVWF      _temp+2
	MOVF       R0+3, 0
	MOVWF      _temp+3
;LAB4.c,31 :: 		}
L_end_READ_temp:
	RETURN
; end of _READ_temp

_data_converstion:

;LAB4.c,32 :: 		void data_converstion(void)
;LAB4.c,34 :: 		floattostr(temp,temper); // float temperature to string
	MOVF       _temp+0, 0
	MOVWF      FARG_FloatToStr_fnum+0
	MOVF       _temp+1, 0
	MOVWF      FARG_FloatToStr_fnum+1
	MOVF       _temp+2, 0
	MOVWF      FARG_FloatToStr_fnum+2
	MOVF       _temp+3, 0
	MOVWF      FARG_FloatToStr_fnum+3
	MOVLW      _temper+0
	MOVWF      FARG_FloatToStr_str+0
	CALL       _FloatToStr+0
;LAB4.c,35 :: 		}
L_end_data_converstion:
	RETURN
; end of _data_converstion

_display1:

;LAB4.c,36 :: 		void display1(void)
;LAB4.c,38 :: 		lcd_out(1,1,"TEMP = ");
	MOVLW      1
	MOVWF      FARG_Lcd_Out_row+0
	MOVLW      1
	MOVWF      FARG_Lcd_Out_column+0
	MOVLW      ?lstr1_LAB4+0
	MOVWF      FARG_Lcd_Out_text+0
	CALL       _Lcd_Out+0
;LAB4.c,39 :: 		lcd_out(1,8, Ltrim(temper));
	MOVLW      _temper+0
	MOVWF      FARG_Ltrim_string+0
	CALL       _Ltrim+0
	MOVF       R0+0, 0
	MOVWF      FARG_Lcd_Out_text+0
	MOVLW      1
	MOVWF      FARG_Lcd_Out_row+0
	MOVLW      8
	MOVWF      FARG_Lcd_Out_column+0
	CALL       _Lcd_Out+0
;LAB4.c,40 :: 		Lcd_Chr_Cp(0xdf);
	MOVLW      223
	MOVWF      FARG_Lcd_Chr_CP_out_char+0
	CALL       _Lcd_Chr_CP+0
;LAB4.c,41 :: 		Lcd_Chr_Cp('C');
	MOVLW      67
	MOVWF      FARG_Lcd_Chr_CP_out_char+0
	CALL       _Lcd_Chr_CP+0
;LAB4.c,42 :: 		Lcd_Chr_Cp(' ');
	MOVLW      32
	MOVWF      FARG_Lcd_Chr_CP_out_char+0
	CALL       _Lcd_Chr_CP+0
;LAB4.c,43 :: 		}
L_end_display1:
	RETURN
; end of _display1

_main:

;LAB4.c,45 :: 		void main()
;LAB4.c,47 :: 		LED_YELLOW_Direction = 0;
	BCF        TRISC2_bit+0, BitPos(TRISC2_bit+0)
;LAB4.c,48 :: 		LED_GREEN_Direction = 0;
	BCF        TRISC3_bit+0, BitPos(TRISC3_bit+0)
;LAB4.c,49 :: 		LED_RED_Direction   = 0;
	BCF        TRISC4_bit+0, BitPos(TRISC4_bit+0)
;LAB4.c,51 :: 		ADC_Init();
	CALL       _ADC_Init+0
;LAB4.c,52 :: 		Lcd_Init(); // Initialize LCD
	CALL       _Lcd_Init+0
;LAB4.c,53 :: 		Lcd_Cmd(_LCD_CLEAR); // Clear display
	MOVLW      1
	MOVWF      FARG_Lcd_Cmd_out_char+0
	CALL       _Lcd_Cmd+0
;LAB4.c,54 :: 		lcd_cmd(_LCD_CURSOR_OFF);
	MOVLW      12
	MOVWF      FARG_Lcd_Cmd_out_char+0
	CALL       _Lcd_Cmd+0
;LAB4.c,55 :: 		Lcd_Cmd(_LCD_CLEAR); // Clear display
	MOVLW      1
	MOVWF      FARG_Lcd_Cmd_out_char+0
	CALL       _Lcd_Cmd+0
;LAB4.c,56 :: 		while(1)
L_main0:
;LAB4.c,58 :: 		READ_temp();
	CALL       _READ_temp+0
;LAB4.c,59 :: 		data_converstion();
	CALL       _data_converstion+0
;LAB4.c,60 :: 		display1();
	CALL       _display1+0
;LAB4.c,62 :: 		if(temp < 20.0){   // LOW TEMP
	MOVLW      0
	MOVWF      R4+0
	MOVLW      0
	MOVWF      R4+1
	MOVLW      32
	MOVWF      R4+2
	MOVLW      131
	MOVWF      R4+3
	MOVF       _temp+0, 0
	MOVWF      R0+0
	MOVF       _temp+1, 0
	MOVWF      R0+1
	MOVF       _temp+2, 0
	MOVWF      R0+2
	MOVF       _temp+3, 0
	MOVWF      R0+3
	CALL       _Compare_Double+0
	MOVLW      1
	BTFSC      STATUS+0, 0
	MOVLW      0
	MOVWF      R0+0
	MOVF       R0+0, 0
	BTFSC      STATUS+0, 2
	GOTO       L_main2
;LAB4.c,63 :: 		YELLOW_LED = 1;
	BSF        RC2_bit+0, BitPos(RC2_bit+0)
;LAB4.c,67 :: 		RED_LED = 0;
	BCF        RC4_bit+0, BitPos(RC4_bit+0)
;LAB4.c,68 :: 		GREEN_LED = 0;
	BCF        RC3_bit+0, BitPos(RC3_bit+0)
;LAB4.c,69 :: 		delay_ms(500);
	MOVLW      3
	MOVWF      R11+0
	MOVLW      138
	MOVWF      R12+0
	MOVLW      85
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
;LAB4.c,70 :: 		}
	GOTO       L_main4
L_main2:
;LAB4.c,71 :: 		else if(temp >= 20.0 && temp <= 30.0){  // NORMAL TEMP
	MOVLW      0
	MOVWF      R4+0
	MOVLW      0
	MOVWF      R4+1
	MOVLW      32
	MOVWF      R4+2
	MOVLW      131
	MOVWF      R4+3
	MOVF       _temp+0, 0
	MOVWF      R0+0
	MOVF       _temp+1, 0
	MOVWF      R0+1
	MOVF       _temp+2, 0
	MOVWF      R0+2
	MOVF       _temp+3, 0
	MOVWF      R0+3
	CALL       _Compare_Double+0
	MOVLW      1
	BTFSS      STATUS+0, 0
	MOVLW      0
	MOVWF      R0+0
	MOVF       R0+0, 0
	BTFSC      STATUS+0, 2
	GOTO       L_main7
	MOVF       _temp+0, 0
	MOVWF      R4+0
	MOVF       _temp+1, 0
	MOVWF      R4+1
	MOVF       _temp+2, 0
	MOVWF      R4+2
	MOVF       _temp+3, 0
	MOVWF      R4+3
	MOVLW      0
	MOVWF      R0+0
	MOVLW      0
	MOVWF      R0+1
	MOVLW      112
	MOVWF      R0+2
	MOVLW      131
	MOVWF      R0+3
	CALL       _Compare_Double+0
	MOVLW      1
	BTFSS      STATUS+0, 0
	MOVLW      0
	MOVWF      R0+0
	MOVF       R0+0, 0
	BTFSC      STATUS+0, 2
	GOTO       L_main7
L__main11:
;LAB4.c,72 :: 		GREEN_LED = 1;
	BSF        RC3_bit+0, BitPos(RC3_bit+0)
;LAB4.c,76 :: 		YELLOW_LED = 0;
	BCF        RC2_bit+0, BitPos(RC2_bit+0)
;LAB4.c,77 :: 		RED_LED = 0;
	BCF        RC4_bit+0, BitPos(RC4_bit+0)
;LAB4.c,78 :: 		delay_ms(500);
	MOVLW      3
	MOVWF      R11+0
	MOVLW      138
	MOVWF      R12+0
	MOVLW      85
	MOVWF      R13+0
L_main8:
	DECFSZ     R13+0, 1
	GOTO       L_main8
	DECFSZ     R12+0, 1
	GOTO       L_main8
	DECFSZ     R11+0, 1
	GOTO       L_main8
	NOP
	NOP
;LAB4.c,79 :: 		}
	GOTO       L_main9
L_main7:
;LAB4.c,81 :: 		RED_LED = 1;
	BSF        RC4_bit+0, BitPos(RC4_bit+0)
;LAB4.c,85 :: 		YELLOW_LED = 0;
	BCF        RC2_bit+0, BitPos(RC2_bit+0)
;LAB4.c,86 :: 		GREEN_LED = 0;
	BCF        RC3_bit+0, BitPos(RC3_bit+0)
;LAB4.c,87 :: 		delay_ms(500);
	MOVLW      3
	MOVWF      R11+0
	MOVLW      138
	MOVWF      R12+0
	MOVLW      85
	MOVWF      R13+0
L_main10:
	DECFSZ     R13+0, 1
	GOTO       L_main10
	DECFSZ     R12+0, 1
	GOTO       L_main10
	DECFSZ     R11+0, 1
	GOTO       L_main10
	NOP
	NOP
;LAB4.c,88 :: 		}
L_main9:
L_main4:
;LAB4.c,89 :: 		}
	GOTO       L_main0
;LAB4.c,90 :: 		}
L_end_main:
	GOTO       $+0
; end of _main
