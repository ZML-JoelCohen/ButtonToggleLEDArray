#include "Arduino.h"
#include <stdint.h>


class Button {
  public:
    Button(uint8_t input, uint8_t gnd = 0, uint8_t pwr = 0) {
      input = input;
      gnd = gnd;
      pwr = pwr;
    }

    void init() {
      pinMode(input, INPUT);

      if (gnd) {
        pinMode(gnd, OUTPUT);
        digitalWrite(gnd, LOW);
      }

      if (pwr) {
        pinMode(pwr, OUTPUT);
        digitalWrite(pwr, HIGH);
      }

    }


  private:
    uint8_t input; 
    uint8_t gnd; 
    uint8_t pwr;
};
