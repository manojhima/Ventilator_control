################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Ventilation/src/VENTILATION/VEN_Actuators.c \
../Ventilation/src/VENTILATION/VEN_Compute.c \
../Ventilation/src/VENTILATION/VEN_Cycles.c \
../Ventilation/src/VENTILATION/VEN_LeakActuators.c \
../Ventilation/src/VENTILATION/VEN_RiseCompute.c 

OBJS += \
./Ventilation/src/VENTILATION/VEN_Actuators.o \
./Ventilation/src/VENTILATION/VEN_Compute.o \
./Ventilation/src/VENTILATION/VEN_Cycles.o \
./Ventilation/src/VENTILATION/VEN_LeakActuators.o \
./Ventilation/src/VENTILATION/VEN_RiseCompute.o 

C_DEPS += \
./Ventilation/src/VENTILATION/VEN_Actuators.d \
./Ventilation/src/VENTILATION/VEN_Compute.d \
./Ventilation/src/VENTILATION/VEN_Cycles.d \
./Ventilation/src/VENTILATION/VEN_LeakActuators.d \
./Ventilation/src/VENTILATION/VEN_RiseCompute.d 


# Each subdirectory must supply rules for building sources it contributes
Ventilation/src/VENTILATION/%.o: ../Ventilation/src/VENTILATION/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DSTM32 -DSTM32F4 -DSTM32F446RETx -DNUCLEO_F446RE -DDEBUG -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/USB_SETTINGS" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/COMPUTE" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/CYCLES" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/SYSTEM" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/SECURITY" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/DISPLAY" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/SET_UP" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/DATABASE" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/ACTUATOR" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/VENTILATION" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/TIMERS" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/DATABASE_SETTINGS" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/GENERAL" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/MAIN" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/SCHEDULER" -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


