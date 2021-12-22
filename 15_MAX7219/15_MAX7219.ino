//We always have to include the library
#include "LedControl.h"

/*
  Now we need a LedControl to work with.
 ***** These pin numbers will probably not work with your hardware *****
  pin 12 is connected to the DataIn
  pin 11 is connected to the CLK
  pin 10 is connected to LOAD(CS)
  We have only a single MAX72XX.
*/
LedControl lc = LedControl(12, 11, 10, 1); // DIN, CLK, CS, NRDEV

/* image switching time */
unsigned long delaytime1 = 500;
unsigned long delaytime2 = 50;
void setup() {
  /*
    The MAX72XX is in power-saving mode on startup,
    we have to do a wakeup call
  */
  lc.shutdown(0, false);
  /* Set the brightness to a medium values */
  lc.setIntensity(0, 8);
  /* and clear the display */
  lc.clearDisplay(0);
}

/*
  This function will light up every Led on the matrix.
  The led will blink along with the row-number.
  row number 4 (index==3) will blink 4 times etc.
*/
void single() {
  for (int row = 0; row < 8; row++) {
    for (int col = 0; col < 8; col++) {
      delay(delaytime2);
      lc.setLed(0, row, col, true);
      delay(delaytime2);
      for (int i = 0; i < col; i++) {
        lc.setLed(0, row, col, false);
        delay(delaytime2);
        lc.setLed(0, row, col, true);
        delay(delaytime2);
      }
    }
  }
}

void writeHiOnMatrix() {
  byte h[8] = {B11111111, B00010000, B00010000, B00010000, B11100000, B00000000, B11110100, B00000000};
  lc.setRow(0, 0, h[0]);
  lc.setRow(0, 1, h[1]);
  lc.setRow(0, 2, h[2]);
  lc.setRow(0, 3, h[3]);
  lc.setRow(0, 4, h[4]);
  lc.setRow(0, 5, h[5]);
  lc.setRow(0, 6, h[6]);
}

void loop() {
  writeHiOnMatrix();
  delay(5000);
  lc.clearDisplay(0);
  single();
  delay(2000);
  lc.clearDisplay(0);
}
