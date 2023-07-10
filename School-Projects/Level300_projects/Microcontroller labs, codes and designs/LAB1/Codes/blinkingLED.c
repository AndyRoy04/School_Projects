void main() {
        TRISB = 0b01111111;

        while(1){
          PORTB.F7 = 1;
          Delay_ms(500);
          PORTB.F7 = 0;
          Delay_ms(500);
        }
}