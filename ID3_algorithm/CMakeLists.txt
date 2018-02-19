cmake_minimum_required(VERSION 3.9)
project(ID3_algorithm)

set(CMAKE_CXX_STANDARD 11)

find_package (Eigen3 3.3 REQUIRED NO_MODULE)

add_executable(ID3_algorithm main.cpp)
target_link_libraries (ID3_algorithm Eigen3::Eigen)