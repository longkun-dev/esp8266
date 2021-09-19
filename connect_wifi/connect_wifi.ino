#include<ESP8266WiFi.h>

const char* ssid = "ZIROOM-5C";
const char* password = "4001001111";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  delay(1000);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println(".");
  }

  Serial.println("");
  Serial.println("WiFi connected!");
  Serial.println(WiFi.localIP());
}

void loop() {
  // put your main code here, to run repeatedly:

}
