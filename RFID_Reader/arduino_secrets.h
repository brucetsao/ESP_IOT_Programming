#include <String.h>

char cmd ;
char Oledchar[30] ;

#define RST_PIN     27        // 讀卡機的重置腳位
#define SS_PIN       5        // 晶片選擇腳位
String NumberChar = String("0123456789.") ;
