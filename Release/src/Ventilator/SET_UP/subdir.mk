################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Ventilator/SET_UP/SET_Actuator.c \
../src/Ventilator/SET_UP/SET_CalibrationManagement.c \
../src/Ventilator/SET_UP/SET_CalibrationVerification.c \
../src/Ventilator/SET_UP/SET_DefaultCalibration.c \
../src/Ventilator/SET_UP/SET_ExhFlowCalibration.c \
../src/Ventilator/SET_UP/SET_FasValveCalibration.c \
../src/Ventilator/SET_UP/SET_InspFlowOffsetDefault.c \
../src/Ventilator/SET_UP/SET_InternalPressureOffsetDefault.c \
../src/Ventilator/SET_UP/SET_O2FlowOffsetDefault.c \
../src/Ventilator/SET_UP/SET_O2PressureOffsetDefault.c \
../src/Ventilator/SET_UP/SET_ProximalPressureOffsetDefault.c \
../src/Ventilator/SET_UP/SET_RTC_Mngt.c \
../src/Ventilator/SET_UP/SET_TechnicalAlarms.c \
../src/Ventilator/SET_UP/SET_ValvePressureOffsetDefault.c 

OBJS += \
./src/Ventilator/SET_UP/SET_Actuator.o \
./src/Ventilator/SET_UP/SET_CalibrationManagement.o \
./src/Ventilator/SET_UP/SET_CalibrationVerification.o \
./src/Ventilator/SET_UP/SET_DefaultCalibration.o \
./src/Ventilator/SET_UP/SET_ExhFlowCalibration.o \
./src/Ventilator/SET_UP/SET_FasValveCalibration.o \
./src/Ventilator/SET_UP/SET_InspFlowOffsetDefault.o \
./src/Ventilator/SET_UP/SET_InternalPressureOffsetDefault.o \
./src/Ventilator/SET_UP/SET_O2FlowOffsetDefault.o \
./src/Ventilator/SET_UP/SET_O2PressureOffsetDefault.o \
./src/Ventilator/SET_UP/SET_ProximalPressureOffsetDefault.o \
./src/Ventilator/SET_UP/SET_RTC_Mngt.o \
./src/Ventilator/SET_UP/SET_TechnicalAlarms.o \
./src/Ventilator/SET_UP/SET_ValvePressureOffsetDefault.o 

C_DEPS += \
./src/Ventilator/SET_UP/SET_Actuator.d \
./src/Ventilator/SET_UP/SET_CalibrationManagement.d \
./src/Ventilator/SET_UP/SET_CalibrationVerification.d \
./src/Ventilator/SET_UP/SET_DefaultCalibration.d \
./src/Ventilator/SET_UP/SET_ExhFlowCalibration.d \
./src/Ventilator/SET_UP/SET_FasValveCalibration.d \
./src/Ventilator/SET_UP/SET_InspFlowOffsetDefault.d \
./src/Ventilator/SET_UP/SET_InternalPressureOffsetDefault.d \
./src/Ventilator/SET_UP/SET_O2FlowOffsetDefault.d \
./src/Ventilator/SET_UP/SET_O2PressureOffsetDefault.d \
./src/Ventilator/SET_UP/SET_ProximalPressureOffsetDefault.d \
./src/Ventilator/SET_UP/SET_RTC_Mngt.d \
./src/Ventilator/SET_UP/SET_TechnicalAlarms.d \
./src/Ventilator/SET_UP/SET_ValvePressureOffsetDefault.d 


# Each subdirectory must supply rules for building sources it contributes
src/Ventilator/SET_UP/%.o: ../src/Ventilator/SET_UP/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mthumb -mfloat-abi=soft -O3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


