/*************************************************************
 *                  UDP SERVER EXAMPLE
 *                  ==================
 *                  
 *  This is an UDP server example. The program sends the message
 *  "Hello from the Server" to an UDP client. The IP addresses
 *  and port numbers of the server and teh client are:
 *  
 *  Server (ESP32 Devkitc) IP address: 192.168.1.156 Port: 5000
 *  Client (PC) IP address:            192.168.1.71
 *  
 *  
 *  File:   UDP
 *  Author: Dogan Ibrahim
 *  Date:   August, 2017
 * 
 **************************************************************/
#include "WiFi.h"
#include <WiFiUDP.h>

const char* ssid = "BTHomeSpot-XNH";
const char* password = "49345abaeb";
const int UDPPort = 5000;
const char* DestUDPAddress = "192.168.1.71";
char Buffer[80];
WiFiUDP udp;

//
// Set mode to station, and connect to the local Wi-Fi. Display
// the local IP address
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
    udp.begin(UDPPort);           `           // listen to incoming packets
}

//
// Parse the received packet and get its details, such as the
// packet size, remote IP address, and remote port number. Then
// display the contents of the received packet which is stored
// in variable Buffer
//
void loop()
{
    udp.beginPacket(DestUDPAddress, UDPPort);
    int packetSize=udp.parsePacket();
    if(packetSize)
    {
       Serial.print("Received packet size is: ");
       Serial.print(packetSize);
       Serial.println(" characters");
       Serial.print("Packet received from: ");
       Serial.println(udp.remoteIP());
       Serial.print("Port address is: ");
       Serial.println(udp.remotePort());
    }
    int len = udp.read(Buffer, 80);
    if(len > 0)
    {
       Serial.println(Buffer);
    }
    udp.printf("Hello from the Server");
    delay(2000);
    udp.endPacket();
}
