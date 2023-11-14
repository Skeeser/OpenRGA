#pragma once

#pragma once

#include <dlfcn.h>
// #include "RgaApi.h"

#include "rga.h"
#include "RgaUtils.h"
#include "im2d.hpp"
// #include "utils.h"
#include "opencv2/opencv.hpp"

namespace RGA
{
    struct MatData
    {
        int src_width;
        int src_height;
        int src_format;
    };

    class Mat
    {
    public:
        Mat() : src_width(0), src_height(0), src_format(-1), src_buf_size(0), src_buf(nullptr), empty_flag(true)
        {
        }

        Mat(const cv::Mat &src_mat)
        {
            src_width = src_mat.cols;
            src_height = src_mat.rows;
            judgeFormat(src_mat);
            empty_flag = src_mat.empty();
            src_buf_size = src_width * src_height * get_bpp_from_format(src_format);
            src_buf = new char[src_buf_size];
            memcpy(src_buf, src_mat.data, src_buf_size);
        }

        Mat &operator=(const Mat &cpy_mat)
        {
            // todo: 防止自我赋值
            return *this;
        }

        bool empty()
        {
            return empty_flag;
        }

        char *retMat()
        {
            return src_buf;
        }

        struct MatData retMatData()
        {
            struct MatData md;
            md.src_format = src_format;
            md.src_height = src_height;
            md.src_width = src_width;
            return md;
        }

        ~Mat()
        {
            delete[] src_buf;
        }

    private:
        void judgeFormat(const cv::Mat &src_mat)
        {
            if (src_mat.type() != CV_8UC3)
            {
                src_format = -1;
                std::cerr << "source image type is: " << src_mat.type() << std::endl;
                return;
            }
            else
            {
                src_format = RK_FORMAT_RGB_888;
            }
        }

    private:
        int src_width;
        int src_height;
        int src_format;
        int src_buf_size;
        char *src_buf;
        bool empty_flag;
    };

}
