#include <iostream>
#include <OpenRGA/imread.h>
#include "gtest/gtest.h"
#include <OpenRGA/rga_utils.hpp>
#include <OpenRGA/resize.h>
#include "opencv2/opencv.hpp"

// 初始化读入图片
TEST(OpenRGA, imread)
{
    auto image = RGA::imread("/home/orangepi/OpenRGA/assets/scut.jpg");
    auto image_data = image.getMatInfo();
    auto mat = image.src_buf_;
    mat[1000] = '\0';
    ASSERT_EQ(image_data.src_width, 537);
    ASSERT_EQ(image_data.src_height, 541);
    std::cout << "image_data: " << mat << std::endl;
}

// resize功能测试
TEST(OpenRGA, resize_func)
{
    RGA::Mat image_rga = RGA::imread("/home/orangepi/OpenRGA/assets/scut_16.jpg");
    // 定义目标大小
    RGA::Size targetSize(80, 80);
    // 调整图像大小
    RGA::Mat resizedImage;
    RGA::resize(image_rga, resizedImage, targetSize);
    auto image_data = resizedImage.getMatInfo();
    ASSERT_EQ(image_data.src_width, 80);
    ASSERT_EQ(image_data.src_height, 80);
}

// resize速度测试
TEST(OpenRGA, resize_fast)
{
    RGA::Mat image_rga = RGA::imread("/home/orangepi/OpenRGA/assets/scut_16.jpg");
    cv::Mat image_opencv = cv::imread("/home/orangepi/OpenRGA/assets/scut_16.jpg");
    RGA::Timer timer;

    // 测试opencv的速度
    for (int i = 0; i < 1000; ++i)
    {
        // 定义目标大小
        cv::Size targetSize(80, 80); // 200宽，150高
        // 调整图像大小
        cv::Mat resizedImage;
        cv::resize(image_opencv, resizedImage, targetSize);
    }

    // timer.PrintElapsedSeconds("Opencv resize time taken: ");

    // 重新计时
    timer.Reset();

    // 测试rga的速度
    for (int i = 0; i < 1000; ++i)
    {
        // 定义目标大小
        RGA::Size targetSize(80, 80); // 200宽，150高
        // 调整图像大小
        RGA::Mat resizedImage;
        RGA::resize(image_rga, resizedImage, targetSize);
    }

    // timer.PrintElapsedSeconds("RGA resize time taken: ");
}

int main(int argc, char *argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
