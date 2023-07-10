			list p=p16f84A            
			#include "p16f84a.inc"

			__CONFIG _CP_OFF & _WDT_OFF & _XT_OSC & _PWRTE_OFF

		org 0x00
		goto START
	START
		bsf STATUS, RP0
		bcf TRISB, 0
		bcf TRISB, 1
		bcf TRISB, 2
		bcf STATUS, RP0
	MAIN
		movlw b'0000'
		movwf PORTB
		
		movlw b'0001'
		movwf PORTB
		
		movlw b'0010'
		movwf PORTB

		movlw b'0011'
		movwf PORTB

		movlw b'0100'
		movwf PORTB

		movlw b'0101'
		movwf PORTB

		movlw b'0110'
		movwf PORTB

		movlw b'0111'
		movwf PORTB
	goto MAIN

 		END
