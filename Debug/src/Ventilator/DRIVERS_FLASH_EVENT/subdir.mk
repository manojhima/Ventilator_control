################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Ventilator/DRIVERS_FLASH_EVENT/DRV_EVENT_BlankCheck.c \
../src/Ventilator/DRIVERS_FLASH_EVENT/DRV_EVENT_Erase_Flash.c \
../src/Ventilator/DRIVERS_FLASH_EVENT/DRV_EVENT_Erase_Sector.c \
../src/Ventilator/DRIVERS_FLASH_EVENT/DRV_EVENT_Identification.c \
../src/Ventilator/DRIVERS_FLASH_EVENT/DRV_EVENT_Init.c \
../src/Ventilator/DRIVERS_FLASH_EVENT/DRV_EVENT_Launch.c \
../src/Ventilator/DRIVERS_FLASH_EVENT/DRV_EVENT_Program_Flash.c \
../src/Ventilator/DRIVERS_FLASH_EVENT/DRV_EVENT_PushEvent.c \
../src/Ventilator/DRIVERS_FLASH_EVENT/DRV_EVENT_RazPointerSector.c \
../src/Ventilator/DRIVERS_FLASH_EVENT/DRV_EVENT_Read_Event.c \
../src/Ventilator/DRIVERS_FLASH_EVENT/DRV_EVENT_TransAdressErase.c \
../src/Ventilator/DRIVERS_FLASH_EVENT/DRV_EVENT_TransPtrMemory.c \
../src/Ventilator/DRIVERS_FLASH_EVENT/DRV_EVENT_TransStateFlash.c \
../src/Ventilator/DRIVERS_FLASH_EVENT/DRV_EVENT_TransfIdent.c 

OBJS += \
./src/Ventilator/DRIVERS_FLASH_EVENT/DRV_EVENT_BlankCheck.o \
./src/Ventilator/DRIVERS_FLASH_EVENT/DRV_EVENT_Erase_Flash.o \
./src/Ventilator/DRIVERS_FLASH_EVENT/DRV_EVENT_Erase_Sector.o \
./src/Ventilator/DRIVERS_FLASH_EVENT/DRV_EVENT_Identification.o \
./src/Ventilator/DRIVERS_FLASH_EVENT/DRV_EVENT_Init.o \
./src/Ventilator/DRIVERS_FLASH_EVENT/DRV_EVENT_Launch.o \
./src/Ventilator/DRIVERS_FLASH_EVENT/DRV_EVENT_Program_Flash.o \
./src/Ventilator/DRIVERS_FLASH_EVENT/DRV_EVENT_PushEvent.o \
./src/Ventilator/DRIVERS_FLASH_EVENT/DRV_EVENT_RazPointerSector.o \
./src/Ventilator/DRIVERS_FLASH_EVENT/DRV_EVENT_Read_Event.o \
./src/Ventilator/DRIVERS_FLASH_EVENT/DRV_EVENT_TransAdressErase.o \
./src/Ventilator/DRIVERS_FLASH_EVENT/DRV_EVENT_TransPtrMemory.o \
./src/Ventilator/DRIVERS_FLASH_EVENT/DRV_EVENT_TransStateFlash.o \
./src/Ventilator/DRIVERS_FLASH_EVENT/DRV_EVENT_TransfIdent.o 

C_DEPS += \
./src/Ventilator/DRIVERS_FLASH_EVENT/DRV_EVENT_BlankCheck.d \
./src/Ventilator/DRIVERS_FLASH_EVENT/DRV_EVENT_Erase_Flash.d \
./src/Ventilator/DRIVERS_FLASH_EVENT/DRV_EVENT_Erase_Sector.d \
./src/Ventilator/DRIVERS_FLASH_EVENT/DRV_EVENT_Identification.d \
./src/Ventilator/DRIVERS_FLASH_EVENT/DRV_EVENT_Init.d \
./src/Ventilator/DRIVERS_FLASH_EVENT/DRV_EVENT_Launch.d \
./src/Ventilator/DRIVERS_FLASH_EVENT/DRV_EVENT_Program_Flash.d \
./src/Ventilator/DRIVERS_FLASH_EVENT/DRV_EVENT_PushEvent.d \
./src/Ventilator/DRIVERS_FLASH_EVENT/DRV_EVENT_RazPointerSector.d \
./src/Ventilator/DRIVERS_FLASH_EVENT/DRV_EVENT_Read_Event.d \
./src/Ventilator/DRIVERS_FLASH_EVENT/DRV_EVENT_TransAdressErase.d \
./src/Ventilator/DRIVERS_FLASH_EVENT/DRV_EVENT_TransPtrMemory.d \
./src/Ventilator/DRIVERS_FLASH_EVENT/DRV_EVENT_TransStateFlash.d \
./src/Ventilator/DRIVERS_FLASH_EVENT/DRV_EVENT_TransfIdent.d 


# Each subdirectory must supply rules for building sources it contributes
src/Ventilator/DRIVERS_FLASH_EVENT/%.o: ../src/Ventilator/DRIVERS_FLASH_EVENT/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mthumb -mfloat-abi=soft -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


