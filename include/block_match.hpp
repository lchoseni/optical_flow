#pragma once

#include <cstdint>

class BlockMatcher {
  public:
    int win_size_;

    BlockMatcher(int win_size);

    virtual int match(
        uint8_t *pre_img,
        uint8_t *cur_img,
        int &pre_row,
        int &pre_col,
        int &cur_row,
        int &cur_col) = 0;

  protected:
    int getPixelLocation(int img_height, int img_width, int row, int col);
};