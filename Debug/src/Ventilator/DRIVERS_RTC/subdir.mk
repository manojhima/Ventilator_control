################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Ventilator/DRIVERS_RTC/DRV_RTC_FIFO_FreeFirstData.c \
../src/Ventilator/DRIVERS_RTC/DRV_RTC_FIFO_PullFirstData.c \
../src/Ventilator/DRIVERS_RTC/DRV_RTC_FIFO_PushOneData.c \
../src/Ventilator/DRIVERS_RTC/DRV_RTC_FIFO_ReadNbDataStored.c \
../src/Ventilator/DRIVERS_RTC/DRV_RTC_Launch.c \
../src/Ventilator/DRIVERS_RTC/DRV_RTC_ReadTimeAndDate.c \
../src/Ventilator/DRIVERS_RTC/DRV_RTC_ReadWriteHardwareRTC.c \
../src/Ventilator/DRIVERS_RTC/DRV_RTC_WaitEndTransmit.c \
../src/Ventilator/DRIVERS_RTC/DRV_RTC_WriteTimeAndDate.c \
../src/Ventilator/DRIVERS_RTC/DRV_RTC_control.c \
../src/Ventilator/DRIVERS_RTC/DRV_RTC_tempo_CE.c 

OBJS += \
./src/Ventilator/DRIVERS_RTC/DRV_RTC_FIFO_FreeFirstData.o \
./src/Ventilator/DRIVERS_RTC/DRV_RTC_FIFO_PullFirstData.o \
./src/Ventilator/DRIVERS_RTC/DRV_RTC_FIFO_PushOneData.o \
./src/Ventilator/DRIVERS_RTC/DRV_RTC_FIFO_ReadNbDataStored.o \
./src/Ventilator/DRIVERS_RTC/DRV_RTC_Launch.o \
./src/Ventilator/DRIVERS_RTC/DRV_RTC_ReadTimeAndDate.o \
./src/Ventilator/DRIVERS_RTC/DRV_RTC_ReadWriteHardwareRTC.o \
./src/Ventilator/DRIVERS_RTC/DRV_RTC_WaitEndTransmit.o \
./src/Ventilator/DRIVERS_RTC/DRV_RTC_WriteTimeAndDate.o \
./src/Ventilator/DRIVERS_RTC/DRV_RTC_control.o \
./src/Ventilator/DRIVERS_RTC/DRV_RTC_tempo_CE.o 

C_DEPS += \
./src/Ventilator/DRIVERS_RTC/DRV_RTC_FIFO_FreeFirstData.d \
./src/Ventilator/DRIVERS_RTC/DRV_RTC_FIFO_PullFirstData.d \
./src/Ventilator/DRIVERS_RTC/DRV_RTC_FIFO_PushOneData.d \
./src/Ventilator/DRIVERS_RTC/DRV_RTC_FIFO_ReadNbDataStored.d \
./src/Ventilator/DRIVERS_RTC/DRV_RTC_Launch.d \
./src/Ventilator/DRIVERS_RTC/DRV_RTC_ReadTimeAndDate.d \
./src/Ventilator/DRIVERS_RTC/DRV_RTC_ReadWriteHardwareRTC.d \
./src/Ventilator/DRIVERS_RTC/DRV_RTC_WaitEndTransmit.d \
./src/Ventilator/DRIVERS_RTC/DRV_RTC_WriteTimeAndDate.d \
./src/Ventilator/DRIVERS_RTC/DRV_RTC_control.d \
./src/Ventilator/DRIVERS_RTC/DRV_RTC_tempo_CE.d 


# Each subdirectory must supply rules for building sources it contributes
src/Ventilator/DRIVERS_RTC/%.o: ../src/Ventilator/DRIVERS_RTC/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mthumb -mfloat-abi=soft -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


