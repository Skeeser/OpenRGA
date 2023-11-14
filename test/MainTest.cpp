extern "C"
{
}
#include "gtest/gtest.h"

// 初始化测试
TEST(GFS, init)
{
    void *ret = GFS_init((fuse_conn_info *)NULL, (fuse_config *)NULL);
    ASSERT_EQ(NULL, ret);
}

int main(int argc, char *argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}