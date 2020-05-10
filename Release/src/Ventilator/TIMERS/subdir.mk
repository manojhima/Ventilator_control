################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Ventilator/TIMERS/TIM_Launch.c \
../src/Ventilator/TIMERS/TIM_ReadCounterValue.c \
../src/Ventilator/TIMERS/TIM_ReadDecounterValue.c \
../src/Ventilator/TIMERS/TIM_ReadMinuteCounterValue.c \
../src/Ventilator/TIMERS/TIM_ReadMinuteDecounterValue.c \
../src/Ventilator/TIMERS/TIM_StartCounter.c \
../src/Ventilator/TIMERS/TIM_StartDecounter.c \
../src/Ventilator/TIMERS/TIM_StartMinuteCounter.c \
../src/Ventilator/TIMERS/TIM_StartMinuteDecounter.c \
../src/Ventilator/TIMERS/TIM_StopDecounter.c \
../src/Ventilator/TIMERS/TIM_StopMinuteDecounter.c \
../src/Ventilator/TIMERS/TIM_Temporize.c \
../src/Ventilator/TIMERS/TIM_TestMinuteDecounterActivateOk.c \
../src/Ventilator/TIMERS/TIM_TestMinuteOverflowOk.c \
../src/Ventilator/TIMERS/TIM_TestOverflowOk.c 

OBJS += \
./src/Ventilator/TIMERS/TIM_Launch.o \
./src/Ventilator/TIMERS/TIM_ReadCounterValue.o \
./src/Ventilator/TIMERS/TIM_ReadDecounterValue.o \
./src/Ventilator/TIMERS/TIM_ReadMinuteCounterValue.o \
./src/Ventilator/TIMERS/TIM_ReadMinuteDecounterValue.o \
./src/Ventilator/TIMERS/TIM_StartCounter.o \
./src/Ventilator/TIMERS/TIM_StartDecounter.o \
./src/Ventilator/TIMERS/TIM_StartMinuteCounter.o \
./src/Ventilator/TIMERS/TIM_StartMinuteDecounter.o \
./src/Ventilator/TIMERS/TIM_StopDecounter.o \
./src/Ventilator/TIMERS/TIM_StopMinuteDecounter.o \
./src/Ventilator/TIMERS/TIM_Temporize.o \
./src/Ventilator/TIMERS/TIM_TestMinuteDecounterActivateOk.o \
./src/Ventilator/TIMERS/TIM_TestMinuteOverflowOk.o \
./src/Ventilator/TIMERS/TIM_TestOverflowOk.o 

C_DEPS += \
./src/Ventilator/TIMERS/TIM_Launch.d \
./src/Ventilator/TIMERS/TIM_ReadCounterValue.d \
./src/Ventilator/TIMERS/TIM_ReadDecounterValue.d \
./src/Ventilator/TIMERS/TIM_ReadMinuteCounterValue.d \
./src/Ventilator/TIMERS/TIM_ReadMinuteDecounterValue.d \
./src/Ventilator/TIMERS/TIM_StartCounter.d \
./src/Ventilator/TIMERS/TIM_StartDecounter.d \
./src/Ventilator/TIMERS/TIM_StartMinuteCounter.d \
./src/Ventilator/TIMERS/TIM_StartMinuteDecounter.d \
./src/Ventilator/TIMERS/TIM_StopDecounter.d \
./src/Ventilator/TIMERS/TIM_StopMinuteDecounter.d \
./src/Ventilator/TIMERS/TIM_Temporize.d \
./src/Ventilator/TIMERS/TIM_TestMinuteDecounterActivateOk.d \
./src/Ventilator/TIMERS/TIM_TestMinuteOverflowOk.d \
./src/Ventilator/TIMERS/TIM_TestOverflowOk.d 


# Each subdirectory must supply rules for building sources it contributes
src/Ventilator/TIMERS/%.o: ../src/Ventilator/TIMERS/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mthumb -mfloat-abi=soft -O3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


