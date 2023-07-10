			list p=p16f84A              ;to specify the type of microcontroller
			#include "p16f84a.inc"
			__CONFIG _CP_OFF & _WDT_OFF & _XT_OSC & _PWRTE_OFF
		org 0x00
		goto start
		start 
			bsf STATUS, RP0
			bcf TRISB,0
			bcf TRISB,1
			bcf TRISB,2
                    bcf TRISB,3
			bcf STATUS,RP0
		MAIN
			movlw b'00000'
			movwf PORTB
						
			movlw b'00001'
			movwf PORTB
						
			movlw b'00010'
			movwf PORTB
						
			movlw b'00011'
			movwf PORTB
						
			movlw b'00100'
			movwf PORTB
						
			movlw b'00101'
			movwf PORTB
						
			movlw b'00110'
			movwf PORTB
						
			movlw b'00111'
			movwf PORTB

                    movlw b'01000'
			movwf PORTB

                    movlw b'01001'
			movwf PORTB
					
			goto MAIN
		END