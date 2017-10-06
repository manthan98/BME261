byte byteRead;
int brightness = 255;
int fadeAmount = 25;

void setup() {
  // put your setup code here, to run once:

  // Turn the serial protocol ON
  Serial.begin(9600);

  pinMode(9, OUTPUT); // LED.
  
  Serial.println("\n\nString replace:\n");
}

void loop() {
  // put your main code here, to run repeatedly:

  if(Serial.available())
  {
    byteRead = Serial.read();

    if(byteRead == 'e')
    {
      byteRead = '*';
    }

    if(byteRead == '+')
    {
      if((brightness + fadeAmount) > 255)
      {
        brightness = 255;
      } else
      {
        brightness = brightness + fadeAmount;
      }
      analogWrite(9, brightness);
    }

    if(byteRead == '-')
    {
      if((brightness - fadeAmount) < 0)
      {
        brightness = 0;
      } else
      {
        brightness = brightness - fadeAmount;
      }
      analogWrite(9, brightness);
    }

    Serial.write(byteRead);
  }
}

void dim(int led, int brightness, int fadeAmount) {
  analogWrite(led, brightness);

  while(brightness != 0) {
    analogWrite(led, brightness);
    brightness = brightness - fadeAmount;
    delay(100);
  }
}
