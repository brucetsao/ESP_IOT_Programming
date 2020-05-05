#include <Arduino.h>
#include <analogWrite.h>
#define LedPin 2
int brightStep = 1;
int brightness = 0;

void setup() {
  // Set resolution for a specific pin
  analogWriteResolution(LedPin, 12);
}

void loop() {
  brightness += brightStep;
  if ( brightness == 0 || brightness == 255 ) {
    brightStep = -brightStep;
  }

  analogWrite(LedPin, brightness);

  delay(25);
}
