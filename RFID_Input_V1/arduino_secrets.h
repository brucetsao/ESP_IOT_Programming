#include <String.h>
#define PowerLedPin 4
#define BlueLedPin 0
#define RXD2 16
#define TXD2 17


char Oledchar[30] ;
const char* AP1     = "NCNU" ;
const char* PW1 = "12345678";
const char* AP2     = "abc" ;
const char* PW2 = "12345678";
#define maxfeekbacktime 5000

char cmd ;


#define RST_PIN     27        // 讀卡機的重置腳位
#define SS_PIN       5        // 晶片選擇腳位
String NumberChar = String("0123456789.") ;
