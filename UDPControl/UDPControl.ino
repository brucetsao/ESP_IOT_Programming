/*************************************************************
 *          UDP BASED CONTROL FROM MOBILE PHONE
 *          ===================================
 *                  
 * This is an UDP based control program where 2 LEDs are connected 
 * to GPIO ports 23 and 22 of the ESP32 devkitc board, and named
 * as LED0 and LED1. Commands are sent from an Android type 
 * mobile phone to turn the LEDs ON/OFF. The ESP32 Devkitc is
 * configured as an UDP client in this application. The format of 
 * the commands are as follows:
 * 
 *  0=ON   turn ON LED0
 *  0=OFF  turn OFF LED0
 *  1=ON   turn ON LED1
 *  1=OFF  turn OFF LED1
 *  
 *  
 *  File:   UDPControl
 *  Author: Dogan Ibrahim
 *  Date:   August, 2017
 * 
 **************************************************************/
#include "WiFi.h"
#include <WiFiUdp.h>
//
// LED assignments
//
#define LED0 23
#define LED1 22
WiFiUDP udp;
//
// Use local port 5000
//
const int Port = 5000;
char Packet[80];

//
// Local Wi-Fi name and password
//
const char* ssid = "BTHomeSpot-XNH";
const char* password = "49345abaeb";

//
// This function connects the ESP32 Devkitc to the local Wi-Fi
// network. The network name and passwors are as specifed earlier
void Connect_WiFi()
{
      WiFi.begin(ssid, password);
      while(WiFi.status() != WL_CONNECTED)
      {
        delay(1000);
      }
}


//
// Configure LEDs as outputs, turn OFF the LEDs to start with,
// Connect to the local Wi-Fi. Also, UDP is started in local port
//
void setup()
{
    pinMode(LED0, OUTPUT);
    pinMode(LED1, OUTPUT);
    digitalWrite(LED0, LOW);
    digitalWrite(LED1, LOW);
    Connect_WiFi();
    udp.begin(Port);
}

//
// This is the main program loop. Inside the main program we read
// UDP packets and then control the LEDs as requested. The format
// of the control commands are:
//
// 0=ON or 0=OFF for LED0
// 1=ON or 1=OFF for LED1
//
// Any other commands are simply ignored by the program
//
void loop()
{
   int PacketSize = udp.parsePacket();
   if(PacketSize)
   {
     udp.read(Packet, PacketSize);
     
     if(Packet[1]=='=')
     {
        if(Packet[0]=='0')
        {
          if(Packet[2]=='O' && Packet[3]=='N')
          {
             digitalWrite(LED0, HIGH);
          }
          else if(Packet[2]=='O' && Packet[3]=='F' && Packet[4]=='F')
          {
             digitalWrite(LED0, LOW);
          }
        }
        else if(Packet[0]=='1')
        {
          if(Packet[2]=='O' && Packet[3]=='N')
          {
            digitalWrite(LED1, HIGH);
          }
          else if(Packet[2]=='O' && Packet[3]=='F' && Packet[4]=='F')
          {
            digitalWrite(LED1, LOW);
          }
        }
     }
   }
}


