set(BINARY config_setting_test)
set(HEADERS )
set(SOURCES main.cpp test_DB_IHM_Setting_Config_Adjust_High_Fio2.cpp)
add_executable(${BINARY} ${SOURCES} ${HEADERS})
add_test(NAME ${BINARY} COMMAND ${BINARY})
target_link_libraries(${BINARY} PUBLIC config_settinglib gtest)

