set(SOURCES DB_IHM_Setting_Adjust_Vol_Mode.c
	DB_IHM_Setting_Adjust_Vol_Mode_Control_R.c
	DB_IHM_Setting_Adjust_Vol_Mode_Disco_Delay.c
	DB_IHM_Setting_Adjust_Vol_Mode_High_Pip.c
	DB_IHM_Setting_Adjust_Vol_Mode_High_R.c
	DB_IHM_Setting_Adjust_Vol_Mode_High_Vte.c
	DB_IHM_Setting_Adjust_Vol_Mode_Insp_Sens.c
	DB_IHM_Setting_Adjust_Vol_Mode_Low_Pip.c
	DB_IHM_Setting_Adjust_Vol_Mode_Low_Vte.c
	DB_IHM_Setting_Adjust_Vol_Mode_Peep.c
	DB_IHM_Setting_Adjust_Vol_Mode_Ramp.c
	DB_IHM_Setting_Adjust_Vol_Mode_Sigh_Cpt.c
	DB_IHM_Setting_Adjust_Vol_Mode_Sigh_Select.c
	DB_IHM_Setting_Adjust_Vol_Mode_Sigh_Vt_Coef.c
	DB_IHM_Setting_Adjust_Vol_Mode_Ti_Control.c
	DB_IHM_Setting_Adjust_Vol_Mode_Vol_Control.c
	DB_IHM_Write_Adjust_Vol_Mode.c
	DB_IHM_Write_Adjust_Vol_Mode_Control_R.c
	DB_IHM_Write_Adjust_Vol_Mode_Disco_Delay.c
	DB_IHM_Write_Adjust_Vol_Mode_Insp_Sens.c
	DB_IHM_Write_Adjust_Vol_Mode_Peep.c
	DB_IHM_Write_Adjust_Vol_Mode_Vol_Control.c
	)
set(HEADER_FILES ${CMAKE_CURRENT_SOURCE_DIR}/../../inc/VOL_SETTINGS/DB_IHM_Setting_Adjust_Vol_Mode_Control_R.h
	${CMAKE_CURRENT_SOURCE_DIR}/../../inc/VOL_SETTINGS/DB_IHM_Setting_Adjust_Vol_Mode.h
	${CMAKE_CURRENT_SOURCE_DIR}/../../inc/VOL_SETTINGS/DB_IHM_Setting_Adjust_Vol_Mode_High_Pip.h
	${CMAKE_CURRENT_SOURCE_DIR}/../../inc/VOL_SETTINGS/DB_IHM_Setting_Adjust_Vol_Mode_High_R.h
	${CMAKE_CURRENT_SOURCE_DIR}/../../inc/VOL_SETTINGS/DB_IHM_Setting_Adjust_Vol_Mode_High_Vte.h
	${CMAKE_CURRENT_SOURCE_DIR}/../../inc/VOL_SETTINGS/DB_IHM_Setting_Adjust_Vol_Mode_Low_Vte.h
	${CMAKE_CURRENT_SOURCE_DIR}/../../inc/VOL_SETTINGS/DB_IHM_Setting_Adjust_Vol_Mode_Ramp.h
	${CMAKE_CURRENT_SOURCE_DIR}/../../inc/VOL_SETTINGS/DB_IHM_Setting_Adjust_Vol_Mode_Sigh_Select.h
	${CMAKE_CURRENT_SOURCE_DIR}/../../inc/VOL_SETTINGS/DB_IHM_Setting_Adjust_Vol_Mode_Sigh_Vt_Coef.h
	${CMAKE_CURRENT_SOURCE_DIR}/../../inc/VOL_SETTINGS/DB_IHM_Setting_Adjust_Vol_Mode_Ti_Control.h
	${CMAKE_CURRENT_SOURCE_DIR}/../../inc/VOL_SETTINGS/DB_IHM_Setting_Adjust_Vol_Mode_Vol_Control.h
	${CMAKE_CURRENT_SOURCE_DIR}/../../inc/VOL_SETTINGS/DB_IHM_Write_Adjust_Vol_Mode_Control_R.h
	${CMAKE_CURRENT_SOURCE_DIR}/../../inc/VOL_SETTINGS/DB_IHM_Write_Adjust_Vol_Mode.h
	${CMAKE_CURRENT_SOURCE_DIR}/../../inc/VOL_SETTINGS/DB_IHM_Write_Adjust_Vol_Mode_Insp_Sens.h
	${CMAKE_CURRENT_SOURCE_DIR}/../../inc/VOL_SETTINGS/DB_IHM_Write_Adjust_Vol_Mode_Vol_Control.h
	)
add_library(Volcontrollib ${SOURCES} ${HEADER_FILES})
target_include_directories(Volcontrollib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
       	${CMAKE_CURRENT_SOURCE_DIR}/../GENERAL/
	${CMAKE_CURRENT_SOURCE_DIR}/../DATABASE/
	${CMAKE_CURRENT_SOURCE_DIR}/../VENTILATION/
	${CMAKE_CURRENT_SOURCE_DIR}/../DATABASE_SETTINGS/
	) 

#add_subdirectory(tests)

