#include "sensors.h"



void get_temp_humidity() {
	readDHT11(&dht);
}

int get_light() {
	return HAL_ADC_GetValue(&hadc1);
}

void delay(int us) {
	int x = 0;
	HAL_TIM_Base_Start(&htim2);
	__HAL_TIM_SET_COUNTER(&htim2, 0);
	while (x < us) {
		x = __HAL_TIM_GET_COUNTER(&htim2);
	}
	HAL_TIM_Base_Stop(&htim2);
}


