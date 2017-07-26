CMAKE_MINIMUM_REQUIRED(VERSION 3.0)

# set project name
PROJECT(algorithms)

# set default compilers
SET(CMAKE_CXX_COMPILER "g++")
SET(CMAKE_C_COMPILER "gcc")

# C++ compiler flags
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wall -pedantic" )

# set source dir
SET(SOURCE_DIR
    ${PROJECT_SOURCE_DIR}/src)
 
# include directories
INCLUDE_DIRECTORIES(
    ${SOURCE_DIR}
)

# Output directories
SET(
    EXECUTABLE_OUTPUT_PATH
    ${CMAKE_BINARY_DIR}/bin
)

# add the executable
ADD_EXECUTABLE(
    algorithms
    src/main.cc
)
