################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Ventilator/CPAP_SETTINGS/DB_IHM_Setting_Adjust_Cpap_Mode.c \
../src/Ventilator/CPAP_SETTINGS/DB_IHM_Setting_Adjust_Cpap_Mode_Apnea_Time.c \
../src/Ventilator/CPAP_SETTINGS/DB_IHM_Setting_Adjust_Cpap_Mode_Disco_Delay.c \
../src/Ventilator/CPAP_SETTINGS/DB_IHM_Setting_Adjust_Cpap_Mode_High_Leak.c \
../src/Ventilator/CPAP_SETTINGS/DB_IHM_Setting_Adjust_Cpap_Mode_High_R.c \
../src/Ventilator/CPAP_SETTINGS/DB_IHM_Setting_Adjust_Cpap_Mode_High_Vti.c \
../src/Ventilator/CPAP_SETTINGS/DB_IHM_Setting_Adjust_Cpap_Mode_Low_Vti.c \
../src/Ventilator/CPAP_SETTINGS/DB_IHM_Setting_Adjust_Cpap_Mode_Peep.c \
../src/Ventilator/CPAP_SETTINGS/DB_IHM_Write_Adjust_Cpap_Mode.c \
../src/Ventilator/CPAP_SETTINGS/DB_IHM_Write_Adjust_Cpap_Mode_Disco_Delay.c \
../src/Ventilator/CPAP_SETTINGS/DB_IHM_Write_Adjust_Cpap_Mode_High_Vti.c \
../src/Ventilator/CPAP_SETTINGS/DB_IHM_Write_Adjust_Cpap_Mode_Low_Vti.c 

OBJS += \
./src/Ventilator/CPAP_SETTINGS/DB_IHM_Setting_Adjust_Cpap_Mode.o \
./src/Ventilator/CPAP_SETTINGS/DB_IHM_Setting_Adjust_Cpap_Mode_Apnea_Time.o \
./src/Ventilator/CPAP_SETTINGS/DB_IHM_Setting_Adjust_Cpap_Mode_Disco_Delay.o \
./src/Ventilator/CPAP_SETTINGS/DB_IHM_Setting_Adjust_Cpap_Mode_High_Leak.o \
./src/Ventilator/CPAP_SETTINGS/DB_IHM_Setting_Adjust_Cpap_Mode_High_R.o \
./src/Ventilator/CPAP_SETTINGS/DB_IHM_Setting_Adjust_Cpap_Mode_High_Vti.o \
./src/Ventilator/CPAP_SETTINGS/DB_IHM_Setting_Adjust_Cpap_Mode_Low_Vti.o \
./src/Ventilator/CPAP_SETTINGS/DB_IHM_Setting_Adjust_Cpap_Mode_Peep.o \
./src/Ventilator/CPAP_SETTINGS/DB_IHM_Write_Adjust_Cpap_Mode.o \
./src/Ventilator/CPAP_SETTINGS/DB_IHM_Write_Adjust_Cpap_Mode_Disco_Delay.o \
./src/Ventilator/CPAP_SETTINGS/DB_IHM_Write_Adjust_Cpap_Mode_High_Vti.o \
./src/Ventilator/CPAP_SETTINGS/DB_IHM_Write_Adjust_Cpap_Mode_Low_Vti.o 

C_DEPS += \
./src/Ventilator/CPAP_SETTINGS/DB_IHM_Setting_Adjust_Cpap_Mode.d \
./src/Ventilator/CPAP_SETTINGS/DB_IHM_Setting_Adjust_Cpap_Mode_Apnea_Time.d \
./src/Ventilator/CPAP_SETTINGS/DB_IHM_Setting_Adjust_Cpap_Mode_Disco_Delay.d \
./src/Ventilator/CPAP_SETTINGS/DB_IHM_Setting_Adjust_Cpap_Mode_High_Leak.d \
./src/Ventilator/CPAP_SETTINGS/DB_IHM_Setting_Adjust_Cpap_Mode_High_R.d \
./src/Ventilator/CPAP_SETTINGS/DB_IHM_Setting_Adjust_Cpap_Mode_High_Vti.d \
./src/Ventilator/CPAP_SETTINGS/DB_IHM_Setting_Adjust_Cpap_Mode_Low_Vti.d \
./src/Ventilator/CPAP_SETTINGS/DB_IHM_Setting_Adjust_Cpap_Mode_Peep.d \
./src/Ventilator/CPAP_SETTINGS/DB_IHM_Write_Adjust_Cpap_Mode.d \
./src/Ventilator/CPAP_SETTINGS/DB_IHM_Write_Adjust_Cpap_Mode_Disco_Delay.d \
./src/Ventilator/CPAP_SETTINGS/DB_IHM_Write_Adjust_Cpap_Mode_High_Vti.d \
./src/Ventilator/CPAP_SETTINGS/DB_IHM_Write_Adjust_Cpap_Mode_Low_Vti.d 


# Each subdirectory must supply rules for building sources it contributes
src/Ventilator/CPAP_SETTINGS/%.o: ../src/Ventilator/CPAP_SETTINGS/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mthumb -mfloat-abi=soft -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


