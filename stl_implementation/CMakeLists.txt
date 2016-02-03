project(stl_implentation)
cmake_minimum_required(VERSION 2.8)
aux_source_directory(. SRC_LIST)
add_executable(${PROJECT_NAME} ${SRC_LIST})

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Link runTests with what we want to test and the GTest and pthread library
#add_executable(${PROJECT_NAME} tests.cpp)
target_link_libraries(${PROJECT_NAME} ${GTEST_LIBRARIES} pthread)

## Compiler flags
if(CMAKE_COMPILER_IS_GNUCXX)
    set(CMAKE_BUILD_TYPE "Debug")
endif()

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

