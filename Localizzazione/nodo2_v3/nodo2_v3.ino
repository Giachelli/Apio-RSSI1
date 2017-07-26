
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
int addressNodo = 2;
int maxNode = 10;
void setup() {
  Apio.setup("Porta2", "1,0", addressNodo, 0x01);
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
int index = 5;
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
            index=5;
          }
          if(value==0){
            value=1;
          } else {
            value = 0;
          }
        }
        if(millis()-preMillis1>3000){
          Apio.send("13:update:Persone:"+String(Apio.rssi[5])+"0"+String(Apio.rssi[6])+"0"+String(Apio.rssi[7])+"0"+String(Apio.rssi[8])+"0"+String(Apio.rssi[9])+"0"+String(Apio.rssi[10])+"-");
          ping++;
          preMillis1 = millis();
        }
  
}
