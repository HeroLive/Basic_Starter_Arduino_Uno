// Run a A4998 Stepstick from an Arduino UNO.
int x = 0;
int n = 0;
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
  Serial.print("Quay bao nhieu vong?: ");
  while (Serial.available() == 0) {
  }
  n = Serial.parseInt();
  Serial.println(n);
  x = n * 200;
  digitalWrite(dirPin, LOW);
  for (int i = 1 ; i <= x ; i = i + 1) {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(1000);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(1000);
  }
  delay(2000);
}
