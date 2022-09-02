# for each "src/x.cpp", generate target "x"
add_library(optical_flow block_match.cpp optical_flow.cpp sad_block_match.cpp)