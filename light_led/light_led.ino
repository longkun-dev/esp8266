int led = 2;

void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
  // 将led置为低电平，保持关闭状态
  digitalWrite(led, 1);
  // 暂停3秒
  delay(3000);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(led, 0);
}
