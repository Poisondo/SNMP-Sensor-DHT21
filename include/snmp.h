/**
  ******************************************************************************
  * @file           : snmp.h
  * @brief          : Header for snmp.c file.
  *                   This file contains the common defines of the application.
  * 
  * @author Dyakonov Oleg <o.u.dyakonov@gmail.com>
  ******************************************************************************
  */

#ifndef __SNMP_H
#define __SNMP_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stdint.h"
#include "config.h"
#include "read_dht.h"
#include "read_hw.h"

/**
 * @brief Инициализация
 * 
 * @return возвращает код ошибки, если все хорошо то 0
 *
 */
uint8_t snmp_init(void);

/**
 * @brief работа протокола snmp
 * 
 * @return возвращает код ошибки, если все хорошо то 0
 * 
 */
uint8_t snmp_job(void);

uint8_t snmp_set_params (dht_read_t *dht_read_r, hw_read_t *hw_read_r);

#ifdef __cplusplus
}
#endif

#endif /* __SNMP_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
