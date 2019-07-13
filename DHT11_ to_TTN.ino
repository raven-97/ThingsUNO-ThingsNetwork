

#include <DHT.h>
#include <DHT_U.h>



#include <TheThingsNetwork.h>


// Set your DevAddr, NwkSKey, AppSKey and the frequency plan

const char *devAddr = "";    //insert values here
const char *nwkSKey = "";    // insert values here
const char *appSKey = "";    // insert values here


#define loraSerial Serial1
#define debugSerial Serial

// Replace REPLACE_ME with TTN_FP_EU868 or TTN_FP_US915
#define freqPlan TTN_FP_IN865_867  //default value for India


DHT dht(2,DHT11);
TheThingsNetwork ttn(loraSerial, debugSerial, freqPlan);

void setup()
{
  loraSerial.begin(57600);
  debugSerial.begin(9600);
  
  
  

  // Wait a maximum of 10s for Serial Monitor
  while (!debugSerial && millis() < 10000)
    ;

  debugSerial.println("-- PERSONALIZE");
  ttn.personalize(devAddr, nwkSKey, appSKey);

  debugSerial.println("-- STATUS");
  ttn.showStatus();
  
  
  dht.begin();
}

void loop()
{
  debugSerial.println("-- LOOP");

   /*Prepare payload of 1 byte to indicate LED status
  float humidity =dht.readHumidity(false);
  float temperature = dht.readTemperature(false);

  debugSerial.println("Humidity: "+ String(humidity));
  debugSerial.println("Temperature: "+ String(temperature));
  */
  uint32_t humidity =dht.readHumidity(false)*100;
  uint32_t temperature = dht.readTemperature(false)*100;
  byte payload[4];
  payload[0] =highByte(humidity);
  payload[1] =lowByte(humidity);
  payload[2] =highByte(temperature);
  payload[3] =lowByte(temperature);

  ttn.sendBytes(payload,sizeof(payload));
  
  
  

  delay(10000);
}
