#include <Arduino.h>
#include <analogWrite.h>
#define LedPin 2
#define MicPin 4
int micValue = 0;
void setup() {
  Serial.begin(9600);
  delay(1000);
  // Set resolution for a specific pin
  analogWriteResolution(LedPin, 12);

}

void loop() {
  micValue = analogRead(MicPin);
  Serial.print(micValue) ;
  Serial.print("/") ;
  Serial.print(map(micValue, 0, 2048,0, 255)) ;
  Serial.print("\n") ;

  analogWrite(LedPin, map(micValue, 1000, 2048,0, 255));

  delay(25);
}
