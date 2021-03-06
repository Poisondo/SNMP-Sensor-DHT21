/**
  ******************************************************************************
  * @file           : config.h
  * @brief          : Конфигурация 
  ******************************************************************************
  */

#ifndef __CONFIG_H
#define __CONFIG_H

#ifdef __cplusplus
extern "C" {
#endif
//датчик температуры и влажности
#define DHT_PIN     PB0
//#define DHT_TYPE    DHT21   // DHT 21 (AM2301)
#define DHT_TYPE    DHT11   // DHT 21 (AM2301)
//датчики протечки
#define HW_1_PIN    PA2
#define HW_2_PIN    PA3


#define ETHERNET_MAC     0xDE,0xAD,0xBE,0xEF,0xFE,0xED
#define ETHERNET_IP      192,168,35,200
#define ETHERNET_DNS     192,168,35,16
#define ETHERNET_GATEWAY 192,168,35,1
#define ETHERNET_SUBNET  255,255,255,0

// #define ETHERNET_IP      192,168,41,51
// #define ETHERNET_DNS     192,168,35,16
// #define ETHERNET_GATEWAY 192,168,41,1
// #define ETHERNET_SUBNET  255,255,255,0

#define SNMP_LOC_DESCR          "Server room monitoring"
#define SNMP_LOC_CONTACT        "Oleg Dyakonov"
#define SNMP_LOC_NAME           "Sensor DHT"
#define SNMP_LOC_LOCATION       "Russia"


#define WEB_SERVER_PORT 80
#define WEB_SERVER_TITLE "Серверная комната 7-этаж"


#define WDT_HARDWARE_TIMEOUT 2000
#define WDT_REQUEST_TIMEOUT 70000

#ifdef __cplusplus
}
#endif

#endif /* __CONFIG_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
