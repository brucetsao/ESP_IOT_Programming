    /////////////////////////////////////////////////////////////////
   //         ESP32 Internet Radio Project     v1.1               //
  //       Get the latest version of the code here:              //
 //          http://educ8s.tv/esp32-internet-radio              //
/////////////////////////////////////////////////////////////////

#include <VS1053.h>  //https://github.com/baldram/ESP_VS1053_Library
#include <WiFi.h>
#include <HTTPClient.h>
#include <esp_wifi.h>
#include <EEPROM.h>

#define VS1053_CS    32 
#define VS1053_DCS   33  
#define VS1053_DREQ  35 

#define VOLUME  100 // volume level 0-100
#define EEPROM_SIZE 2


long interval = 1000; 
int SECONDS_TO_AUTOSAVE = 30;
long seconds = 0;
long previousMillis = 0; 

int radioStation = 0;
int previousRadioStation = -1;
const int previousButton = 12;
const int nextButton = 13;

char ssid[] = "yourSSID";            //  your network SSID (name) 
char pass[] = "yourPassword";       // your network password

// Few Radio Stations
char *host[4] = {"149.255.59.162","radiostreaming.ert.gr","realfm.live24.gr", "secure1.live24.gr"};
char *path[4] = {"/1","/ert-kosmos","/realfm","/skai1003"};
int   port[4] = {8062,80,80,80};

int status = WL_IDLE_STATUS;
WiFiClient  client;
uint8_t mp3buff[32];   // vs1053 likes 32 bytes at a time

VS1053 player(VS1053_CS, VS1053_DCS, VS1053_DREQ);

void IRAM_ATTR previousButtonInterrupt() {

  static unsigned long last_interrupt_time = 0;
  unsigned long interrupt_time = millis();
 
 if (interrupt_time - last_interrupt_time > 200) 
 {
   if(radioStation>0)
    radioStation--;
    else
    radioStation = 3;
 }
 last_interrupt_time = interrupt_time;
}

void IRAM_ATTR nextButtonInterrupt() {

  static unsigned long last_interrupt_time = 0;
  unsigned long interrupt_time = millis();
 
 if (interrupt_time - last_interrupt_time > 200) 
 {
   if(radioStation<4)
    radioStation++;
    else
    radioStation = 0;
 }
 last_interrupt_time = interrupt_time;
}

void setup () {

   Serial.begin(9600);
   delay(500);
   SPI.begin();

   EEPROM.begin(EEPROM_SIZE);

   pinMode(previousButton, INPUT_PULLUP);
   pinMode(nextButton, INPUT_PULLUP);

   attachInterrupt(digitalPinToInterrupt(previousButton), previousButtonInterrupt, FALLING);
   attachInterrupt(digitalPinToInterrupt(nextButton), nextButtonInterrupt, FALLING);

   initMP3Decoder();

   connectToWIFI();

   radioStation = readStationFromEEPROM();
}

void loop() {

    unsigned long currentMillis = millis();
    if(currentMillis - previousMillis > interval) 
    {
    if(radioStation!=previousRadioStation)
    {
      station_connect(radioStation);
      previousRadioStation = radioStation;
      seconds = 0;
    }else
    {
      seconds++;
      if(seconds == SECONDS_TO_AUTOSAVE)
      {
          int readStation = readStationFromEEPROM();
          if(readStation!=radioStation)
          {
            Serial.println("loop(): Saving new station to EEPROM");
            writeStationToEEPROM(&radioStation);
          }
      }
    }
    previousMillis = currentMillis; 
    Serial.println("loop(): "+String(seconds) +" "+String(radioStation));  
  }
     
      if (client.available() > 0)
      {
        uint8_t bytesread = client.read(mp3buff, 32);
        player.playChunk(mp3buff, bytesread);
      }
}    
  
void station_connect (int station_no ) {
    if (client.connect(host[station_no],port[station_no]) ) Serial.println("Connected now"); 
    client.print(String("GET ") + path[station_no] + " HTTP/1.1\r\n" +
               "Host: " + host[station_no] + "\r\n" + 
               "Connection: close\r\n\r\n");   
                 endNextionCommand(); 
                 drawRadioStationName(station_no);
                 endNextionCommand();
  }

  void connectToWIFI()
  {
    WiFi.begin(ssid, pass);
      while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
   }
   Serial.println("WiFi connected");
  }

  void initMP3Decoder()
  {
    player.begin();
    player.switchToMp3Mode(); // optional, some boards require this
    player.setVolume(VOLUME);
  }

  void endNextionCommand()
{
  Serial.write(0xff);
  Serial.write(0xff);
  Serial.write(0xff);
}

void drawRadioStationName(int id)
{
  String command;
  switch (id)  
  {
    case 0:  command = "p1.pic=2"; Serial.print(command); endNextionCommand(); break; //1940 UK Radio
    case 1:  command = "p1.pic=3"; Serial.print(command); endNextionCommand(); break; //KOSMOS     GREEK
    case 2:  command = "p1.pic=4"; Serial.print(command); endNextionCommand(); break; //REAL FM    GREEK
    case 3:  command = "p1.pic=5"; Serial.print(command); endNextionCommand(); break; //SKAI 100.3 GREEK
  }
}

int readStationFromEEPROM()
{
  int station;
  byte ByteArray[2];
  for(int x = 0; x < 2; x++)
  {
   ByteArray[x] = EEPROM.read(x);    
  }
  memcpy(&station, ByteArray, 2);
  Serial.println("readFrequencyFromEEPROM(): "+String(station));
  return station;
}

void writeStationToEEPROM(int *freq)
{
 byte ByteArray[2];
 memcpy(ByteArray, freq, 2);
 for(int x = 0; x < 2; x++)
 {
   EEPROM.write(x, ByteArray[x]);
 }  
 EEPROM.commit();
 Serial.println("writeFrequencyFromEEPROM(): "+String(radioStation));
}


void IRAM_ATTR resetModule(){
   // ets_printf("reboot\n");
    //esp_restart();
}
