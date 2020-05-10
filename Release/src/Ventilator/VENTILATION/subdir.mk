################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Ventilator/VENTILATION/VEN_Actuators.c \
../src/Ventilator/VENTILATION/VEN_Compute.c \
../src/Ventilator/VENTILATION/VEN_Cycles.c \
../src/Ventilator/VENTILATION/VEN_LeakActuators.c \
../src/Ventilator/VENTILATION/VEN_O2_Autorization.c \
../src/Ventilator/VENTILATION/VEN_RiseCompute.c 

OBJS += \
./src/Ventilator/VENTILATION/VEN_Actuators.o \
./src/Ventilator/VENTILATION/VEN_Compute.o \
./src/Ventilator/VENTILATION/VEN_Cycles.o \
./src/Ventilator/VENTILATION/VEN_LeakActuators.o \
./src/Ventilator/VENTILATION/VEN_O2_Autorization.o \
./src/Ventilator/VENTILATION/VEN_RiseCompute.o 

C_DEPS += \
./src/Ventilator/VENTILATION/VEN_Actuators.d \
./src/Ventilator/VENTILATION/VEN_Compute.d \
./src/Ventilator/VENTILATION/VEN_Cycles.d \
./src/Ventilator/VENTILATION/VEN_LeakActuators.d \
./src/Ventilator/VENTILATION/VEN_O2_Autorization.d \
./src/Ventilator/VENTILATION/VEN_RiseCompute.d 


# Each subdirectory must supply rules for building sources it contributes
src/Ventilator/VENTILATION/%.o: ../src/Ventilator/VENTILATION/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mthumb -mfloat-abi=soft -O3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


