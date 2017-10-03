int brightness = 255;
int fadeAmount = 5;

void setup() {
  // put your setup code here, to run once:
  pinMode(3, OUTPUT); // Green 1.
  pinMode(9, OUTPUT); // Green 2.
  pinMode(5, OUTPUT); // Red 1.
  pinMode(6, OUTPUT); // Red 2.
}

void loop() {
  // put your main code here, to run repeatedly:

  // 0-15 sec.
  digitalWrite(3, HIGH);
  digitalWrite(6, HIGH);
  delay(10000);
  dim(3, brightness, fadeAmount); // Green 1.
  digitalWrite(3, LOW);
  digitalWrite(6, LOW);

  // 15-18 sec.
  digitalWrite(5, HIGH); // Red 1.
  digitalWrite(6, HIGH); // Red 2.
  delay(3000);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);

  // 18-33 sec.
  digitalWrite(5, HIGH); // Red 1.
  digitalWrite(9, HIGH); // Green 2.
  delay(10000);
  dim(9, brightness, fadeAmount);
  digitalWrite(5, LOW);
  digitalWrite(9, LOW);

  // 33-36 sec.
  digitalWrite(5, HIGH); // Red 1.
  digitalWrite(6, HIGH); // Red 2.
  delay(3000);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
}

void dim(int led, int brightness, int fadeAmount) {
  analogWrite(led, brightness);

  while(brightness != 0) {
    analogWrite(led, brightness);
    brightness = brightness - fadeAmount;
    delay(100);
  }
}
