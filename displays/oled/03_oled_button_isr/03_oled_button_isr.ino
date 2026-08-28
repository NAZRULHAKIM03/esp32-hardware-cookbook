#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display (SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

volatile uint8_t press_count = 0;
volatile bool new_press = false;

//Debouncing 
volatile unsigned long last_interrupt_time = 0;
const unsigned long DEBOUNCE_DELAY = 250; //ignore bounce for 250 milliseconds

void IRAM_ATTR button_isr()
{
  unsigned long current_time = millis();

  if (current_time - last_interrupt_time > DEBOUNCE_DELAY)
  {
    press_count++;
    new_press = true;
    last_interrupt_time = current_time;
  }
}

void setup()
{
  Serial.begin(115200);
  Wire.begin();

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C))
  {
    Serial.println("CANNOT INITIALIZE OLED");
    while(1);
  }

  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.print("System Ready :)");
  display.display();

  pinMode(14, INPUT_PULLUP);
  pinMode(32, OUTPUT);
  digitalWrite(32, HIGH);

  attachInterrupt(14, button_isr, FALLING);
}

void loop()
{
  if(new_press == true)
  {
    display.clearDisplay();
    display.setCursor(0, (SCREEN_HEIGHT-8)/2);
    display.print("Button pressed : ");
    display.print(press_count);
    display.display();

    new_press = false;
  }
}