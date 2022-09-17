#include <Vars.h>




void ping_server()
{


}




String read_CAN()
{
      // try to parse packet
  int packetSize = CAN.parsePacket();
  if (packetSize) 
  {
    // received a packet
    Serial.print("Received CAN packet  ");
    if (CAN.packetExtended()) 
    {
      Serial.print("CAN_Packet_extended ");
    }
    if (CAN.packetRtr()) 
    {
      // Remote transmission request, packet contains no data
      Serial.print("RTR ");
    }
    Serial.print("packet with id 0x");
    Serial.print(CAN.packetId(), HEX);                                          // Hexadecimal CAN ID, use it to Ping server with a 
    if (CAN.packetRtr()) {
      Serial.print(" and requested length ");
      Serial.println(CAN.packetDlc());
    } else {
      Serial.print(" and length ");
      Serial.println(packetSize);
      // only print packet data for non-RTR packets
      while (CAN.available()) {
        Serial.print((char)CAN.read());
      }
      Serial.println();
    }
    Serial.println();
  }
 return 
}