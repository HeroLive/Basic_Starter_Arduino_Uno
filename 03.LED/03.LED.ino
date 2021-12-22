// Project 1 - Fade LED by PWM
int ledPin = 3; //Chân điều khiển độ sáng LED, đây là pin PWM
int d = 20; //Biến thiết lập 1 bước thay đổi cường độ sáng.
void setup()
{
  pinMode(ledPin, OUTPUT);
}
void loop()
{
  for ( int a = 0 ; a < 256 ; a++ )
  {
    analogWrite(ledPin, a);
    delay(d);
  }
  delay(1000);
  for ( int a = 255 ; a >= 0 ; a-- )
  {
    analogWrite(ledPin, a);
    delay(d);
  }
  delay(1000);
}
