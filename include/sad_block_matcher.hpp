#pragma once

#include "block_match.hpp"

class SADBlockMatcher: public BlockMatcher{

    public:

    SADBlockMatcher(int img_height, int img_width, int win_size);

    int computeSSDDistance(uint8_t &pre_img, uint8_t &cur_img, int &pre_row, int &pre_col, int &cur_row, int &cur_col);

    virtual int match(uint8_t &pre_img, uint8_t &cur_img, int &pre_row, int &pre_col, int &cur_row, int &cur_col) override;


};