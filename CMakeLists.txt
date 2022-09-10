cmake_minimum_required(VERSION 3.2.0)

set(CMAKE_CXX_STANDARD 14)
# set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_C_STANDARD 11)


if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
    message("Setting default build type to Release")
endif()

project(optical_flow VERSION 0.0.1 LANGUAGES C CXX)

include_directories(${PROJECT_SOURCE_DIR}/include)


################################
# GTest
################################
find_package(GTest REQUIRED)
enable_testing()
include_directories(${GTEST_INCLUDE_DIRS})

find_package(Threads REQUIRED)







        add_subdirectory(./src)

        add_subdirectory(./test)
        
        add_subdirectory(./example)