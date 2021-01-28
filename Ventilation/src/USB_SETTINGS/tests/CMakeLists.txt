set(BINARY cycles_test)
set(HEADERS )
set(SOURCES main.cpp test_CYC_CpapCyclesMngt.cpp)
add_executable(${BINARY} ${SOURCES} ${HEADERS})
add_test(NAME ${BINARY} COMMAND ${BINARY})
target_link_libraries(${BINARY} PUBLIC cycleslib gtest)

