#define pul 2
#define dir 3
#define en 8
// Rotary Encoder Inputs
#define CLK 6
#define DT 5
#define SW 4

int counter = 0;
int currentStateCLK;
int lastStateCLK;
unsigned long lastButtonPress = 0;

int microStep = 1; //16;
float angleStep = 1.8;
float stepsPerUnit = 360.0 * microStep / angleStep;
long position = 0;
long target = 0;
long speed = 120; //vong/phut rpm
bool dir_status = HIGH;
unsigned long last_step_time;
unsigned long step_delay;

void setup() {
  //stepper
  pinMode(pul, OUTPUT);
  pinMode(dir, OUTPUT);
  pinMode(en, OUTPUT);
  digitalWrite(en,LOW);
  digitalWrite(dir, dir_status);
  // Set encoder pins as inputs
  pinMode(CLK,INPUT);
  pinMode(DT,INPUT);
  pinMode(SW, INPUT_PULLUP);

  // Setup Serial Monitor
  Serial.begin(9600);

  // Read the initial state of CLK
  lastStateCLK = digitalRead(CLK);
}

void loop() {
  enPos();
  if(checkSW()){
    StepperEvent();
  }
}

void enPos(){
  // Read the current state of CLK
  currentStateCLK = digitalRead(CLK);

  // If last and current state of CLK are different, then pulse occurred
  // React to only 1 state change to avoid double count
  if (currentStateCLK != lastStateCLK  && currentStateCLK == 1){

    // If the DT state is different than the CLK state then
    // the encoder is rotating CCW so decrement
    if (digitalRead(DT) != currentStateCLK) {
      counter --;
    } else {
      // Encoder is rotating CW so increment
      counter ++;
    }
    Serial.print("Counter: ");
    Serial.println(counter);
  }

  // Remember last CLK state
  lastStateCLK = currentStateCLK;
}

boolean checkSW(){
  // Read the button state
  int btnState = digitalRead(SW);
  int isPress = false;

  //If we detect LOW signal, button is pressed
  if (btnState == LOW) {
    //if 50ms have passed since last LOW pulse, it means that the
    //button has been pressed, released and pressed again
    if (millis() - lastButtonPress > 50) {
      Serial.println("Button pressed!");
      isPress = true;
    }

    // Remember last button press event
    lastButtonPress = millis();
  }
  return isPress;
}
void StepperEvent() { 
  long target = counter;
  long newPosition = target * stepsPerUnit;
  Serial.print("Move from ");
  Serial.print(position / stepsPerUnit);
  Serial.print(" to ");
  Serial.println(target);

  step_delay = 60 * 1000L * 1000L / stepsPerUnit / speed;
  if (newPosition > position) {
    digitalWrite(dir, dir_status);
  } else if (newPosition < position) {
    digitalWrite(dir, !dir_status);
  } else {
    return;
  }
  while (position != newPosition)
  {
    if (micros() - last_step_time >= step_delay)
    {
      last_step_time = micros();
      digitalWrite(pul, HIGH);
      digitalWrite(pul, LOW);
      position = (position < newPosition) ? position + 1 : position - 1;
    }
  }
  Serial.println("on target");
}
