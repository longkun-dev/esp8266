#include<ESP8266WiFi.h>
#include<WiFiClientSecure.h>

const int led = 2;
const char* ssid = "ZIROOM-5C";
const char* password = "4001001111";
const char* host = "https://reqres.in";
const int port = 80;
const char* api = "/api/users?page=1";
bool loopFlag = 1;

void setup() {
  // 连接WiFi
  Serial.begin(115200);
  pinMode(led, OUTPUT);
  digitalWrite(led, HIGH);
  Serial.println("connect WiFi..");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("connecting...");
  }
  digitalWrite(led, LOW);
  Serial.println("ip address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  // 只发送一次请求
  if (loopFlag) {
    loopFlag = 0;

    Serial.println("connect to ");
    Serial.println(host);

    WiFiClient client;

    if (!client.connect(host, port)) {
      Serial.println("connect failed.");
      return;
    }

    delay(100);

    String postRequest = (String)("GET ") + api + "/ HTTP/1.1\r\n" +
                         "Content-Type: text/html;charset=utf-8\r\n" +
                         "Host: " + host + "\r\n" +
                         "User-Agent: BuildFailureDetectorESP8266\r\n" +
                         "Connection: Keep Alive\r\n\r\n";
    Serial.println(postRequest);
    client.print(postRequest);

    String line = client.readStringUntil('\r');
    while (line.length() != 0) {
      Serial.println(line);
      line = client.readStringUntil('\r');
    }
    Serial.println(line);
    client.stop();
    delay(3000);
    Serial.println("request finished.");
  }
}
