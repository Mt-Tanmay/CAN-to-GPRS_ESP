bool CAN_Detected;
bool GSM_Detected;
bool HW_Dependencies_Checkout;
String Post_String = {};


//   THE MCP CAN VARS

long unsigned int rxId;
unsigned char len = 0;
unsigned char rxBuf[8];
char msgString[128];  



// Your GPRS credentials, if any
const char apn[]      = "airtelgprs.com";
const char gprsUser[] = "";
const char gprsPass[] = "";

// Your WiFi connection credentials, if applicable
const char wifiSSID[] = "cheap_phone_1";
const char wifiPass[] = "asd111asd";
// Server details
const char server[]   = "https://biggtery.webs.com/";
const char resource[] = "192.168.5.200/TinyGSM/logo.txt";
const int  port       = 80;


#include <TinyGsmClient.h>
#include <ArduinoHttpClient.h>












#include <Functs.h>