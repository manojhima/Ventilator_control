set(BINARY Databaselib_test)
set(HEADERS ) 
set(SOURCES main.cpp
       test_DB_AlarmInfoRead.cpp)
add_executable(${BINARY} ${SOURCES} ${HEADERS})
add_test(NAME ${BINARY} COMMAND ${BINARY})
target_link_libraries(${BINARY} PUBLIC Databaselib gtest)
