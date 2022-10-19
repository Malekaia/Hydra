#include <Arduino.h>
#include "debug.h"

const bool DEBUG = true;

void SERIAL_DEBUG(String message = "") {
  if (DEBUG == true) {
    Serial.println(message);
  }
}

void setup_debug() {
  if(DEBUG == true) {
    Serial.begin(9600);
  }
}