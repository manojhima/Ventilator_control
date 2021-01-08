################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Ventilation/src/CPAP_SETTINGS/DB_IHM_Setting_Adjust_Cpap_Mode.c \
../Ventilation/src/CPAP_SETTINGS/DB_IHM_Setting_Adjust_Cpap_Mode_Apnea_Time.c \
../Ventilation/src/CPAP_SETTINGS/DB_IHM_Setting_Adjust_Cpap_Mode_Disco_Delay.c \
../Ventilation/src/CPAP_SETTINGS/DB_IHM_Setting_Adjust_Cpap_Mode_High_Leak.c \
../Ventilation/src/CPAP_SETTINGS/DB_IHM_Setting_Adjust_Cpap_Mode_High_R.c \
../Ventilation/src/CPAP_SETTINGS/DB_IHM_Setting_Adjust_Cpap_Mode_High_Vti.c \
../Ventilation/src/CPAP_SETTINGS/DB_IHM_Setting_Adjust_Cpap_Mode_Low_Vti.c \
../Ventilation/src/CPAP_SETTINGS/DB_IHM_Setting_Adjust_Cpap_Mode_Peep.c 

OBJS += \
./Ventilation/src/CPAP_SETTINGS/DB_IHM_Setting_Adjust_Cpap_Mode.o \
./Ventilation/src/CPAP_SETTINGS/DB_IHM_Setting_Adjust_Cpap_Mode_Apnea_Time.o \
./Ventilation/src/CPAP_SETTINGS/DB_IHM_Setting_Adjust_Cpap_Mode_Disco_Delay.o \
./Ventilation/src/CPAP_SETTINGS/DB_IHM_Setting_Adjust_Cpap_Mode_High_Leak.o \
./Ventilation/src/CPAP_SETTINGS/DB_IHM_Setting_Adjust_Cpap_Mode_High_R.o \
./Ventilation/src/CPAP_SETTINGS/DB_IHM_Setting_Adjust_Cpap_Mode_High_Vti.o \
./Ventilation/src/CPAP_SETTINGS/DB_IHM_Setting_Adjust_Cpap_Mode_Low_Vti.o \
./Ventilation/src/CPAP_SETTINGS/DB_IHM_Setting_Adjust_Cpap_Mode_Peep.o 

C_DEPS += \
./Ventilation/src/CPAP_SETTINGS/DB_IHM_Setting_Adjust_Cpap_Mode.d \
./Ventilation/src/CPAP_SETTINGS/DB_IHM_Setting_Adjust_Cpap_Mode_Apnea_Time.d \
./Ventilation/src/CPAP_SETTINGS/DB_IHM_Setting_Adjust_Cpap_Mode_Disco_Delay.d \
./Ventilation/src/CPAP_SETTINGS/DB_IHM_Setting_Adjust_Cpap_Mode_High_Leak.d \
./Ventilation/src/CPAP_SETTINGS/DB_IHM_Setting_Adjust_Cpap_Mode_High_R.d \
./Ventilation/src/CPAP_SETTINGS/DB_IHM_Setting_Adjust_Cpap_Mode_High_Vti.d \
./Ventilation/src/CPAP_SETTINGS/DB_IHM_Setting_Adjust_Cpap_Mode_Low_Vti.d \
./Ventilation/src/CPAP_SETTINGS/DB_IHM_Setting_Adjust_Cpap_Mode_Peep.d 


# Each subdirectory must supply rules for building sources it contributes
Ventilation/src/CPAP_SETTINGS/%.o: ../Ventilation/src/CPAP_SETTINGS/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DSTM32 -DSTM32F4 -DSTM32F446RETx -DNUCLEO_F446RE -DDEBUG -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/GENERAL" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/SECURITY" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/CPAP_SETTINGS" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/USB_SETTINGS" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/COMPUTE" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/CYCLES" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/SYSTEM" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/DISPLAY" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/SET_UP" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/DATABASE" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/ACTUATOR" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/VENTILATION" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/TIMERS" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/DATABASE_SETTINGS" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/MAIN" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/SCHEDULER" -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


