#include "main.h"
#include "ssd1306.h"
#include "ssd1306_fonts.h"
#include <stdio.h>
#include <stdbool.h>
#include "sensors.h"

#define work_state 0
#define menu_state 1

struct info {
	char infoName[18];
	int set_val;
};

extern int set_l;
extern char menu[30];
extern ADC_HandleTypeDef hadc1;
extern I2C_HandleTypeDef hi2c1;
extern struct info temp;
extern struct info light;
extern char state;

bool page = false;
void main_show() {
	get_temp_humidity();
	HAL_Delay(10);
	ssd1306_SetCursor(0, 1);
	ssd1306_Fill(Black);
	sprintf(menu, "temp:%-3dlight:%-3d", dht.temperature, get_light());
	ssd1306_WriteString(menu, Font_7x10, White);
	menu[0] = '\0';
	ssd1306_SetCursor(0, 11);
	sprintf(menu, "humidity:%-3d", dht.humidty);
	ssd1306_WriteString(menu, Font_7x10, White);
	menu[0] = '\0';
	ssd1306_SetCursor(0, 21);
	sprintf(menu, "fans:%-2d", 18);
	ssd1306_WriteString(menu, Font_7x10, White);
	HAL_Delay(10);
}
void menu_show() {
	if(state == menu_state)
	{
		switch (page) {
		case 0:
			get_temp_humidity();
			ssd1306_Fill(Black);
			ssd1306_SetCursor(0, 0);
			ssd1306_WriteString(temp.infoName, Font_7x10, White);
			sprintf(menu, "val:%-3d|v:%-3d", dht.temperature, temp.set_val);
			ssd1306_SetCursor(0, 14);
			ssd1306_WriteString(menu, Font_7x10, White);

			if (HAL_GPIO_ReadPin(btn1_GPIO_Port, btn1_Pin) == false) {
				temp.set_val -= 1;
				while (HAL_GPIO_ReadPin(btn1_GPIO_Port, btn1_Pin) == false)
					;
			} else if (HAL_GPIO_ReadPin(btn3_GPIO_Port, btn3_Pin) == false) {
				temp.set_val += 1;
				while (HAL_GPIO_ReadPin(btn3_GPIO_Port, btn3_Pin) == false)
					;
			}
			break;
		case 1:
			ssd1306_Fill(Black);
			ssd1306_SetCursor(0, 0);
			ssd1306_WriteString(light.infoName, Font_7x10, White);
			sprintf(menu, "val:%-3d|v:%-3d", get_light(), light.set_val);
			ssd1306_SetCursor(0, 14);
			ssd1306_WriteString(menu, Font_7x10, White);

			if (HAL_GPIO_ReadPin(btn1_GPIO_Port, btn1_Pin) == false) {
				light.set_val -= 1;
				while (HAL_GPIO_ReadPin(btn1_GPIO_Port, btn1_Pin) == false)
					;
			} else if (HAL_GPIO_ReadPin(btn3_GPIO_Port, btn3_Pin) == false) {
				light.set_val += 1;
				while (HAL_GPIO_ReadPin(btn3_GPIO_Port, btn3_Pin) == false)
					;
			}
		}
		if(HAL_GPIO_ReadPin(btn6_GPIO_Port, btn6_Pin) == false)
		{
			page = !page;
		}
		else if(HAL_GPIO_ReadPin(btn4_GPIO_Port, btn4_Pin) == false)
		{
			page = !page;
		}
		HAL_Delay(10);
	}

}

