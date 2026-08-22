#include <DHT.h>               // Handles the timing to talk to DHT11
#include <Adafruit_Sensor.h>   // Required by DHT library for standardized data

// Configuration
#define DHTPIN 4
#define DHTTYPE DHT11

// Create DHT object
DHT dht(DHTPIN, DHTTYPE);

void setup()
{
  Serial.begin(115200);
  Serial.println("DHT11 Sensor Test");

  // Initialize the sensor
  dht.begin();
}

void loop()
{
  // DHT11 is SLOW. can only take a reading once every ~2 seconds. if ask data too fast, will return garbage or NaN.
  delay(2000);

  // read the humidity (in %)
  float humidity = dht.readHumidity();

  // Read the temperature (in Celsius)
  float temperature = dht.readTemperature();

  // Check if any reads failed (sensor disconnected or read too fast)
  if (isnan(humidity) || isnan(temperature))
  {
    Serial.println("ERROR: Failed to read from DHT sensor!");
    return; // skip the rest of the loop and try again in 2 seconds
  }

  Serial.println("----------------------");
  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.print("%\n");
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print("°C\n\n");
}