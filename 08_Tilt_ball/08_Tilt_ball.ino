const int ledPin = 13;//the led attach to
const int tiltBallPin = 2;

void setup()
{ 
  pinMode(ledPin,OUTPUT);//initialize the ledPin as an output
  pinMode(tiltBallPin,INPUT);

  digitalWrite(ledPin,LOW);
} 

void loop() 
{ 
  int digitalVal = digitalRead(tiltBallPin); //read pin 2
  if(HIGH == digitalVal)
  {
    digitalWrite(ledPin,LOW);//turn the led off
  }
  else
  {
    digitalWrite(ledPin,HIGH);//turn the led on 
  }
}
