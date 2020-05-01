################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Ventilator/ACTUATOR/ACT_BlowerCmd.c \
../src/Ventilator/ACTUATOR/ACT_BrakePower.c \
../src/Ventilator/ACTUATOR/ACT_O2ValveCmd.c \
../src/Ventilator/ACTUATOR/ACT_ValveCmd.c \
../src/Ventilator/ACTUATOR/ACT_ValveDetected.c 

OBJS += \
./src/Ventilator/ACTUATOR/ACT_BlowerCmd.o \
./src/Ventilator/ACTUATOR/ACT_BrakePower.o \
./src/Ventilator/ACTUATOR/ACT_O2ValveCmd.o \
./src/Ventilator/ACTUATOR/ACT_ValveCmd.o \
./src/Ventilator/ACTUATOR/ACT_ValveDetected.o 

C_DEPS += \
./src/Ventilator/ACTUATOR/ACT_BlowerCmd.d \
./src/Ventilator/ACTUATOR/ACT_BrakePower.d \
./src/Ventilator/ACTUATOR/ACT_O2ValveCmd.d \
./src/Ventilator/ACTUATOR/ACT_ValveCmd.d \
./src/Ventilator/ACTUATOR/ACT_ValveDetected.d 


# Each subdirectory must supply rules for building sources it contributes
src/Ventilator/ACTUATOR/%.o: ../src/Ventilator/ACTUATOR/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mthumb -mfloat-abi=soft -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


