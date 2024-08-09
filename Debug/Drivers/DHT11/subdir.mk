################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/DHT11/mk_dht11.c 

OBJS += \
./Drivers/DHT11/mk_dht11.o 

C_DEPS += \
./Drivers/DHT11/mk_dht11.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/DHT11/%.o Drivers/DHT11/%.su Drivers/DHT11/%.cyclo: ../Drivers/DHT11/%.c Drivers/DHT11/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xC -c -I../Core/Inc -I"/home/jamse-web/Code/Lucky-Duck_GreenHouse/Drivers/DHT11" -I"/home/jamse-web/Code/Lucky-Duck_GreenHouse/Drivers/SSD1306" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-DHT11

clean-Drivers-2f-DHT11:
	-$(RM) ./Drivers/DHT11/mk_dht11.cyclo ./Drivers/DHT11/mk_dht11.d ./Drivers/DHT11/mk_dht11.o ./Drivers/DHT11/mk_dht11.su

.PHONY: clean-Drivers-2f-DHT11

