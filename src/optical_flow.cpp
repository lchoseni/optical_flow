#include "optical_flow.hpp"
#include "sad_block_match.hpp"

OpticalFlow::OpticalFlow(
    int img_height, int img_width, int win_size, int block_matcher_type)
    : img_height_(img_height), img_width_(img_width), win_size_(win_size) {
    switch (block_matcher_type) {
        // case SSD_BLOCK_MATCH:
        //     blockMatcher_ =
        //         new SADBlockMatcher(img_height, img_width, win_size_);
        //     break;
        // default:
        //     blockMatcher_ =
        //         new SADBlockMatcher(img_height, img_width, win_size_);
        //     break;
    }
}

void OpticalFlow::calFlow(uint8_t *pre_img, uint8_t *cur_img) {
    // For each block find the best matched pixel.
    int cur_row, cur_col;
    int row_start = win_size_ / 2 + 1,
        row_end = img_height_ - win_size_ / 2 - 1,
        col_start = win_size_ / 2 + 1, col_end = img_width_ - win_size_ / 2 - 1;
    for (int row = row_start; row < row_end; row+= win_size_) {
        for (int col = col_start; col < col_end; col += win_size_) {
            if (-1
                == blockMatcher_->match(
                    pre_img, cur_img, row, col, cur_row, cur_col)) {}
        }
    }
}