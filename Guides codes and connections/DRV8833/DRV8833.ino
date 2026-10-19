int IN1 = 5;
int IN2 = 6;

void setup() {
  pinMode(IN2, OUTPUT);
  pinMode(IN1, OUTPUT);
}

void loop() {
  analogWrite(IN2, 200);
  analogWrite(IN1, 0);


}