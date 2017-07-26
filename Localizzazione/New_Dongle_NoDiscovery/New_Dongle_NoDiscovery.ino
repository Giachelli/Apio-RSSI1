#include <SPI.h>
#include <Wire.h>
#include "Adafruit_GFX.h"
#include "Adafruit_SSD1306.h"

#include <avr/wdt.h>
////// start oled display
/////RT for baudrate

////// end baudrate


#define OLED_RESET 6
Adafruit_SSD1306 display2(OLED_RESET);

#define NUMFLAKES 10
#define XPOS 0
#define YPOS 1
#define DELTAY 2

////// end of oled 


#include "Apio.h"
#include "property.h"
int RX=9;
int TX=10;

int RF = 15;
int T = 13;
int E = 14;
int S = 12;
int Tf = 11;
void setup() {
  wdt_disable();
  
pinMode(RX,OUTPUT);
pinMode(TX,OUTPUT);
pinMode(RF,OUTPUT);
pinMode(T,OUTPUT);
pinMode(E,OUTPUT);
pinMode(S,OUTPUT);
pinMode(Tf,OUTPUT);
/*
  display2.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3C (for the 128x32)
  display2.clearDisplay();
  display2.display();
  display2.setTextSize(0);
  display2.setTextColor(WHITE);
  display2.setCursor(27,0);
  display2.println("APIO srl");
  display2.setCursor(0,9);
  display2.println("Coordinatore V.1");
  display2.display();
  delay(500);
  display2.clearDisplay();
  display2.display();
  display2.setCursor(0,0);
  */
Apio.setup("Miiiio", "1,0", 0, 0x01);
wdt_enable(WDTO_4S);

//UBRR0H  = 0;
//UBRR0L  = 0;
	
}
int flagP = 0;
unsigned long previousM = 0;
unsigned long previousM1 = 0;
int t = 0;
void loop(){
  Apio.loop();
  wdt_reset();	
  digitalWrite(RX,LOW);
  digitalWrite(TX,LOW);

  if(millis()-previousM>150){
    
    digitalWrite(RX,LOW);
    digitalWrite(TX,LOW);
    
    previousM = millis();
    }

    if(millis()-previousM1>800){

    digitalWrite(RF,LOW);
    digitalWrite(T,LOW);
    digitalWrite(E,LOW);
    digitalWrite(S,LOW);
    digitalWrite(Tf,LOW);
    
    previousM1 = millis();
    }
}
