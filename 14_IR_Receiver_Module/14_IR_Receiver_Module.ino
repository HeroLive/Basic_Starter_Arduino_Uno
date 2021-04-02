#include <IRremote.h> //thư viện hỗ trợ IR remote
int IR_RECEIVE_PIN = 11; // chân digital 11 dùng để đọc tín hiệu

IRrecv IrReceiver(IR_RECEIVE_PIN); // tạo đối tượng IrReceiver mới

void setup() {
  Serial.begin(9600);
  Serial.println("IR Receiver Button Decode");
  Serial.println("Enabling IRin");
  IrReceiver.enableIRIn(); // start the IR receiver
  Serial.print(F("Ready to receive IR signals at pin "));
  Serial.println(IR_RECEIVE_PIN);
}

void loop() {
  if (IrReceiver.decode())  // nếu nhận được tín hiệu
  {
    uint32_t IRcode = IrReceiver.results.value;
    Serial.println(IRcode);
    String keyBuf = translateIR(IRcode);
    delay(300);
    IrReceiver.resume(); // nhận giá trị tiếp theo
  }
  delay(100);
}

String translateIR(uint32_t code) {
  String keyBuff = "";
  switch (code) {
    case 0xFFA25D:
      Serial.println("POWER");
      keyBuff = "POWER";
      break;
    case 0xFFE21D:
      Serial.println("FUNC/STOP");
      keyBuff = "FUNC/STOP";
      break;
    case 0xFF629D:
      Serial.println("VOL+");
      keyBuff = "VOL+";
      break;
    case 0xFF22DD:
      Serial.println("FAST BACK");
      keyBuff = "FAST BACK";
      break;
    case 0xFF02FD:
      Serial.println("PAUSE");
      keyBuff = "PAUSE";
      break;
    case 0xFFC23D:
      Serial.println("FAST FORWARD");
      keyBuff = "FAST FORWARD";
      break;
    case 0xFFE01F:
      Serial.println("DOWN");
      keyBuff = "DOWN";
      break;
    case 0xFFA857:
      Serial.println("VOL-");
      keyBuff = "VOL-";
      break;
    case 0xFF906F:
      Serial.println("UP");
      keyBuff = "UP";
      break;
    case 0xFF9867:
      Serial.println("EQ");
      keyBuff = "EQ";
      break;
    case 0xFFB04F:
      Serial.println("ST/REPT");
      keyBuff = "ST/REPT";
      break;
    case 0xFF6897:
      Serial.println("0");
      keyBuff = "0";
      break;
    case 0xFF30CF:
      Serial.println("1");
      keyBuff = "1";
      break;
    case 0xFF18E7:
      Serial.println("2");
      keyBuff = "2";
      break;
    case 0xFF7A85:
      Serial.println("3");
      keyBuff = "3";
      break;
    case 0xFF10EF:
      Serial.println("4");
      keyBuff = "4";
      break;
    case 0xFF38C7:
      Serial.println("5");
      keyBuff = "5";
      break;
    case 0xFF5AA5:
      Serial.println("6");
      keyBuff = "6";
      break;
    case 0xFF42BD:
      Serial.println("7");
      keyBuff = "7";
      break;
    case 0xFF4AB5:
      Serial.println("8");
      keyBuff = "8";
      break;
    case 0xFF52AD:
      Serial.println("9");
      keyBuff = "9";
      break;
    case 0xFFFFFFFF:
      Serial.println("REPEAT");
      keyBuff = "REPEAT";
      break;
    default:
      Serial.println("other button");
      keyBuff = "OTHER";
  }
  return keyBuff;
}

//#include <IRremote.h> //thư viện hỗ trợ IR remote
//int IR_RECEIVE_PIN = 11; // chân digital 11 dùng để đọc tín hiệu
//
//IRrecv IrReceiver(IR_RECEIVE_PIN); // tạo đối tượng IrReceiver mới
//
//void setup() {
//  Serial.begin(9600);
//  Serial.println("IR Receiver Button Decode");
//  Serial.println("Enabling IRin");
//  IrReceiver.enableIRIn(); // start the IR receiver
//  Serial.print(F("Ready to receive IR signals at pin "));
//  Serial.println(IR_RECEIVE_PIN);
//}
//
//void loop() {
//  if (IrReceiver.decode())  // nếu nhận được tín hiệu
//  {
//    uint32_t IRcode = IrReceiver.results.value;
//    Serial.println(IRcode);
//    delay(300);
//    IrReceiver.resume(); // nhận giá trị tiếp theo
//  }
//  delay(100);
//}
