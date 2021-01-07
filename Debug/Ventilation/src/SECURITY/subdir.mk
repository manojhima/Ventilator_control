################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Ventilation/src/SECURITY/SEC_100_FiO2.c \
../Ventilation/src/SECURITY/SEC_ACPowerFail.c \
../Ventilation/src/SECURITY/SEC_AlarmIndication.c \
../Ventilation/src/SECURITY/SEC_AmbientTemperature.c \
../Ventilation/src/SECURITY/SEC_Apnea.c \
../Ventilation/src/SECURITY/SEC_BatteryTemperature.c \
../Ventilation/src/SECURITY/SEC_BuzzerBatteryChargeFailure.c \
../Ventilation/src/SECURITY/SEC_BuzzerBatteryLow.c \
../Ventilation/src/SECURITY/SEC_CanceledStateMngt.c \
../Ventilation/src/SECURITY/SEC_CheckBattery.c \
../Ventilation/src/SECURITY/SEC_CheckBatteryCharge.c \
../Ventilation/src/SECURITY/SEC_CheckBuzzer.c \
../Ventilation/src/SECURITY/SEC_CheckFio2.c \
../Ventilation/src/SECURITY/SEC_CheckFio2_XL2.c \
../Ventilation/src/SECURITY/SEC_CheckO2.c \
../Ventilation/src/SECURITY/SEC_CheckO2Supply.c \
../Ventilation/src/SECURITY/SEC_CheckPressure.c \
../Ventilation/src/SECURITY/SEC_CheckProximal.c \
../Ventilation/src/SECURITY/SEC_CheckRemoteAlarm.c \
../Ventilation/src/SECURITY/SEC_CheckSettings.c \
../Ventilation/src/SECURITY/SEC_CheckSupply.c \
../Ventilation/src/SECURITY/SEC_CheckValve.c \
../Ventilation/src/SECURITY/SEC_CheckValvePressure.c \
../Ventilation/src/SECURITY/SEC_ClockDefault.c \
../Ventilation/src/SECURITY/SEC_ControlledCycles.c \
../Ventilation/src/SECURITY/SEC_CoolingFanFailure.c \
../Ventilation/src/SECURITY/SEC_CpapMode.c \
../Ventilation/src/SECURITY/SEC_DCPowerFail.c \
../Ventilation/src/SECURITY/SEC_Disconnection.c \
../Ventilation/src/SECURITY/SEC_EndOfBattery.c \
../Ventilation/src/SECURITY/SEC_ExhFlowOffsetDefault.c \
../Ventilation/src/SECURITY/SEC_Fio2CalibrationNeeded.c \
../Ventilation/src/SECURITY/SEC_Fio2OffsetDefault.c \
../Ventilation/src/SECURITY/SEC_FirstCycleDetection.c \
../Ventilation/src/SECURITY/SEC_HighFio2_M2.c \
../Ventilation/src/SECURITY/SEC_HighPressure.c \
../Ventilation/src/SECURITY/SEC_HighRate.c \
../Ventilation/src/SECURITY/SEC_HighVte.c \
../Ventilation/src/SECURITY/SEC_HighVti.c \
../Ventilation/src/SECURITY/SEC_LeakDisconnection.c \
../Ventilation/src/SECURITY/SEC_LeakOcclusion.c \
../Ventilation/src/SECURITY/SEC_Leakage.c \
../Ventilation/src/SECURITY/SEC_LooseFlashPointer.c \
../Ventilation/src/SECURITY/SEC_LowBattery.c \
../Ventilation/src/SECURITY/SEC_LowVte.c \
../Ventilation/src/SECURITY/SEC_LowVti.c \
../Ventilation/src/SECURITY/SEC_MissingO2Supply.c \
../Ventilation/src/SECURITY/SEC_NoBattery.c \
../Ventilation/src/SECURITY/SEC_NoFio2Sensor_XL2.c \
../Ventilation/src/SECURITY/SEC_Occlusion.c \
../Ventilation/src/SECURITY/SEC_PresMode.c \
../Ventilation/src/SECURITY/SEC_ProxDisconnection.c \
../Ventilation/src/SECURITY/SEC_PsimvMode.c \
../Ventilation/src/SECURITY/SEC_PsvtMode.c \
../Ventilation/src/SECURITY/SEC_ResetAlarms.c \
../Ventilation/src/SECURITY/SEC_TechnicalProblem.c \
../Ventilation/src/SECURITY/SEC_TurbineOverheat.c \
../Ventilation/src/SECURITY/SEC_ValveAlarmsToReset.c \
../Ventilation/src/SECURITY/SEC_ValveLeakage.c \
../Ventilation/src/SECURITY/SEC_ValveUseChangeMngt.c \
../Ventilation/src/SECURITY/SEC_VentilAuthorization.c \
../Ventilation/src/SECURITY/SEC_VolMode.c \
../Ventilation/src/SECURITY/SEC_VoluntaryStop.c \
../Ventilation/src/SECURITY/SEC_VsimvMode.c \
../Ventilation/src/SECURITY/VEN_Security.c 

