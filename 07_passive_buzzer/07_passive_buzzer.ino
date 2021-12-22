#include "pitches.h"
int buzzer = 12;
// notes in the melody:
int melody[] = {
  NOTE_C5, NOTE_D5, NOTE_E5, NOTE_F5, NOTE_G5, NOTE_A5, NOTE_B5, NOTE_C6};
int duration = 500;  // 500 miliseconds
 
void setup() {
 
}
 
void loop() {  
  for (int thisNote = 0; thisNote < 8; thisNote++) {
    // output the voice, every scale is 0.5 sencond
    tone(buzzer, melody[thisNote], duration);
     
    // Output the voice after several minutes
    delay(1000);
  }
   
  // restart after two seconds 
  delay(2000);
}
