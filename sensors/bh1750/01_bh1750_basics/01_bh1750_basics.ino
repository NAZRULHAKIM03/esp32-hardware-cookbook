// BH1750 Library
#include <BH1750.h>

// I2C Library
#include <Wire.h>

// BH1750 object
BH1750 lightmeter;

void setup()
{
  Serial.begin(115200);

  // I2C init
  Wire.begin();

  // BH1750 init
  if(!lightmeter.begin(BH1750::CONTINUOUS_HIGH_RES_MODE, 0x23, &Wire))
  {
    Serial.println("BH1750 Failed to Initialize!");
    while(true);
  }
}

void loop()
{
  // Read from BH1750
  float lux = lightmeter.readLightLevel();

  Serial.println("<--------------------->");
  Serial.print("LUX : ");
  Serial.println(lux);

  delay(1000);
}