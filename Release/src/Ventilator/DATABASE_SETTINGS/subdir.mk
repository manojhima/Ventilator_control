################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Ventilator/DATABASE_SETTINGS/DB_IHM_Decrease_Access.c \
../src/Ventilator/DATABASE_SETTINGS/DB_IHM_Decrease_Config.c \
../src/Ventilator/DATABASE_SETTINGS/DB_IHM_Increase_Access.c \
../src/Ventilator/DATABASE_SETTINGS/DB_IHM_Increase_Config.c \
../src/Ventilator/DATABASE_SETTINGS/DB_IHM_Read_Access.c \
../src/Ventilator/DATABASE_SETTINGS/DB_IHM_Read_Info_Access.c \
../src/Ventilator/DATABASE_SETTINGS/DB_IHM_Write_Access.c \
../src/Ventilator/DATABASE_SETTINGS/DB_IHM_Write_Info_Access.c \
../src/Ventilator/DATABASE_SETTINGS/DB_IhmAccessParaDataBase.c 

OBJS += \
./src/Ventilator/DATABASE_SETTINGS/DB_IHM_Decrease_Access.o \
./src/Ventilator/DATABASE_SETTINGS/DB_IHM_Decrease_Config.o \
./src/Ventilator/DATABASE_SETTINGS/DB_IHM_Increase_Access.o \
./src/Ventilator/DATABASE_SETTINGS/DB_IHM_Increase_Config.o \
./src/Ventilator/DATABASE_SETTINGS/DB_IHM_Read_Access.o \
./src/Ventilator/DATABASE_SETTINGS/DB_IHM_Read_Info_Access.o \
./src/Ventilator/DATABASE_SETTINGS/DB_IHM_Write_Access.o \
./src/Ventilator/DATABASE_SETTINGS/DB_IHM_Write_Info_Access.o \
./src/Ventilator/DATABASE_SETTINGS/DB_IhmAccessParaDataBase.o 

C_DEPS += \
./src/Ventilator/DATABASE_SETTINGS/DB_IHM_Decrease_Access.d \
./src/Ventilator/DATABASE_SETTINGS/DB_IHM_Decrease_Config.d \
./src/Ventilator/DATABASE_SETTINGS/DB_IHM_Increase_Access.d \
./src/Ventilator/DATABASE_SETTINGS/DB_IHM_Increase_Config.d \
./src/Ventilator/DATABASE_SETTINGS/DB_IHM_Read_Access.d \
./src/Ventilator/DATABASE_SETTINGS/DB_IHM_Read_Info_Access.d \
./src/Ventilator/DATABASE_SETTINGS/DB_IHM_Write_Access.d \
./src/Ventilator/DATABASE_SETTINGS/DB_IHM_Write_Info_Access.d \
./src/Ventilator/DATABASE_SETTINGS/DB_IhmAccessParaDataBase.d 


# Each subdirectory must supply rules for building sources it contributes
src/Ventilator/DATABASE_SETTINGS/%.o: ../src/Ventilator/DATABASE_SETTINGS/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mthumb -mfloat-abi=soft -O3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


