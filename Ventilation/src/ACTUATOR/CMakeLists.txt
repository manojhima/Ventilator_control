set(SOURCES ACT_BlowerCmd.c
	ACT_BrakePower.c
	ACT_O2ValveCmd.c
	ACT_ValveCmd.c
	ACT_ValveDetected.c
	)
set(HEADER_FILES ${CMAKE_CURRENT_SOURCE_DIR}/../../inc/ACTUATOR/ACT_BlowerCmd.h
	${CMAKE_CURRENT_SOURCE_DIR}/../../inc/ACTUATOR/ACT_BrakePower.h
	${CMAKE_CURRENT_SOURCE_DIR}/../../inc/ACTUATOR/ACT_O2ValveCmd.h
	${CMAKE_CURRENT_SOURCE_DIR}/../../inc/ACTUATOR/ACT_ValveCmd.h
	${CMAKE_CURRENT_SOURCE_DIR}/../../inc/ACTUATOR/ACT_ValveDetected.h
	)
add_library(Actuatorlib ${SOURCES} ${HEADER_FILES})
target_include_directories(Actuatorlib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
       	${CMAKE_CURRENT_SOURCE_DIR}/../GENERAL/
	${CMAKE_CURRENT_SOURCE_DIR}/../DATABASE/
	${CMAKE_CURRENT_SOURCE_DIR}/../VENTILATION/
	${CMAKE_CURRENT_SOURCE_DIR}/../DATABASE_SETTINGS/
	) 

add_subdirectory(tests)

