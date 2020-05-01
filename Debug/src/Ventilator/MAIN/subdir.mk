################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Ventilator/MAIN/MAIN.c \
../src/Ventilator/MAIN/MAIN_Airox_Symbol_Display.c \
../src/Ventilator/MAIN/MAIN_Global_Variables_Init.c \
../src/Ventilator/MAIN/MAIN_Interfaces_Init.c \
../src/Ventilator/MAIN/MAIN_Leds_Backlight_Buzzers_StartControl.c \
../src/Ventilator/MAIN/MAIN_NAND_Flash_Bad_Block_Detection.c \
../src/Ventilator/MAIN/MAIN_NAND_Flash_Bad_Block_Read.c \
../src/Ventilator/MAIN/MAIN_Security_Init.c \
../src/Ventilator/MAIN/MAIN_System_Init.c \
../src/Ventilator/MAIN/MAIN_Target_Init.c \
../src/Ventilator/MAIN/MAIN_Tasks_Init.c \
../src/Ventilator/MAIN/MAIN_Ventilation_Init.c \
../src/Ventilator/MAIN/MAIN_Version_Error_Mngt.c \
../src/Ventilator/MAIN/MAIN_activate_tasks.c 

OBJS += \
./src/Ventilator/MAIN/MAIN.o \
./src/Ventilator/MAIN/MAIN_Airox_Symbol_Display.o \
./src/Ventilator/MAIN/MAIN_Global_Variables_Init.o \
./src/Ventilator/MAIN/MAIN_Interfaces_Init.o \
./src/Ventilator/MAIN/MAIN_Leds_Backlight_Buzzers_StartControl.o \
./src/Ventilator/MAIN/MAIN_NAND_Flash_Bad_Block_Detection.o \
./src/Ventilator/MAIN/MAIN_NAND_Flash_Bad_Block_Read.o \
./src/Ventilator/MAIN/MAIN_Security_Init.o \
./src/Ventilator/MAIN/MAIN_System_Init.o \
./src/Ventilator/MAIN/MAIN_Target_Init.o \
./src/Ventilator/MAIN/MAIN_Tasks_Init.o \
./src/Ventilator/MAIN/MAIN_Ventilation_Init.o \
./src/Ventilator/MAIN/MAIN_Version_Error_Mngt.o \
./src/Ventilator/MAIN/MAIN_activate_tasks.o 

C_DEPS += \
./src/Ventilator/MAIN/MAIN.d \
./src/Ventilator/MAIN/MAIN_Airox_Symbol_Display.d \
./src/Ventilator/MAIN/MAIN_Global_Variables_Init.d \
./src/Ventilator/MAIN/MAIN_Interfaces_Init.d \
./src/Ventilator/MAIN/MAIN_Leds_Backlight_Buzzers_StartControl.d \
./src/Ventilator/MAIN/MAIN_NAND_Flash_Bad_Block_Detection.d \
./src/Ventilator/MAIN/MAIN_NAND_Flash_Bad_Block_Read.d \
./src/Ventilator/MAIN/MAIN_Security_Init.d \
./src/Ventilator/MAIN/MAIN_System_Init.d \
./src/Ventilator/MAIN/MAIN_Target_Init.d \
./src/Ventilator/MAIN/MAIN_Tasks_Init.d \
./src/Ventilator/MAIN/MAIN_Ventilation_Init.d \
./src/Ventilator/MAIN/MAIN_Version_Error_Mngt.d \
./src/Ventilator/MAIN/MAIN_activate_tasks.d 


# Each subdirectory must supply rules for building sources it contributes
src/Ventilator/MAIN/%.o: ../src/Ventilator/MAIN/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mthumb -mfloat-abi=soft -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


