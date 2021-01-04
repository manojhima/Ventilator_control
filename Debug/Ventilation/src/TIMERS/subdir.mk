################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Ventilation/src/TIMERS/TIM_Launch.c \
../Ventilation/src/TIMERS/TIM_ReadCounterValue.c \
../Ventilation/src/TIMERS/TIM_ReadDecounterValue.c \
../Ventilation/src/TIMERS/TIM_StartDecounter.c \
../Ventilation/src/TIMERS/TIM_Temporize.c 

OBJS += \
./Ventilation/src/TIMERS/TIM_Launch.o \
./Ventilation/src/TIMERS/TIM_ReadCounterValue.o \
./Ventilation/src/TIMERS/TIM_ReadDecounterValue.o \
./Ventilation/src/TIMERS/TIM_StartDecounter.o \
./Ventilation/src/TIMERS/TIM_Temporize.o 

C_DEPS += \
./Ventilation/src/TIMERS/TIM_Launch.d \
./Ventilation/src/TIMERS/TIM_ReadCounterValue.d \
./Ventilation/src/TIMERS/TIM_ReadDecounterValue.d \
./Ventilation/src/TIMERS/TIM_StartDecounter.d \
./Ventilation/src/TIMERS/TIM_Temporize.d 


# Each subdirectory must supply rules for building sources it contributes
Ventilation/src/TIMERS/%.o: ../Ventilation/src/TIMERS/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DSTM32 -DSTM32F4 -DSTM32F446RETx -DNUCLEO_F446RE -DDEBUG -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/SYSTEM" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/SECURITY" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/DISPLAY" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/SET_UP" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/DATABASE" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/ACTUATOR" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/VENTILATION" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/TIMERS" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/DATABASE_SETTINGS" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/GENERAL" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/MAIN" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/SCHEDULER" -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


