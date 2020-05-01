################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Ventilator/DRIVERS_NAND_FLASH/DRV_MONIT_Data_Load.c \
../src/Ventilator/DRIVERS_NAND_FLASH/DRV_MONIT_Launch.c \
../src/Ventilator/DRIVERS_NAND_FLASH/DRV_MONIT_PageRead.c \
../src/Ventilator/DRIVERS_NAND_FLASH/DRV_MONIT_PageWrite.c \
../src/Ventilator/DRIVERS_NAND_FLASH/DRV_NAND_AddressInput.c \
../src/Ventilator/DRIVERS_NAND_FLASH/DRV_NAND_BadBlock_Check.c \
../src/Ventilator/DRIVERS_NAND_FLASH/DRV_NAND_CommandInput.c \
../src/Ventilator/DRIVERS_NAND_FLASH/DRV_NAND_EraseBlock.c \
../src/Ventilator/DRIVERS_NAND_FLASH/DRV_NAND_Erase_Flash.c \
../src/Ventilator/DRIVERS_NAND_FLASH/DRV_NAND_Flash_Init.c \
../src/Ventilator/DRIVERS_NAND_FLASH/DRV_NAND_ReadID.c \
../src/Ventilator/DRIVERS_NAND_FLASH/DRV_TREND_Data_Load.c \
../src/Ventilator/DRIVERS_NAND_FLASH/DRV_TREND_Launch.c \
../src/Ventilator/DRIVERS_NAND_FLASH/DRV_TREND_PageRead.c \
../src/Ventilator/DRIVERS_NAND_FLASH/DRV_TREND_PageWrite.c 

OBJS += \
./src/Ventilator/DRIVERS_NAND_FLASH/DRV_MONIT_Data_Load.o \
./src/Ventilator/DRIVERS_NAND_FLASH/DRV_MONIT_Launch.o \
./src/Ventilator/DRIVERS_NAND_FLASH/DRV_MONIT_PageRead.o \
./src/Ventilator/DRIVERS_NAND_FLASH/DRV_MONIT_PageWrite.o \
./src/Ventilator/DRIVERS_NAND_FLASH/DRV_NAND_AddressInput.o \
./src/Ventilator/DRIVERS_NAND_FLASH/DRV_NAND_BadBlock_Check.o \
./src/Ventilator/DRIVERS_NAND_FLASH/DRV_NAND_CommandInput.o \
./src/Ventilator/DRIVERS_NAND_FLASH/DRV_NAND_EraseBlock.o \
./src/Ventilator/DRIVERS_NAND_FLASH/DRV_NAND_Erase_Flash.o \
./src/Ventilator/DRIVERS_NAND_FLASH/DRV_NAND_Flash_Init.o \
./src/Ventilator/DRIVERS_NAND_FLASH/DRV_NAND_ReadID.o \
./src/Ventilator/DRIVERS_NAND_FLASH/DRV_TREND_Data_Load.o \
./src/Ventilator/DRIVERS_NAND_FLASH/DRV_TREND_Launch.o \
./src/Ventilator/DRIVERS_NAND_FLASH/DRV_TREND_PageRead.o \
./src/Ventilator/DRIVERS_NAND_FLASH/DRV_TREND_PageWrite.o 

C_DEPS += \
./src/Ventilator/DRIVERS_NAND_FLASH/DRV_MONIT_Data_Load.d \
./src/Ventilator/DRIVERS_NAND_FLASH/DRV_MONIT_Launch.d \
./src/Ventilator/DRIVERS_NAND_FLASH/DRV_MONIT_PageRead.d \
./src/Ventilator/DRIVERS_NAND_FLASH/DRV_MONIT_PageWrite.d \
./src/Ventilator/DRIVERS_NAND_FLASH/DRV_NAND_AddressInput.d \
./src/Ventilator/DRIVERS_NAND_FLASH/DRV_NAND_BadBlock_Check.d \
./src/Ventilator/DRIVERS_NAND_FLASH/DRV_NAND_CommandInput.d \
./src/Ventilator/DRIVERS_NAND_FLASH/DRV_NAND_EraseBlock.d \
./src/Ventilator/DRIVERS_NAND_FLASH/DRV_NAND_Erase_Flash.d \
./src/Ventilator/DRIVERS_NAND_FLASH/DRV_NAND_Flash_Init.d \
./src/Ventilator/DRIVERS_NAND_FLASH/DRV_NAND_ReadID.d \
./src/Ventilator/DRIVERS_NAND_FLASH/DRV_TREND_Data_Load.d \
./src/Ventilator/DRIVERS_NAND_FLASH/DRV_TREND_Launch.d \
./src/Ventilator/DRIVERS_NAND_FLASH/DRV_TREND_PageRead.d \
./src/Ventilator/DRIVERS_NAND_FLASH/DRV_TREND_PageWrite.d 


# Each subdirectory must supply rules for building sources it contributes
src/Ventilator/DRIVERS_NAND_FLASH/%.o: ../src/Ventilator/DRIVERS_NAND_FLASH/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mthumb -mfloat-abi=soft -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


