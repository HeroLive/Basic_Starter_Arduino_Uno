int buzzer = 12;//the pin of the active buzzer
void setup()
{
 pinMode(buzzer,OUTPUT);//initialize the buzzer pin as an output
}
void loop()
{
    digitalWrite(buzzer,HIGH);
    delay(2000);//wait for 2s
    digitalWrite(buzzer,LOW);
    delay(1000);//wait for 1s
} 
