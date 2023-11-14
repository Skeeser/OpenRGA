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

    class Size
    {
    public:
        Size(const int width, const int height) : src_width(width),
        {
            src_width = src_mat.cols;
            src_height = src_mat.rows;
            judgeFormat(src_mat);
            empty_flag = src_mat.empty();
            src_buf_size = src_width * src_height * get_bpp_from_format(src_format);
            src_buf = new char[src_buf_size];
            memcpy(src_buf, src_mat.data, src_buf_size);
        }

        Size &operator=(const Size &cpy_size)
        {
            // todo: 防止自我赋值
            return *this;
        }

        ~Size()
        {
        }

    private:
        Size()
        {
        }

    private:
        int src_width;
        int src_height;
    };

}
