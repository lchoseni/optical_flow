#include "block_match.hpp"
#include <cstdint>
#include <iostream>

using namespace std;

BlockMatcher::BlockMatcher(int win_size): win_size_(win_size){
    if(win_size % 2 != 1){
        cout << "size of matching window should be odd and is modified to be odd." << endl;
        win_size_ = win_size  + 1;
    }
}

// Get the pixel location in the array.
int BlockMatcher::getPixelLocation(int img_height, int img_width, int row, int col){
    if(row < 0 || row >= img_height || col < 0 || col >= img_width)
        return -1;
    int row_start = row * img_width;
    return row_start + col;
}