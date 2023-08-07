cmake_minimum_required(VERSION 3.5)

add_subdirectory(./googletest-main)
set(gtest_SOURCE_DIR, ./googletest-main)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(TEST_SOURCE_FILES runAllTests.cpp AccountFixture.cpp AccountTest.cpp TransactionTest.cpp TransactionFixture.cpp)
add_executable(runAllTests ${TEST_SOURCE_FILES})
target_link_libraries(runAllTests gtest gtest_main core)