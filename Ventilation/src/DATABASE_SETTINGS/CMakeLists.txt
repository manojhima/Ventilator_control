set(SOURCES DB_IhmAccessParaDataBase.c
	DB_IHM_Decrease_Access.c
	DB_IHM_Decrease_Config.c
	DB_IHM_Increase_Access.c
	DB_IHM_Increase_Config.c
	DB_IHM_Read_Access.c
	DB_IHM_Read_Info_Access.c
	DB_IHM_Write_Access.c
	DB_IHM_Write_Info_Access.c
	)
set(HEADER_FILES ${CMAKE_CURRENT_SOURCE_DIR}/../../inc/DATABASE_SETTINGS/DB_IhmAccessParaDataBase.h
	${CMAKE_CURRENT_SOURCE_DIR}/../../inc/DATABASE_SETTINGS/DB_IHM_Decrease_Config.h
	${CMAKE_CURRENT_SOURCE_DIR}/../../inc/DATABASE_SETTINGS/DB_IHM_Increase_Access.h
	${CMAKE_CURRENT_SOURCE_DIR}/../../inc/DATABASE_SETTINGS/DB_IHM_Increase_Config.h
	${CMAKE_CURRENT_SOURCE_DIR}/../../inc/DATABASE_SETTINGS/DB_IHM_Read_Access.h
	${CMAKE_CURRENT_SOURCE_DIR}/../../inc/DATABASE_SETTINGS/DB_IHM_Read_Info_Access.h
	${CMAKE_CURRENT_SOURCE_DIR}/../../inc/DATABASE_SETTINGS/DB_IHM_Write_Access.h
	${CMAKE_CURRENT_SOURCE_DIR}/../../inc/DATABASE_SETTINGS/DB_IHM_Write_Info_Access.h
	)
add_library(Databasesettingslib ${SOURCES} ${HEADER_FILES})
target_include_directories(Databasesettingslib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
       	${CMAKE_CURRENT_SOURCE_DIR}/../GENERAL/
	${CMAKE_CURRENT_SOURCE_DIR}/../DATABASE/
	${CMAKE_CURRENT_SOURCE_DIR}/../VENTILATION/
	${CMAKE_CURRENT_SOURCE_DIR}/../DATABASE_SETTINGS/
	) 

#add_subdirectory(tests)

