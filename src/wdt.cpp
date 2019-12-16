/**
* Agentuino SNMP Agent Library Prototyping...
*
* Copyright 2010 Eric C. Gionet <lavco_eg@hotmail.com>
*
* Update snmpGetNext by Petr Domorazek <petr@domorazek.cz>
*/

#include "wdt.h"
#include "IWatchdog.h"
#include "config.h"

static uint32_t timeout;

uint8_t wdt_init(void){

    /* Enable Watchdog*/
    IWatchdog.begin(WDT_HARDWARE_TIMEOUT * 1000);
    if (IWatchdog.isReset()) Serial.println("IWatchdog.isReset");
    IWatchdog.clearReset();
    IWatchdog.reload();

    timeout = millis() + WDT_REQUEST_TIMEOUT;

    return 0;
}

uint8_t wdt_reset_request(void){
    timeout = millis() + WDT_REQUEST_TIMEOUT;
}

uint8_t wdt_job(void){
    
    if (timeout < millis()){
        Serial.println("Programm Reset");
        delay(500);
        NVIC_SystemReset();
    }

    IWatchdog.reload();
    
    return 0;
}