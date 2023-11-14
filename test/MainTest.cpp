#include <iostream>
#include <OpenRGA/imread.h>
// #include "gtest/gtest.h"

int main(int argc, char *argv[])
{

    auto image = RGA::imread("/home/orangepi/OpenRGA/assets/scut.jpg");
    auto image_data = image.retMatData();
    auto mat = image.retMat();
    mat[1000] = '\0';
    std::cout << "src_width: " << image_data.src_width << std::endl;
    std::cout << "src_height: " << image_data.src_height << std::endl;
    std::cout << "image_data: " << mat << std::endl;
    return 0;
}

// 初始化读入图片
// TEST(OpenRGA, imread)
// {
//     auto image = RGA::imread("../assets/scut.jpg");
//     auto image_data = image.retMatData();
//     ASSERT_EQ(image_data.src_width, 537);
//     ASSERT_EQ(image_data.src_height, 541);
// }

// testing::InitGoogleTest(&argc, argv);
// return RUN_ALL_TESTS();