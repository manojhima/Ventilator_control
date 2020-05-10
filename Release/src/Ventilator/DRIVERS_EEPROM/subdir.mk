################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Ventilator/DRIVERS_EEPROM/DRV_EEP_Launch.c \
../src/Ventilator/DRIVERS_EEPROM/DRV_EEP_ReadWord.c \
../src/Ventilator/DRIVERS_EEPROM/DRV_EEP_StartWriteWord.c \
../src/Ventilator/DRIVERS_EEPROM/DRV_EEP_WaitEndTransmit.c \
../src/Ventilator/DRIVERS_EEPROM/DRV_EEP_WaitEndWrite.c \
../src/Ventilator/DRIVERS_EEPROM/DRV_EEP_tempo_CE.c 

OBJS += \
./src/Ventilator/DRIVERS_EEPROM/DRV_EEP_Launch.o \
./src/Ventilator/DRIVERS_EEPROM/DRV_EEP_ReadWord.o \
./src/Ventilator/DRIVERS_EEPROM/DRV_EEP_StartWriteWord.o \
./src/Ventilator/DRIVERS_EEPROM/DRV_EEP_WaitEndTransmit.o \
./src/Ventilator/DRIVERS_EEPROM/DRV_EEP_WaitEndWrite.o \
./src/Ventilator/DRIVERS_EEPROM/DRV_EEP_tempo_CE.o 

C_DEPS += \
./src/Ventilator/DRIVERS_EEPROM/DRV_EEP_Launch.d \
./src/Ventilator/DRIVERS_EEPROM/DRV_EEP_ReadWord.d \
./src/Ventilator/DRIVERS_EEPROM/DRV_EEP_StartWriteWord.d \
./src/Ventilator/DRIVERS_EEPROM/DRV_EEP_WaitEndTransmit.d \
./src/Ventilator/DRIVERS_EEPROM/DRV_EEP_WaitEndWrite.d \
./src/Ventilator/DRIVERS_EEPROM/DRV_EEP_tempo_CE.d 


# Each subdirectory must supply rules for building sources it contributes
src/Ventilator/DRIVERS_EEPROM/%.o: ../src/Ventilator/DRIVERS_EEPROM/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mthumb -mfloat-abi=soft -O3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


