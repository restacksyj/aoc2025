cmake_minimum_required(VERSION 3.12)
project(aoc10)

# REQUIRED: Z3 headers use noexcept → means you MUST compile with C++11 or newer
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find the Z3 package (installed via Homebrew)
find_package(Z3 REQUIRED)

add_executable(output 10_3.cpp)

# Link your target to Z3
target_link_libraries(output PRIVATE z3::libz3)

