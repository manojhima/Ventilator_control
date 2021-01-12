################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Ventilation/src/CONFIG_SETTINGS/DB_IHM_Setting_Config_Adjust_Fio2.c \
../Ventilation/src/CONFIG_SETTINGS/DB_IHM_Setting_Config_Adjust_High_Fio2.c \
../Ventilation/src/CONFIG_SETTINGS/DB_IHM_Setting_Config_Adjust_High_Spo2.c \
../Ventilation/src/CONFIG_SETTINGS/DB_IHM_Setting_Config_Adjust_Low_Fio2.c \
../Ventilation/src/CONFIG_SETTINGS/DB_IHM_Setting_Config_Adjust_Low_Spo2.c \
../Ventilation/src/CONFIG_SETTINGS/DB_IHM_Setting_Config_Adjust_Mode.c \
../Ventilation/src/CONFIG_SETTINGS/DB_IHM_Setting_Config_Adjust_Mode_S2.c \
../Ventilation/src/CONFIG_SETTINGS/DB_IHM_Write_Config_Adjust_Fio2.c 

OBJS += \
./Ventilation/src/CONFIG_SETTINGS/DB_IHM_Setting_Config_Adjust_Fio2.o \
./Ventilation/src/CONFIG_SETTINGS/DB_IHM_Setting_Config_Adjust_High_Fio2.o \
./Ventilation/src/CONFIG_SETTINGS/DB_IHM_Setting_Config_Adjust_High_Spo2.o \
./Ventilation/src/CONFIG_SETTINGS/DB_IHM_Setting_Config_Adjust_Low_Fio2.o \
./Ventilation/src/CONFIG_SETTINGS/DB_IHM_Setting_Config_Adjust_Low_Spo2.o \
./Ventilation/src/CONFIG_SETTINGS/DB_IHM_Setting_Config_Adjust_Mode.o \
./Ventilation/src/CONFIG_SETTINGS/DB_IHM_Setting_Config_Adjust_Mode_S2.o \
./Ventilation/src/CONFIG_SETTINGS/DB_IHM_Write_Config_Adjust_Fio2.o 

C_DEPS += \
./Ventilation/src/CONFIG_SETTINGS/DB_IHM_Setting_Config_Adjust_Fio2.d \
./Ventilation/src/CONFIG_SETTINGS/DB_IHM_Setting_Config_Adjust_High_Fio2.d \
./Ventilation/src/CONFIG_SETTINGS/DB_IHM_Setting_Config_Adjust_High_Spo2.d \
./Ventilation/src/CONFIG_SETTINGS/DB_IHM_Setting_Config_Adjust_Low_Fio2.d \
./Ventilation/src/CONFIG_SETTINGS/DB_IHM_Setting_Config_Adjust_Low_Spo2.d \
./Ventilation/src/CONFIG_SETTINGS/DB_IHM_Setting_Config_Adjust_Mode.d \
./Ventilation/src/CONFIG_SETTINGS/DB_IHM_Setting_Config_Adjust_Mode_S2.d \
./Ventilation/src/CONFIG_SETTINGS/DB_IHM_Write_Config_Adjust_Fio2.d 


# Each subdirectory must supply rules for building sources it contributes
Ventilation/src/CONFIG_SETTINGS/%.o: ../Ventilation/src/CONFIG_SETTINGS/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DSTM32 -DSTM32F4 -DSTM32F446RETx -DNUCLEO_F446RE -DDEBUG -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/GENERAL" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/SECURITY" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/CPAP_SETTINGS" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/USB_SETTINGS" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/COMPUTE" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/CYCLES" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/SYSTEM" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/DISPLAY" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/SET_UP" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/DATABASE" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/ACTUATOR" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/VENTILATION" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/TIMERS" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/DATABASE_SETTINGS" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/MAIN" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/SCHEDULER" -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


