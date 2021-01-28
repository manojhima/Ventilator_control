set(SOURCES DB_IHM_Setting_Adjust_Psimv_Mode_Apnea_Time.c
	DB_IHM_Setting_Adjust_Psimv_Mode.c
	DB_IHM_Setting_Adjust_Psimv_Mode_Control_R.c
	DB_IHM_Setting_Adjust_Psimv_Mode_Disco_Delay.c
	DB_IHM_Setting_Adjust_Psimv_Mode_Exh_Sens.c
	DB_IHM_Setting_Adjust_Psimv_Mode_Exh_Sens_Neg.c
	DB_IHM_Setting_Adjust_Psimv_Mode_High_R.c
	DB_IHM_Setting_Adjust_Psimv_Mode_High_Vm.c
	DB_IHM_Setting_Adjust_Psimv_Mode_High_Vte.c
	DB_IHM_Setting_Adjust_Psimv_Mode_High_Vte.c
	DB_IHM_Setting_Adjust_Psimv_Mode_Insp_Sens.c
	DB_IHM_Setting_Adjust_Psimv_Mode_Low_Vm.c
	DB_IHM_Setting_Adjust_Psimv_Mode_Low_Vte.c
	DB_IHM_Setting_Adjust_Psimv_Mode_Low_Vti.c
	DB_IHM_Setting_Adjust_Psimv_Mode_PControl.c
	DB_IHM_Setting_Adjust_Psimv_Mode_Peep.c
	DB_IHM_Setting_Adjust_Psimv_Mode_PSupport.c
	DB_IHM_Setting_Adjust_Psimv_Mode_Rise_Time.c
	DB_IHM_Setting_Adjust_Psimv_Mode_Ti_Control.c
	DB_IHM_Write_Adjust_Psimv_Mode_Apnea_Time.c
	DB_IHM_Write_Adjust_Psimv_Mode.c
	DB_IHM_Write_Adjust_Psimv_Mode_Control_R.c
	DB_IHM_Write_Adjust_Psimv_Mode_Disco_Delay.c
	DB_IHM_Write_Adjust_Psimv_Mode_Exh_Sens.c
	DB_IHM_Write_Adjust_Psimv_Mode_Exh_Sens_Neg.c
	DB_IHM_Write_Adjust_Psimv_Mode_High_Vm.c
	DB_IHM_Write_Adjust_Psimv_Mode_High_Vte.c
	DB_IHM_Write_Adjust_Psimv_Mode_High_Vti.c
	DB_IHM_Write_Adjust_Psimv_Mode_Low_Vm.c
	DB_IHM_Write_Adjust_Psimv_Mode_Low_Vte.c
	DB_IHM_Write_Adjust_Psimv_Mode_Low_Vti.c
	DB_IHM_Write_Adjust_Psimv_Mode_Ti_Control.c
	)
set(HEADER_FILES ${CMAKE_CURRENT_SOURCE_DIR}/../../inc/PSIMV_SETTINGS/DB_IHM_Setting_Adjust_Psimv_Mode_Apnea_Time.h
	${CMAKE_CURRENT_SOURCE_DIR}/../../inc/PSIMV_SETTINGS/DB_IHM_Setting_Adjust_Psimv_Mode_Control_R.h
	${CMAKE_CURRENT_SOURCE_DIR}/../../inc/PSIMV_SETTINGS/DB_IHM_Setting_Adjust_Psimv_Mode.h
	${CMAKE_CURRENT_SOURCE_DIR}/../../inc/PSIMV_SETTINGS/DB_IHM_Setting_Adjust_Psimv_Mode_High_R.h
	${CMAKE_CURRENT_SOURCE_DIR}/../../inc/PSIMV_SETTINGS/DB_IHM_Setting_Adjust_Psimv_Mode_High_Vm.h
	${CMAKE_CURRENT_SOURCE_DIR}/../../inc/PSIMV_SETTINGS/DB_IHM_Setting_Adjust_Psimv_Mode_High_Vte.h
	${CMAKE_CURRENT_SOURCE_DIR}/../../inc/PSIMV_SETTINGS/DB_IHM_Setting_Adjust_Psimv_Mode_High_Vti.h
	${CMAKE_CURRENT_SOURCE_DIR}/../../inc/PSIMV_SETTINGS/DB_IHM_Setting_Adjust_Psimv_Mode_Low_Vm.h
	${CMAKE_CURRENT_SOURCE_DIR}/../../inc/PSIMV_SETTINGS/DB_IHM_Setting_Adjust_Psimv_Mode_Low_Vte.h
	${CMAKE_CURRENT_SOURCE_DIR}/../../inc/PSIMV_SETTINGS/DB_IHM_Setting_Adjust_Psimv_Mode_Low_Vti.h
	${CMAKE_CURRENT_SOURCE_DIR}/../../inc/PSIMV_SETTINGS/DB_IHM_Setting_Adjust_Psimv_Mode_PControl.h
	${CMAKE_CURRENT_SOURCE_DIR}/../../inc/PSIMV_SETTINGS/DB_IHM_Setting_Adjust_Psimv_Mode_Peep.h
	${CMAKE_CURRENT_SOURCE_DIR}/../../inc/PSIMV_SETTINGS/DB_IHM_Setting_Adjust_Psimv_Mode_PSupport.h
	${CMAKE_CURRENT_SOURCE_DIR}/../../inc/PSIMV_SETTINGS/DB_IHM_Setting_Adjust_Psimv_Mode_Ti_Control.h
	${CMAKE_CURRENT_SOURCE_DIR}/../../inc/PSIMV_SETTINGS/DB_IHM_Write_Adjust_Psimv_Mode.h
	)
add_library(PSIMlib ${SOURCES} ${HEADER_FILES})
target_include_directories(Actuatorlib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
       	${CMAKE_CURRENT_SOURCE_DIR}/../GENERAL/
	${CMAKE_CURRENT_SOURCE_DIR}/../DATABASE/
	${CMAKE_CURRENT_SOURCE_DIR}/../VENTILATION/
	${CMAKE_CURRENT_SOURCE_DIR}/../DATABASE_SETTINGS/
	) 

#add_subdirectory(tests)

