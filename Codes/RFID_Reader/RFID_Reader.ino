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
 

long Carno = 0 ;
String CarNumber = "";
 String connectstr ;
String MacData ;


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
    Serial.begin(9600);
    Serial.println("System Start") ;  
   SPI.begin();
  mfrc522.PCD_Init();   
  
   Serial.println("RFID Reader is OK!!!") ; 

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


boolean isNumber(String sss)
{
  boolean ck = false ;
  if (sss.length() > 0)
    {
        for(int i = 0 ; i <sss.length() ; i++)
          {
              if (NumberChar.indexOf(sss.substring(i,i+1)) >=0 )
              {
                  return false ;
              }
          }
      // Show1(sss)     ;
       
       return true ;
    }
    else
    {
      return false ;
    }
    
}


 void listNetworks() 
 {
  // scan for nearby networks:
  Serial.println("** Scan Networks **");
    Serial.println("scan start");

    // WiFi.scanNetworks will return the number of networks found
    int n = WiFi.scanNetworks();
    Serial.println("scan done");
    if (n == 0) 
    {
        Serial.println("no networks found");
    } 
    else 
    {
        Serial.print(n);
        Serial.println(" networks found");
        for (int i = 0; i < n; ++i) 
          {
            // Print SSID and RSSI for each network found
            Serial.print(i + 1);
            Serial.print(": ");
            Serial.print(WiFi.SSID(i));
            Serial.print(" (");
            Serial.print(WiFi.RSSI(i));
            Serial.print(")");
            Serial.println((WiFi.encryptionType(i) == WIFI_AUTH_OPEN)?" ":"*");
            delay(10);
        }
    }
    Serial.println("");
}




String chrtoString(char *p)
{
    String tmp ;
    char c ;
    int count = 0 ;
    while (count <100)
    {
        c= *p ;
        if (c != 0x00)
          {
            tmp.concat(String(c)) ;
          }
          else
          {
              return tmp ;
          }
       count++ ;
       p++;
       
    }
}


void CopyString2Char(String ss, char *p)
{
         //  sprintf(p,"%s",ss) ;

  if (ss.length() <=0)
      {
           *p =  0x00 ;
          return ;
      }
    ss.toCharArray(p, ss.length()+1) ;
   // *(p+ss.length()+1) = 0x00 ;
}

boolean CharCompare(char *p, char *q)
  {
      boolean flag = false ;
      int count = 0 ;
      int nomatch = 0 ;
      while (flag <100)
      {
          if (*(p+count) == 0x00 or *(q+count) == 0x00)
            break ;
          if (*(p+count) != *(q+count) )
              {
                 nomatch ++ ; 
              }
             count++ ; 
      }
     if (nomatch >0)
      {
        return false ;
      }
      else
      {
        return true ;
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
    ShowMAC() ;
    ShowIP()  ;
}

void ShowMAC()
{
      CopyString2Char(MacData,Oledchar) ;
    Serial.println(Oledchar) ;
}
void ShowIP()
{
    sprintf(Oledchar, "IP:%d.%d.%d.%d", ip[0], ip[1], ip[2], ip[3] );
    Serial.println(Oledchar) ;


}
