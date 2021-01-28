set(SOURCES CMP_AveragePressureComputing.c
	CMP_CalculAutoAdaptInsp.c
	CMP_CalculFlowLeak.c
	CMP_ExhalationComputings.c
	CMP_ExhPlatComputings.c
	CMP_InspirationComputings.c
	CMP_InspPlatComputings.c
	CMP_InspRiseComputings.c
	CMP_LeakComputing.c
	CMP_LeakFactors.c
	CMP_MeanTable.c
	CMP_O2Consigne.c
	CMP_PiSetPointPsimvMode.c
	CMP_TargetVt.c
	CMP_TimeComputing.c
	CMP_VentilationReport.c
	)
set(HEADER_FILES ${CMAKE_CURRENT_SOURCE_DIR}/../../inc/COMPUTE/CMP_AveragePressureComputing.h
	${CMAKE_CURRENT_SOURCE_DIR}/../../inc/COMPUTE/CMP_CalculAutoAdaptInsp.h
	${CMAKE_CURRENT_SOURCE_DIR}/../../inc/COMPUTE/CMP_CalculFlowLeak.h
	${CMAKE_CURRENT_SOURCE_DIR}/../../inc/COMPUTE/CMP_ExhalationComputings.h
	${CMAKE_CURRENT_SOURCE_DIR}/../../inc/COMPUTE/CMP_ExhPlatComputings.h
	${CMAKE_CURRENT_SOURCE_DIR}/../../inc/COMPUTE/CMP_InspirationComputings.h
	${CMAKE_CURRENT_SOURCE_DIR}/../../inc/COMPUTE/CMP_InspPlatComputings.h
	${CMAKE_CURRENT_SOURCE_DIR}/../../inc/COMPUTE/CMP_InspRiseComputings.h
	${CMAKE_CURRENT_SOURCE_DIR}/../../inc/COMPUTE/CMP_LeakComputing.h
	${CMAKE_CURRENT_SOURCE_DIR}/CMP_LeakFactors.c
	${CMAKE_CURRENT_SOURCE_DIR}/CMP_MeanTable.c
	${CMAKE_CURRENT_SOURCE_DIR}/CMP_O2Consigne.c
	${CMAKE_CURRENT_SOURCE_DIR}/CMP_PiSetPointPsimvMode.c
	${CMAKE_CURRENT_SOURCE_DIR}/CMP_TargetVt.c
	${CMAKE_CURRENT_SOURCE_DIR}/CMP_TimeComputing.c
	${CMAKE_CURRENT_SOURCE_DIR}/CMP_VentilationReport.c
	)
add_library(computelib ${SOURCES} ${HEADER_FILES})
target_include_directories(computelib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
       	${CMAKE_CURRENT_SOURCE_DIR}/../GENERAL/
	${CMAKE_CURRENT_SOURCE_DIR}/../DATABASE/
	${CMAKE_CURRENT_SOURCE_DIR}/../VENTILATION/
	${CMAKE_CURRENT_SOURCE_DIR}/../DATABASE_SETTINGS/
	) 

add_subdirectory(tests)

