CMAKE_MINIMUM_REQUIRED(VERSION 3.0)

# set project name
PROJECT(algorithms)

# set default compilers
SET(CMAKE_CXX_COMPILER "g++")
SET(CMAKE_C_COMPILER "gcc")

# C++ compiler flags
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread" )

# set source dir and test dir
SET(SOURCE_DIR ${PROJECT_SOURCE_DIR}/src)
 
# add the binary tree to the search path for include files
# so that we will find TutorialConfig.h
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
