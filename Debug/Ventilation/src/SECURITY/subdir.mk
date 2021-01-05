################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Ventilation/src/SECURITY/SEC_ExhFlowOffsetDefault.c \
../Ventilation/src/SECURITY/SEC_LooseFlashPointer.c \
../Ventilation/src/SECURITY/SEC_TurbineOverheat.c \
../Ventilation/src/SECURITY/VEN_Security.c 

OBJS += \
./Ventilation/src/SECURITY/SEC_ExhFlowOffsetDefault.o \
./Ventilation/src/SECURITY/SEC_LooseFlashPointer.o \
./Ventilation/src/SECURITY/SEC_TurbineOverheat.o \
./Ventilation/src/SECURITY/VEN_Security.o 

C_DEPS += \
./Ventilation/src/SECURITY/SEC_ExhFlowOffsetDefault.d \
./Ventilation/src/SECURITY/SEC_LooseFlashPointer.d \
./Ventilation/src/SECURITY/SEC_TurbineOverheat.d \
./Ventilation/src/SECURITY/VEN_Security.d 


# Each subdirectory must supply rules for building sources it contributes
Ventilation/src/SECURITY/%.o: ../Ventilation/src/SECURITY/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DSTM32 -DSTM32F4 -DSTM32F446RETx -DNUCLEO_F446RE -DDEBUG -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/USB_SETTINGS" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/SYSTEM" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/SECURITY" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/DISPLAY" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/SET_UP" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/DATABASE" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/ACTUATOR" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/VENTILATION" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/TIMERS" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/DATABASE_SETTINGS" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/GENERAL" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/MAIN" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/SCHEDULER" -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

