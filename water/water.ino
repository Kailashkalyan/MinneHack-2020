#include <ESP8266WiFi.h>
int resval = 0;  // holds the value
int respin = A0; // sensor pin use
boolean leak = false;
void setup(){
  pinMode(A0, INPUT);
  Serial.begin(115200);
} 
  
void loop() { 
   
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
