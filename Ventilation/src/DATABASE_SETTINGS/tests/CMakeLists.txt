set(BINARY database_setting_test)
set(HEADERS )
set(SOURCES main.cpp test_DB_IHM_Decrease_Access.cpp)
add_executable(${BINARY} ${SOURCES} ${HEADERS})
add_test(NAME ${BINARY} COMMAND ${BINARY})
target_link_libraries(${BINARY} PUBLIC DATABASE_SETTINGSlib gtest)

