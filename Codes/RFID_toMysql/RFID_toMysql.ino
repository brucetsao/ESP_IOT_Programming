#include "arduino_secrets.h"

#include <WiFi.h>
//---------------
//--- RFID LIB
#include <SPI.h>
#include <MFRC522.h>   
MFRC522 mfrc522(RST_PIN);  // 建立MFRC522物件
//MFRC522 mfrc522(SS_PIN, RST_PIN);  // 建立MFRC522物件
  IPAddress ip ;
  long rssi ;
  
int status = WL_IDLE_STATUS;
char iotserver[] = "192.168.99.200";    // name address for Google (using DNS)
int iotport = 80 ;
// Initialize the Ethernet client library
// with the IP address and port of the server
// that you want to connect to (port 80 is default for HTTP):
String strGet="GET /iot03/work/dataadd.php";
String strHttp=" HTTP/1.1";
String strHost="Host: 192.168.99.200";  //OK
 String connectstr ;
WiFiClient client;
 boolean isopen = false ;

long Carno = 0 ;
String CarNumber = "";
String MacData ;
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3f,20,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display

#define relaypin 4
void setup() 
{
  //Initialize serial and wait for port to open:
    initAll() ;


  Serial.println("System  Ready");

}

void loop()   
{
    if (ReadCard())
      {
          Serial.print("Received RFID Card:(") ;
          Serial.print(CarNumber) ;
          Serial.print(")\n") ;
          if (CheckKey(CarNumber))
            {
                isopen = true ;
                ShowData();
                OpenDoor() ;
                SendtoNAS() ;
            }   
            else
            {
                isopen = false ;
                ShowData();
                SendtoNAS() ;
            }   
            
                
          
      }

    delay(100) ;
} // END Loop


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
    pinMode(relaypin,OUTPUT) ;
    digitalWrite(relaypin,LOW) ;
    Serial.begin(9600);
    Serial.println("System Start") ;  
   SPI.begin();
  mfrc522.PCD_Init();   
  
   Serial.println("RFID Reader is OK!!!") ; 
  lcd.init();                      // initialize the lcd 
  // Print a message to the LCD.
  lcd.backlight();
  lcd.setCursor(0,0);

 // initialize the lcd 


  // check for the presence of the shield:
  if (WiFi.status() == WL_NO_SHIELD) {
    Serial.println("WiFi shield not present");
    // don't continue:
  }
}









boolean ReadCard()
{
   long st1 = millis() ;
   while( (millis() - st1) < 1500)
    {
       Carno = ReadRFID() ;
      if (Carno != 0)
        {
            CarNumber = strzero(Carno,10,10) ;
          //  Serial.print("RFID NUMBER:(") ;
          //  Serial.print(CarNumber) ;
          //  Serial.print(")\n") ;

            return true ;
        }
    }
    return false ;
}

long ReadRFID()
{
  long tmp = 0 ;
  
    if (mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial())
      {
      byte *id = mfrc522.uid.uidByte;   // 取得卡片的UID
      byte idSize = mfrc522.uid.size;   // 取得UID的長度

     // Serial.print("PICC type: ");      // 顯示卡片類型
      // 根據卡片回應的SAK值（mfrc522.uid.sak）判斷卡片類型
      MFRC522::PICC_Type piccType = mfrc522.PICC_GetType(mfrc522.uid.sak);
   //   Serial.println(mfrc522.PICC_GetTypeName(piccType));

   //   Serial.print("UID Size: ");       // 顯示卡片的UID長度值
  //    Serial.println(idSize);

      /*
      for (byte i = 0; i < idSize; i++) {  // 逐一顯示UID碼
        Serial.print("id[");
        Serial.print(i);
        Serial.print("]: ");
        Serial.println(id[i], HEX);       // 以16進位顯示UID值
      }
      Serial.println();
      */
       tmp = id[3]* 16777216+ id[2]* 65536+id[1]* 256+id[0] ;       

      mfrc522.PICC_HaltA();  // 讓卡片進入停止模式
  } 
    
  return tmp ;
}


void ShowInternet()
{
    Serial.print("MAC:") ;
    Serial.print(MacData) ;
    Serial.print("\n") ;
    ShowMAC() ;
    ShowIP()  ;
}

void ShowLCDR1(String gg)
{
  lcd.setCursor(0,0);
  lcd.print("                    ");  
  lcd.setCursor(0,0);
  lcd.print(gg);  
}

