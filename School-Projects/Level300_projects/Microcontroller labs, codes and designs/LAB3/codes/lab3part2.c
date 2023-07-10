// Define the switch pin
sbit LCD_RS at RC4_bit;
sbit LCD_EN at RC5_bit;
sbit LCD_D4 at RC0_bit;
sbit LCD_D5 at RC1_bit;
sbit LCD_D6 at RC2_bit;
sbit LCD_D7 at RC3_bit;

sbit LCD_RS_Direction at TRISC4_bit;
sbit LCD_EN_Direction at TRISC5_bit;
sbit LCD_D4_Direction at TRISC0_bit;
sbit LCD_D5_Direction at TRISC1_bit;
sbit LCD_D6_Direction at TRISC2_bit;
sbit LCD_D7_Direction at TRISC3_bit;

    int Adread;
    float voltage;
    char volt[5];
void main() {
    PORTA = 0;
    TRISA = 0X01;
    PORTC = 0;
    TRISC = 0;

    Lcd_Init();    // Initialize the LCD
    ADC_Init();
    LCD_Cmd(_LCD_CURSOR_OFF);
    LCD_Cmd(_LCD_CLEAR);
//    LCD_Out(1, 1, "Digital voltmeter");
    delay_ms(1000);
    
    while (1) {
	voltage = ADC_Read(0);
//    voltage = (voltage * 5 * 10)/ (1024);
      inttostr(voltage,volt); // it converts integer value into string
      Lcd_Out(2,1,"Voltage = ");
      Lcd_Out(2,11,Ltrim(volt));
      Lcd_Out(2,13,"V");

    }
}