OBJS += \
./Ventilation/src/SECURITY/SEC_100_FiO2.o \
./Ventilation/src/SECURITY/SEC_ACPowerFail.o \
./Ventilation/src/SECURITY/SEC_AlarmIndication.o \
./Ventilation/src/SECURITY/SEC_AmbientTemperature.o \
./Ventilation/src/SECURITY/SEC_Apnea.o \
./Ventilation/src/SECURITY/SEC_BatteryTemperature.o \
./Ventilation/src/SECURITY/SEC_BuzzerBatteryChargeFailure.o \
./Ventilation/src/SECURITY/SEC_BuzzerBatteryLow.o \
./Ventilation/src/SECURITY/SEC_CanceledStateMngt.o \
./Ventilation/src/SECURITY/SEC_CheckBattery.o \
./Ventilation/src/SECURITY/SEC_CheckBatteryCharge.o \
./Ventilation/src/SECURITY/SEC_CheckBuzzer.o \
./Ventilation/src/SECURITY/SEC_CheckFio2.o \
./Ventilation/src/SECURITY/SEC_CheckFio2_XL2.o \
./Ventilation/src/SECURITY/SEC_CheckO2.o \
./Ventilation/src/SECURITY/SEC_CheckO2Supply.o \
./Ventilation/src/SECURITY/SEC_CheckPressure.o \
./Ventilation/src/SECURITY/SEC_CheckProximal.o \
./Ventilation/src/SECURITY/SEC_CheckRemoteAlarm.o \
./Ventilation/src/SECURITY/SEC_CheckSettings.o \
./Ventilation/src/SECURITY/SEC_CheckSupply.o \
./Ventilation/src/SECURITY/SEC_CheckValve.o \
./Ventilation/src/SECURITY/SEC_CheckValvePressure.o \
./Ventilation/src/SECURITY/SEC_ClockDefault.o \
./Ventilation/src/SECURITY/SEC_ControlledCycles.o \
./Ventilation/src/SECURITY/SEC_CoolingFanFailure.o \
./Ventilation/src/SECURITY/SEC_CpapMode.o \
./Ventilation/src/SECURITY/SEC_DCPowerFail.o \
./Ventilation/src/SECURITY/SEC_Disconnection.o \
./Ventilation/src/SECURITY/SEC_EndOfBattery.o \
./Ventilation/src/SECURITY/SEC_ExhFlowOffsetDefault.o \
./Ventilation/src/SECURITY/SEC_Fio2CalibrationNeeded.o \
./Ventilation/src/SECURITY/SEC_Fio2OffsetDefault.o \
./Ventilation/src/SECURITY/SEC_FirstCycleDetection.o \
./Ventilation/src/SECURITY/SEC_HighFio2_M2.o \
./Ventilation/src/SECURITY/SEC_HighPressure.o \
./Ventilation/src/SECURITY/SEC_HighRate.o \
./Ventilation/src/SECURITY/SEC_HighVte.o \
./Ventilation/src/SECURITY/SEC_HighVti.o \
./Ventilation/src/SECURITY/SEC_LeakDisconnection.o \
./Ventilation/src/SECURITY/SEC_LeakOcclusion.o \
./Ventilation/src/SECURITY/SEC_Leakage.o \
./Ventilation/src/SECURITY/SEC_LooseFlashPointer.o \
./Ventilation/src/SECURITY/SEC_LowBattery.o \
./Ventilation/src/SECURITY/SEC_LowVte.o \
./Ventilation/src/SECURITY/SEC_LowVti.o \
./Ventilation/src/SECURITY/SEC_MissingO2Supply.o \
./Ventilation/src/SECURITY/SEC_NoBattery.o \
./Ventilation/src/SECURITY/SEC_NoFio2Sensor_XL2.o \
./Ventilation/src/SECURITY/SEC_Occlusion.o \
./Ventilation/src/SECURITY/SEC_PresMode.o \
./Ventilation/src/SECURITY/SEC_ProxDisconnection.o \
./Ventilation/src/SECURITY/SEC_PsimvMode.o \
./Ventilation/src/SECURITY/SEC_PsvtMode.o \
./Ventilation/src/SECURITY/SEC_ResetAlarms.o \
./Ventilation/src/SECURITY/SEC_TechnicalProblem.o \
./Ventilation/src/SECURITY/SEC_TurbineOverheat.o \
./Ventilation/src/SECURITY/SEC_ValveAlarmsToReset.o \
./Ventilation/src/SECURITY/SEC_ValveLeakage.o \
./Ventilation/src/SECURITY/SEC_ValveUseChangeMngt.o \
./Ventilation/src/SECURITY/SEC_VentilAuthorization.o \
./Ventilation/src/SECURITY/SEC_VolMode.o \
./Ventilation/src/SECURITY/SEC_VoluntaryStop.o \
./Ventilation/src/SECURITY/SEC_VsimvMode.o \
./Ventilation/src/SECURITY/VEN_Security.o 

