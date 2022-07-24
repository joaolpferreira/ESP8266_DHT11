#define led0 D0
#define led1 D1
#define led2 D2
#define BUTTON_PIN D7
void setup() {
  Serial.begin(9600);
  Serial.println("Hello, ESP!");
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(led0, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}

int lastState = HIGH;
void loop() {
  int value = digitalRead((BUTTON_PIN));
  if (lastState != value) {
    lastState = value;
    if (value == HIGH) {
      //Serial.println(" released");
      digitalWrite(led0, LOW);
      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
      Serial.println("LEDS OFF!");
    }
    if (value == LOW) {
      //Serial.println(" pressed");
      digitalWrite(led0, HIGH);
      digitalWrite(led1, HIGH);
      digitalWrite(led2, HIGH);
      Serial.println("LEDS ON!");
    }
  }
  delay(100);
  //Serial.println(value);
}
