set(SOURCES SET_Actuator.c
	SET_CalibrationManagement.c
	SET_CalibrationVerification.c
	SET_DefaultCalibration.c
	SET_ExhFlowCalibration.c
	SET_FasValveCalibration.c
	SET_InspFlowOffsetDefault.c
	SET_InternalPressureOffsetDefault.c
	SET_O2FlowOffsetDefault.c
	SET_O2PressureOffsetDefault.c
	SET_ProximalPressureOffsetDefault.c
	SET_RTC_Mngt.c
	SET_TechnicalAlarms.c
	SET_ValvePressureOffsetDefault.c
	)
set(HEADER_FILES ${CMAKE_CURRENT_SOURCE_DIR}/../../inc/SET_UP/SET_Actuator.h
	${CMAKE_CURRENT_SOURCE_DIR}/../../inc/SET_UP/SET_CalibrationManagement.h
	${CMAKE_CURRENT_SOURCE_DIR}/../../inc/SET_UP/SET_CalibrationVerification.h
	${CMAKE_CURRENT_SOURCE_DIR}/../../inc/SET_UP/SET_DefaultCalibration.h
	${CMAKE_CURRENT_SOURCE_DIR}/../../inc/SET_UP/SET_ExhFlowCalibration.h
	${CMAKE_CURRENT_SOURCE_DIR}/../../inc/SET_UP/SET_FasValveCalibration.h
	${CMAKE_CURRENT_SOURCE_DIR}/../../inc/SET_UP/SET_InspFlowOffsetDefault.h
	${CMAKE_CURRENT_SOURCE_DIR}/../../inc/SET_UP/SET_InternalPressureOffsetDefault.h
	${CMAKE_CURRENT_SOURCE_DIR}/../../inc/SET_UP/SET_O2FlowOffsetDefault.h
	${CMAKE_CURRENT_SOURCE_DIR}/../../inc/SET_UP/SET_O2PressureOffsetDefault.h
	${CMAKE_CURRENT_SOURCE_DIR}/../../inc/SET_UP/SET_ProximalPressureOffsetDefault.h
	${CMAKE_CURRENT_SOURCE_DIR}/../../inc/SET_UP/SET_RTC_Mngt.h
	${CMAKE_CURRENT_SOURCE_DIR}/../../inc/SET_UP/SET_TechnicalAlarms.h
	${CMAKE_CURRENT_SOURCE_DIR}/../../inc/SET_UP/SET_ValvePressureOffsetDefault.h
	)
add_library(Setuplib ${SOURCES} ${HEADER_FILES})
target_include_directories(Setuplib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
       	${CMAKE_CURRENT_SOURCE_DIR}/../GENERAL/
	${CMAKE_CURRENT_SOURCE_DIR}/../DATABASE/
	${CMAKE_CURRENT_SOURCE_DIR}/../VENTILATION/
	${CMAKE_CURRENT_SOURCE_DIR}/../DATABASE_SETTINGS/
	) 

#add_subdirectory(tests)

