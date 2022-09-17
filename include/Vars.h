bool CAN_Detected;
bool GSM_Detected;
bool HW_Dependencies_Checkout;


//   THE MCP CAN VARS
long unsigned int rxId;
unsigned char len = 0;
unsigned char rxBuf[8];
char msgString[128];  