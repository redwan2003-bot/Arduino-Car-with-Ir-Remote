#include <IRremote.h>

const int RemotePin = 8;
IRrecv irrecv(RemotePin);
decode_results results;

const int in1 = 3;
const int in2 = 5;
const int in3 = 6;
const int in4 = 9;

void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn();

  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  stopMotors();
}

void loop() {
  if (irrecv.decode(&results)) {
    switch (results.value) {
      case 0xFF629D:  // UP
        forward();
        break;
      case 0xFFA857:  // DOWN
        backward();
        break;
      case 0xFF22DD:  // LEFT
        turnLeft();
        break;
      case 0xFFC23D:  // RIGHT
        turnRight();
        break;
      case 0xFF02FD:  // STOP
        stopMotors();
        break;
    }

    irrecv.resume();
  }
}

void backward() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void forward() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void stopMotors() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}

void turnLeft() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void turnRight() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}
