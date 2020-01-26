#define WIFI_SSID "MHFallback"
#define WIFI_PASSWORD "bruhsoundeffect#2"
#define FIREBASE_HOST "cleanse-c7568.firebaseio.com"
#define FIREBASE_AUTH "yv9o02h6RBiXMPnrpZwdyZdKSfzENSph4MMgp5IH"
int in1 = 5;
int in2 = 12;
#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>
int resval = 0;  // holds the value
int respin = A0; // sensor pin use
boolean leak = false;

void setup() {
  Serial.begin(115200);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
  
  pinMode(in1,OUTPUT);
  digitalWrite(in1,HIGH);
  pinMode(in2,OUTPUT);
 digitalWrite(in2,HIGH);
 pinMode(A0, INPUT);
 Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}

 void turnOn() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
}

void turnOff() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
}
void interMed(){
  digitalWrite(in1, HIGH);
  digitalWrite(in2, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  resval = analogRead(A0); //Read data from analog pin and store it to resval variable
  Firebase.setBool("super/infantderrick/devices/leak", resval>100);
//  if( resval>100){
//    Serial.print("T");
//  }else{
//    Serial.print("F");
//  }
  float maxTemp = Firebase.getFloat("super/infantderrick/devices/maxTemp");
  float minTemp = Firebase.getFloat("super/infantderrick/devices/minTemp");
  float temp = Firebase.getFloat("super/infantderrick/devices/temp");
  if(maxTemp < temp){
    turnOff();
  }else if(temp < minTemp){
    turnOn();
  }else{
    interMed();
  }
  delay(50);

}
