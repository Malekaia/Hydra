#pragma once
#include <Arduino.h>

#ifndef DEBUG_H
  #define DEBUG_H

  extern const bool DEBUG;

  void SERIAL_DEBUG(String message = "");
  void setup_debug();
#endif