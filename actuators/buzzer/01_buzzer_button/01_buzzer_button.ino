#define BUZZER 18
#define BUTTON 25

void setup()
{
  Serial.begin(115200);

  pinMode(BUTTON, INPUT_PULLUP);
  pinMode(BUZZER, OUTPUT);
  digitalWrite(BUZZER, LOW);
}

void loop()
{
  if(digitalRead(BUTTON) == LOW)
  {
    digitalWrite(BUZZER, HIGH);
    delay(200);                   // 500ms beep
    digitalWrite(BUZZER, LOW);
  }
}