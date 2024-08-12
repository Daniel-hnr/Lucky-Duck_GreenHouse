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
	int set_val_min,set_val_max;
};

extern int set_l;
extern char menu[30];
extern ADC_HandleTypeDef hadc1;
extern I2C_HandleTypeDef hi2c1;
extern struct info temp;
extern struct info light;
extern char state;

uint8_t page = 0;
void main_show() {
	get_temp_humidity();
	HAL_Delay(10);
	ssd1306_SetCursor(0, 1);
	ssd1306_Fill(Black);
	menu[0] = '\0';
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
	if (state == menu_state) {
		// menu
		switch (page) {
		// temp min
		case 0:
			get_temp_humidity();
			ssd1306_Fill(Black);
			ssd1306_SetCursor(0, 0);
			menu[0] = '\0';
			sprintf(menu, "%s min", temp.infoName);
			ssd1306_WriteString(menu, Font_7x10, White);
			menu[0] = '\0';
			sprintf(menu, "val:%-3d|v:%-3d", dht.temperature, temp.set_val_min);
			ssd1306_SetCursor(0, 14);
			ssd1306_WriteString(menu, Font_7x10, White);

			if (HAL_GPIO_ReadPin(btn1_GPIO_Port, btn1_Pin) == false) {
				temp.set_val_min -= 1;
				while (HAL_GPIO_ReadPin(btn1_GPIO_Port, btn1_Pin) == false)
					;
			} else if (HAL_GPIO_ReadPin(btn3_GPIO_Port, btn3_Pin) == false) {
				temp.set_val_min += 1;
				while (HAL_GPIO_ReadPin(btn3_GPIO_Port, btn3_Pin) == false)
					;
			}
			break;
			// light min
		case 1:
			ssd1306_Fill(Black);
			ssd1306_SetCursor(0, 0);
			menu[0] = '\0';
			sprintf(menu, "%s min", light.infoName);
			ssd1306_WriteString(menu, Font_7x10, White);
			menu[0] = '\0';
			sprintf(menu, "val:%-3d|v:%-3d", get_light(), light.set_val_min);
			ssd1306_SetCursor(0, 14);
			ssd1306_WriteString(menu, Font_7x10, White);

			if (HAL_GPIO_ReadPin(btn1_GPIO_Port, btn1_Pin) == false) {
				light.set_val_min -= 1;
				while (HAL_GPIO_ReadPin(btn1_GPIO_Port, btn1_Pin) == false)
					;
			} else if (HAL_GPIO_ReadPin(btn3_GPIO_Port, btn3_Pin) == false) {
				light.set_val_min += 1;
				while (HAL_GPIO_ReadPin(btn3_GPIO_Port, btn3_Pin) == false)
					;
			}
			break;
			// temp max
		case 2:
			get_temp_humidity();
			ssd1306_Fill(Black);
			ssd1306_SetCursor(0, 0);
			menu[0] = '\0';
			sprintf(menu, "%s max", temp.infoName);
			ssd1306_WriteString(menu, Font_7x10, White);
			menu[0] = '\0';
			sprintf(menu, "val:%-3d|v:%-3d", dht.temperature, temp.set_val_max);
			ssd1306_SetCursor(0, 14);
			ssd1306_WriteString(menu, Font_7x10, White);

			if (HAL_GPIO_ReadPin(btn1_GPIO_Port, btn1_Pin) == false) {
				temp.set_val_max -= 1;
				while (HAL_GPIO_ReadPin(btn1_GPIO_Port, btn1_Pin) == false)
					;
			} else if (HAL_GPIO_ReadPin(btn3_GPIO_Port, btn3_Pin) == false) {
				temp.set_val_max += 1;
				while (HAL_GPIO_ReadPin(btn3_GPIO_Port, btn3_Pin) == false)
					;
			}
			break;
			// light max
		case 3:
			ssd1306_Fill(Black);
			ssd1306_SetCursor(0, 0);
			menu[0] = '\0';
			sprintf(menu, "%s max", light.infoName);
			ssd1306_WriteString(menu, Font_7x10, White);
			menu[0] = '\0';
			sprintf(menu, "val:%-3d|v:%-3d", get_light(), light.set_val_max);
			ssd1306_SetCursor(0, 14);
			ssd1306_WriteString(menu, Font_7x10, White);

			if (HAL_GPIO_ReadPin(btn1_GPIO_Port, btn1_Pin) == false) {
				light.set_val_max -= 1;
				while (HAL_GPIO_ReadPin(btn1_GPIO_Port, btn1_Pin) == false)
					;
			} else if (HAL_GPIO_ReadPin(btn3_GPIO_Port, btn3_Pin) == false) {
				light.set_val_max += 1;
				while (HAL_GPIO_ReadPin(btn3_GPIO_Port, btn3_Pin) == false)
					;
			}
			break;
		}

		// menu control
		if (HAL_GPIO_ReadPin(btn6_GPIO_Port, btn6_Pin) == false) {
			if (page != 3)
				page++;
			else
				page = 0;
		} else if (HAL_GPIO_ReadPin(btn4_GPIO_Port, btn4_Pin) == false) {
			if (page != 0)
				page--;
			else
				page = 3;
		}
		HAL_Delay(10);
	}

}

