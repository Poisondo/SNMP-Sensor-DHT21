#include <Arduino.h>
#include "read_dht.h"
#include "ethernet.h"
#include "snmp.h"
#include "web_server.h"
#include "wdt.h"
#include "read_hw.h"


void setup()
{
  
  Serial.begin(115200);

  wdt_init();

  Serial.println("Start");
  
  dht_init ();

  hw_init ();

  ethernet_init_default();
 
}

void loop()
{
  static uint32_t prevMillis = 0;
  static dht_read_t dht_read_r = {0}; 
  static hw_read_t hw_read_r = {0}; 

  //tic 1000ms
  if ( prevMillis < millis() ) {

    prevMillis = millis() + 1000;
    dht_read(&dht_read_r);
    hw_read(&hw_read_r);
    snmp_set_params(&dht_read_r, &hw_read_r);
    //web_server_set_params(&dht_read_r);
    Serial.println("hw_dht_read");
    if (hw_read_r.hw_1) Serial.println("hw_1 true");
    if (hw_read_r.hw_2) Serial.println("hw_2 true");
  }

  ethernet_job();
  wdt_job();
}



