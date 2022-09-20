
#include <CAN.h>
#include "mcp_can.h"
#include <SPI.h>

#define SerialMon Serial
#define TINY_GSM_MODEM_SIM800
// 
#define GSM_PIN ""


#define CAN0_INT 2                              // Set INT to pin 2
MCP_CAN CAN0(10); 


//Standard NATIVE ESP32 CAN driver
bool CAN_Detected;
bool GSM_Detected;
bool HW_Dependencies_Checkout;
String Post_String = {};
String CAN_ID;



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


#include "TinyGsmClient.h"
#include "ArduinoHttpClient.h"





//#endif                                                    
#define SerialAT Serial2    
#include <SoftwareSerial.h>                                   // HW PIn definition for Software Serial device  for used as UART2 
SoftwareSerial SerialAT(2, 3);                                // RX, TX
#if !defined(TINY_GSM_RX_BUFFER)
#define TINY_GSM_RX_BUFFER 650
#endif
#define TINY_GSM_DEBUG SerialMon
#define GSM_AUTOBAUD_MIN 9600
#define GSM_AUTOBAUD_MAX 115200
#define TINY_GSM_USE_GPRS true
#define TINY_GSM_USE_WIFI false

































#include <Functs.h>