/**
  ******************************************************************************
  * @file           : wdt.h
  * @brief          : Header for wdt.c file.
  *                   This file contains the common defines of the application.
  * 
  * @author Dyakonov Oleg <o.u.dyakonov@gmail.com>
  ******************************************************************************
  */

#ifndef __WDT_H
#define __WDT_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stdint.h"
#include "config.h"
#include "read_dht.h"

/**
 * @brief Инициализация
 * 
 * @return возвращает код ошибки, если все хорошо то 0
 *
 */
uint8_t wdt_init(void);

/**
 * @brief работа сторожевого таймера
 * 
 * @return возвращает код ошибки, если все хорошо то 0
 * 
 */
uint8_t wdt_job(void);

/**
 * @brief сброс таймера
 * 
 * @return возвращает код ошибки, если все хорошо то 0
 * 
 */
uint8_t wdt_reset_request(void);

#ifdef __cplusplus
}
#endif

#endif /* __WDT_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
