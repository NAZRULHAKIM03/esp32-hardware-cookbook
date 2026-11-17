// Touch Sensor Module
// Operating voltage : 2.0 ~ 5.5V (Note : ESP32 GPIO are not 5V tolerant (3.3V max))
// Output : Active High

#include <Arduino.h>    // Arduino Lib
#include <inttypes.h>   // Data types Lib

#define TOUCH 23        // define Touch Sensor pin
#define LED 32          // define Led pin

void setup(){

  Serial.begin(115200); // Set Baud Rate

  pinMode(TOUCH, INPUT);  // Set Touch Sensor as INPUT
  pinMode(LED, OUTPUT);   // Set Led as OUTPUT
}

void loop(){

  uint8_t touch = digitalRead(TOUCH);   // Store output from touch sensor

  if (touch == HIGH)    // Sensor output HIGH when touched
  {
    digitalWrite(LED, HIGH);  // Led ON when sensor touched
  }
  else
  {
    digitalWrite(LED, LOW);     // Led OFF when sensor not touched
  }
}