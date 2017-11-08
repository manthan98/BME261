Servo servo;
const int tempSensor = 3;
const int plusBtnPin = 4;
const int minusBtnPin = 7;
const int servoPin = 9;
int userTemp = 20; // Temperature that user can control, arbitrary start point.
bool closed = false; // Vent closed by the servo.

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  servo.attach(servoPin);
  pinMode(plusBtnPin, INPUT);
  pinMode(minusBtnPin, INPUT);
}

void loop() {
  plusBtnState = digitalRead(plusBtnPin);
  minusBtnState = digitalRead(minusBtnPin);

  // Get the voltage reading from sensor.
  int temp = analogRead(tempSensor);

  // Convert to voltage
  float voltage = temp * 5.0;
  voltage /= 1024.0;

  // Temperature conversion
  float tempC = (voltage - 0.5) * 100;

  if(plusBtnState == HIGH)
  {
    userTemp += 1;
    if(userTemp >= 20)
    {
      servo.write(0); // Close.
    }
  }

  if(minusBtnState == HIGH)
  {
    userTemp -= 1;
    if(userTemp < 20)
    {
      servo.write(180); // Open.
    }
  }

  if(userTemp >= tempC)
  {
    if(!closed)
    {
      servo.write(180); // Open.
      closed = true;
    }
  } else if(userBtn < tempC)
  {
    if(!closed)
    {
      servo.write(180); // Close.
      closed = true;
    }
  }

  delay(2000); // 2 sec.
}
