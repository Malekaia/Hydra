#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal.h>
#include "debug.h"
#include "lcd.h"
#include "lib.h"

// setup and configure the LCD display
const int rs = 7, en = 6, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// DEBUG: set pump enabled and disabled time to 5 seconds
const int PUMP_ENABLED_SECONDS = 5; /* 45 */
const int PUMP_DISABLED_SECONDS = 5; /* 15*60 */

// write a 16 character padded string to the lcd
void lcd_write(String row_1, String row_2) {
  // write the second line of the lcd
  lcd.setCursor(0, 0);
  String r1 = pad_end(row_1, 16);
  lcd.print(r1);
  SERIAL_DEBUG(r1);
  // write the first line of the lcd
  lcd.setCursor(0, 1);
  String r2 = pad_end(row_2, 16);
  lcd.print(r2);
  SERIAL_DEBUG(r2);
}

// 1. time pump delay
// 2. write delay status and time elapsed / remaining to the lcd
void lcd_pumps_disabled() {
  int current_delay = 0;
  while (current_delay < PUMP_ENABLED_SECONDS) {
    current_delay++;
    lcd_write("Enabled: None", seconds_to_MS(current_delay) + " | " + seconds_to_MS(PUMP_ENABLED_SECONDS));
    delay(1000);
  }
}

// 1. time pump activity
// 2. write active status and time elapsed / remaining to the lcd
void lcd_pump_enabled(int pump_number) {
  int current_active = 0;
  while (current_active < PUMP_DISABLED_SECONDS) {
    current_active++;
    lcd_write("Enabled: " + String(pump_number), seconds_to_MS(current_active) + " | " + seconds_to_MS(PUMP_DISABLED_SECONDS));
    delay(1000);
  }
}

// SETUP: lcd
// 1. clear the screen
void setup_lcd() {
  lcd.begin(16, 2);
  lcd_write("-", "-");
}