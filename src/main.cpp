#include <Arduino.h>
#include "Vars.h"




//#endif                                                    




void setup() 
{

  Serial.begin(115200);



  while (!Serial);
  Serial.println("CAN Receiver");
  // start the CAN bus at some KBPS blah blah blah
  if (!CAN.begin(500E3))        // 500 KBPS in this case lol
  {
    Serial.println("Starting CAN failed!");       // Failover add more Action sthan just Serial Callback
    while (1);
  }
  else
  {  CAN_Detected = true;}


//Detect_All_hardware();
//
//Setup_SIM800();
//timeout;
//
//ping_MQTT_Home_Server();
//Get_Key();
//eeprom.write(Port, Keys, Other U_AUTH Tokens);
 
 
 
 // Initialize MCP2515 running at 16MHz with a baudrate of 500kb/s and the masks and filters disabled.
  if(CAN0.begin(MCP_ANY, CAN_500KBPS, MCP_16MHZ) == CAN_OK)
    Serial.println("MCP2515 Initialized Successfully!");
  else
    Serial.println("Error Initializing MCP2515...");

  CAN0.setMode(MCP_NORMAL);                     // Set operation mode to normal so the MCP2515 sends acks to received data.

  pinMode(CAN0_INT, INPUT);
  



  SerialMon.println("Wait...");             // GSM Intitialization 
  // Set GSM module baud rate
  TinyGsmAutoBaud(SerialAT, GSM_AUTOBAUD_MIN, GSM_AUTOBAUD_MAX);                    // @BUG 
                                                                                    // @markup 
  // SerialAT.begin(9600);
  delay(6000);

  // Restart takes quite some time
  // To skip it, call init() instead of restart()
  SerialMon.println("Initializing modem...");
  modem.restart();
  // modem.init();

  String modemInfo = modem.getModemInfo();
  SerialMon.print("Modem Info: ");
  SerialMon.println(modemInfo);

#if TINY_GSM_USE_GPRS
  // Unlock your SIM card with a PIN if needed
  if (GSM_PIN && modem.getSimStatus() != 3) { modem.simUnlock(GSM_PIN); }
#endif



}





void loop() {

if (CAN_Detected || GSM_Detected ) 
  {
    HW_Dependencies_Checkout = true;
  }



if(HW_Dependencies_Checkout)
  {
    ping_server(); 
    // DIscover CAN devices, 
    // Read() CAN messages, get CAN_Id
    //ASK CAN for data ( store in Strings,)
    //Filter Out Valid Packets and  
    Send_GPRS();
  }

Post_String  = (read_CAN()) ;
                                                                    // Add a ESP-Deepsleep From  Flag@GSM800 

// Post_String will be retrieved from the GPRS Code, to be sent in a HTTP content Body, Add a Parser to Infuse NMEA and CAN Data in a 255 CHar Message
Send_GPRS();


}