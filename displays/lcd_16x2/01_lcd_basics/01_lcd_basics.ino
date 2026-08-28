/*
WIRING (ESP32):
VCC  -> 5V
GND  -> GND
SDA  -> GPIO 21
SCL  -> GPIO 22

I2C address: Default 0x27
*/

#include <Wire.h>
#include <LiquidCrystal_I2C.h>  // Library for I2C LCD

#define I2C_ADDR 0x27
#define LCD_COLUMNS 16
#define LCD_ROWS 2

// LCD Object
LiquidCrystal_I2C lcd (I2C_ADDR, LCD_COLUMNS, LCD_ROWS);

void setup()
{
  Serial.begin(115200);

  Wire.begin();

  // LCD Init
  lcd.init();

  // Turn on backlight
  lcd.backlight();

  // Clear LCD
  lcd.clear();

  // set LCD cursor
  lcd.setCursor(0, 0);

  // Print 
  lcd.print("HELLO");

  lcd.setCursor(0, 1);

  lcd.print("16x2 LCD Ready");
}

void loop()
{
  // empty
}