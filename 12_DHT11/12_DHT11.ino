// Gọi thư viện DHT11
#include "DHT.h"
const int DHTPIN = 2;      //Đọc dữ liệu từ DHT11 ở chân 2 trên mạch Arduino
const int DHTTYPE = DHT11; //Khai báo loại cảm biến, có 2 loại là DHT11 và DHT22
DHT dht(DHTPIN, DHTTYPE);
void setup()
{
  Serial.begin(9600);
  dht.begin();
}
void loop()
{
  float h = dht.readHumidity(); //Đọc độ ẩm
  float t = dht.readTemperature(); //Đọc nhiệt độ

  Serial.print("Nhiet do: ");
  Serial.println(t); //Xuất nhiệt độ
  Serial.print("Do am: ");
  Serial.println(h); //Xuất độ ẩm

  Serial.println(); //Xuống hàng
  delay(1000); //Đợi 1 giây
}
