#include <iostream>
#include <OpenRGA/imread.h>
#include "gtest/gtest.h"

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

int main(int argc, char *argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
