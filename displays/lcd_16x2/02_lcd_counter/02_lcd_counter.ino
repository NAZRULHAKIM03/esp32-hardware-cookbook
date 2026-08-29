#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define LCD_ADDR 0x27
#define LCD_COLUMNS 16
#define LCD_ROWS 2

int counter = 0;

LiquidCrystal_I2C lcd (LCD_ADDR, LCD_COLUMNS, LCD_ROWS);

void setup()
{
  Serial.begin(115200);
  Wire.begin();

  lcd.init();
  lcd.backlight();
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("NAZRUL");
}

void loop()
{
  lcd.setCursor(0, 1);
  lcd.print("Count : ");
  lcd.print(counter);
  lcd.print("   ");   // 3 spaces to clear leftover digits if count down

  counter++;
  delay(1000); // 1 second delay
}