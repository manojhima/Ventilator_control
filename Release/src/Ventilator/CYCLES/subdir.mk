################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Ventilator/CYCLES/CYC_CpapCyclesMngt.c \
../src/Ventilator/CYCLES/CYC_Exh_Controller_Phase.c \
../src/Ventilator/CYCLES/CYC_Insp_Controller_Phase.c \
../src/Ventilator/CYCLES/CYC_Pres_Vol_CyclesMngt.c \
../src/Ventilator/CYCLES/CYC_Psimv_CyclesMngt.c \
../src/Ventilator/CYCLES/CYC_Psvt_CyclesMngt.c \
../src/Ventilator/CYCLES/CYC_TiLimitsCompute.c \
../src/Ventilator/CYCLES/CYC_TriggerEDetection.c \
../src/Ventilator/CYCLES/CYC_TriggerIDetection.c \
../src/Ventilator/CYCLES/CYC_Vsimv_CyclesMngt.c 

OBJS += \
./src/Ventilator/CYCLES/CYC_CpapCyclesMngt.o \
./src/Ventilator/CYCLES/CYC_Exh_Controller_Phase.o \
./src/Ventilator/CYCLES/CYC_Insp_Controller_Phase.o \
./src/Ventilator/CYCLES/CYC_Pres_Vol_CyclesMngt.o \
./src/Ventilator/CYCLES/CYC_Psimv_CyclesMngt.o \
./src/Ventilator/CYCLES/CYC_Psvt_CyclesMngt.o \
./src/Ventilator/CYCLES/CYC_TiLimitsCompute.o \
./src/Ventilator/CYCLES/CYC_TriggerEDetection.o \
./src/Ventilator/CYCLES/CYC_TriggerIDetection.o \
./src/Ventilator/CYCLES/CYC_Vsimv_CyclesMngt.o 

C_DEPS += \
./src/Ventilator/CYCLES/CYC_CpapCyclesMngt.d \
./src/Ventilator/CYCLES/CYC_Exh_Controller_Phase.d \
./src/Ventilator/CYCLES/CYC_Insp_Controller_Phase.d \
./src/Ventilator/CYCLES/CYC_Pres_Vol_CyclesMngt.d \
./src/Ventilator/CYCLES/CYC_Psimv_CyclesMngt.d \
./src/Ventilator/CYCLES/CYC_Psvt_CyclesMngt.d \
./src/Ventilator/CYCLES/CYC_TiLimitsCompute.d \
./src/Ventilator/CYCLES/CYC_TriggerEDetection.d \
./src/Ventilator/CYCLES/CYC_TriggerIDetection.d \
./src/Ventilator/CYCLES/CYC_Vsimv_CyclesMngt.d 


# Each subdirectory must supply rules for building sources it contributes
src/Ventilator/CYCLES/%.o: ../src/Ventilator/CYCLES/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mthumb -mfloat-abi=soft -O3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


