#include<ESP8266WiFi.h>

int abc = 1234;
bool isTrue = 1;

void setup() {
  Serial.begin(115200);
  Serial.println("init...");
  Serial.println("Setup..");
  Serial.println(abc);

  int a = 2;
  a += 1;
  abc = a;
  Serial.println(abc);
}

void loop() {
  if (isTrue) {
    isTrue = 0;
    Serial.println("loop");
  }
  abc += 1;
  delay(1000);
  Serial.println(abc);
}
