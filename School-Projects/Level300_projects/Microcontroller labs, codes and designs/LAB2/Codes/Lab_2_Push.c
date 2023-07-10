const long int seg[10]= { 0x3F, 0x06 ,0x5B  , 0x4F ,0x66 , 0x6D , 0x7D,  0x07 , 0x7F, 0x6F};
  int i=0;
void main() {
     TRISB = 0x80;
     PORTB= 0x3F;

while(1) {
    if (Button(&PORTB, 7, 1, 1)) {               // Detect logical one
      i++;
      Delay_ms(500);
    }
    else  {   // Detect one-to-zero transition
        PORTB=seg[i];
        Delay_ms(100);
    }
}
 }