int tempPin=A0;
int motPin=9;
void setup(){
  pinMode(motPin,OUTPUT);
  Serial.begin(9600);
}
void loop(){
  int tempReading=analogRead(tempPin);
  float voltage=tempReading*(5.0/1023);
  float temperature=(voltage-0.5)*100;
  Serial.print("Temp:");
  Serial.print(temperature);
  Serial.println("C");
  int motorSpeed=map(temperature,0,50,0,255);
  motorSpeed=constrain(motorSpeed,0,255);
  analogWrite(motPin,OUTPUT);
  delay(500);
}