################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Ventilator/COMPUTE/CMP_AveragePressureComputing.c \
../src/Ventilator/COMPUTE/CMP_CalculAutoAdaptInsp.c \
../src/Ventilator/COMPUTE/CMP_CalculFlowLeak.c \
../src/Ventilator/COMPUTE/CMP_ExhPlatComputings.c \
../src/Ventilator/COMPUTE/CMP_ExhalationComputings.c \
../src/Ventilator/COMPUTE/CMP_InspPlatComputings.c \
../src/Ventilator/COMPUTE/CMP_InspRiseComputings.c \
../src/Ventilator/COMPUTE/CMP_InspirationComputings.c \
../src/Ventilator/COMPUTE/CMP_LeakComputing.c \
../src/Ventilator/COMPUTE/CMP_LeakFactors.c \
../src/Ventilator/COMPUTE/CMP_MeanTable.c \
../src/Ventilator/COMPUTE/CMP_O2Consigne.c \
../src/Ventilator/COMPUTE/CMP_PiSetPointPsimvMode.c \
../src/Ventilator/COMPUTE/CMP_TargetVt.c \
../src/Ventilator/COMPUTE/CMP_TimeComputing.c \
../src/Ventilator/COMPUTE/CMP_VentilationReport.c 

OBJS += \
./src/Ventilator/COMPUTE/CMP_AveragePressureComputing.o \
./src/Ventilator/COMPUTE/CMP_CalculAutoAdaptInsp.o \
./src/Ventilator/COMPUTE/CMP_CalculFlowLeak.o \
./src/Ventilator/COMPUTE/CMP_ExhPlatComputings.o \
./src/Ventilator/COMPUTE/CMP_ExhalationComputings.o \
./src/Ventilator/COMPUTE/CMP_InspPlatComputings.o \
./src/Ventilator/COMPUTE/CMP_InspRiseComputings.o \
./src/Ventilator/COMPUTE/CMP_InspirationComputings.o \
./src/Ventilator/COMPUTE/CMP_LeakComputing.o \
./src/Ventilator/COMPUTE/CMP_LeakFactors.o \
./src/Ventilator/COMPUTE/CMP_MeanTable.o \
./src/Ventilator/COMPUTE/CMP_O2Consigne.o \
./src/Ventilator/COMPUTE/CMP_PiSetPointPsimvMode.o \
./src/Ventilator/COMPUTE/CMP_TargetVt.o \
./src/Ventilator/COMPUTE/CMP_TimeComputing.o \
./src/Ventilator/COMPUTE/CMP_VentilationReport.o 

C_DEPS += \
./src/Ventilator/COMPUTE/CMP_AveragePressureComputing.d \
./src/Ventilator/COMPUTE/CMP_CalculAutoAdaptInsp.d \
./src/Ventilator/COMPUTE/CMP_CalculFlowLeak.d \
./src/Ventilator/COMPUTE/CMP_ExhPlatComputings.d \
./src/Ventilator/COMPUTE/CMP_ExhalationComputings.d \
./src/Ventilator/COMPUTE/CMP_InspPlatComputings.d \
./src/Ventilator/COMPUTE/CMP_InspRiseComputings.d \
./src/Ventilator/COMPUTE/CMP_InspirationComputings.d \
./src/Ventilator/COMPUTE/CMP_LeakComputing.d \
./src/Ventilator/COMPUTE/CMP_LeakFactors.d \
./src/Ventilator/COMPUTE/CMP_MeanTable.d \
./src/Ventilator/COMPUTE/CMP_O2Consigne.d \
./src/Ventilator/COMPUTE/CMP_PiSetPointPsimvMode.d \
./src/Ventilator/COMPUTE/CMP_TargetVt.d \
./src/Ventilator/COMPUTE/CMP_TimeComputing.d \
./src/Ventilator/COMPUTE/CMP_VentilationReport.d 


# Each subdirectory must supply rules for building sources it contributes
src/Ventilator/COMPUTE/%.o: ../src/Ventilator/COMPUTE/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mthumb -mfloat-abi=soft -O3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


