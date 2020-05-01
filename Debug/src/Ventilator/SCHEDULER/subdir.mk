################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Ventilator/SCHEDULER/SCHED_Setup_Main.c \
../src/Ventilator/SCHEDULER/SCHED_Setup_entry.c \
../src/Ventilator/SCHEDULER/SCHED_Ventilation_Main.c \
../src/Ventilator/SCHEDULER/SCHED_Ventilation_entry.c 

OBJS += \
./src/Ventilator/SCHEDULER/SCHED_Setup_Main.o \
./src/Ventilator/SCHEDULER/SCHED_Setup_entry.o \
./src/Ventilator/SCHEDULER/SCHED_Ventilation_Main.o \
./src/Ventilator/SCHEDULER/SCHED_Ventilation_entry.o 

C_DEPS += \
./src/Ventilator/SCHEDULER/SCHED_Setup_Main.d \
./src/Ventilator/SCHEDULER/SCHED_Setup_entry.d \
./src/Ventilator/SCHEDULER/SCHED_Ventilation_Main.d \
./src/Ventilator/SCHEDULER/SCHED_Ventilation_entry.d 


# Each subdirectory must supply rules for building sources it contributes
src/Ventilator/SCHEDULER/%.o: ../src/Ventilator/SCHEDULER/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mthumb -mfloat-abi=soft -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


