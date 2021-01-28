set(BINARY actuator_test)
set(HEADERS )
set(SOURCES main.cpp test_ACT_BlowerCmd.cpp)
add_executable(${BINARY} ${SOURCES} ${HEADERS})
add_test(NAME ${BINARY} COMMAND ${BINARY})
target_link_libraries(${BINARY} PUBLIC Actuatorlib gtest)

