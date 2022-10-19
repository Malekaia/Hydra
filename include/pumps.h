#pragma once
#include <Arduino.h>

#ifndef PUMPS_H
  #define PUMPS_H

  extern int RELAY_LED_PINS[];
  extern const int RELAY_LED_PINS_LENGTH;

  void pumps_disable_all();
  void pump_enable(int pin_relay, int pin_indicator_led);
  void setup_pumps();
#endif