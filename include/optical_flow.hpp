#pragma once

#include "block_match.hpp"
#include <cstdint>

#define SSD_BLOCK_MATCH 0

class OpticalFlow {
  public:
    BlockMatcher *blockMatcher_;
    int img_height_, img_width_, win_size_, step_size_;
    int distance_up_threshold_ = 4000, distance_low_threshold_ = 400,
        sub_shift_size_ = 3, // Length for subpixel shift
        hist_range_ = 6;
    int shift_arr_size_, count_;
    int8_t *shift_x_, *shift_y_;
    uint16_t *shift_row_, *shift_col_;

    OpticalFlow(
        int img_height,
        int img_width,
        int win_size,
        int step_size_,
        int block_matcher_type);
    ~OpticalFlow();
    int calFlow(
        uint8_t *&pre_img,
        uint8_t *&cur_img,
        float &mean_shift_x,
        float &mean_shift_y);
    void getSubPixelShift(
        uint8_t *pre_img,
        uint8_t *cur_img,
        int pre_row,
        int pre_col,
        int cur_row,
        int cur_col,
        uint8_t &min_dir);
};