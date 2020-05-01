################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Ventilator/CONFIG_SETTINGS/DB_IHM_Setting_Config_Adjust_Fio2.c \
../src/Ventilator/CONFIG_SETTINGS/DB_IHM_Setting_Config_Adjust_High_Fio2.c \
../src/Ventilator/CONFIG_SETTINGS/DB_IHM_Setting_Config_Adjust_High_Spo2.c \
../src/Ventilator/CONFIG_SETTINGS/DB_IHM_Setting_Config_Adjust_Low_Fio2.c \
../src/Ventilator/CONFIG_SETTINGS/DB_IHM_Setting_Config_Adjust_Low_Spo2.c \
../src/Ventilator/CONFIG_SETTINGS/DB_IHM_Setting_Config_Adjust_Mode.c \
../src/Ventilator/CONFIG_SETTINGS/DB_IHM_Setting_Config_Adjust_Mode_S2.c \
../src/Ventilator/CONFIG_SETTINGS/DB_IHM_Write_Config_Adjust_Fio2.c 

OBJS += \
./src/Ventilator/CONFIG_SETTINGS/DB_IHM_Setting_Config_Adjust_Fio2.o \
./src/Ventilator/CONFIG_SETTINGS/DB_IHM_Setting_Config_Adjust_High_Fio2.o \
./src/Ventilator/CONFIG_SETTINGS/DB_IHM_Setting_Config_Adjust_High_Spo2.o \
./src/Ventilator/CONFIG_SETTINGS/DB_IHM_Setting_Config_Adjust_Low_Fio2.o \
./src/Ventilator/CONFIG_SETTINGS/DB_IHM_Setting_Config_Adjust_Low_Spo2.o \
./src/Ventilator/CONFIG_SETTINGS/DB_IHM_Setting_Config_Adjust_Mode.o \
./src/Ventilator/CONFIG_SETTINGS/DB_IHM_Setting_Config_Adjust_Mode_S2.o \
./src/Ventilator/CONFIG_SETTINGS/DB_IHM_Write_Config_Adjust_Fio2.o 

C_DEPS += \
./src/Ventilator/CONFIG_SETTINGS/DB_IHM_Setting_Config_Adjust_Fio2.d \
./src/Ventilator/CONFIG_SETTINGS/DB_IHM_Setting_Config_Adjust_High_Fio2.d \
./src/Ventilator/CONFIG_SETTINGS/DB_IHM_Setting_Config_Adjust_High_Spo2.d \
./src/Ventilator/CONFIG_SETTINGS/DB_IHM_Setting_Config_Adjust_Low_Fio2.d \
./src/Ventilator/CONFIG_SETTINGS/DB_IHM_Setting_Config_Adjust_Low_Spo2.d \
./src/Ventilator/CONFIG_SETTINGS/DB_IHM_Setting_Config_Adjust_Mode.d \
./src/Ventilator/CONFIG_SETTINGS/DB_IHM_Setting_Config_Adjust_Mode_S2.d \
./src/Ventilator/CONFIG_SETTINGS/DB_IHM_Write_Config_Adjust_Fio2.d 


# Each subdirectory must supply rules for building sources it contributes
src/Ventilator/CONFIG_SETTINGS/%.o: ../src/Ventilator/CONFIG_SETTINGS/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mthumb -mfloat-abi=soft -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


