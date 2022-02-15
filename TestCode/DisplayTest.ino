#include <TM1637.h>

int CLK = 4;
int DIO = 5;

TM1637 tm(CLK,DIO);

void setup() {
  tm.init();
  // set brightness; 0-7
  tm.set(7);
}

void loop(){
    tm.display(0,1);
    tm.display(1,1);
    tm.display(2,1);
    tm.display(3,1);
}