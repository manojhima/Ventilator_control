################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Ventilator/HMI/HMI_IhmType.c 

OBJS += \
./src/Ventilator/HMI/HMI_IhmType.o 

C_DEPS += \
./src/Ventilator/HMI/HMI_IhmType.d 


# Each subdirectory must supply rules for building sources it contributes
src/Ventilator/HMI/%.o: ../src/Ventilator/HMI/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mthumb -mfloat-abi=soft -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


