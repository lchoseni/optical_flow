#pragma once

#include "block_match.hpp"

#define SSD_BLOCK_MATCH 0

class OpticalFlow{
    public:
    BlockMatcher *blockMatcher_;
    int img_height_, img_width_, win_size_;

    OpticalFlow(int img_height, int img_width, int win_size, int block_matcher_type);
    void calFlow(uint8_t *pre_img, uint8_t *cur_img);
    void match();
};