#include "DHT.h"
 
#define DHT11PIN D3       // define the digital I/O pin

 
#define DHT11TYPE DHT11         // DHT 11 
#define BUTTON_PIN D7
#define led0 D0

DHT dht11(DHT11PIN, DHT11TYPE);

float t_def=30; 
void setup() {
  Serial.begin(9600);    
  dht11.begin();
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(led0, OUTPUT);
  t_def=dht11.readTemperature();
  
}

int state=0;
int lastState = HIGH;
float t=0;

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
    t=t11;
  }

  //Ligar e Desligar sistema
  int value = digitalRead((BUTTON_PIN));
  if (lastState != value) {
    lastState = value;
    if (value == LOW) {
      Serial.println(" pressed");
      if(state==1) {state=0; digitalWrite(led0, LOW);}
      else if(state==0) state=1;
    }
  }
//Ligar e Desligar aquecedor 
  if(state==1 && t>t_def+0.1) digitalWrite(led0, LOW);
  else if(state==1 && t<t_def-0.1) digitalWrite(led0, HIGH);
  
  Serial.println("Estado:" + String(state));
  Serial.println("T inicial:" + String(t_def));
  
  Serial.println();   // print a free line to make the output nicer
  delay(1000);       // print new values every 1 seconds
}
