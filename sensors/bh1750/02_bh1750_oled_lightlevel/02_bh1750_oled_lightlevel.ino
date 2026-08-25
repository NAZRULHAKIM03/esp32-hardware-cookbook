// BH1750 Library
#include <BH1750.h>

// I2C Library
#include <Wire.h>

// OLED Library
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// OLED definition
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

// LED definition
#define LED_PIN 25

// BH1750 object
BH1750 lightmeter;

// OLED Object
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup()
{
  Serial.begin(115200);

  pinMode(LED_PIN, OUTPUT);

  // I2C init
  Wire.begin();

  // OLED Init
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C))
  {
    Serial.println("OLED Init Fail!");
    while(true);
  }

  display.setTextColor(SSD1306_WHITE);
  display.setTextSize(1);
  display.clearDisplay();
  display.setCursor(0, 0);
  display.println("BH1750 TEST");
  display.display();
  delay(2000);

  // BH1750 Init
  if(!lightmeter.begin(BH1750::CONTINUOUS_HIGH_RES_MODE, 0x23, &Wire))
  {
    display.clearDisplay();
    display.println("BH1750 Init Fail!");
    display.display();
    while(true);
  }
}

void loop()
{
  // Read from BH1750
  float lux = lightmeter.readLightLevel();

  display.clearDisplay();
  display.setCursor(0,0);
  display.println("--------------");
  display.print("LUX : ");
  display.println(lux);
  display.println("--------------\n");

  if(lux >= 300)
  {
    display.println(">> Bright\n");
  }
  else if(lux > 50)
  {
    display.println(">> Medium\n");
  }
  else
  {
    display.println(">> Dark\n");
  }

  // LED ON/OFF LOGIC
  if(lux < 300)
  {
    digitalWrite(LED_PIN, HIGH);
    display.println("LED : ON");
  }
  else
  {
    digitalWrite(LED_PIN, LOW);
    display.println("LED : OFF");
  }

  display.display();

  delay(1000);
}