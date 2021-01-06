################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Ventilation/src/COMPUTE/CMP_AveragePressureComputing.c \
../Ventilation/src/COMPUTE/CMP_CalculAutoAdaptInsp.c \
../Ventilation/src/COMPUTE/CMP_CalculFlowLeak.c \
../Ventilation/src/COMPUTE/CMP_ExhPlatComputings.c \
../Ventilation/src/COMPUTE/CMP_ExhalationComputings.c \
../Ventilation/src/COMPUTE/CMP_InspPlatComputings.c \
../Ventilation/src/COMPUTE/CMP_InspRiseComputings.c \
../Ventilation/src/COMPUTE/CMP_InspirationComputings.c \
../Ventilation/src/COMPUTE/CMP_LeakComputing.c \
../Ventilation/src/COMPUTE/CMP_LeakFactors.c \
../Ventilation/src/COMPUTE/CMP_MeanTable.c \
../Ventilation/src/COMPUTE/CMP_TargetVt.c \
../Ventilation/src/COMPUTE/CMP_TimeComputing.c \
../Ventilation/src/COMPUTE/CMP_VentilationReport.c 

OBJS += \
./Ventilation/src/COMPUTE/CMP_AveragePressureComputing.o \
./Ventilation/src/COMPUTE/CMP_CalculAutoAdaptInsp.o \
./Ventilation/src/COMPUTE/CMP_CalculFlowLeak.o \
./Ventilation/src/COMPUTE/CMP_ExhPlatComputings.o \
./Ventilation/src/COMPUTE/CMP_ExhalationComputings.o \
./Ventilation/src/COMPUTE/CMP_InspPlatComputings.o \
./Ventilation/src/COMPUTE/CMP_InspRiseComputings.o \
./Ventilation/src/COMPUTE/CMP_InspirationComputings.o \
./Ventilation/src/COMPUTE/CMP_LeakComputing.o \
./Ventilation/src/COMPUTE/CMP_LeakFactors.o \
./Ventilation/src/COMPUTE/CMP_MeanTable.o \
./Ventilation/src/COMPUTE/CMP_TargetVt.o \
./Ventilation/src/COMPUTE/CMP_TimeComputing.o \
./Ventilation/src/COMPUTE/CMP_VentilationReport.o 

C_DEPS += \
./Ventilation/src/COMPUTE/CMP_AveragePressureComputing.d \
./Ventilation/src/COMPUTE/CMP_CalculAutoAdaptInsp.d \
./Ventilation/src/COMPUTE/CMP_CalculFlowLeak.d \
./Ventilation/src/COMPUTE/CMP_ExhPlatComputings.d \
./Ventilation/src/COMPUTE/CMP_ExhalationComputings.d \
./Ventilation/src/COMPUTE/CMP_InspPlatComputings.d \
./Ventilation/src/COMPUTE/CMP_InspRiseComputings.d \
./Ventilation/src/COMPUTE/CMP_InspirationComputings.d \
./Ventilation/src/COMPUTE/CMP_LeakComputing.d \
./Ventilation/src/COMPUTE/CMP_LeakFactors.d \
./Ventilation/src/COMPUTE/CMP_MeanTable.d \
./Ventilation/src/COMPUTE/CMP_TargetVt.d \
./Ventilation/src/COMPUTE/CMP_TimeComputing.d \
./Ventilation/src/COMPUTE/CMP_VentilationReport.d 


# Each subdirectory must supply rules for building sources it contributes
Ventilation/src/COMPUTE/%.o: ../Ventilation/src/COMPUTE/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DSTM32 -DSTM32F4 -DSTM32F446RETx -DNUCLEO_F446RE -DDEBUG -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/USB_SETTINGS" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/COMPUTE" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/CYCLES" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/SYSTEM" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/SECURITY" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/DISPLAY" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/SET_UP" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/DATABASE" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/ACTUATOR" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/VENTILATION" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/TIMERS" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/DATABASE_SETTINGS" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/GENERAL" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/MAIN" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/SCHEDULER" -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


