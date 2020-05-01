################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Ventilator/INTERRUPTS/INTERRUPT_ADC_Convert.c \
../src/Ventilator/INTERRUPTS/INTERRUPT_ADC_ConvertError.c \
../src/Ventilator/INTERRUPTS/INTERRUPT_COM_EndTransmit.c \
../src/Ventilator/INTERRUPTS/INTERRUPT_COM_Receive.c \
../src/Ventilator/INTERRUPTS/INTERRUPT_Capture_CC0.c \
../src/Ventilator/INTERRUPTS/INTERRUPT_Class_B_trap.c \
../src/Ventilator/INTERRUPTS/INTERRUPT_STKOF_trap.c \
../src/Ventilator/INTERRUPTS/INTERRUPT_STKUF_trap.c \
../src/Ventilator/INTERRUPTS/INTERRUPT_Timer1Overflow.c \
../src/Ventilator/INTERRUPTS/INTERRUPT_Timer2.c \
../src/Ventilator/INTERRUPTS/INTERRUPT_Timer4.c \
../src/Ventilator/INTERRUPTS/INTERRUPT_Timer5.c \
../src/Ventilator/INTERRUPTS/INTERRUPT_Timer6.c \
../src/Ventilator/INTERRUPTS/INTERRUPT_USB_Busy.c \
../src/Ventilator/INTERRUPTS/INTERRUPT_USB_SpiBus.c \
../src/Ventilator/INTERRUPTS/INTERRUPT_USB_error.c \
../src/Ventilator/INTERRUPTS/Interrupt_Receive_SPO2.c \
../src/Ventilator/INTERRUPTS/It_watchdog.c 

OBJS += \
./src/Ventilator/INTERRUPTS/INTERRUPT_ADC_Convert.o \
./src/Ventilator/INTERRUPTS/INTERRUPT_ADC_ConvertError.o \
./src/Ventilator/INTERRUPTS/INTERRUPT_COM_EndTransmit.o \
./src/Ventilator/INTERRUPTS/INTERRUPT_COM_Receive.o \
./src/Ventilator/INTERRUPTS/INTERRUPT_Capture_CC0.o \
./src/Ventilator/INTERRUPTS/INTERRUPT_Class_B_trap.o \
./src/Ventilator/INTERRUPTS/INTERRUPT_STKOF_trap.o \
./src/Ventilator/INTERRUPTS/INTERRUPT_STKUF_trap.o \
./src/Ventilator/INTERRUPTS/INTERRUPT_Timer1Overflow.o \
./src/Ventilator/INTERRUPTS/INTERRUPT_Timer2.o \
./src/Ventilator/INTERRUPTS/INTERRUPT_Timer4.o \
./src/Ventilator/INTERRUPTS/INTERRUPT_Timer5.o \
./src/Ventilator/INTERRUPTS/INTERRUPT_Timer6.o \
./src/Ventilator/INTERRUPTS/INTERRUPT_USB_Busy.o \
./src/Ventilator/INTERRUPTS/INTERRUPT_USB_SpiBus.o \
./src/Ventilator/INTERRUPTS/INTERRUPT_USB_error.o \
./src/Ventilator/INTERRUPTS/Interrupt_Receive_SPO2.o \
./src/Ventilator/INTERRUPTS/It_watchdog.o 

C_DEPS += \
./src/Ventilator/INTERRUPTS/INTERRUPT_ADC_Convert.d \
./src/Ventilator/INTERRUPTS/INTERRUPT_ADC_ConvertError.d \
./src/Ventilator/INTERRUPTS/INTERRUPT_COM_EndTransmit.d \
./src/Ventilator/INTERRUPTS/INTERRUPT_COM_Receive.d \
./src/Ventilator/INTERRUPTS/INTERRUPT_Capture_CC0.d \
./src/Ventilator/INTERRUPTS/INTERRUPT_Class_B_trap.d \
./src/Ventilator/INTERRUPTS/INTERRUPT_STKOF_trap.d \
./src/Ventilator/INTERRUPTS/INTERRUPT_STKUF_trap.d \
./src/Ventilator/INTERRUPTS/INTERRUPT_Timer1Overflow.d \
./src/Ventilator/INTERRUPTS/INTERRUPT_Timer2.d \
./src/Ventilator/INTERRUPTS/INTERRUPT_Timer4.d \
./src/Ventilator/INTERRUPTS/INTERRUPT_Timer5.d \
./src/Ventilator/INTERRUPTS/INTERRUPT_Timer6.d \
./src/Ventilator/INTERRUPTS/INTERRUPT_USB_Busy.d \
./src/Ventilator/INTERRUPTS/INTERRUPT_USB_SpiBus.d \
./src/Ventilator/INTERRUPTS/INTERRUPT_USB_error.d \
./src/Ventilator/INTERRUPTS/Interrupt_Receive_SPO2.d \
./src/Ventilator/INTERRUPTS/It_watchdog.d 


# Each subdirectory must supply rules for building sources it contributes
src/Ventilator/INTERRUPTS/%.o: ../src/Ventilator/INTERRUPTS/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mthumb -mfloat-abi=soft -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


