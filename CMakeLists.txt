cmake_minimum_required(VERSION 3.20)

project(ctest)
set(EXEC "ctest")

# import google test module
enable_testing()
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

# set compilation flags
include(etc/cflags.cmake)

add_subdirectory(src)

add_executable(${EXEC} main.cpp)
target_link_libraries(${EXEC} PRIVATE run_app)

add_subdirectory(test)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
