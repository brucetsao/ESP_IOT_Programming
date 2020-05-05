#include <Arduino.h>
#include <analogWrite.h>
#define LedPin 2
#define LightPin 4
int lightValue = 0 ;
void setup() {
  // Set resolution for a specific pin
  Serial.begin(9600) ;
  Serial.println("System Work") ;
  analogWriteResolution(LedPin, 12);
}

void loop() {
  lightValue = analogRead(LightPin);
  Serial.print("Light Strength is :(") ;
  Serial.print(lightValue) ;
  Serial.print(")\n") ;
  analogWrite(LedPin,map(lightValue,4095,0,0,255) );

  delay(50);
}
