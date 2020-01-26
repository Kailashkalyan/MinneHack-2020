int in1 = 5;
int in2 = 12;
#include <ESP8266WiFi.h>
int resval = 0;  // holds the value
int respin = A0; // sensor pin use
boolean leak = false;

void setup() {
  Serial.begin(115200);
  pinMode(in1,OUTPUT);
  digitalWrite(in1,HIGH);
  pinMode(in2,OUTPUT);
 digitalWrite(in2,HIGH);
 pinMode(A0, INPUT);
  Serial.begin(115200);
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
  resval = analogRead(A0); //Read data from analog pin and store it to resval variable
 
  if (resval<=100)
  { Serial.println("Water Level: No Leak");
    leak = false;
  } 
  else{ 
    Serial.println("Water Level: Leak"); 
    leak = true;
  }
  delay(1000); 
}
