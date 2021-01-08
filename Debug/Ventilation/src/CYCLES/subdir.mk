################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Ventilation/src/CYCLES/CYC_CpapCyclesMngt.c \
../Ventilation/src/CYCLES/CYC_Exh_Controller_Phase.c \
../Ventilation/src/CYCLES/CYC_Insp_Controller_Phase.c \
../Ventilation/src/CYCLES/CYC_Pres_Vol_CyclesMngt.c \
../Ventilation/src/CYCLES/CYC_Psvt_CyclesMngt.c \
../Ventilation/src/CYCLES/CYC_TiLimitsCompute.c \
../Ventilation/src/CYCLES/CYC_TriggerEDetection.c \
../Ventilation/src/CYCLES/CYC_TriggerIDetection.c 

OBJS += \
./Ventilation/src/CYCLES/CYC_CpapCyclesMngt.o \
./Ventilation/src/CYCLES/CYC_Exh_Controller_Phase.o \
./Ventilation/src/CYCLES/CYC_Insp_Controller_Phase.o \
./Ventilation/src/CYCLES/CYC_Pres_Vol_CyclesMngt.o \
./Ventilation/src/CYCLES/CYC_Psvt_CyclesMngt.o \
./Ventilation/src/CYCLES/CYC_TiLimitsCompute.o \
./Ventilation/src/CYCLES/CYC_TriggerEDetection.o \
./Ventilation/src/CYCLES/CYC_TriggerIDetection.o 

C_DEPS += \
./Ventilation/src/CYCLES/CYC_CpapCyclesMngt.d \
./Ventilation/src/CYCLES/CYC_Exh_Controller_Phase.d \
./Ventilation/src/CYCLES/CYC_Insp_Controller_Phase.d \
./Ventilation/src/CYCLES/CYC_Pres_Vol_CyclesMngt.d \
./Ventilation/src/CYCLES/CYC_Psvt_CyclesMngt.d \
./Ventilation/src/CYCLES/CYC_TiLimitsCompute.d \
./Ventilation/src/CYCLES/CYC_TriggerEDetection.d \
./Ventilation/src/CYCLES/CYC_TriggerIDetection.d 


# Each subdirectory must supply rules for building sources it contributes
Ventilation/src/CYCLES/%.o: ../Ventilation/src/CYCLES/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DSTM32 -DSTM32F4 -DSTM32F446RETx -DNUCLEO_F446RE -DDEBUG -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/GENERAL" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/SECURITY" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/CPAP_SETTINGS" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/USB_SETTINGS" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/COMPUTE" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/CYCLES" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/SYSTEM" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/DISPLAY" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/SET_UP" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/DATABASE" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/ACTUATOR" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/VENTILATION" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/TIMERS" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/DATABASE_SETTINGS" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/MAIN" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/SCHEDULER" -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


