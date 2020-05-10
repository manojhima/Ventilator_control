################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Ventilator/DRIVERS/DRV_CheckPageAndRetransmitAddress.c \
../src/Ventilator/DRIVERS/DRV_Key_Sound_Bip.c \
../src/Ventilator/DRIVERS/DRV_Key_Sound_Cloc.c \
../src/Ventilator/DRIVERS/DRV_OutputPort.c \
../src/Ventilator/DRIVERS/DRV_ResetOnReturnSupply.c \
../src/Ventilator/DRIVERS/DRV_VarEeprom.c 

OBJS += \
./src/Ventilator/DRIVERS/DRV_CheckPageAndRetransmitAddress.o \
./src/Ventilator/DRIVERS/DRV_Key_Sound_Bip.o \
./src/Ventilator/DRIVERS/DRV_Key_Sound_Cloc.o \
./src/Ventilator/DRIVERS/DRV_OutputPort.o \
./src/Ventilator/DRIVERS/DRV_ResetOnReturnSupply.o \
./src/Ventilator/DRIVERS/DRV_VarEeprom.o 

C_DEPS += \
./src/Ventilator/DRIVERS/DRV_CheckPageAndRetransmitAddress.d \
./src/Ventilator/DRIVERS/DRV_Key_Sound_Bip.d \
./src/Ventilator/DRIVERS/DRV_Key_Sound_Cloc.d \
./src/Ventilator/DRIVERS/DRV_OutputPort.d \
./src/Ventilator/DRIVERS/DRV_ResetOnReturnSupply.d \
./src/Ventilator/DRIVERS/DRV_VarEeprom.d 


# Each subdirectory must supply rules for building sources it contributes
src/Ventilator/DRIVERS/%.o: ../src/Ventilator/DRIVERS/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mthumb -mfloat-abi=soft -O3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


