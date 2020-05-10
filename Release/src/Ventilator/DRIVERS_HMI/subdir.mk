################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Ventilator/DRIVERS_HMI/DRV_BuzInit.c \
../src/Ventilator/DRIVERS_HMI/DRV_Buz_Sound.c \
../src/Ventilator/DRIVERS_HMI/DRV_Buz_Test.c \
../src/Ventilator/DRIVERS_HMI/DRV_Led_Orange.c \
../src/Ventilator/DRIVERS_HMI/DRV_Led_Red.c \
../src/Ventilator/DRIVERS_HMI/DRV_Led_Ventil.c \
../src/Ventilator/DRIVERS_HMI/DRV_Led_White.c \
../src/Ventilator/DRIVERS_HMI/DRV_PwmBuzzer.c 

OBJS += \
./src/Ventilator/DRIVERS_HMI/DRV_BuzInit.o \
./src/Ventilator/DRIVERS_HMI/DRV_Buz_Sound.o \
./src/Ventilator/DRIVERS_HMI/DRV_Buz_Test.o \
./src/Ventilator/DRIVERS_HMI/DRV_Led_Orange.o \
./src/Ventilator/DRIVERS_HMI/DRV_Led_Red.o \
./src/Ventilator/DRIVERS_HMI/DRV_Led_Ventil.o \
./src/Ventilator/DRIVERS_HMI/DRV_Led_White.o \
./src/Ventilator/DRIVERS_HMI/DRV_PwmBuzzer.o 

C_DEPS += \
./src/Ventilator/DRIVERS_HMI/DRV_BuzInit.d \
./src/Ventilator/DRIVERS_HMI/DRV_Buz_Sound.d \
./src/Ventilator/DRIVERS_HMI/DRV_Buz_Test.d \
./src/Ventilator/DRIVERS_HMI/DRV_Led_Orange.d \
./src/Ventilator/DRIVERS_HMI/DRV_Led_Red.d \
./src/Ventilator/DRIVERS_HMI/DRV_Led_Ventil.d \
./src/Ventilator/DRIVERS_HMI/DRV_Led_White.d \
./src/Ventilator/DRIVERS_HMI/DRV_PwmBuzzer.d 


# Each subdirectory must supply rules for building sources it contributes
src/Ventilator/DRIVERS_HMI/%.o: ../src/Ventilator/DRIVERS_HMI/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mthumb -mfloat-abi=soft -O3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


