/**
  ******************************************************************************
  * @file           : read_hw.h
  * @brief          : Header for read_hw.c file.
  *                   This file contains the common defines of the application.
  * 
  * @author Dyakonov Oleg <o.u.dyakonov@gmail.com>
  ******************************************************************************
  */

#ifndef __READ_HW_H
#define __READ_HW_H

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
  bool     hw_1;        /**< протечка 1 датчик */
  bool     hw_2;        /**< протечка 2 датчик */  
} hw_read_t;

/**
 * @brief Инициализация
 * 
 * @return возвращает код ошибки, если все хорошо то 0
 *
 */
uint8_t hw_init(void);

/**
 * @brief чтение значений с датчика
 * 
 * @param read структуру hw_read_t, прочитанные значения
 * 
 * @return возвращает код ошибки, если все хорошо то 0
 * 
 */
uint8_t hw_read(hw_read_t *read);

#ifdef __cplusplus
}
#endif

#endif /* __READ_HW_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
