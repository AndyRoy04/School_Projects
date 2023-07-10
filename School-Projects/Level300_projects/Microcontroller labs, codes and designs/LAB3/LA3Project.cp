#line 1 "C:/Users/djeut/OneDrive/Desktop/Antana/Micro/LAB3/LA3Project.c"

sbit Switch at RB0_bit;
sbit LCD_RS at RC2_bit;
sbit LCD_EN at RC3_bit;
sbit LCD_D4 at RC4_bit;
sbit LCD_D5 at RC5_bit;
sbit LCD_D6 at RC6_bit;
sbit LCD_D7 at RC7_bit;

sbit LCD_RS_Direction at TRISC2_bit;
sbit LCD_EN_Direction at TRISC3_bit;
sbit LCD_D4_Direction at TRISC4_bit;
sbit LCD_D5_Direction at TRISC5_bit;
sbit LCD_D6_Direction at TRISC6_bit;
sbit LCD_D7_Direction at TRISC7_bit;


char* members[4][2] = {
 {"DJEUTIO ANDERSON ROY", "FE21A169"},
 {"AJAMAH GODLOVE", "FE21A129"},
 {"AKENGNI EMMANUEL", "FE21A132"},
 {"ALAIN NKEH MBUNKUR", "FE21A133"}
};

void main() {
 int i = 0;
 char line1[16], line2[16];


 Lcd_Init();
 Lcd_Cmd(_LCD_CURSOR_OFF);
 while (1) {

 Lcd_Out(1, 1, members[i][0]);
 Lcd_Out(2, 1, members[i][1]);
 Delay_ms(1000);
 Lcd_Cmd(_LCD_CLEAR);
 i++;
 if (i >= 4) {
 i = 0;
 }
 }
}
