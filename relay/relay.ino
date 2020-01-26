int in1 = 5;
int in2 = 12;
void setup() {
  Serial.begin(115200);
  pinMode(in1,OUTPUT);
  digitalWrite(in1,HIGH);
  pinMode(in2,OUTPUT);
 digitalWrite(in2,HIGH);
}

 void turnOn() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
}

void turnOff() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  turnOn();
  delay(500);
  turnOff();
  delay(500);
}
