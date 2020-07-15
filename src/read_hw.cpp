/**
  ******************************************************************************
  * @file           : read_hw.c
  * 
  * @author Dyakonov Oleg <o.u.dyakonov@gmail.com>
  ******************************************************************************
  */

#include <Arduino.h>

#include "read_hw.h"
#include "config.h"

uint8_t hw_init(void)
{
    pinMode(HW_1_PIN, INPUT_PULLDOWN);
    pinMode(HW_2_PIN, INPUT_PULLDOWN);
    return 0;
}

uint8_t hw_read(hw_read_t *read){
  read->hw_1 = digitalRead(HW_1_PIN);
  read->hw_2 = digitalRead(HW_2_PIN);
  return 0;
}
