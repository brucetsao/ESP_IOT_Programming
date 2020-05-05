#include "WiFi.h"
#include <String.h>

void setup(){
  Serial.begin(9600);

  WiFi.mode(WIFI_MODE_STA);
  
  Serial.println("");
  Serial.print("Mac Address :");
  Serial.println(WiFi.macAddress());
}

void loop(){}
