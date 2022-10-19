#include <Arduino.h>
#include "debug.h"
#include "lcd.h"
#include "pumps.h"

void setup() {
  setup_debug();
  setup_pumps();
  setup_lcd();
}

void loop() {
  // start the pump cycle loop
  int current_pump = 0;
  for (size_t i = 0; i < (unsigned)RELAY_LED_PINS_LENGTH; i +=  2) {
    // note wich pump is currently active
    current_pump = (i == 0) ? 1 : current_pump + 1;
    // disable all other pumps
    pumps_disable_all();
    lcd_pumps_disabled();
    // enable the pumps
    pump_enable(RELAY_LED_PINS[i], RELAY_LED_PINS[i + 1]);
    lcd_pump_enabled(current_pump);
  }
}