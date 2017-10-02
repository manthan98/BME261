void setup() {
  // put your setup code here, to run once:

  // Initialize digital pin 13 as an output.
  pinMode(13, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite(13, HIGH); // Turn the LED on (HIGH is the voltage level)
  delay(1000); // Wait for a second.
  digitalWrite(13, LOW); // Turn the LED off by making the voltage LOW.
  delay(1000); // Wait for a second.
}