C_DEPS += \
./Ventilation/src/SECURITY/SEC_100_FiO2.d \
./Ventilation/src/SECURITY/SEC_ACPowerFail.d \
./Ventilation/src/SECURITY/SEC_AlarmIndication.d \
./Ventilation/src/SECURITY/SEC_AmbientTemperature.d \
./Ventilation/src/SECURITY/SEC_Apnea.d \
./Ventilation/src/SECURITY/SEC_BatteryTemperature.d \
./Ventilation/src/SECURITY/SEC_BuzzerBatteryChargeFailure.d \
./Ventilation/src/SECURITY/SEC_BuzzerBatteryLow.d \
./Ventilation/src/SECURITY/SEC_CanceledStateMngt.d \
./Ventilation/src/SECURITY/SEC_CheckBattery.d \
./Ventilation/src/SECURITY/SEC_CheckBatteryCharge.d \
./Ventilation/src/SECURITY/SEC_CheckBuzzer.d \
./Ventilation/src/SECURITY/SEC_CheckFio2.d \
./Ventilation/src/SECURITY/SEC_CheckFio2_XL2.d \
./Ventilation/src/SECURITY/SEC_CheckO2.d \
./Ventilation/src/SECURITY/SEC_CheckO2Supply.d \
./Ventilation/src/SECURITY/SEC_CheckPressure.d \
./Ventilation/src/SECURITY/SEC_CheckProximal.d \
./Ventilation/src/SECURITY/SEC_CheckRemoteAlarm.d \
./Ventilation/src/SECURITY/SEC_CheckSettings.d \
./Ventilation/src/SECURITY/SEC_CheckSupply.d \
./Ventilation/src/SECURITY/SEC_CheckValve.d \
./Ventilation/src/SECURITY/SEC_CheckValvePressure.d \
./Ventilation/src/SECURITY/SEC_ClockDefault.d \
./Ventilation/src/SECURITY/SEC_ControlledCycles.d \
./Ventilation/src/SECURITY/SEC_CoolingFanFailure.d \
./Ventilation/src/SECURITY/SEC_CpapMode.d \
./Ventilation/src/SECURITY/SEC_DCPowerFail.d \
./Ventilation/src/SECURITY/SEC_Disconnection.d \
./Ventilation/src/SECURITY/SEC_EndOfBattery.d \
./Ventilation/src/SECURITY/SEC_ExhFlowOffsetDefault.d \
./Ventilation/src/SECURITY/SEC_Fio2CalibrationNeeded.d \
./Ventilation/src/SECURITY/SEC_Fio2OffsetDefault.d \
./Ventilation/src/SECURITY/SEC_FirstCycleDetection.d \
./Ventilation/src/SECURITY/SEC_HighFio2_M2.d \
./Ventilation/src/SECURITY/SEC_HighPressure.d \
./Ventilation/src/SECURITY/SEC_HighRate.d \
./Ventilation/src/SECURITY/SEC_HighVte.d \
./Ventilation/src/SECURITY/SEC_HighVti.d \
./Ventilation/src/SECURITY/SEC_LeakDisconnection.d \
./Ventilation/src/SECURITY/SEC_LeakOcclusion.d \
./Ventilation/src/SECURITY/SEC_Leakage.d \
./Ventilation/src/SECURITY/SEC_LooseFlashPointer.d \
./Ventilation/src/SECURITY/SEC_LowBattery.d \
./Ventilation/src/SECURITY/SEC_LowVte.d \
./Ventilation/src/SECURITY/SEC_LowVti.d \
./Ventilation/src/SECURITY/SEC_MissingO2Supply.d \
./Ventilation/src/SECURITY/SEC_NoBattery.d \
./Ventilation/src/SECURITY/SEC_NoFio2Sensor_XL2.d \
./Ventilation/src/SECURITY/SEC_Occlusion.d \
./Ventilation/src/SECURITY/SEC_PresMode.d \
./Ventilation/src/SECURITY/SEC_ProxDisconnection.d \
./Ventilation/src/SECURITY/SEC_PsimvMode.d \
./Ventilation/src/SECURITY/SEC_PsvtMode.d \
./Ventilation/src/SECURITY/SEC_ResetAlarms.d \
./Ventilation/src/SECURITY/SEC_TechnicalProblem.d \
./Ventilation/src/SECURITY/SEC_TurbineOverheat.d \
./Ventilation/src/SECURITY/SEC_ValveAlarmsToReset.d \
./Ventilation/src/SECURITY/SEC_ValveLeakage.d \
./Ventilation/src/SECURITY/SEC_ValveUseChangeMngt.d \
./Ventilation/src/SECURITY/SEC_VentilAuthorization.d \
./Ventilation/src/SECURITY/SEC_VolMode.d \
./Ventilation/src/SECURITY/SEC_VoluntaryStop.d \
./Ventilation/src/SECURITY/SEC_VsimvMode.d \
./Ventilation/src/SECURITY/VEN_Security.d 


# Each subdirectory must supply rules for building sources it contributes
Ventilation/src/SECURITY/%.o: ../Ventilation/src/SECURITY/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DSTM32 -DSTM32F4 -DSTM32F446RETx -DNUCLEO_F446RE -DDEBUG -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/USB_SETTINGS" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/COMPUTE" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/CYCLES" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/SYSTEM" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/SECURITY" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/DISPLAY" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/SET_UP" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/DATABASE" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/ACTUATOR" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/VENTILATION" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/TIMERS" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/DATABASE_SETTINGS" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/GENERAL" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/MAIN" -I"/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/inc/SCHEDULER" -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


