cmake_minimum_required(VERSION 3.10)
project(sorting_performance C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_executable(sorting_performance
    src/main.c
    src/sorting_algorithms.c
    src/benchmark.c
    src/plot.c
)

target_include_directories(sorting_performance PRIVATE include)

if(CMAKE_C_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(sorting_performance PRIVATE -Wall -Wextra)
endif()
