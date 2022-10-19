#include <Arduino.h>
#include "debug.h"
#include "pumps.h"

int RELAY_LED_PINS[] = {
  // relay in and indicator led for pump 2
  8, 10,
  // relay in and indicator led for pump 2
  9, 11
};

const int RELAY_LED_PINS_LENGTH = (sizeof(RELAY_LED_PINS) / sizeof(*RELAY_LED_PINS));
// ensure the "RELAY_LED_PINS" always contains an even number for each pair
// of pump relay in(s) and their led indicator lights
static_assert(RELAY_LED_PINS_LENGTH % 2 == 0, "\"RELAY_LED_PINS_LENGTH\" must contain pairs of \"relay\" and \"led indicator\" pins.");

// disable all pump relay in(s) and their led indicator lights
void pumps_disable_all() {
  SERIAL_DEBUG();
  for (size_t i = 0; i < RELAY_LED_PINS_LENGTH; i++) {
    // turn off the current pin
    digitalWrite(RELAY_LED_PINS[i], LOW);
    SERIAL_DEBUG("Turn off pin: " + String(RELAY_LED_PINS[i]));
  }
  SERIAL_DEBUG();
}

// enable a pump's relay in and it's led indicator light
void pump_enable(int pin_relay, int pin_indicator_led) {
  // turn on the relay pin
  SERIAL_DEBUG();
  digitalWrite(pin_relay, HIGH);
  SERIAL_DEBUG("Turn on pin: " + String(pin_relay));
  // turn on the indicator pin
  digitalWrite(pin_indicator_led, HIGH);
  SERIAL_DEBUG("Turn on pin: " + String(pin_indicator_led));
  SERIAL_DEBUG();
}

// SETUP: pumps
// 1. iterate pins for relay in(s) and led indicators
//   2. set those pin modes output
//   3. turn off those pins
void setup_pumps() {
  SERIAL_DEBUG();
  for (size_t i = 0; i < RELAY_LED_PINS_LENGTH; i++) {
    // set the current pin to output
    pinMode(RELAY_LED_PINS[i], OUTPUT);
    SERIAL_DEBUG("Set mode: " + String(RELAY_LED_PINS[i]) + ", output");
    // turn off the current pin
    digitalWrite(RELAY_LED_PINS[i], LOW);
    SERIAL_DEBUG("Turn off pin: " + String(RELAY_LED_PINS[i]));
  }
  SERIAL_DEBUG();
}