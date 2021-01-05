################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Ventilation/src/USB_SETTINGS/DB_IHM_Setting_Adjust_Usb.c \
../Ventilation/src/USB_SETTINGS/DB_IHM_Setting_Adjust_Usb_Default.c \
../Ventilation/src/USB_SETTINGS/DB_IHM_Setting_Adjust_Usb_Monitor_Transfer.c \
../Ventilation/src/USB_SETTINGS/DB_IHM_Setting_Adjust_Usb_Trend_Transfer.c 

OBJS += \
./Ventilation/src/USB_SETTINGS/DB_IHM_Setting_Adjust_Usb.o \
./Ventilation/src/USB_SETTINGS/DB_IHM_Setting_Adjust_Usb_Default.o \
./Ventilation/src/USB_SETTINGS/DB_IHM_Setting_Adjust_Usb_Monitor_Transfer.o \
./Ventilation/src/USB_SETTINGS/DB_IHM_Setting_Adjust_Usb_Trend_Transfer.o 

C_DEPS += \
./Ventilation/src/USB_SETTINGS/DB_IHM_Setting_Adjust_Usb.d \
./Ventilation/src/USB_SETTINGS/DB_IHM_Setting_Adjust_Usb_Default.d \
./Ventilation/src/USB_SETTINGS/DB_IHM_Setting_Adjust_Usb_Monitor_Transfer.d \
./Ventilation/src/USB_SETTINGS/DB_IHM_Setting_Adjust_Usb_Trend_Transfer.d 


# Each subdirectory must supply rules for building sources it contributes
Ventilation/src/USB_SETTINGS/%.o: ../Ventilation/src/USB_SETTINGS/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DSTM32 -DSTM32F4 -DSTM32F446RETx -DNUCLEO_F446RE -DDEBUG -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/USB_SETTINGS" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/SYSTEM" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/SECURITY" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/DISPLAY" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/SET_UP" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/DATABASE" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/ACTUATOR" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/VENTILATION" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/TIMERS" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/DATABASE_SETTINGS" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/GENERAL" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/MAIN" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/SCHEDULER" -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


