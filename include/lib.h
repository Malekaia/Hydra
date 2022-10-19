#pragma once
#include <Arduino.h>

#ifndef LIB_H
  #define LIB_H

  String pad_end(String str, unsigned int length);
  String seconds_to_MS(int total);
#endif