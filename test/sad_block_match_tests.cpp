#include "sad_block_match.hpp"
#include <cstdlib>
#include <gtest/gtest.h>

TEST(test_sad_block_match, test_compute_sad_distance) {
    int img_height = 40, img_width = 40, win_size = 9;
    SADBlockMatcher matcher(img_height, img_width, win_size);

    uint8_t *img1 = (uint8_t *)malloc(sizeof(uint8_t) * img_height * img_width);
    uint8_t *img2 = (uint8_t *)malloc(sizeof(uint8_t) * img_height * img_width);
    for (int row = 0; row < img_height; row++) {
        for(int col = 0; col < img_width; col++){
            *(img1 + row * img_height + col) = row;
            *(img2 + row * img_height + col) = row;
        }
    }
    // ASSERT_EQ(matcher.computeSADDistance(img1, img2, 0, 0, 0, 0), -1);
    // ASSERT_EQ(
    //     matcher.computeSADDistance(
    //         img1, img2, win_size / 2 - 1, win_size / 2, win_size / 2,
    //         win_size / 2),
    //     -1);
    ASSERT_EQ(
        matcher.computeSADDistance(
            img1, img2, win_size / 2, win_size / 2, win_size / 2, win_size / 2),
        0);
    ASSERT_EQ(
        matcher.computeSADDistance(
            img1, img2, win_size / 2, win_size / 2, win_size / 2 + 1,
            win_size / 2 ),
        win_size * win_size);
    ASSERT_EQ(
        matcher.computeSADDistance(
            img1, img2, win_size / 2, win_size / 2, win_size / 2 + 1,
            win_size / 2 + 1),
        win_size * win_size);
    free(img1);
    free(img2);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);

    // Runs all tests using Google Test.
    return RUN_ALL_TESTS();
}