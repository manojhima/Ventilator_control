################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Ventilator/GENERAL/Average.c \
../src/Ventilator/GENERAL/CRC16_TableCompute.c \
../src/Ventilator/GENERAL/DRV_Temperature_WaitEndTransmit.c \
../src/Ventilator/GENERAL/Saturation.c \
../src/Ventilator/GENERAL/lsqrt.c 

OBJS += \
./src/Ventilator/GENERAL/Average.o \
./src/Ventilator/GENERAL/CRC16_TableCompute.o \
./src/Ventilator/GENERAL/DRV_Temperature_WaitEndTransmit.o \
./src/Ventilator/GENERAL/Saturation.o \
./src/Ventilator/GENERAL/lsqrt.o 

C_DEPS += \
./src/Ventilator/GENERAL/Average.d \
./src/Ventilator/GENERAL/CRC16_TableCompute.d \
./src/Ventilator/GENERAL/DRV_Temperature_WaitEndTransmit.d \
./src/Ventilator/GENERAL/Saturation.d \
./src/Ventilator/GENERAL/lsqrt.d 


# Each subdirectory must supply rules for building sources it contributes
src/Ventilator/GENERAL/%.o: ../src/Ventilator/GENERAL/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mthumb -mfloat-abi=soft -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


