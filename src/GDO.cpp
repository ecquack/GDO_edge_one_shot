// ESP32 GDO
//
/*
This program implements an edge triggered monostable multivibrator.

When the input pin changes state, the output pin is brough high for 100 milliseconds.

The input is wired to the dry contact closure of a relay on a 433mhz RF/Tuya switch board.
The output is wired to the garage door opener switch.

*/



#include <Arduino.h>

#define EDGE_PIN  14  // input from Tuya RF relay board
#define RELAY_PIN 15  // output to Feather relay board
#define PUSH_TIME 100 // milliseconds


void setup() {
  Serial.begin(115200);

  Serial.println("GDO Online");
  pinMode(EDGE_PIN,INPUT);
  pinMode(RELAY_PIN,OUTPUT);
  digitalWrite(RELAY_PIN,0);
}

int history=0;

void loop(void) {

  int present;
  present=digitalRead(EDGE_PIN);

  delay(100);
  if(history!=present) {
    history=present;
    digitalWrite(RELAY_PIN,1);
    delay(PUSH_TIME);
    digitalWrite(RELAY_PIN,0);
    Serial.println("EDGE Triggered");
  }
}
