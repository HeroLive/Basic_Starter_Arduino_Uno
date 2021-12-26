/*
   EEPROM Write

   Stores values read from analog input 0 into the EEPROM.
   These values will stay in the EEPROM when the board is
   turned off and may be retrieved later by another sketch.
       Larger AVR processors have larger EEPROM sizes, E.g:
    - Arduno Duemilanove: 512b EEPROM storage.
    - Arduino Uno:        1kb EEPROM storage.
    - Arduino Mega:       4kb EEPROM storage.
*/

#include <EEPROM.h>

/** the current address in the EEPROM (i.e. which byte we're going to write to next) **/
int addr = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int storeVal = random(255);
  Serial.print("address: ");
  Serial.print(addr);
  Serial.print(" value: ");
  Serial.println(storeVal);

  EEPROM.write(addr, storeVal);

  addr = addr + 1;
  if (addr == 10) {
    printValue(addr);
    addr = 0;    
  }
  delay(1000);
}

void printValue(int n) {
  Serial.println("----Print stored value----");
  for (int i = 0; i < n; i++) {
    int storeVal = EEPROM.read(i);     
    Serial.print(i);
    Serial.print("\t");
    Serial.println(storeVal);
  }
}
