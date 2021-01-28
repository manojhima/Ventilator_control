set(BINARY SCHEDULER_test)
set(HEADERS )
set(SOURCES main.cpp test_SCHED_Setup_entry.cpp)
add_executable(${BINARY} ${SOURCES} ${HEADERS})
add_test(NAME ${BINARY} COMMAND ${BINARY})
target_link_libraries(${BINARY} PUBLIC Schedulerlib gtest)

