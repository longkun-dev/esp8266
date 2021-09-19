#include <ESP8266WiFi.h>

// WiFi parameters
const char* ssid = "ZIROOM-5C";
const char* password = "4001001111";

void setup(void)
{
  // Start Serial
  Serial.begin(9600);

  // Connect to WiFi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");

  // Print the IP address
  Serial.println(WiFi.localIP());

  Serial.println("start connect to WiFi..");
}

void loop() {
}
