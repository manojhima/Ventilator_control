################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Ventilator/DISPLAY/DIS_Backlight.c \
../src/Ventilator/DISPLAY/DIS_Box.c \
../src/Ventilator/DISPLAY/DIS_DisplayPage.c \
../src/Ventilator/DISPLAY/DIS_ErasePage.c \
../src/Ventilator/DISPLAY/DIS_EraseZone.c \
../src/Ventilator/DISPLAY/DIS_FifoRead.c \
../src/Ventilator/DISPLAY/DIS_FifoWrite.c \
../src/Ventilator/DISPLAY/DIS_Line.c \
../src/Ventilator/DISPLAY/DIS_LoadTable.c \
../src/Ventilator/DISPLAY/DIS_NegativeCar.c \
../src/Ventilator/DISPLAY/DIS_Number.c \
../src/Ventilator/DISPLAY/DIS_Pixel.c \
../src/Ventilator/DISPLAY/DIS_String.c \
../src/Ventilator/DISPLAY/DIS_Symbol.c 

OBJS += \
./src/Ventilator/DISPLAY/DIS_Backlight.o \
./src/Ventilator/DISPLAY/DIS_Box.o \
./src/Ventilator/DISPLAY/DIS_DisplayPage.o \
./src/Ventilator/DISPLAY/DIS_ErasePage.o \
./src/Ventilator/DISPLAY/DIS_EraseZone.o \
./src/Ventilator/DISPLAY/DIS_FifoRead.o \
./src/Ventilator/DISPLAY/DIS_FifoWrite.o \
./src/Ventilator/DISPLAY/DIS_Line.o \
./src/Ventilator/DISPLAY/DIS_LoadTable.o \
./src/Ventilator/DISPLAY/DIS_NegativeCar.o \
./src/Ventilator/DISPLAY/DIS_Number.o \
./src/Ventilator/DISPLAY/DIS_Pixel.o \
./src/Ventilator/DISPLAY/DIS_String.o \
./src/Ventilator/DISPLAY/DIS_Symbol.o 

C_DEPS += \
./src/Ventilator/DISPLAY/DIS_Backlight.d \
./src/Ventilator/DISPLAY/DIS_Box.d \
./src/Ventilator/DISPLAY/DIS_DisplayPage.d \
./src/Ventilator/DISPLAY/DIS_ErasePage.d \
./src/Ventilator/DISPLAY/DIS_EraseZone.d \
./src/Ventilator/DISPLAY/DIS_FifoRead.d \
./src/Ventilator/DISPLAY/DIS_FifoWrite.d \
./src/Ventilator/DISPLAY/DIS_Line.d \
./src/Ventilator/DISPLAY/DIS_LoadTable.d \
./src/Ventilator/DISPLAY/DIS_NegativeCar.d \
./src/Ventilator/DISPLAY/DIS_Number.d \
./src/Ventilator/DISPLAY/DIS_Pixel.d \
./src/Ventilator/DISPLAY/DIS_String.d \
./src/Ventilator/DISPLAY/DIS_Symbol.d 


# Each subdirectory must supply rules for building sources it contributes
src/Ventilator/DISPLAY/%.o: ../src/Ventilator/DISPLAY/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mthumb -mfloat-abi=soft -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


