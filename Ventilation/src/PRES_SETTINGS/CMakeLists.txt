set(SOURCES DB_IHM_Setting_Adjust_Pres_Mode.c
	DB_IHM_Setting_Adjust_Pres_Mode_Control_R.c
	DB_IHM_Setting_Adjust_Pres_Mode_Disco_Delay.c
	DB_IHM_Setting_Adjust_Pres_Mode_High_Leak.c
	DB_IHM_Setting_Adjust_Pres_Mode_High_R.c
	DB_IHM_Setting_Adjust_Pres_Mode_High_Vte.c
	DB_IHM_Setting_Adjust_Pres_Mode_High_Vti.c
	DB_IHM_Setting_Adjust_Pres_Mode_Insp_Sens.c
	DB_IHM_Setting_Adjust_Pres_Mode_Low_Vte.c
	DB_IHM_Setting_Adjust_Pres_Mode_Low_Vti.c
	DB_IHM_Setting_Adjust_Pres_Mode_Max_Pressure.c
	DB_IHM_Setting_Adjust_Pres_Mode_P_Control.c
	DB_IHM_Setting_Adjust_Pres_Mode_Peep.c
	DB_IHM_Setting_Adjust_Pres_Mode_Rise_Time.c
	DB_IHM_Setting_Adjust_Pres_Mode_Target_Vt.c
	DB_IHM_Setting_Adjust_Pres_Mode_Ti_Control.c
	DB_IHM_Write_Adjust_Pres_Mode.c
	DB_IHM_Write_Adjust_Pres_Mode_Control_R.c
	DB_IHM_Write_Adjust_Pres_Mode_Disco_Delay.c
	DB_IHM_Write_Adjust_Pres_Mode_High_Vte.c
	DB_IHM_Write_Adjust_Pres_Mode_High_Vti.c
	DB_IHM_Write_Adjust_Pres_Mode_Insp_Sens.c
	DB_IHM_Write_Adjust_Pres_Mode_Low_Vte.c
	DB_IHM_Write_Adjust_Pres_Mode_Low_Vti.c
	DB_IHM_Write_Adjust_Pres_Mode_Max_Pressure.c
	DB_IHM_Write_Adjust_Pres_Mode_P_Control.c
	DB_IHM_Write_Adjust_Pres_Mode_Peep.c
	DB_IHM_Write_Adjust_Pres_Mode_Target_Vt.c
	)
set(HEADER_FILES ${CMAKE_CURRENT_SOURCE_DIR}/../../inc/PRES_SETTINGS/DB_IHM_Setting_Adjust_Pres_Mode_Control_R.h
	${CMAKE_CURRENT_SOURCE_DIR}/../../inc/PRES_SETTINGS/DB_IHM_Setting_Adjust_Pres_Mode.h
	${CMAKE_CURRENT_SOURCE_DIR}/../../inc/PRES_SETTINGS/DB_IHM_Setting_Adjust_Pres_Mode_High_R.h
	${CMAKE_CURRENT_SOURCE_DIR}/../../inc/PRES_SETTINGS/DB_IHM_Setting_Adjust_Pres_Mode_High_Vte.h
	${CMAKE_CURRENT_SOURCE_DIR}/../../inc/PRES_SETTINGS/DB_IHM_Setting_Adjust_Pres_Mode_High_Vti.h
	${CMAKE_CURRENT_SOURCE_DIR}/../../inc/PRES_SETTINGS/DB_IHM_Setting_Adjust_Pres_Mode_Low_Vte.h
	${CMAKE_CURRENT_SOURCE_DIR}/../../inc/PRES_SETTINGS/DB_IHM_Setting_Adjust_Pres_Mode_Low_Vti.h
	${CMAKE_CURRENT_SOURCE_DIR}/../../inc/PRES_SETTINGS/DB_IHM_Setting_Adjust_Pres_Mode_Max_Pressure.h
	${CMAKE_CURRENT_SOURCE_DIR}/../../inc/PRES_SETTINGS/DB_IHM_Setting_Adjust_Pres_Mode_Max_Pressure.h
	${CMAKE_CURRENT_SOURCE_DIR}/../../inc/PRES_SETTINGS/DB_IHM_Setting_Adjust_Pres_Mode_Peep.h
	${CMAKE_CURRENT_SOURCE_DIR}/../../inc/PRES_SETTINGS/DB_IHM_Setting_Adjust_Pres_Mode_Ti_Control.h
	${CMAKE_CURRENT_SOURCE_DIR}/../../inc/PRES_SETTINGS/DB_IHM_Write_Adjust_Pres_Mode_Control_R.h
	${CMAKE_CURRENT_SOURCE_DIR}/../../inc/PRES_SETTINGS/DB_IHM_Write_Adjust_Pres_Mode.h
	${CMAKE_CURRENT_SOURCE_DIR}/../../inc/PRES_SETTINGS/DB_IHM_Write_Adjust_Pres_Mode_Insp_Sens.h
	${CMAKE_CURRENT_SOURCE_DIR}/../../inc/PRES_SETTINGS/DB_IHM_Write_Adjust_Pres_Mode_Peep.h
	)
add_library(pressettingslib ${SOURCES} ${HEADER_FILES})
target_include_directories(pressettingslib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
       	${CMAKE_CURRENT_SOURCE_DIR}/../GENERAL/
	${CMAKE_CURRENT_SOURCE_DIR}/../DATABASE/
	${CMAKE_CURRENT_SOURCE_DIR}/../VENTILATION/
	${CMAKE_CURRENT_SOURCE_DIR}/../DATABASE_SETTINGS/
	) 

#add_subdirectory(tests)

