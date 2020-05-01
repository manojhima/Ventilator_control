################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Ventilator/USB_SETTINGS/DB_IHM_Setting_Adjust_Usb.c \
../src/Ventilator/USB_SETTINGS/DB_IHM_Setting_Adjust_Usb_Default.c \
../src/Ventilator/USB_SETTINGS/DB_IHM_Setting_Adjust_Usb_Monitor_Transfer.c \
../src/Ventilator/USB_SETTINGS/DB_IHM_Setting_Adjust_Usb_Trend_Transfer.c 

OBJS += \
./src/Ventilator/USB_SETTINGS/DB_IHM_Setting_Adjust_Usb.o \
./src/Ventilator/USB_SETTINGS/DB_IHM_Setting_Adjust_Usb_Default.o \
./src/Ventilator/USB_SETTINGS/DB_IHM_Setting_Adjust_Usb_Monitor_Transfer.o \
./src/Ventilator/USB_SETTINGS/DB_IHM_Setting_Adjust_Usb_Trend_Transfer.o 

C_DEPS += \
./src/Ventilator/USB_SETTINGS/DB_IHM_Setting_Adjust_Usb.d \
./src/Ventilator/USB_SETTINGS/DB_IHM_Setting_Adjust_Usb_Default.d \
./src/Ventilator/USB_SETTINGS/DB_IHM_Setting_Adjust_Usb_Monitor_Transfer.d \
./src/Ventilator/USB_SETTINGS/DB_IHM_Setting_Adjust_Usb_Trend_Transfer.d 


# Each subdirectory must supply rules for building sources it contributes
src/Ventilator/USB_SETTINGS/%.o: ../src/Ventilator/USB_SETTINGS/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mthumb -mfloat-abi=soft -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


