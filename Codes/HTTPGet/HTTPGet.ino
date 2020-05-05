/*************************************************************
 *                  HTTP GET EXAMPLE
 *                  ================
 *                  
 *  This is an example of using the HTTP GET service to retrieve
 *  information from a web site. In this example the web site:
 *  http://httpbin.org/ip is used as an example, where this URL
 *  returns the local IP address. The retrieved information is 
 *  displayed on the Serial Monitor together with the HTTP return
 *  code
 *  
 *  File:   HTTPGet
 *  Author: Dogan Ibrahim
 *  Date:   August, 2017
 * 
 **************************************************************/
#include "WiFi.h"
#include <HTTPClient.h>

const char* ssid = "NCNU";
const char* password = "12345678";

//
// Set mode to station, and connect to teh local Wi-Fi
//
void setup()
{
    Serial.begin(9600);
    WiFi.begin(ssid, password);
    while(WiFi.status() != WL_CONNECTED)
    {
       Serial.println("Attempting to connect...");
       delay(1000);
    }
    Serial.println("Connected to local Wi-Fi");

}

//
// Retrieve infrmation from site:
// http://httpbin.org/ip and display on the Serial Monitor
//
void loop()
{
    HTTPClient http;
    http.begin("http://192.168.99.200/iot/");         // Specify site
    int HttpRetCode = http.GET();               // HTTP GET request

    if(HttpRetCode > 0)                            // If data returned
    {
      Serial.println("Received data...");       // Display the data
      String Contents = http.getString();
      Serial.println(HttpRetCode);              // Display the code
      Serial.println(Contents);                 // Display the contents
      http.end();                               // End the connection
    }
}
