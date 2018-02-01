cmake_minimum_required(VERSION 3.9)
project(MachineLearning)

set(CMAKE_CXX_STANDARD 11)

add_executable(MachineLearning main.cpp)

target_link_libraries(MachineLearning curl tidy)