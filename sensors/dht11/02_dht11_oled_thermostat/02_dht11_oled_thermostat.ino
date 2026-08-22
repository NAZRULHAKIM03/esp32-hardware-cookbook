// OLED library
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// DHT library
#include <DHT.h>
#include <Adafruit_Sensor.h>

// LED define
#define LED 25

// OLED define
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

// DHT define
#define DHTPIN 4
#define DHTTYPE DHT11

// define threshold
#define TEMP_THRESHOLD 25.0

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
DHT dht(DHTPIN, DHTTYPE);

void setup()
{
  Serial.begin(115200);

  // LED
  pinMode(LED, OUTPUT);

  // I2C init
  Wire.begin();

  // OLED init
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C))
  {
    Serial.println("Failed to Initialize OLED");
    while(true);
  }

  display.setTextColor(SSD1306_WHITE);
  display.setTextSize(1);

  // DHT init
  dht.begin();
}

void loop()
{
  delay(2000);

  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  if (isnan(humidity) || isnan(temperature))
  {
    Serial.print("Error try to read dht11");
    return;
  }

  if (temperature > TEMP_THRESHOLD)
  {
    digitalWrite(LED, HIGH);
  }
  else
  {
    digitalWrite(LED, LOW);
  }

  display.clearDisplay();
  display.setCursor(0,0);
  display.print("Temperature : ");
  display.print(temperature);
  display.println("C");
  display.print("Humidity : ");
  display.print(humidity);
  display.print("%");
  display.display();
}