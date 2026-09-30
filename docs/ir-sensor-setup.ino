#include <IRremote.h>

const int RemotePin = 8;
IRrecv irrecv(RemotePin);
decode_results results;

void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn();
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    delay(200);
    irrecv.resume();
  }
}
