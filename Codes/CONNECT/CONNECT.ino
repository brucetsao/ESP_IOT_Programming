/*************************************************************
 *                  CONNECT TO A WI-FI NETWORK
 *                  ==========================
 *                  
 *  This program connect to the local Wi-Fi network with the
 *  name BTHomeSpot-XNH. The conenction status is displayed on
 *  the Serial Monitor.
 *  
 *  
 *  File:   CONNECT
 *  Author: Dogan Ibrahim
 *  Date:   August, 2017
 * 
 **************************************************************/
#include "WiFi.h"
const char* ssid = "BTHomeSpot-XNH";
const char* password = "49315abaeb";

//
// Set mode to station, scan the surrounding Wi-Fi networks and
// display their details on the Serial Monitor
//
void setup()
{
    Serial.begin(9600);
    Serial.println("");
    WiFi.begin(ssid, password);
    while(WiFi.status() != WL_CONNECTED)
    {
       Serial.println("Attempting to connect...");
       delay(1000);
    }
    Serial.println("Connected to Wi-Fi network");
}


void loop()
{
  // no code
}
