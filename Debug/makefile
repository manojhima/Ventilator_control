################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include startup/subdir.mk
-include src/subdir.mk
-include Ventilation/src/VENTILATION/subdir.mk
-include Ventilation/src/USB_SETTINGS/subdir.mk
-include Ventilation/src/TIMERS/subdir.mk
-include Ventilation/src/SYSTEM/subdir.mk
-include Ventilation/src/SET_UP/subdir.mk
-include Ventilation/src/SECURITY/subdir.mk
-include Ventilation/src/SCHEDULER/subdir.mk
-include Ventilation/src/PRES_SETTINGS/subdir.mk
-include Ventilation/src/MAIN/subdir.mk
-include Ventilation/src/INTERRUPTS/subdir.mk
-include Ventilation/src/GENERAL/subdir.mk
-include Ventilation/src/DISPLAY/subdir.mk
-include Ventilation/src/DATABASE_SETTINGS/subdir.mk
-include Ventilation/src/DATABASE/subdir.mk
-include Ventilation/src/CYCLES/subdir.mk
-include Ventilation/src/CPAP_SETTINGS/subdir.mk
-include Ventilation/src/COMPUTE/subdir.mk
-include Ventilation/src/ACTUATOR/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: Ventilation_Maintest.elf

# Tool invocations
Ventilation_Maintest.elf: $(OBJS) $(USER_OBJS) /home/bhavya/Main_WS/Ventilation_Maintest/LinkerScript.ld
	@echo 'Building target: $@'
	@echo 'Invoking: MCU GCC Linker'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -T"/home/bhavya/Main_WS/Ventilation_Maintest/LinkerScript.ld" -Wl,-Map=output.map -Wl,--gc-sections -o "Ventilation_Maintest.elf" @"objects.list" $(USER_OBJS) $(LIBS) -lm
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

post-build:
	-@echo 'Generating binary and Printing size information:'
	arm-none-eabi-objcopy -O binary "Ventilation_Maintest.elf" "Ventilation_Maintest.bin"
	arm-none-eabi-size "Ventilation_Maintest.elf"
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY: post-build

-include ../makefile.targets
