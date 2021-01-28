set(BINARY PSV_Settings_test)
set(HEADERS )
set(SOURCES main.cpp test_DB_IHM_Setting_Adjust_Psv_Mode_Apnea_Time.cpp)
add_executable(${BINARY} ${SOURCES} ${HEADERS})
add_test(NAME ${BINARY} COMMAND ${BINARY})
target_link_libraries(${BINARY} PUBLIC PSV_Settings_testlib gtest)

