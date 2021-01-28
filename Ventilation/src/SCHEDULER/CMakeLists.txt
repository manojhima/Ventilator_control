set(SOURCES SCHED_Setup_entry.c
	SCHED_Setup_Main.c
	SCHED_Ventilation_entry.c
	SCHED_Ventilation_Main.c
	)
set(HEADER_FILES ${CMAKE_CURRENT_SOURCE_DIR}/../../inc/SCHEDULER/SCHED_Setup_entry.h
	${CMAKE_CURRENT_SOURCE_DIR}/../../inc/SCHEDULER/SCHED_Setup_Main.h
	${CMAKE_CURRENT_SOURCE_DIR}/../../inc/SCHEDULER/SCHED_Setup_Scheduler_Config.h
	${CMAKE_CURRENT_SOURCE_DIR}/../../inc/SCHEDULER/Scheduler_Data.h
	${CMAKE_CURRENT_SOURCE_DIR}/../../inc/SCHEDULER/SCHED_Ventilation_Main.h
	${CMAKE_CURRENT_SOURCE_DIR}/../../inc/SCHEDULER/SCHED_Ventilation_Scheduler_Config.h
	)
add_library(Schedulerlib ${SOURCES} ${HEADER_FILES})
target_include_directories(Schedulerlib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
       	${CMAKE_CURRENT_SOURCE_DIR}/../GENERAL/
	${CMAKE_CURRENT_SOURCE_DIR}/../DATABASE/
	${CMAKE_CURRENT_SOURCE_DIR}/../VENTILATION/
	${CMAKE_CURRENT_SOURCE_DIR}/../DATABASE_SETTINGS/
	) 

#add_subdirectory(tests)

