set(SOURCES DB_IHM_Setting_Config_Adjust_Fio2.c
	DB_IHM_Setting_Config_Adjust_High_Fio2.c
	DB_IHM_Setting_Config_Adjust_High_Spo2.c
	DB_IHM_Setting_Config_Adjust_Low_Fio2.c
	DB_IHM_Setting_Config_Adjust_Low_Spo2.c
	DB_IHM_Setting_Config_Adjust_Mode.c
	DB_IHM_Setting_Config_Adjust_Mode_S2.c
	DB_IHM_Write_Config_Adjust_Fio2.c
	)
set(HEADER_FILES ${CMAKE_CURRENT_SOURCE_DIR}/../../inc/CONFIG_SETTINGS/DB_IHM_Setting_Config_Adjust_High_Fio2.h
	${CMAKE_CURRENT_SOURCE_DIR}/../../inc/CONFIG_SETTINGS/DB_IHM_Setting_Config_Adjust_High_Spo2.h
	${CMAKE_CURRENT_SOURCE_DIR}/../../inc/CONFIG_SETTINGS/DB_IHM_Setting_Config_Adjust_Low_Fio2.h
	${CMAKE_CURRENT_SOURCE_DIR}/../../inc/CONFIG_SETTINGS/DB_IHM_Setting_Config_Adjust_Low_Spo2.h
	${CMAKE_CURRENT_SOURCE_DIR}/../../inc/CONFIG_SETTINGS/DB_IHM_Setting_Config_Adjust_Mode.h
	${CMAKE_CURRENT_SOURCE_DIR}/../../inc/CONFIG_SETTINGS/DB_IHM_Write_Config_Adjust_Fio2.h
	)
add_library(Configsettingslib ${SOURCES} ${HEADER_FILES})
target_include_directories(Configsettingslib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
       	${CMAKE_CURRENT_SOURCE_DIR}/../GENERAL/
	${CMAKE_CURRENT_SOURCE_DIR}/../DATABASE/
	${CMAKE_CURRENT_SOURCE_DIR}/../VENTILATION/
	${CMAKE_CURRENT_SOURCE_DIR}/../DATABASE_SETTINGS/
	) 

#add_subdirectory(tests)

