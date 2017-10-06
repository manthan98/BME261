#include <Wire.h>

int mpu = 0x68;
int16_t AcX, AcY, AcZ, Tmp, GyX, GyY, GyZ;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  
  Wire.begin();
  Wire.beginTransmission(mpu);
  Wire.write(0x6B);
  Wire.write(0);
  Wire.endTransmission(true);
}

void loop() {
  // put your main code here, to run repeatedly:

  Wire.beginTransmission(mpu);
  Wire.write(0x3B);
  Wire.endTransmission(false);
  Wire.requestFrom(mpu,14,true);
  AcX = Wire.read()<<8|Wire.read();
  AcY = Wire.read()<<8|Wire.read();
  AcZ = Wire.read()<<8|Wire.read();
  Tmp = Wire.read()<<8|Wire.read();
  GyX = Wire.read()<<8|Wire.read();
  GyY = Wire.read()<<8|Wire.read();
  GyZ = Wire.read()<<8|Wire.read();

  Serial.println(AcX);
  Serial.println(AcY);
  Serial.println(AcZ);
  Serial.println(Tmp);
  Serial.println(GyX);
  Serial.println(GyY);
  Serial.println(GyZ);
  
  
  delay(33);
  
}
