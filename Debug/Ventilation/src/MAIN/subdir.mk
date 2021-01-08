################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Ventilation/src/MAIN/MAIN_Global_Variables_Init.c \
../Ventilation/src/MAIN/MAIN_Interfaces_Init.c \
../Ventilation/src/MAIN/MAIN_Security_Init.c \
../Ventilation/src/MAIN/MAIN_System_Init.c \
../Ventilation/src/MAIN/MAIN_Target_Init.c \
../Ventilation/src/MAIN/MAIN_Tasks_Init.c \
../Ventilation/src/MAIN/MAIN_Ventilation_Init.c 

OBJS += \
./Ventilation/src/MAIN/MAIN_Global_Variables_Init.o \
./Ventilation/src/MAIN/MAIN_Interfaces_Init.o \
./Ventilation/src/MAIN/MAIN_Security_Init.o \
./Ventilation/src/MAIN/MAIN_System_Init.o \
./Ventilation/src/MAIN/MAIN_Target_Init.o \
./Ventilation/src/MAIN/MAIN_Tasks_Init.o \
./Ventilation/src/MAIN/MAIN_Ventilation_Init.o 

C_DEPS += \
./Ventilation/src/MAIN/MAIN_Global_Variables_Init.d \
./Ventilation/src/MAIN/MAIN_Interfaces_Init.d \
./Ventilation/src/MAIN/MAIN_Security_Init.d \
./Ventilation/src/MAIN/MAIN_System_Init.d \
./Ventilation/src/MAIN/MAIN_Target_Init.d \
./Ventilation/src/MAIN/MAIN_Tasks_Init.d \
./Ventilation/src/MAIN/MAIN_Ventilation_Init.d 


# Each subdirectory must supply rules for building sources it contributes
Ventilation/src/MAIN/%.o: ../Ventilation/src/MAIN/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DSTM32 -DSTM32F4 -DSTM32F446RETx -DNUCLEO_F446RE -DDEBUG -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/GENERAL" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/SECURITY" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/CPAP_SETTINGS" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/USB_SETTINGS" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/COMPUTE" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/CYCLES" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/SYSTEM" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/DISPLAY" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/SET_UP" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/DATABASE" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/ACTUATOR" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/VENTILATION" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/TIMERS" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/DATABASE_SETTINGS" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/MAIN" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/SCHEDULER" -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


