################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Ventilator/DRIVERS_COM/DRV_COM_Launch.c \
../src/Ventilator/DRIVERS_COM/DRV_COM_Read_Buffer.c \
../src/Ventilator/DRIVERS_COM/DRV_COM_Read_Eeprom.c \
../src/Ventilator/DRIVERS_COM/DRV_COM_Ready.c \
../src/Ventilator/DRIVERS_COM/DRV_COM_Receive_Database.c \
../src/Ventilator/DRIVERS_COM/DRV_COM_Receive_ID.c \
../src/Ventilator/DRIVERS_COM/DRV_COM_Receive_Machine_Counter.c \
../src/Ventilator/DRIVERS_COM/DRV_COM_Transmit_Database.c \
../src/Ventilator/DRIVERS_COM/DRV_COM_Transmit_Detailled.c \
../src/Ventilator/DRIVERS_COM/DRV_COM_Transmit_ID.c \
../src/Ventilator/DRIVERS_COM/DRV_COM_Transmit_Machine_Counter.c \
../src/Ventilator/DRIVERS_COM/DRV_COM_Transmit_Monitoring.c \
../src/Ventilator/DRIVERS_COM/DRV_COM_Transmit_Monitoring_To_Key.c \
../src/Ventilator/DRIVERS_COM/DRV_COM_Transmit_Retrieval.c \
../src/Ventilator/DRIVERS_COM/DRV_COM_Transmit_Settings.c \
../src/Ventilator/DRIVERS_COM/DRV_COM_Transmit_TaskMeasure.c \
../src/Ventilator/DRIVERS_COM/DRV_COM_Transmit_TaskMeasureResetMaximum.c \
../src/Ventilator/DRIVERS_COM/DRV_COM_Transmit_Trend.c \
../src/Ventilator/DRIVERS_COM/DRV_COM_Treatment_Buffer.c 

OBJS += \
./src/Ventilator/DRIVERS_COM/DRV_COM_Launch.o \
./src/Ventilator/DRIVERS_COM/DRV_COM_Read_Buffer.o \
./src/Ventilator/DRIVERS_COM/DRV_COM_Read_Eeprom.o \
./src/Ventilator/DRIVERS_COM/DRV_COM_Ready.o \
./src/Ventilator/DRIVERS_COM/DRV_COM_Receive_Database.o \
./src/Ventilator/DRIVERS_COM/DRV_COM_Receive_ID.o \
./src/Ventilator/DRIVERS_COM/DRV_COM_Receive_Machine_Counter.o \
./src/Ventilator/DRIVERS_COM/DRV_COM_Transmit_Database.o \
./src/Ventilator/DRIVERS_COM/DRV_COM_Transmit_Detailled.o \
./src/Ventilator/DRIVERS_COM/DRV_COM_Transmit_ID.o \
./src/Ventilator/DRIVERS_COM/DRV_COM_Transmit_Machine_Counter.o \
./src/Ventilator/DRIVERS_COM/DRV_COM_Transmit_Monitoring.o \
./src/Ventilator/DRIVERS_COM/DRV_COM_Transmit_Monitoring_To_Key.o \
./src/Ventilator/DRIVERS_COM/DRV_COM_Transmit_Retrieval.o \
./src/Ventilator/DRIVERS_COM/DRV_COM_Transmit_Settings.o \
./src/Ventilator/DRIVERS_COM/DRV_COM_Transmit_TaskMeasure.o \
./src/Ventilator/DRIVERS_COM/DRV_COM_Transmit_TaskMeasureResetMaximum.o \
./src/Ventilator/DRIVERS_COM/DRV_COM_Transmit_Trend.o \
./src/Ventilator/DRIVERS_COM/DRV_COM_Treatment_Buffer.o 

C_DEPS += \
./src/Ventilator/DRIVERS_COM/DRV_COM_Launch.d \
./src/Ventilator/DRIVERS_COM/DRV_COM_Read_Buffer.d \
./src/Ventilator/DRIVERS_COM/DRV_COM_Read_Eeprom.d \
./src/Ventilator/DRIVERS_COM/DRV_COM_Ready.d \
./src/Ventilator/DRIVERS_COM/DRV_COM_Receive_Database.d \
./src/Ventilator/DRIVERS_COM/DRV_COM_Receive_ID.d \
./src/Ventilator/DRIVERS_COM/DRV_COM_Receive_Machine_Counter.d \
./src/Ventilator/DRIVERS_COM/DRV_COM_Transmit_Database.d \
./src/Ventilator/DRIVERS_COM/DRV_COM_Transmit_Detailled.d \
./src/Ventilator/DRIVERS_COM/DRV_COM_Transmit_ID.d \
./src/Ventilator/DRIVERS_COM/DRV_COM_Transmit_Machine_Counter.d \
./src/Ventilator/DRIVERS_COM/DRV_COM_Transmit_Monitoring.d \
./src/Ventilator/DRIVERS_COM/DRV_COM_Transmit_Monitoring_To_Key.d \
./src/Ventilator/DRIVERS_COM/DRV_COM_Transmit_Retrieval.d \
./src/Ventilator/DRIVERS_COM/DRV_COM_Transmit_Settings.d \
./src/Ventilator/DRIVERS_COM/DRV_COM_Transmit_TaskMeasure.d \
./src/Ventilator/DRIVERS_COM/DRV_COM_Transmit_TaskMeasureResetMaximum.d \
./src/Ventilator/DRIVERS_COM/DRV_COM_Transmit_Trend.d \
./src/Ventilator/DRIVERS_COM/DRV_COM_Treatment_Buffer.d 


# Each subdirectory must supply rules for building sources it contributes
src/Ventilator/DRIVERS_COM/%.o: ../src/Ventilator/DRIVERS_COM/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mthumb -mfloat-abi=soft -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


