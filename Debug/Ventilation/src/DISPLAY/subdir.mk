################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Ventilation/src/DISPLAY/DIS_Backlight.c \
../Ventilation/src/DISPLAY/DIS_Box.c \
../Ventilation/src/DISPLAY/DIS_DisplayPage.c \
../Ventilation/src/DISPLAY/DIS_ErasePage.c \
../Ventilation/src/DISPLAY/DIS_EraseZone.c \
../Ventilation/src/DISPLAY/DIS_FifoRead.c \
../Ventilation/src/DISPLAY/DIS_FifoWrite.c \
../Ventilation/src/DISPLAY/DIS_Line.c \
../Ventilation/src/DISPLAY/DIS_Number.c \
../Ventilation/src/DISPLAY/DIS_Pixel.c \
../Ventilation/src/DISPLAY/DIS_String.c \
../Ventilation/src/DISPLAY/DIS_Symbol.c 

OBJS += \
./Ventilation/src/DISPLAY/DIS_Backlight.o \
./Ventilation/src/DISPLAY/DIS_Box.o \
./Ventilation/src/DISPLAY/DIS_DisplayPage.o \
./Ventilation/src/DISPLAY/DIS_ErasePage.o \
./Ventilation/src/DISPLAY/DIS_EraseZone.o \
./Ventilation/src/DISPLAY/DIS_FifoRead.o \
./Ventilation/src/DISPLAY/DIS_FifoWrite.o \
./Ventilation/src/DISPLAY/DIS_Line.o \
./Ventilation/src/DISPLAY/DIS_Number.o \
./Ventilation/src/DISPLAY/DIS_Pixel.o \
./Ventilation/src/DISPLAY/DIS_String.o \
./Ventilation/src/DISPLAY/DIS_Symbol.o 

C_DEPS += \
./Ventilation/src/DISPLAY/DIS_Backlight.d \
./Ventilation/src/DISPLAY/DIS_Box.d \
./Ventilation/src/DISPLAY/DIS_DisplayPage.d \
./Ventilation/src/DISPLAY/DIS_ErasePage.d \
./Ventilation/src/DISPLAY/DIS_EraseZone.d \
./Ventilation/src/DISPLAY/DIS_FifoRead.d \
./Ventilation/src/DISPLAY/DIS_FifoWrite.d \
./Ventilation/src/DISPLAY/DIS_Line.d \
./Ventilation/src/DISPLAY/DIS_Number.d \
./Ventilation/src/DISPLAY/DIS_Pixel.d \
./Ventilation/src/DISPLAY/DIS_String.d \
./Ventilation/src/DISPLAY/DIS_Symbol.d 


# Each subdirectory must supply rules for building sources it contributes
Ventilation/src/DISPLAY/%.o: ../Ventilation/src/DISPLAY/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DSTM32 -DSTM32F4 -DSTM32F446RETx -DNUCLEO_F446RE -DDEBUG -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/GENERAL" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/SECURITY" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/CPAP_SETTINGS" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/USB_SETTINGS" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/COMPUTE" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/CYCLES" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/SYSTEM" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/DISPLAY" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/SET_UP" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/DATABASE" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/ACTUATOR" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/VENTILATION" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/TIMERS" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/DATABASE_SETTINGS" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/MAIN" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/SCHEDULER" -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


