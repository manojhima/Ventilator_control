set(SOURCES Average.c
	#CRC16_TableCompute.c
	#DRV_Temperature_WaitEndTransmit.c
	#ECMAIN.CPP
	#lsqrt.c
	Saturation.c
	)
set(HEADER_FILES ${CMAKE_CURRENT_SOURCE_DIR}/../../inc/GENERAL/define.h
	${CMAKE_CURRENT_SOURCE_DIR}/../../inc/GENERAL/enum.h
	${CMAKE_CURRENT_SOURCE_DIR}/../../inc/GENERAL/io_declare.h
	${CMAKE_CURRENT_SOURCE_DIR}/../../inc/GENERAL/io_stubs.h
	${CMAKE_CURRENT_SOURCE_DIR}/../../inc/GENERAL/limits.h
	${CMAKE_CURRENT_SOURCE_DIR}/../../inc/GENERAL/locate_database_code.h
	${CMAKE_CURRENT_SOURCE_DIR}/../../inc/GENERAL/Product.h
	${CMAKE_CURRENT_SOURCE_DIR}/../../inc/GENERAL/Structure.h
	${CMAKE_CURRENT_SOURCE_DIR}/../../inc/GENERAL/typedef.h
	)
add_library(Generallib ${SOURCES} ${HEADER_FILES})
target_include_directories(Generallib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
	${CMAKE_CURRENT_SOURCE_DIR}/../DATABASE/
	${CMAKE_CURRENT_SOURCE_DIR}/../VENTILATION/
	${CMAKE_CURRENT_SOURCE_DIR}/../DATABASE_SETTINGS/
	) 

#add_subdirectory(tests)

