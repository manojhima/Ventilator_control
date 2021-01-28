set(BINARY compute_test)
set(HEADERS )
set(SOURCES main.cpp test_CMP_AveragePressureComputing.cpp)
add_executable(${BINARY} ${SOURCES} ${HEADERS})
add_test(NAME ${BINARY} COMMAND ${BINARY})
target_link_libraries(${BINARY} PUBLIC computelib gtest)

