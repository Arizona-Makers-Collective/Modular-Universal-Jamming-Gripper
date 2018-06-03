#include <Servo.h>

#define IN 1
#define OUT -1
#define OFF 0

#define pumpPin 3
#define servoPin 6

Servo servo;

void pumpInit() {
  pinMode(pumpPin, OUTPUT);

  servo.attach(servoPin);
  servo.write(180);
}

void pump(int dir) {
  if (dir == IN) {
    digitalWrite(pumpPin, LOW);
    servo.write(180);
  } else if (dir == OUT) {
    digitalWrite(pumpPin, LOW);
    servo.write(140);
  } else {
    digitalWrite(pumpPin, HIGH);
  }
}

void setup() {
  pumpInit();
}

void loop() {
  pump(OUT);
  delay(2500);

  pump(OFF);
  delay(1000);
  
  pump(IN);
  delay(4000);

  pump(OFF);
  delay(2000);
}
