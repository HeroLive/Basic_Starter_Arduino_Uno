// Run a A4998 Stepstick from an Arduino UNO.
int en = 8 ;
int dirPin = 3 ;
int stepPin = 2 ;

void setup()
{
  Serial.begin(9600);
  pinMode(en, OUTPUT); // Enable
  pinMode(stepPin, OUTPUT); // Step
  pinMode(dirPin, OUTPUT); // Dir
  digitalWrite(en, LOW); // Set Enable low
}

void loop() {
  digitalWrite(dirPin, HIGH);
  for (int i = 1 ; i <= 200 ; i = i + 1) {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(1000);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(1000);
  }
  delay(2000);
  
  digitalWrite(dirPin, LOW);
  for (int i = 1 ; i <= 200 ; i = i + 1) {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(1000);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(1000);
  }
  delay(1000);
}
