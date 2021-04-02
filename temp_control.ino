#include "DHT.h"                
#define DHTPIN 6
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);


// PINs
#define PIN_BLAU 3

#define UPDATE_ZYKLUS 1000
#define INTERRUPT_GELB 0


// Variablen
char eingabe;
int dauer_low = 1;
int dauer_high = 9;
int baseTime = 10; // Insgesamt 10 ms
int temp;

int counter_rpm = 0;
int rpm = 0;
unsigned long letzte_ausgabe = 0;

 
void setup()
{
  Serial.begin(9600);
  pinMode(PIN_BLAU, OUTPUT);
  attachInterrupt(INTERRUPT_GELB, rpm_fan, FALLING);
  dht.begin();
}
 
void loop(){
  temp = dht.readTemperature();
  if (temp < 30){
    dauer_low = 10;
    dauer_high = 0;
  }
  if (temp > 30 and temp < 32){
    dauer_low = 9;
    dauer_high = 1;
  }
  if (temp > 32 and temp < 34){
    dauer_low = 8;
    dauer_high = 2;
  }
  if (temp > 34 and temp < 36){
    dauer_low = 7;
    dauer_high = 3;
  }
  if (temp > 36 and temp < 38){
    dauer_low = 6;
    dauer_high = 4;
  }
  if (temp > 38 and temp < 40){
    dauer_low = 5;
    dauer_high = 5;
  }
  if (temp > 40 and temp < 42){
    dauer_low = 4;
    dauer_high = 6;
  }
  if (temp > 42 and temp < 44){
    dauer_low = 3;
    dauer_high = 7;
  }
  if (temp > 44 and temp < 46){
    dauer_low = 2;
    dauer_high = 8;
  }
  if (temp > 46 and temp < 60){
    dauer_low = 1;
    dauer_high = 9;
  }

  

  if(dauer_low * 10 != 0){
    digitalWrite(PIN_BLAU, LOW);
    delayMicroseconds(dauer_low * 10);
  }
 
  if(dauer_high * 10 != 0){
    digitalWrite(PIN_BLAU, HIGH);
    delayMicroseconds(dauer_high * 10);
  }

  if (millis() - letzte_ausgabe >= UPDATE_ZYKLUS){
    detachInterrupt(0);
    attachInterrupt(0, rpm_fan, FALLING);
  }
}

void rpm_fan(){
  counter_rpm++;
}
