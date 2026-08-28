#include <Wire.h>               //I2C communication library
#include <Adafruit_GFX.h>       // Graphics library (drawing functions)
#include <Adafruit_SSD1306.h>   // SSD1306 driver library

// Define OLED display dimensions
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

// Create an OLED object
// Parameters : width, height, I2C address,reset pin (not used)
Adafruit_SSD1306 display (SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup()
{
  Serial.begin(115200);

  // Initialize I2C (default SDA=21, SCL=22)
  Wire.begin();

  //Initialize the display
  // SSD1306_SWITCHCAPVCC = use internal voltage regulator
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C))
  {
    Serial.println("OLED initialization failed!");
    while(true); // Stop here if display not found
  }

  // Clear the display buffer
  display.clearDisplay();

  // Set text color to white (pixels ON)
  display.setTextColor(SSD1306_WHITE);

  // set text size (1 = tiny, 2 = bigger, etc.)
  display.setTextSize(1);

  // set cursor position (x, y) in pixels
  display.setCursor(0, 0);

  // Print text to the display buffer
  display.println("Hello, ESP32!");
  display.println("OLED Works!");

  // Send buffer to the display (actually show it)
  display.display();
}

void loop()
{
  // nothing yet
}