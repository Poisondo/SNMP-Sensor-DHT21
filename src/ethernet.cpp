/**
* Agentuino SNMP Agent Library Prototyping...
*
* Copyright 2010 Eric C. Gionet <lavco_eg@hotmail.com>
*
* Update snmpGetNext by Petr Domorazek <petr@domorazek.cz>
*/

#include <UIPEthernet.h>       // Include the Ethernet library
#include <SPI.h>
#include "config.h"
#include "ethernet.h"
#include "snmp.h"
//#include "web_server.h"


uint8_t ethernet_init_default(){

    ethernet_config_t ethernet_config = {
        .mac     = { ETHERNET_MAC },
        .ip      = { ETHERNET_IP },
        .dns     = { ETHERNET_DNS },
        .gateway = { ETHERNET_GATEWAY },
        .subnet  = { ETHERNET_SUBNET }
    };
    return ethernet_init(&ethernet_config);
}

uint8_t ethernet_init(ethernet_config_t *config){

    Ethernet.begin(config->mac, config->ip, config->dns, config->gateway, config->subnet);
    snmp_init();
    //web_server_init();
    return 0;
}

uint8_t ethernet_job(){
  
  snmp_job();
  //web_server_job();
  return 0;
}