/*************************************************************
 *                  SCAN WI-FI NETWORK
 *                  ==================
 *                  
 *  This program does a scan and displays the surrounding Wi-Fi 
 *  networks. The following parameters of the found networks 
 *  are displayed: Network name (SSID), signal strength (RSSI),
 *  and MAC address (BSSIDstr).
 *  
 *  File:   SCAN
 *  Author: Dogan Ibrahim
 *  Date:   August, 2017
 * 
 **************************************************************/
#include "WiFi.h"

//
// Set mode to station, scan the surrounding Wi-Fi networks and
// display their details on the Serial Monitor
//
void setup()
{
    Serial.begin(9600);
    WiFi.mode(WIFI_STA);                        // Mode station

    int N = WiFi.scanNetworks();                  // Scan networks
    if(N > 0)                                     // If networks found
    {
        Serial.println("");
        Serial.print(N);
        Serial.println(" Networks found");
        for (int i = 0; i < N; ++i) 
        {
            Serial.print(i + 1);
            Serial.print(": ");
            Serial.print("Network Name: ");
            Serial.print(WiFi.SSID(i));
            Serial.print("  ");
            Serial.print("Signal Strength: ");
            Serial.print(WiFi.RSSI(i));
            Serial.print("  ");
            Serial.print("MAC Address: ");
            Serial.println(WiFi.BSSIDstr(i));
            delay(50);
        }
    }   
}

void loop()
{
  // no code
}
