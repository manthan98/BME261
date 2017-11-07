Servo servo;
int tempSensor = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  servo.attach(9);
}

void loop() {
  // put your main code here, to run repeatedly:

  // Get the voltage reading from sensor.
  int temp = analogRead(tempSensor);

  // Convert to voltage
  float voltage = temp * 5.0;
  voltage /= 1024.0;

  // Temperature conversion
  float tempC = (voltage - 0.5) * 100;

  if(tempC >= 20)
  {
    // Close.
    servo.write(0);
  } else 
  {
    // Open.
    servo.write(180);
  }

  delay(2000); // 2 sec.
}
