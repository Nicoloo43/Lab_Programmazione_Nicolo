cmake_minimum_required(VERSION 3.5)
project(El_Lab_Prog)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

add_subdirectory(Test)

set(SOURCE_FILES Account.cpp Account.h Transaction.cpp Transaction.h)
add_executable(El_Lab_Prog main.cpp)

add_library(core ${SOURCE_FILES})
target_link_libraries(El_Lab_Prog core)