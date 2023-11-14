#include "imread.h"

namespace RGA
{

    RGA::Mat imread(const std::string &filename)
    {
        // 读取图像
        cv::Mat image = cv::imread(filename, cv::IMREAD_COLOR);

        // 检查图像是否成功读取
        if (image.empty())
        {
            RGA::Mat empty;
            std::cerr << "Error: Could not open or find the image." << std::endl;
            return empty;
        }

        return RGA::Mat(image);
    }
}