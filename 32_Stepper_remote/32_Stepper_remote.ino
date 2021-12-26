//==========================================
#include <IRremote.h>

int RECV_PIN = 11;
int en = 8 ;
int dirPin = 3 ;
int stepPin = 2 ;
int rpm_motor = 60; // vong/phut
int dir_motor = 0;
boolean run_status = false;

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
  Serial.begin(9600);

  pinMode(en, OUTPUT); // Enable
  pinMode(stepPin, OUTPUT); // Step
  pinMode(dirPin, OUTPUT); // Dir
  digitalWrite(en, LOW); // Set Enable low

  Serial.println("IR Receiver Button Decode");
  Serial.println("Enabling IRin");
  irrecv.enableIRIn(); // start the IR receiver
  Serial.print(F("Ready to receive IR signals at pin "));
  Serial.println(RECV_PIN);
}

void loop() {
  if (irrecv.decode(&results))  // nếu nhận được tín hiệu
  {
    uint32_t IRcode = results.value;
    //    Serial.println(IRcode);
    String keyBuf = translateIR(IRcode);
    
    if (keyBuf == "UP") {
      rpm_motor++;
    } else if (keyBuf == "DOWN") {
      rpm_motor--;
    } else if (keyBuf == "LEFT") {
      dir_motor = 0;
    } else if (keyBuf == "RIGHT") {
      dir_motor = 1;
    } else if (keyBuf == "OK") {
      run_status = !run_status;
    }
//    Serial.println(rpm_motor);
//    Serial.println(dir_motor);
    irrecv.resume(); // nhận giá trị tiếp theo
  }
  if (run_status) {
    runMotor(dir_motor, rpm_motor);
  }
}

void runMotor(int dir, int rpm) {
  float maxSpeed = rpm / 60.0 * 200;
  float period = 0.5 / maxSpeed * 1000000;
  digitalWrite(dirPin, dir);
  digitalWrite(stepPin, HIGH);
  delayMicroseconds(period);
  digitalWrite(stepPin, LOW);
  delayMicroseconds(period);
}

String translateIR(uint32_t code) {
  String keyBuff = "";
  switch (code) {
    case 0xFF6897:
      keyBuff = "*";
      break;
    case 0xFFB04F:
      keyBuff = "#";
      break;
    case 0xFF18E7:
      keyBuff = "UP";
      break;
    case 0xFF4AB5:
      keyBuff = "DOWN";
      break;
    case 0xFF5AA5:
      keyBuff = "RIGHT";
      break;
    case 0xFF10EF:
      keyBuff = "LEFT";
      break;
    case 0xFF38C7:
      keyBuff = "OK";
      break;
    case 0xFF9867:
      keyBuff = "0";
      break;
    case 0xFFA25D:
      keyBuff = "1";
      break;
    case 0xFF629D:
      keyBuff = "2";
      break;
    case 0xFFE21D:
      keyBuff = "3";
      break;
    case 0xFF22DD:
      keyBuff = "4";
      break;
    case 0xFF02FD:
      keyBuff = "5";
      break;
    case 0xFFC23D:
      keyBuff = "6";
      break;
    case 0xFFE01F:
      keyBuff = "7";
      break;
    case 0xFFA857:
      keyBuff = "8";
      break;
    case 0xFF906F:
      keyBuff = "9";
      break;
    default:
      return keyBuff;
  }
//  Serial.println(keyBuff);
  return keyBuff;
}
