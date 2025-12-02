#include <Arduino.h>
#include <DHT.h>

#define DHTPIN 4 
#define DHTTYPE DHT11   

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);  
  dht.begin();       
}

void loop() {
  delay(2000);  

  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t)) {
    Serial.println("Lỗi: Không thể đọc từ cảm biến DHT11!");
    return;
  }

  Serial.print("Độ ẩm: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Nhiệt độ: ");
  Serial.print(t);
  Serial.println(" °C");
}
