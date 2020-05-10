################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Ventilator/EEPROM/EEP_FIFO_FreeFirstData.c \
../src/Ventilator/EEPROM/EEP_FIFO_PullFirstData.c \
../src/Ventilator/EEPROM/EEP_FIFO_PushOneData.c \
../src/Ventilator/EEPROM/EEP_FIFO_ReadNbDataStored.c 

OBJS += \
./src/Ventilator/EEPROM/EEP_FIFO_FreeFirstData.o \
./src/Ventilator/EEPROM/EEP_FIFO_PullFirstData.o \
./src/Ventilator/EEPROM/EEP_FIFO_PushOneData.o \
./src/Ventilator/EEPROM/EEP_FIFO_ReadNbDataStored.o 

C_DEPS += \
./src/Ventilator/EEPROM/EEP_FIFO_FreeFirstData.d \
./src/Ventilator/EEPROM/EEP_FIFO_PullFirstData.d \
./src/Ventilator/EEPROM/EEP_FIFO_PushOneData.d \
./src/Ventilator/EEPROM/EEP_FIFO_ReadNbDataStored.d 


# Each subdirectory must supply rules for building sources it contributes
src/Ventilator/EEPROM/%.o: ../src/Ventilator/EEPROM/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mthumb -mfloat-abi=soft -O3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


