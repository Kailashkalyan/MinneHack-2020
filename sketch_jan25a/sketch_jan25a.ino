#include <dht.h>
#include <TimeLib.h>
#include <ESP8266WiFi.h>
#include <string>

dht DHT;
// Set these to run example.
#define SENSORPIN 4
#define LIGHTPIN 4
#define DHT11_PIN 5
int trigPin = 5;    // Trigger
int echoPin = 4;    // Echo
long duration, cm, inches;
void setup() {
  pinMode(0, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin (115200);
  //Define inputs and outputs
}
 
void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
 
  // Read the signal from the sensor: a HIGH pulse whose
  // duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
 
  // Convert the time into a distance
  cm = (duration/2) / 29.1;     // Divide by 29.1 or multiply by 0.0343
  inches = (duration/2) / 74;   // Divide by 74 or multiply by 0.0135
  
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
}
