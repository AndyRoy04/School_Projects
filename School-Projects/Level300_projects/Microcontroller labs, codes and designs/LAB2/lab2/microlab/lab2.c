void main() {
  TRISB = 0X00;
  while(1){
    unsigned char numbers[10]={0x3F,0x06,0x5B,0X4F,0X66,0X6D,0X7D,0X07,0XFF,0X6F};
    int i=0;
    while(i<10){
      PORTB=numbers[i];
      delay_ms(1000);
      i++;
    }
  }
}