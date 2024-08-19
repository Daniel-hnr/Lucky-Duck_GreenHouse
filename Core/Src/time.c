#include "time.h"

RTC_TimeTypeDef get_time() {
	RTC_TimeTypeDef gTime = {0};
	RTC_DateTypeDef gDate = {0};

	HAL_RTC_GetTime(&hrtc, &gTime, RTC_FORMAT_BIN);
	HAL_RTC_GetDate(&hrtc, &gDate, RTC_FORMAT_BIN);
	return gTime;
}

