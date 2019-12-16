/**
  ******************************************************************************
  * @file           : ethernet.h
  * @brief          : Header for ethernet.c file.
  *                   This file contains the common defines of the application.
  * 
  * @author Dyakonov Oleg <o.u.dyakonov@gmail.com>
  ******************************************************************************
  */

#ifndef __ETHERNET_H
#define __ETHERNET_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stdint.h"
#include "config.h"


// /**
//  * @brief структура конфигурации ethernet
//  *
//  * @note Call etyhernet_init(ethernet_config_t *config);
//  */
typedef struct {
    uint8_t mac[6];        /**< MAC адрес */
    uint8_t ip[4];         /**< IP адрес */
    uint8_t dns[4];        /**< DNS адрес */
    uint8_t gateway[4];    /**< шлюз */
    uint8_t subnet[4];     /**< маска */
} ethernet_config_t;

/**
 * @brief Инициализация
 * 
 * @return возвращает код ошибки, если все хорошо то 0
 *
 */
uint8_t ethernet_init_default(void);
uint8_t ethernet_init(ethernet_config_t *config);



/**
 * @brief работа изернет
 * 
 * @return возвращает код ошибки, если все хорошо то 0
 * 
 */
uint8_t ethernet_job(void);

#ifdef __cplusplus
}
#endif

#endif /* __ETHERNET_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
