/*************************************************************
 *                  CONNECT TO A WI-FI NETWORK
 *                  ==========================
 *                  
 *  This program connect to the local Wi-Fi network with the
 *  name BTHomeSpot-XNH. The connection status is displayed on
 *  the Serial Monitor. In addition, the local IP address and the
 *  MAC address aee displayed. The program disconnects from the
 *  network before stopping
 *  
 *  
 *  File:   CONNECT2
 *  Author: Dogan Ibrahim
 *  Date:   August, 2017
 * 
 **************************************************************/
#include "WiFi.h"
const char* ssid = "BTHomeSpot-XNH";
const char* password = "49341abaeb";

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
//
// Display the local IP address and the MAC address, and then
// disconnect from the Wi-Fi
//
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());
    Serial.print("Mac address: ");
    Serial.println(WiFi.macAddress());
    WiFi.disconnect(true);
}


void loop()
{
  // no code
}
