
#include "Apio.h"
#include "property.h"
#include "DHT.h"
#define DHTTYPE DHT22
#define DHTPIN 0
DHT dht0(0, DHTTYPE);
unsigned long dht0pMillis = 0;
int dht0Flag = 0;
int pin20=20;
int pin21=21;
int pin0=0;
int pin9=9;
void setup() {
	Apio.setup("", "1,0", 1, 0x01);
	pinMode(pin20,OUTPUT);
	digitalWrite(pin20,LOW);
	pinMode(pin21,OUTPUT);
	digitalWrite(pin21,LOW);
	dht0.begin();
	pinMode(pin9,OUTPUT);
	digitalWrite(pin9,LOW);
}
int ping = 0;
unsigned long preMillis = 0;
void loop(){
	Apio.loop();
        if(millis()-preMillis>1000){
          Apio.send("11:update:b1:2|90/3|90/4|90/5|90/6|90/7|90/8|90/9|90/10|90/11|90/12|90/13|90/14|90/-");
          ping++;
          preMillis = millis();
        }
	
}
