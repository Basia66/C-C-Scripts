cmake_minimum_required(VERSION 3.10)
project(lab6 C)

set(CMAKE_C_STANDARD 11)

add_executable(lab6 main.c lista.c)

target_link_libraries(lab6 m)

set(GCC_COVERAGE_COMPILE_FLAGS "-Wall -Wextra -Wpedantic -Werror")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")