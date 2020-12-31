################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Ventilation/src/DATABASE/DB_AlarmInfoWrite.c \
../Ventilation/src/DATABASE/DB_AlarmStatusWrite.c \
../Ventilation/src/DATABASE/DB_ComputeRead.c \
../Ventilation/src/DATABASE/DB_ComputeWrite.c \
../Ventilation/src/DATABASE/DB_ConfigRead.c \
../Ventilation/src/DATABASE/DB_ConfigWrite.c \
../Ventilation/src/DATABASE/DB_ControlRead.c \
../Ventilation/src/DATABASE/DB_ControlWrite.c \
../Ventilation/src/DATABASE/DB_CurrentRead.c \
../Ventilation/src/DATABASE/DB_EventMngt.c \
../Ventilation/src/DATABASE/DB_RTCRead.c \
../Ventilation/src/DATABASE/DB_RTCWrite.c \
../Ventilation/src/DATABASE/DB_StartInitDb.c \
../Ventilation/src/DATABASE/DB_TrendWrite.c 

OBJS += \
./Ventilation/src/DATABASE/DB_AlarmInfoWrite.o \
./Ventilation/src/DATABASE/DB_AlarmStatusWrite.o \
./Ventilation/src/DATABASE/DB_ComputeRead.o \
./Ventilation/src/DATABASE/DB_ComputeWrite.o \
./Ventilation/src/DATABASE/DB_ConfigRead.o \
./Ventilation/src/DATABASE/DB_ConfigWrite.o \
./Ventilation/src/DATABASE/DB_ControlRead.o \
./Ventilation/src/DATABASE/DB_ControlWrite.o \
./Ventilation/src/DATABASE/DB_CurrentRead.o \
./Ventilation/src/DATABASE/DB_EventMngt.o \
./Ventilation/src/DATABASE/DB_RTCRead.o \
./Ventilation/src/DATABASE/DB_RTCWrite.o \
./Ventilation/src/DATABASE/DB_StartInitDb.o \
./Ventilation/src/DATABASE/DB_TrendWrite.o 

C_DEPS += \
./Ventilation/src/DATABASE/DB_AlarmInfoWrite.d \
./Ventilation/src/DATABASE/DB_AlarmStatusWrite.d \
./Ventilation/src/DATABASE/DB_ComputeRead.d \
./Ventilation/src/DATABASE/DB_ComputeWrite.d \
./Ventilation/src/DATABASE/DB_ConfigRead.d \
./Ventilation/src/DATABASE/DB_ConfigWrite.d \
./Ventilation/src/DATABASE/DB_ControlRead.d \
./Ventilation/src/DATABASE/DB_ControlWrite.d \
./Ventilation/src/DATABASE/DB_CurrentRead.d \
./Ventilation/src/DATABASE/DB_EventMngt.d \
./Ventilation/src/DATABASE/DB_RTCRead.d \
./Ventilation/src/DATABASE/DB_RTCWrite.d \
./Ventilation/src/DATABASE/DB_StartInitDb.d \
./Ventilation/src/DATABASE/DB_TrendWrite.d 


# Each subdirectory must supply rules for building sources it contributes
Ventilation/src/DATABASE/%.o: ../Ventilation/src/DATABASE/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DSTM32 -DSTM32F4 -DSTM32F446RETx -DNUCLEO_F446RE -DDEBUG -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/DATABASE" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/ACTUATOR" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/VENTILATION" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/TIMERS" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/DATABASE_SETTINGS" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/GENERAL" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/MAIN" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/SCHEDULER" -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


