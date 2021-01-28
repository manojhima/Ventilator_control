set(SOURCES DB_IHM_Setting_Adjust_Psv_Mode_Apnea_Time.c
	DB_IHM_Setting_Adjust_Psv_Mode_Backup_R.c
	DB_IHM_Setting_Adjust_Psv_Mode.c
	DB_IHM_Setting_Adjust_Psv_Mode_Disco_Delay.c
	DB_IHM_Setting_Adjust_Psv_Mode_Exh_Sens.c
	DB_IHM_Setting_Adjust_Psv_Mode_Exh_Sens_Neg.c
	DB_IHM_Setting_Adjust_Psv_Mode_High_Leak.c
	DB_IHM_Setting_Adjust_Psv_Mode_High_R.c
	DB_IHM_Setting_Adjust_Psv_Mode_High_Vte.c
	DB_IHM_Setting_Adjust_Psv_Mode_High_Vti.c
	DB_IHM_Setting_Adjust_Psv_Mode_Insp_Sens.c
	DB_IHM_Setting_Adjust_Psv_Mode_Low_Vte.c
	DB_IHM_Setting_Adjust_Psv_Mode_Low_Vti.c
	DB_IHM_Setting_Adjust_Psv_Mode_Max_Pressure.c
	DB_IHM_Setting_Adjust_Psv_Mode_Peep.c
	DB_IHM_Setting_Adjust_Psv_Mode_P_Support.c
	DB_IHM_Setting_Adjust_Psv_Mode_Rise_Time.c
	DB_IHM_Setting_Adjust_Psv_Mode_Target_Vt.c
	DB_IHM_Setting_Adjust_Psv_Mode_Ti_Max.c
	DB_IHM_Setting_Adjust_Psv_Mode_Ti_Min.c
	DB_IHM_Write_Adjust_Psv_Mode_Apnea_Time.c
	DB_IHM_Write_Adjust_Psv_Mode_Backup_R.c
	DB_IHM_Write_Adjust_Psv_Mode.c
	DB_IHM_Write_Adjust_Psv_Mode_Disco_Delay.c
	DB_IHM_Write_Adjust_Psv_Mode_Exh_Sens.c
	DB_IHM_Write_Adjust_Psv_Mode_Exh_Sens_Neg.c
	DB_IHM_Write_Adjust_Psv_Mode_High_Vte.c
	DB_IHM_Write_Adjust_Psv_Mode_High_Vti.c
	DB_IHM_Write_Adjust_Psv_Mode_Low_Vte.c
	DB_IHM_Write_Adjust_Psv_Mode_Low_Vti.c
	DB_IHM_Write_Adjust_Psv_Mode_Max_Pressure.c
	DB_IHM_Write_Adjust_Psv_Mode_Peep.c
	DB_IHM_Write_Adjust_Psv_Mode_P_Support.c
	DB_IHM_Write_Adjust_Psv_Mode_P_Support_No_Select.c
	DB_IHM_Write_Adjust_Psv_Mode_Target_Vt.c
	DB_IHM_Write_Adjust_Psv_Mode_Ti_Max.c
	DB_IHM_Write_Adjust_Psv_Mode_Ti_Min.c
	)
set(HEADER_FILES ${CMAKE_CURRENT_SOURCE_DIR}/../../inc/PSV_SETTINGS/DB_IHM_Setting_Adjust_Psv_Mode_Apnea_Time.h
	${CMAKE_CURRENT_SOURCE_DIR}/../../inc/PSV_SETTINGS/DB_IHM_Setting_Adjust_Psv_Mode_Backup_R.h
	${CMAKE_CURRENT_SOURCE_DIR}/../../inc/PSV_SETTINGS/DB_IHM_Setting_Adjust_Psv_Mode.h
	${CMAKE_CURRENT_SOURCE_DIR}/../../inc/PSV_SETTINGS/DB_IHM_Setting_Adjust_Psv_Mode_High_R.h
	${CMAKE_CURRENT_SOURCE_DIR}/../../inc/PSV_SETTINGS/DB_IHM_Setting_Adjust_Psv_Mode_High_Vte.h
	${CMAKE_CURRENT_SOURCE_DIR}/../../inc/PSV_SETTINGS/DB_IHM_Setting_Adjust_Psv_Mode_High_Vti.h
	${CMAKE_CURRENT_SOURCE_DIR}/../../inc/PSV_SETTINGS/DB_IHM_Setting_Adjust_Psv_Mode_Low_Vte.h
	${CMAKE_CURRENT_SOURCE_DIR}/../../inc/PSV_SETTINGS/DB_IHM_Setting_Adjust_Psv_Mode_Low_Vti.h
	${CMAKE_CURRENT_SOURCE_DIR}/../../inc/PSV_SETTINGS/DB_IHM_Setting_Adjust_Psv_Mode_Max_Pressure.h
	${CMAKE_CURRENT_SOURCE_DIR}/../../inc/PSV_SETTINGS/DB_IHM_Setting_Adjust_Psv_Mode_Peep.h
	${CMAKE_CURRENT_SOURCE_DIR}/../../inc/PSV_SETTINGS/DB_IHM_Setting_Adjust_Psv_Mode_P_Support.h
	${CMAKE_CURRENT_SOURCE_DIR}/../../inc/PSV_SETTINGS/DB_IHM_Setting_Adjust_Psv_Mode_Ti_Max.h
	${CMAKE_CURRENT_SOURCE_DIR}/../../inc/PSV_SETTINGS/DB_IHM_Setting_Adjust_Psv_Mode_Ti_Min.h
	${CMAKE_CURRENT_SOURCE_DIR}/../../inc/PSV_SETTINGS/DB_IHM_Write_Adjust_Psv_Mode_Backup_R.h
	${CMAKE_CURRENT_SOURCE_DIR}/../../inc/PSV_SETTINGS/DB_IHM_Write_Adjust_Psv_Mode.h
	${CMAKE_CURRENT_SOURCE_DIR}/../../inc/PSV_SETTINGS/DB_IHM_Write_Adjust_Psv_Mode_Peep.h
	${CMAKE_CURRENT_SOURCE_DIR}/../../inc/PSV_SETTINGS/DB_IHM_Write_Adjust_Psv_Mode_P_Support_No_Select.h
	${CMAKE_CURRENT_SOURCE_DIR}/../../inc/PSV_SETTINGS/DB_IHM_Write_Adjust_Psv_Mode_Ti_Max.h
	)
add_library(Psvsettingslib ${SOURCES} ${HEADER_FILES})
target_include_directories(Psvsettingslib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
       	${CMAKE_CURRENT_SOURCE_DIR}/../GENERAL/
	${CMAKE_CURRENT_SOURCE_DIR}/../DATABASE/
	${CMAKE_CURRENT_SOURCE_DIR}/../VENTILATION/
	${CMAKE_CURRENT_SOURCE_DIR}/../DATABASE_SETTINGS/
	) 

#add_subdirectory(tests)

