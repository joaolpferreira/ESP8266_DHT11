#include "DHT.h"
 
#define DHT11PIN D2       // define the digital I/O pin

 
#define DHT11TYPE DHT11         // DHT 11 


DHT dht11(DHT11PIN, DHT11TYPE);

 
void setup() {
  Serial.begin(9600);    
  dht11.begin();
}
 
void loop() {
  // Read all temperature and humidity sensor data
  float h11 = dht11.readHumidity();
  float t11 = dht11.readTemperature();
 
  // check if returns are valid and print the sensor data
  if (isnan(t11) || isnan(h11)) {
    Serial.println("Failed to read from DHT 11");
  } else {
    Serial.print("Humidity 11: "); 
    Serial.print(h11);
    Serial.print(" %\t");
    Serial.print("Temperature 11: "); 
    Serial.print(t11);
    Serial.println(" *C");
  }

  
  
  Serial.println();   // print a free line to make the output nicer
  delay(1000);       // print new values every 1 seconds
}
