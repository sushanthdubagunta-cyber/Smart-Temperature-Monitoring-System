// Smart Temperature Monitoring System
// Arduino UNO + TMP36 Sensor + LED + Buzzer

int tempPin = A0;
int ledPin = 13;
int buzzerPin = 8;

float threshold = 30.0;

void setup()
{
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop()
{
  int sensorValue = analogRead(tempPin);

  float voltage = sensorValue * (5.0 / 1023.0);
  float temperature = (voltage - 0.5) * 100;

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" C");

  if (temperature > threshold)
  {
    digitalWrite(ledPin, HIGH);
    tone(buzzerPin, 1000);
  }
  else
  {
    digitalWrite(ledPin, LOW);
    noTone(buzzerPin);
  }

  delay(1000);
}
