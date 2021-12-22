/*
 Chân data của các Module thu kết nối chân 11 của Arduino
 Mở Serial Monitor, chọn No line ending, baud 9600
 Dùng Remote hồng ngoại để kiểm tra tín hiệu
 */
#include <IRremote.h>

int RECV_PIN = 11;

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    Serial.println(results.value);
    irrecv.resume(); // Receive the next value
  }
}
/*
//==========================================
#include <IRremote.h>

int RECV_PIN = 11;

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
  Serial.begin(9600);
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
    delay(100);
    irrecv.resume(); // nhận giá trị tiếp theo
  }
  delay(100);
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
  Serial.println(keyBuff);
  return keyBuff;
}
*/
