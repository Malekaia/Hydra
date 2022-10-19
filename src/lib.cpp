#include <Arduino.h>
#include "lib.h"

// pad a string with another string (multiple times, if needed)
// until the resulting string reaches the given length
String pad_end(String str, unsigned int length) {
  while(str.length() < length) {
    str += " ";
  }
  return str;
}

// convert a seconds integer to a time string (MM:SS)
String seconds_to_MS(int total) {
  if (total < 60) {
    String prefix = String(total < 10 ? "0" : "");
    return "00:" + prefix + String(total);
  }
  int remainder = total % 60;
  int minutes = (total - remainder) / 60;
  String minutes_out = (minutes < 10) ? "0" + String(minutes) : String(minutes);
  String seconds_out = (remainder < 10) ? "0" + String(remainder) : String(remainder);
  return minutes_out + ":" + seconds_out;
}