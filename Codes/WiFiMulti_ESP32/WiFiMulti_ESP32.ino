/*
 *  This sketch trys to Connect to the best AP based on a given list
 *
 */

#include <WiFi.h>
#include <WiFiMulti.h>
#define LED_BUILTIN 2   // Set the GPIO pin where you connected your test LED or comment this line out if your dev board has a built-in LED

WiFiMulti wifiMulti;

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN,LOW) ;
  Serial.begin(9600);
  delay(10);

    wifiMulti.addAP("BRUCE", "12345678");
    wifiMulti.addAP("Brucetsao", "12345678");
  
      Serial.println("Connecting Wifi...");
    if(wifiMulti.run() == WL_CONNECTED) {
        Serial.println("");
        Serial.print("Successful Connecting to Access Point:");
        Serial.println(WiFi.SSID());
        Serial.println("WiFi connected");
        Serial.println("IP address: ");
        Serial.println(WiFi.localIP());
    }

    digitalWrite(LED_BUILTIN,HIGH) ;
    Serial.println("");
    Serial.println("WiFi connected");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
    
}

void loop()
{

}
