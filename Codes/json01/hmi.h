#define MaxReadStringLength 30
byte  push[] = {0xff,0xff,0xff}; //結束指令
String comma= "\"" ;
String equal= "=" ;
String txttype= ".txt" ;
String numtype= ".val" ;
String bloodmax = "blood1" ;
String bloodmin = "blood1" ;
String heartbeat = "hbr" ;
String bodytemp = "temp1" ;
String headtemp = "temp2" ;
String bodyweight = "wgt" ;
String rfidnum = "t2" ;
String HMTString ;


void SendCommand(String sss)
{
    Serial.print("HMI Command:(") ;
    Serial.print(sss) ;
    Serial.print(")\n") ;
    Serial2.print(sss) ;
    Serial2.write(push,3);
}

void SendStr(String cmd, String cc)
{
    String tmp = cmd+txttype+equal+comma+cc+comma ;
    SendCommand(tmp) ;

}

void Sendint(String cmd, int vv)
{
    String tmp = cmd+numtype+equal+String(vv) ;
    SendCommand(tmp) ;
}

void Sendfloat(String cmd, float vv)
{
    String tmp = cmd+numtype+equal+String((int)(vv*10)) ;
    SendCommand(tmp) ;
}
void ShowmonitorScreen()
{
    SendCommand("page page1") ;
}

void ShowRfidonLCD(String cc)
{
    SendStr(rfidnum,cc) ;
}
void HMILoginIn()
{
 
    SendCommand("page measure") ;
}

void HMILoginOut()
{
 
    SendCommand("page login") ;
}


void HMIStartScreen()
{
 
    SendCommand("page login") ;
}


String ReadHMIString()
{
    String tmp = "" ;
    int count=0 ;
    char cc;
    boolean startread = false ;
    boolean endreadok = false ;
  //MaxReadStringLength
   if (Serial2.available() > 0)
    {

        while(Serial2.available() > 0)  
          {
              count++ ;
              cc = Serial2.read() ;
              if (cc == '@')
                {
                    startread = true ;
                    continue ;
                }   // end of if (cc == '@')
              if (cc == '#')
                {
                    endreadok = true ;
                    break  ;
                }   // end of if (cc == '#')
              if (startread && cc != '#' )
              {
                  tmp.concat(cc);
                  continue ;
              }   // end of if (startread && cc != '#' )
             if ( count >= MaxReadStringLength)
                {
                    break  ;                                    
                }
          }   //  end of while(Serial2.available() > 0) 
 
          if (startread && endreadok)
            {
                return tmp ;
            }
            else
            {
                return "" ;
              
            }
    }     // end of if (Serial2.available() > 0)
                    return "" ;
}
