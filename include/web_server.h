/**
  ******************************************************************************
  * @file           : web_server.h
  * @brief          : Header for web_server.c file.
  *                   This file contains the common defines of the application.
  * 
  * @author Dyakonov Oleg <o.u.dyakonov@gmail.com>
  ******************************************************************************
  */

#ifndef __WEB_SERVER_H
#define __WEB_SERVER_H

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
uint8_t web_server_init(void);



/**
 * @brief работа изернет
 * 
 * @return возвращает код ошибки, если все хорошо то 0
 * 
 */
uint8_t web_server_job(void);

/**
 * @brief установить температуру
 * 
 * @return возвращает код ошибки, если все хорошо то 0
 * 
 */
uint8_t web_server_set_params(dht_read_t *dht_read_r);


#ifdef __cplusplus
}
#endif

#endif /* __WEB_SERVER_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
