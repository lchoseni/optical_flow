# for each "test/x.cpp", generate target "x"
# file(GLOB_RECURSE all_tests *.cpp)
# foreach(v ${all_tests})
#     string(REGEX MATCH "test/.*" relative_path ${v})
#     # message(${relative_path})
#     string(REGEX REPLACE "test/" "" target_name ${relative_path})
#     string(REGEX REPLACE ".cpp" "" target_name ${target_name})

#     add_executable(${target_name} ${v})
#     target_link_libraries(${target_name} gtest Threads::Threads)
# endforeach()

find_package(OpenCV 3.1 REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(optical_flow_tests optical_flow_tests.cpp)
add_test( optical_flow_tests optical_flow_tests )
add_executable(sad_block_match_tests sad_block_match_tests.cpp)
add_test( sad_block_match_tests sad_block_match_tests )

target_link_libraries(sad_block_match_tests optical_flow gtest Threads::Threads)
target_link_libraries(optical_flow_tests optical_flow gtest Threads::Threads ${OpenCV_LIBS})