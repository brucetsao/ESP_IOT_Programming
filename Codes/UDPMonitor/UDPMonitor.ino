/*************************************************************
 *          SEND TEMPERATURE AND HUMIDITY TO A MOBILE PHONE
 *          ================================================
 *                  
 * This is an UDP based monitoring program where a DHT11 type
 * temperatrue and humidity sensor chip is connected to GPIO
 * port 23 of the ESP32 Devkitc. The program reads the ambient
 * temperatrue and humidity and sends the readings to an Android
 * mobile phone using UDP packets. The data on the mobile phone
 * is displayed using an UDP apps, available on the Play Store.
 * The data is sent to the mobile phone whenever it is requested.
 * 
 * A request for data is made to teh ESp32 Devkitc when character 
 * S is sent to the ESp32 Devkit over the UDP link. The ESP32 
 * Devkitc sends the temperature and humidiry data to the device 
 * that made the request. Port 5000 is used for the communication
 *  
 *  The IP addresses of the ESP32 Devkitc and mobile phone are:
 *  192.168.1.56 and 192.168.1.125 respectively.
 *  
 *  File:   UDPMonitor
 *  Author: Dogan Ibrahim
 *  Date:   August, 2017
 * 
 **************************************************************/
#include "WiFi.h"
#include <WiFiUdp.h>
//
// DHT11 sensor library includes
//
#include <Adafruit_Sensor.h>
#include "DHT.h"
#define DHT11_PIN 23
#define DHTTYPE DHT11
DHT dht(DHT11_PIN, DHTTYPE);

WiFiUDP udp;

//
// Use local port 5000
//
const int Port = 5000;
char Packet[20];

//
// Local Wi-Fi name and password
//
const char* ssid = "BTHomeSpot-XNH";
const char* password = "49345abaeb";
int T, H;

//
// Read the ambient temperature and humidity and store in variables
// T and H respectively
//
void TempHum()
{
   H = dht.readHumidity();                    // Read humidity
   T = dht.readTemperature();                 // Read temperature
}

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
// Connect to the local Wi-Fi. Also, UDP is started in local
// port and DHT11 is started
//
void setup()
{
    Connect_WiFi();
    udp.begin(Port);
    dht.begin();
}

//
// This is the main program loop. Inside the main program we read
// the temperatrue and humidity an send them as a packet to the
// mobile phone when a request is made by the mobile phone.
// A request is made when character S is sent by the mobile
// phone.
//
// The packet format is:
//
//  T=nn H=nn
//
void loop()
{
    int PacketSize = udp.parsePacket();
    if(PacketSize)
    {
        udp.read(Packet, PacketSize);
        if(Packet[0] == 'S')
        {
           TempHum();
           Packet[0] = 'T';
           Packet[1] = '=';
           int msd = T/10;
           int lsd = T - msd*10;
           Packet[2] = msd + '0';
           Packet[3] = lsd + '0';
           Packet[4] = ' ';
           Packet[5] = ' ';
           Packet[6] = 'H';
           Packet[7] = '=';
           msd = H/10;
           lsd = H - msd*10;
           Packet[8] = msd + '0';
           Packet[9] = lsd + '0';
           Packet[10] = 0;
           udp.beginPacket(udp.remoteIP(), Port);
           udp.print(Packet);
           udp.endPacket();
        }
    }
}


