project(POSIX_state_machine)
cmake_minimum_required(VERSION 3.4 FATAL_ERROR)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../bin)

include_directories(include)
include_directories(espl_lib)
include_directories(states_lib)

file(GLOB CHALLENGE2_SOURCES "src/challenge2/*.c")
file(GLOB CHALLENGE3_SOURCES "src/challenge3/*.c")

add_executable(challenge2 ${CHALLENGE2_SOURCES})
add_executable(state_machine ${CHALLENGE3_SOURCES})

file(GLOB ESPL_LIB_SRCS "espl_lib/*.c")
add_library(ESPL_LIB ${ESPL_LIB_SRCS})
target_link_libraries(challenge2 ESPL_LIB)

file(GLOB STATES_LIB_SRCS "states_lib/*.c")
add_library(STATES_LIB STATIC ${STATES_LIB_SRCS})
target_link_libraries(state_machine STATES_LIB)

if(UNIX AND NOT APPLE)
    target_link_libraries(state_machine rt)
endif()
