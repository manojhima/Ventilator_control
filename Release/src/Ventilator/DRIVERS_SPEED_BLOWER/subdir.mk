################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Ventilator/DRIVERS_SPEED_BLOWER/DRV_SPEED_LaunchingSpeedBlowerMeasure.c 

OBJS += \
./src/Ventilator/DRIVERS_SPEED_BLOWER/DRV_SPEED_LaunchingSpeedBlowerMeasure.o 

C_DEPS += \
./src/Ventilator/DRIVERS_SPEED_BLOWER/DRV_SPEED_LaunchingSpeedBlowerMeasure.d 


# Each subdirectory must supply rules for building sources it contributes
src/Ventilator/DRIVERS_SPEED_BLOWER/%.o: ../src/Ventilator/DRIVERS_SPEED_BLOWER/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mthumb -mfloat-abi=soft -O3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


