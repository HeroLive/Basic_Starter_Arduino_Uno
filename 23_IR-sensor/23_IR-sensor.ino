int infrared = 2;
int led = 3;

void setup()
{
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(infrared, INPUT_PULLUP);
}
void loop() 
{
  Serial.println(digitalRead(infrared));
  if(digitalRead(infrared) == 0)
  {
    digitalWrite(led, HIGH);    
  }
  else
  {   
    digitalWrite(led, LOW);
  }
}
