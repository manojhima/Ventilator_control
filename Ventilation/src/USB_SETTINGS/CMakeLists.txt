set(SOURCES DB_IHM_Setting_Adjust_Usb.c
	DB_IHM_Setting_Adjust_Usb_Default.c
	DB_IHM_Setting_Adjust_Usb_Monitor_Transfer.c
	DB_IHM_Setting_Adjust_Usb_Trend_Transfer.c
	)
set(HEADER_FILES ${CMAKE_CURRENT_SOURCE_DIR}/../../inc/USB_SETTINGS/DB_IHM_Setting_Adjust_Usb_Default.h
	${CMAKE_CURRENT_SOURCE_DIR}/../../inc/USB_SETTINGS/DB_IHM_Setting_Adjust_Usb.h
	${CMAKE_CURRENT_SOURCE_DIR}/../../inc/USB_SETTINGS/DB_IHM_Setting_Adjust_Usb_Monitor_Transfer.h
	${CMAKE_CURRENT_SOURCE_DIR}/../../inc/USB_SETTINGS/DB_IHM_Setting_Adjust_Usb_Trend_Transfer.h
	)
add_library(Usbsettingslib ${SOURCES} ${HEADER_FILES})
target_include_directories(Usbsettingslib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
       	${CMAKE_CURRENT_SOURCE_DIR}/../GENERAL/
	${CMAKE_CURRENT_SOURCE_DIR}/../DATABASE/
	${CMAKE_CURRENT_SOURCE_DIR}/../VENTILATION/
	${CMAKE_CURRENT_SOURCE_DIR}/../DATABASE_SETTINGS/
	) 

#add_subdirectory(tests)

