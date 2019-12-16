#include <Arduino.h>
#include "read_dht.h"
#include "ethernet.h"
#include "snmp.h"
#include "web_server.h"
#include "wdt.h"


void setup()
{
  
  Serial.begin(115200);

  wdt_init();

  Serial.println("Start");
  
  dht_init ();

  ethernet_init_default();
 
}

void loop()
{
  static uint32_t prevMillis = 0;
  static dht_read_t dht_read_r; 

  //tic 1000ms
  if ( prevMillis < millis() ) {

    prevMillis = millis() + 1000;

    dht_read(&dht_read_r);
    snmp_set_params(&dht_read_r);
    web_server_set_params(&dht_read_r);

    Serial.println("dht_read");
  }

  ethernet_job();
  wdt_job();
}



