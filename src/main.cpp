#include <Arduino.h>
#include "Vars.h"

#include <CAN.h>

#include "mcp_can.h"
#include <SPI.h>



#define CAN0_INT 2                              // Set INT to pin 2
MCP_CAN CAN0(10); 

void setup() {

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
  
}


#include <Functs.h>


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

  }










}