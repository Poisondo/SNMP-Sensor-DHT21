/**
  ******************************************************************************
  * @file           : read_dht.h
  * @brief          : Header for read_dht.c file.
  *                   This file contains the common defines of the application.
  * 
  * @author Dyakonov Oleg <o.u.dyakonov@gmail.com>
  ******************************************************************************
  */

#ifndef __READ_DHT_H
#define __READ_DHT_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stdint.h"
#include "config.h"

//----------------------------------PRIVATE--------------------------------------


//----------------------------------PUBLIC-----------------------------------------
/**
 * @brief структура чтения температуры и влажности
 *
 * @note Call dht_read(dht_read_t *raad) 
 */
typedef struct {
  float     dht_temperature;        /**< показание температуры */
  float     dht_humidity;           /**< показания влажности */
  float     dht_hic;                /**< показания относительной температуры */
  
} dht_read_t;

/**
 * @brief Инициализация
 * 
 * @return возвращает код ошибки, если все хорошо то 0
 *
 */
uint8_t dht_init(void);

/**
 * @brief чтение значений с датчика
 * 
 * @param read структуру dht_read_t, прочитанные значения
 * 
 * @return возвращает код ошибки, если все хорошо то 0
 * 
 */
uint8_t dht_read(dht_read_t *read);

#ifdef __cplusplus
}
#endif

#endif /* __READ_DHT_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
