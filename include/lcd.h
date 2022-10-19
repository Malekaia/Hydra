#pragma once
#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal.h>

#ifndef LCD_H
  #define LCD_H

  extern const int rs, en, d4, d5, d6, d7;
  extern LiquidCrystal lcd;

  extern const int PUMP_ENABLED_SECONDS;
  extern const int PUMP_DISABLED_SECONDS;

  void setup_lcd();
  void lcd_write(String row_1, String row_2);
  void lcd_pumps_disabled();
  void lcd_pump_enabled(int pump_number);
#endif