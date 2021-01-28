set(SOURCES CYC_CpapCyclesMngt.c
	CYC_Exh_Controller_Phase.c
	CYC_Insp_Controller_Phase.c
	CYC_Pres_Vol_CyclesMngt.c
	CYC_Psvt_CyclesMngt.c
	CYC_TiLimitsCompute.c
	CYC_TriggerEDetection.c
	CYC_TriggerIDetection.c
	)
set(HEADER_FILES ${CMAKE_CURRENT_SOURCE_DIR}/../../inc/CYCLES/CYC_CpapCyclesMngt.h
	${CMAKE_CURRENT_SOURCE_DIR}/../../inc/CYCLES/CYC_Exh_Controller_Phase.h
	${CMAKE_CURRENT_SOURCE_DIR}/../../inc/CYCLES/CYC_Insp_Controller_Phase.h
	${CMAKE_CURRENT_SOURCE_DIR}/../../inc/CYCLES/CYC_Pres_Vol_CyclesMngt.h
	${CMAKE_CURRENT_SOURCE_DIR}/../../inc/CYCLES/CYC_Psvt_CyclesMngt.h
	${CMAKE_CURRENT_SOURCE_DIR}/../../inc/CYCLES/CYC_TiLimitsCompute.h
	${CMAKE_CURRENT_SOURCE_DIR}/../../inc/CYCLES/CYC_TriggerEDetection.h
	${CMAKE_CURRENT_SOURCE_DIR}/../../inc/CYCLES/CYC_TriggerIDetection.h
	)
add_library(Cycleslib ${SOURCES} ${HEADER_FILES})
target_include_directories(Cycleslib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
       	${CMAKE_CURRENT_SOURCE_DIR}/../GENERAL/
	${CMAKE_CURRENT_SOURCE_DIR}/../DATABASE/
	${CMAKE_CURRENT_SOURCE_DIR}/../VENTILATION/
	${CMAKE_CURRENT_SOURCE_DIR}/../DATABASE_SETTINGS/
	) 

#add_subdirectory(tests)

