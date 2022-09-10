#include "block_match.hpp"
#include <cstdint>
#include <iostream>

using namespace std;

BlockMatcher::BlockMatcher(int win_size, int img_height, int img_width): win_size_(win_size), img_height_(img_height), img_width_(img_width){
    if(win_size % 2 != 1){
        cout << "size of matching window should be odd and is modified to be odd." << endl;
        win_size_ = win_size  + 1;
    }
}

