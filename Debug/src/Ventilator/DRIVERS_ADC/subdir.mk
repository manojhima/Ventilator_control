################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Ventilator/DRIVERS_ADC/DRV_ADC_ChannelConvert.c \
../src/Ventilator/DRIVERS_ADC/DRV_ADC_ConvertInit.c 

OBJS += \
./src/Ventilator/DRIVERS_ADC/DRV_ADC_ChannelConvert.o \
./src/Ventilator/DRIVERS_ADC/DRV_ADC_ConvertInit.o 

C_DEPS += \
./src/Ventilator/DRIVERS_ADC/DRV_ADC_ChannelConvert.d \
./src/Ventilator/DRIVERS_ADC/DRV_ADC_ConvertInit.d 


# Each subdirectory must supply rules for building sources it contributes
src/Ventilator/DRIVERS_ADC/%.o: ../src/Ventilator/DRIVERS_ADC/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mthumb -mfloat-abi=soft -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


