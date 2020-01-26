#include <dht11.h>
#define DHT11PIN 2
dht11 DHT11;

void setup(){
  Serial.begin(115200);
}

void loop()
{
  int chk = DHT11.read(DHT11PIN);
  Serial.print("Temperature = ");
  Serial.println((DHT11.temperature * 1.8) + 27);
  Serial.print("Humidity = ");
  Serial.println(DHT11.humidity);
  delay(1000);
}
