cmake_minimum_required(VERSION 3.25.2)
project(Project_5 C)

set(CMAKE_C_STANDARD 99)

include_directories(.)



set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_VERBOSE_MAKEFILE ON)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99 -pedantic -Wall -Werror")
set(SOURCE_FILES main.c Boolean.c Circuit.c Gates.c strdup.c main.c)

add_executable(Project_5 ${SOURCE_FILES})

target_link_libraries(Project_5 m)