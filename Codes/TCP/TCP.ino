/*************************************************************
 *                  TCP/IP SERVER EXAMPLE
 *                  =====================
 *                  
 *  This is a TCP/IP server example. The program sends the message
 *  "Hello from the Server" to a TCP/IP client. The IP addresses
 *  and port numbers of the server and the client are:
 *  
 *  Server (ESP32 Devkitc) IP address: 192.168.1.156 Port: 5000
 *  Client (PC) IP address:            192.168.1.71
 *  
 *  
 *  File:   TCP
 *  Author: Dogan Ibrahim
 *  Date:   August, 2017
 * 
 **************************************************************/
#include "WiFi.h"

const char* ssid = "BTHomeSpot-XNH";
const char* password = "49345abaeb";
const int TCPPort = 5000;
char Buffer[80];
WiFiServer server(TCPPort);

//
// Set mode to station, and connect to the local Wi-Fi. Display
// the local IP address, and begin listening for clients
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
    Serial.print("Local IP address is: ");
    Serial.println(WiFi.localIP());
    server.begin();                             // Begin listening for clients
}

//
// Read the packet from the client until character "." detected,
// and then send the message "Hello from teh Server" to the
// client
//
void loop()
{
    WiFiClient client = server.available();       // A client connected?
    while(client.connected() && !client.available())
    {  delay(1);
    }
    String line=client.readStringUntil('.');
    Serial.println(line);
    client.printf("Hello from the Server");
    client.stop();
    
    
}
