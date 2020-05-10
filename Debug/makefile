################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/Ventilator/VSIMV_SETTINGS/subdir.mk
-include src/Ventilator/VOL_SETTINGS/subdir.mk
-include src/Ventilator/VENTILATION/subdir.mk
-include src/Ventilator/USB_SETTINGS/subdir.mk
-include src/Ventilator/TIMERS/subdir.mk
-include src/Ventilator/SYSTEM/subdir.mk
-include src/Ventilator/SET_UP/subdir.mk
-include src/Ventilator/SECURITY/subdir.mk
-include src/Ventilator/SCHEDULER/subdir.mk
-include src/Ventilator/PUST/subdir.mk
-include src/Ventilator/PSV_SETTINGS/subdir.mk
-include src/Ventilator/PSIMV_SETTINGS/subdir.mk
-include src/Ventilator/PRES_SETTINGS/subdir.mk
-include src/Ventilator/MAIN/subdir.mk
-include src/Ventilator/INTERRUPTS/subdir.mk
-include src/Ventilator/HMI/subdir.mk
-include src/Ventilator/GENERAL/subdir.mk
-include src/Ventilator/EEPROM/subdir.mk
-include src/Ventilator/DRIVERS_USB/subdir.mk
-include src/Ventilator/DRIVERS_SPI/subdir.mk
-include src/Ventilator/DRIVERS_SPEED_BLOWER/subdir.mk
-include src/Ventilator/DRIVERS_RTC/subdir.mk
-include src/Ventilator/DRIVERS_NAND_FLASH/subdir.mk
-include src/Ventilator/DRIVERS_HMI/subdir.mk
-include src/Ventilator/DRIVERS_FLASH_EVENT/subdir.mk
-include src/Ventilator/DRIVERS_EEPROM/subdir.mk
-include src/Ventilator/DRIVERS_DISPLAY/subdir.mk
-include src/Ventilator/DRIVERS_COM/subdir.mk
-include src/Ventilator/DRIVERS_ADC/subdir.mk
-include src/Ventilator/DRIVERS/subdir.mk
-include src/Ventilator/DISPLAY/subdir.mk
-include src/Ventilator/DATABASE_SETTINGS/subdir.mk
-include src/Ventilator/DATABASE/subdir.mk
-include src/Ventilator/CYCLES/subdir.mk
-include src/Ventilator/CPAP_SETTINGS/subdir.mk
-include src/Ventilator/CONFIG_SETTINGS/subdir.mk
-include src/Ventilator/COMPUTE/subdir.mk
-include src/Ventilator/ACTUATOR/subdir.mk
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
all: test.elf

# Tool invocations
test.elf: $(OBJS) $(USER_OBJS) /home/manoj/Stm32_f446/st_exmples/test/LinkerScript.ld
	@echo 'Building target: $@'
	@echo 'Invoking: MCU GCC Linker'
	arm-none-eabi-gcc -mthumb -mfloat-abi=soft -T"/home/manoj/Stm32_f446/st_exmples/test/LinkerScript.ld" -Wl,-Map=output.map -Wl,--gc-sections -o "test.elf" @"objects.list" $(USER_OBJS) $(LIBS) -lm
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

post-build:
	-@echo 'Generating binary and Printing size information:'
	arm-none-eabi-objcopy -O binary "test.elf" "test.bin"
	arm-none-eabi-size "test.elf"
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY: post-build

-include ../makefile.targets
