#pragma once

#include <cstdint>

class BlockMatcher {
  public:
    int win_size_,img_height_, img_width_;

    BlockMatcher(int win_size, int img_height, int img_width);

    virtual int match(
    uint8_t *&pre_img,
    uint8_t *&cur_img,
        int &pre_row,
        int &pre_col,
        int &cur_row,
        int &cur_col) = 0;


};