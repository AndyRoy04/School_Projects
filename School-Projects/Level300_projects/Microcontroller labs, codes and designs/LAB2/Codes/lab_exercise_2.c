void main() {
     TRISB = 0;
     while(1) {
           PORTB = 0x3F;
           Delay_ms(1000);
           PORTB = 0x06;
           Delay_ms(1000);
           PORTB = 0x5B;
           Delay_ms(1000);
           PORTB = 0x4F;
           Delay_ms(1000);
           PORTB = 0x66;
           Delay_ms(1000);
           PORTB = 0x6D;
           Delay_ms(1000);
           PORTB = 0x7D;
           Delay_ms(1000);
           PORTB = 0x07;
           Delay_ms(1000);
           PORTB = 0x7F;
           Delay_ms(1000);
           PORTB = 0x6F;
           Delay_ms(1000);
     }
}