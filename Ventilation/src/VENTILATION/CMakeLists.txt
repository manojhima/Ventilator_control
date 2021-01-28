set(SOURCES VEN_Actuators.c
	VEN_Compute.c
	VEN_Cycles.c
	VEN_LeakActuators.c
	VEN_RiseCompute.c
	)
	
set(HEADER_FILES ${CMAKE_CURRENT_SOURCE_DIR}/../../inc/VENTILATION/VEN_Actuators.h
	${CMAKE_CURRENT_SOURCE_DIR}/../../inc/VENTILATION/VEN_Compute.h
	${CMAKE_CURRENT_SOURCE_DIR}/../../inc/VENTILATION/VEN_Cycles.h
	${CMAKE_CURRENT_SOURCE_DIR}/../../inc/VENTILATION/VEN_RiseCompute.h
	${CMAKE_CURRENT_SOURCE_DIR}/../../inc/VENTILATION/Ventilation_Compute_data.h
	${CMAKE_CURRENT_SOURCE_DIR}/../../inc/VENTILATION/Ventilation_Constants.h
	${CMAKE_CURRENT_SOURCE_DIR}/../../inc/VENTILATION/Ventilation_Cycles_Datas.h
	${CMAKE_CURRENT_SOURCE_DIR}/../../inc/VENTILATION/Ventilation_Datas.h
	)
add_library(Volsettingslib ${SOURCES} ${HEADER_FILES})
target_include_directories(Volsettingslib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
       	${CMAKE_CURRENT_SOURCE_DIR}/../GENERAL/
	${CMAKE_CURRENT_SOURCE_DIR}/../DATABASE/
	${CMAKE_CURRENT_SOURCE_DIR}/../VENTILATION/
	${CMAKE_CURRENT_SOURCE_DIR}/../DATABASE_SETTINGS/
	) 

#add_subdirectory(tests)

