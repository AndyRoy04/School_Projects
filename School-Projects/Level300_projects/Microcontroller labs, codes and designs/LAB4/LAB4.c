 // Temp-sensor connections
    sbit LCD_D7 at RB2_bit;
    sbit LCD_D6 at RB3_bit;
    sbit LCD_D5 at RB4_bit;
    sbit LCD_D4 at RB5_bit;
    sbit LCD_EN at RB6_bit;
    sbit LCD_RS at RB7_bit;
// led connections
    sbit YELLOW_LED at RC2_bit;
    sbit GREEN_LED  at RC3_bit;
    sbit RED_LED    at RC4_bit;
// PIN DIRECTIONS
    sbit LCD_D7_Direction at TRISB2_bit;
    sbit LCD_D6_Direction at TRISB3_bit;
    sbit LCD_D5_Direction at TRISB4_bit;
    sbit LCD_D4_Direction at TRISB5_bit;
    sbit LCD_EN_Direction at TRISB6_bit;
    sbit LCD_RS_Direction at TRISB7_bit;
//Initiallising LED output
    sbit LED_YELLOW_Direction at TRISC2_bit;
    sbit LED_GREEN_Direction  at TRISC3_bit;
    sbit LED_RED_Direction    at TRISC4_bit;
//defining Temperature variables
float temp;
char temper[7];
//code
void READ_temp(void)
{
    temp = ADC_Read(0);
    temp = temp * 5/1023;                                                                                                                                                                       temp = temp * 100;
}
void data_converstion(void)
{
floattostr(temp,temper); // float temperature to string
}
void display1(void)
{
    lcd_out(1,1,"TEMP = ");
    lcd_out(1,8, Ltrim(temper));
    Lcd_Chr_Cp(0xdf);
    Lcd_Chr_Cp('C');
    Lcd_Chr_Cp(' ');
}
   // main function
void main()
{
    LED_YELLOW_Direction = 0;
    LED_GREEN_Direction = 0;
    LED_RED_Direction   = 0;
// Read ADC Value
    ADC_Init();
    Lcd_Init(); // Initialize LCD
    Lcd_Cmd(_LCD_CLEAR); // Clear display
    lcd_cmd(_LCD_CURSOR_OFF);
    Lcd_Cmd(_LCD_CLEAR); // Clear display
while(1)
{
    READ_temp();
    data_converstion();
    display1();

       if(temp < 20.0){   // LOW TEMP
               YELLOW_LED = 1;
//               delay_ms(500);
//               YELLOW_LED = 0;
//               delay_ms(500);
               RED_LED = 0;
               GREEN_LED = 0;
               delay_ms(500);
       }
       else if(temp >= 20.0 && temp <= 30.0){  // NORMAL TEMP
               GREEN_LED = 1;
//               delay_ms(500);
//               GREEN_LED = 0;
//               delay_ms(500);
               YELLOW_LED = 0;
               RED_LED = 0;
               delay_ms(500);
       }
       else{                  // HIGH TEMP
               RED_LED = 1;
//               delay_ms(500);
//               RED_LED = 0;
//               delay_ms(500);
               YELLOW_LED = 0;
               GREEN_LED = 0;
               delay_ms(500);
       }
}
}