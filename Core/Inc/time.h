/*
 * time.h
 *
 *  Created on: Aug 19, 2024
 *      Author: james-web
 */

#ifndef INC_TIME_H_
#define INC_TIME_H_

#include "main.h"
#include "ssd1306.h"
#include "ssd1306_fonts.h"
#include <stdio.h>
#include <stdbool.h>
#include "sensors.h"

extern RTC_HandleTypeDef hrtc;


RTC_TimeTypeDef get_time();

#endif /* INC_TIME_H_ */
