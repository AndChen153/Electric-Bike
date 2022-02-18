#include <TM1637Display.h>

#define CLK 4
#define DIO 5

TM1637Display display = TM1637Display(CLK, DIO);

const uint8_t OFF[] = {
  SEG_A | SEG_B | SEG_C | SEG_D | SEG_E | SEG_F,   // O
  SEG_A | SEG_E | SEG_F | SEG_G,                   // F
  SEG_A | SEG_E | SEG_F | SEG_G                   // F
};

const uint8_t ON[] = {
  SEG_A | SEG_B | SEG_C | SEG_D | SEG_E | SEG_F,   // O
  SEG_A | SEG_B | SEG_C | SEG_E | SEG_F   // N
};


void setup() {
  display.clear();
  delay(30);
  display.setBrightness(7);
}

void loop(){
  display.setSegments(OFF, 3, 0);
  display.showNumberDec(1, false, 1, 3);
  delay(1000);
  display.clear();
  display.setSegments(ON, 2, 0);
  display.showNumberDec(2, false, 1, 3);
  delay(1000);
  display.clear();

}