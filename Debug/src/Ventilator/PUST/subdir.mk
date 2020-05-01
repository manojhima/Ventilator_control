################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Ventilator/PUST/PUST.c \
../src/Ventilator/PUST/PUST_crc8.c \
../src/Ventilator/PUST/PUST_ramtestlib.c \
../src/Ventilator/PUST/PUST_ref_voltages.c 

OBJS += \
./src/Ventilator/PUST/PUST.o \
./src/Ventilator/PUST/PUST_crc8.o \
./src/Ventilator/PUST/PUST_ramtestlib.o \
./src/Ventilator/PUST/PUST_ref_voltages.o 

C_DEPS += \
./src/Ventilator/PUST/PUST.d \
./src/Ventilator/PUST/PUST_crc8.d \
./src/Ventilator/PUST/PUST_ramtestlib.d \
./src/Ventilator/PUST/PUST_ref_voltages.d 


# Each subdirectory must supply rules for building sources it contributes
src/Ventilator/PUST/%.o: ../src/Ventilator/PUST/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mthumb -mfloat-abi=soft -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


