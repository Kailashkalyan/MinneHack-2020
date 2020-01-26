#include <dht11.h>
#define DHT11PIN 2

dht11 DHT11;

void setup()
{
  Serial.begin(115200);
 
}

void loop()
{
  Serial.println();

  int chk = DHT11.read(DHT11PIN);

  Serial.print("Humidity (%): ");
  Serial.println((float)DHT11.humidity, 2);

  Serial.print("Temperature (F): ");
  Serial.println((((float)DHT11.temperature)*(9/5)+32), 2);

  delay(2000);

}
