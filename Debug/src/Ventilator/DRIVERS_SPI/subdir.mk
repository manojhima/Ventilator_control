################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Ventilator/DRIVERS_SPI/DRV_SPIPowerSupplyUpdate.c \
../src/Ventilator/DRIVERS_SPI/DRV_SPI_POWER_Launch.c \
../src/Ventilator/DRIVERS_SPI/DRV_SPI_POWER_ReadStatus.c \
../src/Ventilator/DRIVERS_SPI/DRV_SPI_POWER_WaitEndTransmit.c 

OBJS += \
./src/Ventilator/DRIVERS_SPI/DRV_SPIPowerSupplyUpdate.o \
./src/Ventilator/DRIVERS_SPI/DRV_SPI_POWER_Launch.o \
./src/Ventilator/DRIVERS_SPI/DRV_SPI_POWER_ReadStatus.o \
./src/Ventilator/DRIVERS_SPI/DRV_SPI_POWER_WaitEndTransmit.o 

C_DEPS += \
./src/Ventilator/DRIVERS_SPI/DRV_SPIPowerSupplyUpdate.d \
./src/Ventilator/DRIVERS_SPI/DRV_SPI_POWER_Launch.d \
./src/Ventilator/DRIVERS_SPI/DRV_SPI_POWER_ReadStatus.d \
./src/Ventilator/DRIVERS_SPI/DRV_SPI_POWER_WaitEndTransmit.d 


# Each subdirectory must supply rules for building sources it contributes
src/Ventilator/DRIVERS_SPI/%.o: ../src/Ventilator/DRIVERS_SPI/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mthumb -mfloat-abi=soft -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


