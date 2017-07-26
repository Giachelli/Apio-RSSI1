
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
int addressNodo = 8;
int maxNode = 4;
void setup() {
  Apio.setup("nodo8", "1,0", addressNodo, 0x01);
  pinMode(pin20,OUTPUT);
  digitalWrite(pin20,LOW);
  pinMode(pin21,OUTPUT);
  digitalWrite(pin21,LOW);
  dht0.begin();
  pinMode(pin9,OUTPUT);
  digitalWrite(pin9,LOW);
}
int ping = 0;
unsigned long preMillis1 = 0;
unsigned long preMillis = 0;
int index = 1;
int value = 0;
void loop(){
  Apio.loop();
        if(millis()-preMillis>500){
          SYS_TaskHandler();
          Apio.sendTo = String(index);
          Apio.mex = "1:ping:"+String(value)+"-";
          Apio.send();
          Serial.println(index);
          /*Apio.send("11:update:b1:2|90/3|90/4|90/5|90/6|90/7|90/8|90/9|90/10|90/11|90/12|90/13|90/14|90/-");
          ping++;*/
          preMillis = millis();
          index++;
          if(index>maxNode){
            index=1;
          }
          if(value==0){
            value=1;
          } else {
            value = 0;
          }
        }
        if(millis()-preMillis1>5000){
          Apio.send("19:update:Porte:"+String(Apio.rssi[1])+"0"+String(Apio.rssi[2])+"0"+String(Apio.rssi[3])+"0"+String(Apio.rssi[4])+"-");
          ping++;  
          preMillis1 = millis();
          Serial.println("ping"); 
          Serial.println(ping);
        }
  
}
