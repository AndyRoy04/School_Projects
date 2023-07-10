#line 1 "D:/300.2/EEF 368 micro lab/lab2/microlab/microCPush.c"
void main() {
const long int seg[10]= { 0x3F, 0x06 ,0x5B , 0x4F ,0x66 , 0x6D , 0x7D, 0x07 , 0x7F, 0x6F};
 int i=0;
 TRISB = 0x80;
 PORTB= 0x3F;
 int Button = RA0;
while(1) {
 if (Button(&PORTB, 7, 1, 1)) {
 i++;
 Delay_ms(500);
 }
 else {
 PORTB=seg[i];
 Delay_ms(100);
 }

}
 }
