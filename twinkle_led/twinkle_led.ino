const int led = 2;

void setup() {
  Serial.begin(115200);
  Serial.println("init..");
  pinMode(led, OUTPUT);
  delay(500);
}

void loop() {
  digitalWrite(led, HIGH);
  delay(400);
  digitalWrite(led, LOW);
  delay(500);
}
