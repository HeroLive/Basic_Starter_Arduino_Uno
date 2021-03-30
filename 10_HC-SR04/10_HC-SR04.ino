#include <Ultrasonic.h>

/*
   Pass as a parameter the trigger and echo pin, respectively,
*/
int trigPin = 3;
int echoPin = 2;
Ultrasonic ultrasonic(trigPin, echoPin);
int distance;

void setup() {
  Serial.begin(9600);
}

void loop() {
  // Pass INC as a parameter to get the distance in inches
  distance = ultrasonic.read();

  Serial.print("Distance in CM: ");
  Serial.println(distance);
  delay(1000);
}