void ShowMAC()
{
  lcd.setCursor(0,0);
  lcd.print("MAC:");  
  lcd.print(MacData);  

}
void ShowIP()
{
  lcd.setCursor(0,1);
  lcd.print("IP:");  
  lcd.print(ip);  

}



void Show1(String ss)
{
  lcd.setCursor(0,2);
  lcd.print("                    ");  
  lcd.setCursor(0,2);
  lcd.print(ss);  
}

void Show2(String ss)
{
  lcd.setCursor(0,3);
  lcd.print("                    ");  
  lcd.setCursor(0,3);
  lcd.print(ss);  
}

String SPACE(int sp)
{
    String tmp = "" ;
    for (int i = 0 ; i < sp; i++)
      {
          tmp.concat(' ')  ;
      }
    return tmp ;
}


String strzero(long num, int len, int base)
{
  String retstring = String("");
  int ln = 1 ;
    int i = 0 ; 
    char tmp[10] ;
    long tmpnum = num ;
    int tmpchr = 0 ;
    char hexcode[]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'} ;
    while (ln <= len)
    {
        tmpchr = (int)(tmpnum % base) ;
        tmp[ln-1] = hexcode[tmpchr] ;
        ln++ ;
         tmpnum = (long)(tmpnum/base) ;
 
        
    }
    for (i = len-1; i >= 0 ; i --)
      {
          retstring.concat(tmp[i]);
      }
    
  return retstring;
}

unsigned long unstrzero(String hexstr, int base)
{
  String chkstring  ;
  int len = hexstr.length() ;
  
    unsigned int i = 0 ;
    unsigned int tmp = 0 ;
    unsigned int tmp1 = 0 ;
    unsigned long tmpnum = 0 ;
    String hexcode = String("0123456789ABCDEF") ;
    for (i = 0 ; i < (len ) ; i++)
    {
  //     chkstring= hexstr.substring(i,i) ; 
      hexstr.toUpperCase() ;
           tmp = hexstr.charAt(i) ;   // give i th char and return this char
           tmp1 = hexcode.indexOf(tmp) ;
      tmpnum = tmpnum + tmp1* POW(base,(len -i -1) )  ;
 
        
    }
  return tmpnum;
}

long POW(long num, int expo)
{
  long tmp =1 ;
  if (expo > 0)
  { 
        for(int i = 0 ; i< expo ; i++)
          tmp = tmp * num ;
         return tmp ; 
  } 
  else
  {
   return tmp ; 
  }
}

void SendtoNAS()
{
  int tmp = 0 ;
  if (isopen) 
    {
        tmp = 1 ;
    }
     else
    {
        tmp = 9 ;
    }
      
              //http://iot.nhri.org.tw/headtemp/headtempadd.php?mac=aabbccddeeff&usrid=0123456789&temperature=33.65
        //INSERT INTO headtemptbl (mac, userid,datatime,dateorder,headtemp) VALUES ('aabbccddeeff','0123456789','2019/08/14 21:37:48','20190814213748',33.65)
            
          
          connectstr = "?MAC="+MacData+"&open="+String(tmp);
         Serial.println(connectstr) ;
         if (client.connect(iotserver, iotport)) {
                 Serial.println("Make a HTTP request ... ");
                 //### Send to Server
                 String strHttpGet = strGet + connectstr + strHttp;
                 Serial.println(strHttpGet);
     
                 client.println(strHttpGet);
                 client.println(strHost);
                 client.println();
               } 
    
      if (client.connected()) 
      { 
        client.stop();  // DISCONNECT FROM THE SERVER
      }

    
}


void ShowData()
{

  
  Serial.print("Card:");    
  Serial.println(CarNumber);  
  lcd.setCursor(0,2);
  lcd.print("                    ");  
  lcd.setCursor(0,2);
  lcd.print("Card:");    
  lcd.print(CarNumber);    
  lcd.setCursor(0,3);
 if (isopen)
  {
      lcd.print("Open Door");  
     Serial.print("Open Door"); 
  }
  else
  {
      lcd.print("Access Deny");  
       Serial.print("Access Deny"); 
  }
  
  
 
}
//--------------------
boolean CheckKey(String kk)
{
 
    for (int i = 0 ; i <3 ; i++)
        {
            if (Key[i] ==kk)
              {
                  return true ;
              }
        }
   return false ;        
}
void OpenDoor()
{
      digitalWrite(relaypin,HIGH) ;
      delay(1000) ;
      digitalWrite(relaypin,LOW) ;
      
}
