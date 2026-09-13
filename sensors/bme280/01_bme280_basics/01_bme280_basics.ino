/*
WIRING (ESP32):
VCC  -> 3.3V
GND  -> GND
SCL  -> GPIO 22
SDA  -> GPIO 21
CSB  -> Leave unconnected (I2C mode)
SDO  -> GND (Sets I2C address to 0x76)

I2C Address
SDO to GND : 0x76
SDO to 3.3V : 0x77
*/

#include <Wire.h>

// BME280 library
#include <Adafruit_BME280.h>

// BME280 Object
Adafruit_BME280 bme;

void setup()
{
  Serial.begin(115200);

  Wire.begin();

  // BME280 Init
  if (!bme.begin(0x76, &Wire))
  {
    Serial.println("BME280 Initialization Fail");
    while(true);
  }

  Serial.println("SENSOR BME280 READY :)");
}

void loop()
{
  float temperature = bme.readTemperature();    // Celcius
  float humidity = bme.readHumidity();          // %
  float pressure = bme.readPressure() / 100.0F; // Convert Pa to hPa (hectopascals)

  // check for error
  if(isnan(temperature) || isnan(humidity) || isnan(pressure))
  {
    Serial.println("Fail to read from BME280");
    return;
  }

  // Print Result
  Serial.print("Temperature : ");
  Serial.print(temperature, 1);
  Serial.println("C");

  Serial.print("Humidity : ");
  Serial.print(humidity, 1);
  Serial.println("%");

  Serial.print("Pressure : ");
  Serial.print(pressure, 0);
  Serial.println("hPa\n");

  delay(2000);
}