#include <cstdint>
#include <gtest/gtest.h>
#include <opencv2/core/core.hpp>
#include <opencv2/core/types.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include "optical_flow.hpp"

TEST(test_optical_flow, test_optical_flow) {
    cv::Mat img1_mat = cv::imread(
        "/home/yeren/OneDrive/C C++ Projects/optical_flow/test/3.jpg",
        // "/home/yeren/OneDrive/C C++ Projects/optical_flow/test/1.png",
        // "/home/yeren/dataset/sequences/05/image_0/000000.png",

        cv::IMREAD_GRAYSCALE);
    cv::resize(img1_mat, img1_mat, cv::Size(), 0.25, 0.25, cv::INTER_NEAREST);
    uint8_t *img1 = img1_mat.data;
    cv::Mat img2_mat = cv::imread(
        "/home/yeren/OneDrive/C C++ Projects/optical_flow/test/4.jpg",
        // "/home/yeren/OneDrive/C C++ Projects/optical_flow/test/2.png",
        // "/home/yeren/dataset/sequences/05/image_0/000001.png",
        cv::IMREAD_GRAYSCALE);
    cv::resize(img2_mat, img2_mat, cv::Size(), 0.25, 0.25, cv::INTER_NEAREST);

    uint8_t *img2 = img2_mat.data;
    OpticalFlow opt_flow(img1_mat.rows, img1_mat.cols, 17, 20, SSD_BLOCK_MATCH);

    float mean_shift_x, mean_shift_y;
    int quality;
    quality = opt_flow.calFlow(img1, img2, mean_shift_x, mean_shift_y);
    std::cout << "Quality of optical flow is " << quality << std::endl
              << "mean shift off x and y are " << mean_shift_x << " and "
              << mean_shift_y << std::endl;

    for (int i = 0; i < opt_flow.count_; i++) {
        cv::line(
            img1_mat,
            cv::Point(*(opt_flow.shift_col_ + i), *(opt_flow.shift_row_ + i)),
            cv::Point(
                *(opt_flow.shift_col_ + i) + *(opt_flow.shift_y_ + i),
                *(opt_flow.shift_row_ + i) + *(opt_flow.shift_x_ + i)),
            cv::Scalar(0, 0, 255));
        cv::circle(
            img1_mat,

            cv::Point(
                *(opt_flow.shift_col_ + i) + *(opt_flow.shift_y_ + i),
                *(opt_flow.shift_row_ + i) + *(opt_flow.shift_x_ + i)),
            2, cv::Scalar(0, 0, 255));
    }
    cv::imwrite("optical_1.png", img1_mat);

    ASSERT_TRUE(true);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);

    // Runs all tests using Google Test.
    return RUN_ALL_TESTS();
}