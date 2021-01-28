set(SOURCES TIM_Launch.c
	TIM_ReadCounterValue.c
	TIM_ReadDecounterValue.c
	TIM_ReadMinuteCounterValue.c
	TIM_ReadMinuteDecounterValue.c
	TIM_StartCounter.c
	TIM_StartDecounter.c
	TIM_StartMinuteCounter.c
	TIM_StartMinuteDecounter.c
	TIM_StopDecounter.c
	TIM_Temporize.c
	TIM_TestOverflowOk.c
	)
set(HEADER_FILES ${CMAKE_CURRENT_SOURCE_DIR}/../../inc/TIMERS/Timer_Data.h
	${CMAKE_CURRENT_SOURCE_DIR}/../../inc/TIMERS/TIM_Temporize.h
	)
add_library(Timerlib ${SOURCES} ${HEADER_FILES})
target_include_directories(Timerlib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
       	${CMAKE_CURRENT_SOURCE_DIR}/../GENERAL/
	${CMAKE_CURRENT_SOURCE_DIR}/../DATABASE/
	${CMAKE_CURRENT_SOURCE_DIR}/../VENTILATION/
	${CMAKE_CURRENT_SOURCE_DIR}/../DATABASE_SETTINGS/
	) 

#add_subdirectory(tests)

