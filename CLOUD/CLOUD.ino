/*************************************************************
 *          TEMPERATURE AND HUMIDITY ON THE CLOUD
 *          =====================================
 *                  
 *  In this project a DHT11 type temperature and humidity sensor
 *  chip is connected to GPIO port 23 of the ESP32 Devkitc. The
 *  program reads the ambient temperature and humidity and sends
 *  this data to the cloud every 60 seconds where it can be 
 *  accessed from anywhere on Earth. In addition, change of the 
 *  temperature and the humidity can be plotted using the cloud 
 *  services.
 *  
 *  The program uses the Thingspeak cloud service. The ESP32
 *  must be connected to the Wi-Fi network before we can send
 *  data to the cloud
 *  
 *  
 *  File:   CLOUD
 *  Author: Dogan Ibrahim
 *  Date:   August, 2017
 * 
 **************************************************************/
#include "WiFi.h"
//
// DHT11 sensor library includes
//
#include <Adafruit_Sensor.h>
#include "DHT.h"
#define DHT11_PIN 23
#define DHTTYPE DHT11
//
// Local Wi-Fi name and password
//
const char* ssid = "BTHomeSpot-XNH";
const char* password = "49341abaeb";
//
// Thingspeak API key, channel number, and host name
//
unsigned long myChannelNumber = 265433;
String APIKEY = "QAAHT5XIK3ZB8736";
const char* host = "api.thingspeak.com";

int T, H;
DHT dht(DHT11_PIN, DHTTYPE);
WiFiClient client;


//
// This function connects the ESP32 Devkitc to the local Wi-Fi
// network. The network name and passwors are specifed earlier
void Connect_WiFi()
{
      WiFi.begin(ssid, password);
      while(WiFi.status() != WL_CONNECTED)
      {
        delay(1000);
      }
}

//
// This function reads the ambient temperature and humidity and
// stores in variables T and H respectively
//
void TempHum()
{
   H = dht.readHumidity();                    // Read humidity
   T = dht.readTemperature();                 // Read temperature
}


//
// Initialize DHT11, connect to local Wi-Fi, connect to HTTP
//
void setup()
{
    dht.begin();
    Connect_WiFi();
    client.connect(host, 80);
}

//
// This is the main program. Read the ambient temperature and
// humidity and send the data to Thingspeak every 30 seconds
//
void loop()
{
    client.connect(host,80);
    TempHum();
    client.print("GET /update?api_key=QAAHT5XIK3ZB8736&field1=");
    client.print(String(T));
    client.print("&field2=");
    client.print(String(H));
    client.print(" HTTP/1.0\r\nHost: api.thingspeak.com\r\n\r\n");
    delay(30000);    
}

