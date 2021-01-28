set(SOURCES DB_AlarmInfoRead.c
	DB_AlarmInfoWrite.c
	DB_AlarmIsActive.c
	DB_AlarmStatusRead.c
	DB_AlarmStatusWrite.c  
	DB_ComputeBreathTimingRatios.c
	DB_ComputeRead.c
	DB_ComputeWrite.c
	DB_ConfigRead.c
	DB_ConfigWrite.c
	DB_ControlRead.c          
	DB_ControlWrite.c               
	DB_CopyMngt.c
	DB_CurrentRead.c
	DB_CurrentWrite.c                  
	DB_EventMngt.c           
	DB_IHM_Setting_Rtc_Day.c        
	DB_InitializeTables.c
	DB_KeyboardEventRead.c
	DB_KeyboardEventWrite.c
	DB_LoadAndCheckEepromIntoRam.c
	DB_MeasurementWrite.c
	DB_PowerSupplyRead.C
	DB_PowerSupplyWrite.C
	DB_Revision.c
	DB_RiseTimeCompute.c
	DB_RTCRead.c
	DB_RTCWrite.c
	DB_SoftwareVersionTest.c
	DB_StartInitDb.c
	DB_TrendRead.c
	DB_TrendWrite.c
	DB_UsbRead.c
	DB_UsbWrite.C
	DB_VersionRead.c
	DB_VersionWrite.c
	DB_WriteDataInEepAndRam.c	
	)
set(HEADER_FILES ${CMAKE_CURRENT_SOURCE_DIR}/
	${CMAKE_CURRENT_SOURCE_DIR}/../../inc/DATABASE/DB_AlarmStatus.h
	${CMAKE_CURRENT_SOURCE_DIR}/../../inc/DATABASE/DB_Compute.h
	${CMAKE_CURRENT_SOURCE_DIR}/../../inc/DATABASE/DB_Compute.h
	${CMAKE_CURRENT_SOURCE_DIR}/../../inc/DATABASE/DB_Compute.h
	${CMAKE_CURRENT_SOURCE_DIR}/../../inc/DATABASE/DB_CopyMngt.h
	${CMAKE_CURRENT_SOURCE_DIR}/../../inc/DATABASE/DB_Current.h
	${CMAKE_CURRENT_SOURCE_DIR}/../../inc/DATABASE/DB_Event.h
	${CMAKE_CURRENT_SOURCE_DIR}/../../inc/DATABASE/DB_EventMngt.h
	${CMAKE_CURRENT_SOURCE_DIR}/../../inc/DATABASE/DB_InitializeTables.h
	${CMAKE_CURRENT_SOURCE_DIR}/../../inc/DATABASE/DB_KeyboardEvent.h
	${CMAKE_CURRENT_SOURCE_DIR}/../../inc/DATABASE/DB_LoadAndCheckEepromIntoRam.h
	${CMAKE_CURRENT_SOURCE_DIR}/../../inc/DATABASE/DB_Measurement.h
	${CMAKE_CURRENT_SOURCE_DIR}/../../inc/DATABASE/DB_PowerSupply.h
	${CMAKE_CURRENT_SOURCE_DIR}/../../inc/DATABASE/DB_Revision.h
	${CMAKE_CURRENT_SOURCE_DIR}/../../inc/DATABASE/DB_RiseTimeCompute.h
	${CMAKE_CURRENT_SOURCE_DIR}/../../inc/DATABASE/DB_Rtc.h
	${CMAKE_CURRENT_SOURCE_DIR}/../../inc/DATABASE/DB_SoftwareVersionTest.h
	${CMAKE_CURRENT_SOURCE_DIR}/../../inc/DATABASE/DB_StartInitDb.h
	${CMAKE_CURRENT_SOURCE_DIR}/../../inc/DATABASE/DB_TrendWrite.h
	${CMAKE_CURRENT_SOURCE_DIR}/../../inc/DATABASE/DB_Usb.h
	${CMAKE_CURRENT_SOURCE_DIR}/../../inc/DATABASE/DB_VersionWrite.h
	${CMAKE_CURRENT_SOURCE_DIR}/../../inc/DATABASE/DB_WriteDataInEepAndRam.h
	)
add_library(Databaselib ${SOURCES} ${HEADER_FILES})
target_include_directories(Databaselib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
       	${CMAKE_CURRENT_SOURCE_DIR}/../GENERAL/
	) 

add_subdirectory(tests)


