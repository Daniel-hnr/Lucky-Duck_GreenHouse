#ifndef INC_SENSORS_H_
#define INC_SENSORS_H_

#include "main.h"
#include "ssd1306.h"
#include "ssd1306_fonts.h"
#include <stdio.h>
#include <stdbool.h>
#include "mk_dht11.h"

extern ADC_HandleTypeDef hadc1;
extern I2C_HandleTypeDef hi2c1;
extern TIM_HandleTypeDef htim2;
extern dht11_t dht;


void get_temp_humidity();
int get_light();
void delay(int us);

#endif /* INC_SENSORS_H_ */
