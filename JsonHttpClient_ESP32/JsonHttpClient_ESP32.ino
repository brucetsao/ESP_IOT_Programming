#include "arduino_secrets.h"
#include <WiFi.h>


char ssid[20] ;
char password[20] ;
int keyIndex = 0;            // your network key Index number (needed only for WEP)
          // your network key Index number (needed only for WEP)
int wifierror = 0 ;
  IPAddress ip ;
  long rssi ;
  
int status = WL_IDLE_STATUS;
// Initialize the Ethernet client library
// with the IP address and port of the server
// that you want to connect to (port 80 is default for HTTP):
String MacData ;
WiFiClient client;



// ArduinoJson - arduinojson.org
// Copyright Benoit Blanchon 2014-2019
// MIT License
//
// This example shows how to parse a JSON document in an HTTP response.
// It uses the Ethernet library, but can be easily adapted for Wifi.
//
// It performs a GET resquest on arduinojson.org/example.json
// Here is the expected response:
// {
//   "sensor": "gps",
//   "time": 1351824120,
//   "data": [
//     48.756080,
//     2.302038
//   ]
// }
//
// https://arduinojson.org/v6/example/http-client/

#include <ArduinoJson.h>

#include <SPI.h>

void setup() {
  // Initialize Serial port
  Serial.begin(9600);
if (WiFi.status() != WL_CONNECTED)
    {
      // try one pass for AP1
     // attempt to connect to WiFi network:
        Serial.print("Attempting to connect to SSID: ");
        Serial.println(AP1);
        // Connect to WPA/WPA2 network. Change this line if using open or WEP network:
       // status = WiFi.begin(ssid, pass);
          WiFi.begin(AP1, PW1);
        // wait 10 seconds for connection:
        wifierror = 0 ;
            while (WiFi.status() != WL_CONNECTED) {
            delay(500);
            Serial.print(".");
            wifierror++ ;
            if (wifierror >100)
              break ;
        }
      
    } 

  if (WiFi.status() == WL_CONNECTED)
    {
              Serial.print("Sucessful to connect to SSID: ");
    }
    else
    {
          Serial.println("Fail to Connect to wifi successful ");
    }

  printWiFiStatus();
  MacData = GetMacAddress() ;
                                                                                                                                                                                                                                                                                                                                                                                                       

  if (!client.connect("arduinojson.org", 80)) {
    Serial.println(F("Connection failed"));
    return;
  }

  Serial.println(F("Connected!"));

  // Send HTTP request
  client.println(F("GET /example.json HTTP/1.0"));
  client.println(F("Host: arduinojson.org"));
  client.println(F("Connection: close"));
  if (client.println() == 0) {
    Serial.println(F("Failed to send request"));
    return;
  }

  // Check HTTP status
  char status[32] = {0};
  client.readBytesUntil('\r', status, sizeof(status));
  // It should be "HTTP/1.0 200 OK" or "HTTP/1.1 200 OK"
  if (strcmp(status + 9, "200 OK") != 0) {
    Serial.print(F("Unexpected response: "));
    Serial.println(status);
    return;
  }

  // Skip HTTP headers
  char endOfHeaders[] = "\r\n\r\n";
  if (!client.find(endOfHeaders)) {
    Serial.println(F("Invalid response"));
    return;
  }

  // Allocate the JSON document
  // Use arduinojson.org/v6/assistant to compute the capacity.
  const size_t capacity = JSON_OBJECT_SIZE(3) + JSON_ARRAY_SIZE(2) + 60;
  DynamicJsonDocument doc(capacity);

  // Parse JSON object
  DeserializationError error = deserializeJson(doc, client);
  if (error) {
    Serial.print(F("deserializeJson() failed: "));
    Serial.println(error.c_str());
    return;
  }

  // Extract values
  Serial.println(F("Response:"));
  Serial.println(doc["sensor"].as<char*>());
  Serial.println(doc["time"].as<long>());
  Serial.println(doc["data"][0].as<float>(), 6);
  Serial.println(doc["data"][1].as<float>(), 6);

  // Disconnect
  client.stop();
}

void loop() {
  // not used in this example
}


void printWiFiStatus() {
  // print the SSID of the network you're attached to:
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

  // print your WiFi shield's IP address:
  ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);

  // print the received signal strength:
  rssi = WiFi.RSSI();
  Serial.print("signal strength (RSSI):");
  Serial.print(rssi);
  Serial.println(" dBm");
}

String GetMacAddress() {
  // the MAC address of your WiFi shield
  String Tmp = "" ;
  byte mac[6];
  
  // print your MAC address:
  WiFi.macAddress(mac);
  for (int i=0; i<6; i++)
    {
        Tmp.concat(print2HEX(mac[i])) ;
    }
    Tmp.toUpperCase() ;
  return Tmp ;
}



String  print2HEX(int number) {
  String ttt ;
  if (number >= 0 && number < 16)
  {
    ttt = String("0") + String(number,HEX);
  }
  else
  {
      ttt = String(number,HEX);
  }
  return ttt ;
}



void initAll()
{
    Serial.begin(9600);
     Serial2.begin(9600, SERIAL_8N1, RXD2, TXD2);
  Serial.println("System Start") ;  
  
  

 // initialize the lcd 

  // check for the presence of the shield:
  if (WiFi.status() == WL_NO_SHIELD) {
    Serial.println("WiFi shield not present");
    // don't continue:
  }
 
}
