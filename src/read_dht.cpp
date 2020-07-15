/**
  ******************************************************************************
  * @file           : read_dht.c
  * 
  * @author Dyakonov Oleg <o.u.dyakonov@gmail.com>
  ******************************************************************************
  */

#include "read_dht.h"
#include "config.h"
#include "DHT.h"

DHT dht(DHT_PIN, DHT_TYPE);

uint8_t dht_init(void){
  dht.begin();
    return 0;
}

uint8_t dht_read(dht_read_t *read){
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  if (isnan(h) || isnan(t)){
    return 1;
  }
  float hic = dht.computeHeatIndex(t, h, false);
  read->dht_temperature = t;
  read->dht_humidity = h;
  read->dht_hic = hic;
  return 0;
}
