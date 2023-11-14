extern "C"
{
#include <OpenRGA/imread.h>
}
#include "gtest/gtest.h"

// 初始化读入图片
TEST(OpenRGA, imread)
{
}

int main(int argc, char *argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}