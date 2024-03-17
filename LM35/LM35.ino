const int temperaturePin = A0;                        // Analog pin for LM35 temperature sensor
const int ledPin = 13;                                // Digital pin for onboard LED

unsigned long previousMillis = 0;
const long intervalLowTemp = 250;                     // Blink interval for temperature below 30 degrees Celsius
const long intervalHighTemp = 500;                    // Blink interval for temperature above 30 degrees Celsius

void setup() 
{
  pinMode(temperaturePin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() 
{
  int temperature = readTemperature();
  
  if (temperature < 30) {
    blinkLED(intervalLowTemp);
  } else {
    blinkLED(intervalHighTemp);
  }
}

int readTemperature() 
{
  // Read analog input and convert to temperature in Celsius
  int sensorValue = analogRead(temperaturePin);
  float temperature = (sensorValue / 1023.0) * 500;     // 10 mV per degree with LM35, 0°C is 0.0 mV
  
  return temperature;
}

void blinkLED(long interval) 
{
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    digitalWrite(ledPin, !digitalRead(ledPin));         // Toggle LED state
  }
}
