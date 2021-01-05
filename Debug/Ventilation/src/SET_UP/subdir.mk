################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Ventilation/src/SET_UP/SET_Actuator.c \
../Ventilation/src/SET_UP/SET_CalibrationManagement.c \
../Ventilation/src/SET_UP/SET_CalibrationVerification.c \
../Ventilation/src/SET_UP/SET_DefaultCalibration.c \
../Ventilation/src/SET_UP/SET_ExhFlowCalibration.c \
../Ventilation/src/SET_UP/SET_FasValveCalibration.c \
../Ventilation/src/SET_UP/SET_InspFlowOffsetDefault.c \
../Ventilation/src/SET_UP/SET_InternalPressureOffsetDefault.c \
../Ventilation/src/SET_UP/SET_O2FlowOffsetDefault.c \
../Ventilation/src/SET_UP/SET_O2PressureOffsetDefault.c \
../Ventilation/src/SET_UP/SET_ProximalPressureOffsetDefault.c \
../Ventilation/src/SET_UP/SET_RTC_Mngt.c \
../Ventilation/src/SET_UP/SET_TechnicalAlarms.c \
../Ventilation/src/SET_UP/SET_ValvePressureOffsetDefault.c 

OBJS += \
./Ventilation/src/SET_UP/SET_Actuator.o \
./Ventilation/src/SET_UP/SET_CalibrationManagement.o \
./Ventilation/src/SET_UP/SET_CalibrationVerification.o \
./Ventilation/src/SET_UP/SET_DefaultCalibration.o \
./Ventilation/src/SET_UP/SET_ExhFlowCalibration.o \
./Ventilation/src/SET_UP/SET_FasValveCalibration.o \
./Ventilation/src/SET_UP/SET_InspFlowOffsetDefault.o \
./Ventilation/src/SET_UP/SET_InternalPressureOffsetDefault.o \
./Ventilation/src/SET_UP/SET_O2FlowOffsetDefault.o \
./Ventilation/src/SET_UP/SET_O2PressureOffsetDefault.o \
./Ventilation/src/SET_UP/SET_ProximalPressureOffsetDefault.o \
./Ventilation/src/SET_UP/SET_RTC_Mngt.o \
./Ventilation/src/SET_UP/SET_TechnicalAlarms.o \
./Ventilation/src/SET_UP/SET_ValvePressureOffsetDefault.o 

C_DEPS += \
./Ventilation/src/SET_UP/SET_Actuator.d \
./Ventilation/src/SET_UP/SET_CalibrationManagement.d \
./Ventilation/src/SET_UP/SET_CalibrationVerification.d \
./Ventilation/src/SET_UP/SET_DefaultCalibration.d \
./Ventilation/src/SET_UP/SET_ExhFlowCalibration.d \
./Ventilation/src/SET_UP/SET_FasValveCalibration.d \
./Ventilation/src/SET_UP/SET_InspFlowOffsetDefault.d \
./Ventilation/src/SET_UP/SET_InternalPressureOffsetDefault.d \
./Ventilation/src/SET_UP/SET_O2FlowOffsetDefault.d \
./Ventilation/src/SET_UP/SET_O2PressureOffsetDefault.d \
./Ventilation/src/SET_UP/SET_ProximalPressureOffsetDefault.d \
./Ventilation/src/SET_UP/SET_RTC_Mngt.d \
./Ventilation/src/SET_UP/SET_TechnicalAlarms.d \
./Ventilation/src/SET_UP/SET_ValvePressureOffsetDefault.d 


# Each subdirectory must supply rules for building sources it contributes
Ventilation/src/SET_UP/%.o: ../Ventilation/src/SET_UP/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DSTM32 -DSTM32F4 -DSTM32F446RETx -DNUCLEO_F446RE -DDEBUG -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/USB_SETTINGS" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/SYSTEM" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/SECURITY" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/DISPLAY" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/SET_UP" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/DATABASE" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/ACTUATOR" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/VENTILATION" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/TIMERS" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/DATABASE_SETTINGS" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/GENERAL" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/MAIN" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/SCHEDULER" -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


