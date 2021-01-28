set(BINARY PRES_SETTINGS_test)
set(HEADERS )
set(SOURCES main.cpp test_DB_IHM_Setting_Adjust_Pres_Mode.cpp)
add_executable(${BINARY} ${SOURCES} ${HEADERS})
add_test(NAME ${BINARY} COMMAND ${BINARY})
target_link_libraries(${BINARY} PUBLIC Pres_settings gtest)

