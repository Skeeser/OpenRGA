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
        Mat() : src_width_(0), src_height_(0), src_format_(-1), src_buf_size_(0), src_buf_(nullptr), empty_flag_(true)
        {
        }

        Mat(const cv::Mat &src_mat)
        {
            src_width_ = src_mat.cols;
            src_height_ = src_mat.rows;
            judgeFormat(src_mat);
            empty_flag_ = src_mat.empty();
            src_buf_size_ = src_width_ * src_height_ * get_bpp_from_format(src_format_);
            src_buf_ = new char[src_buf_size_];
            memcpy(src_buf_, src_mat.data, src_buf_size_);
        }

        Mat &operator=(const Mat &cpy_mat)
        {
            // todo: 防止自我赋值
            return *this;
        }

        bool empty()
        {
            return empty_flag_;
        }

        char *retMat()
        {
            return src_buf_;
        }

        struct MatData retMatData()
        {
            struct MatData md;
            md.src_format = src_format_;
            md.src_height = src_height_;
            md.src_width = src_width_;
            return md;
        }

        ~Mat()
        {
            delete[] src_buf_;
        }

    private:
        void judgeFormat(const cv::Mat &src_mat)
        {
            if (src_mat.type() != CV_8UC3)
            {
                src_format_ = -1;
                std::cerr << "source image type is: " << src_mat.type() << std::endl;
                return;
            }
            else
            {
                src_format_ = RK_FORMAT_RGB_888;
            }
        }

    private:
        int src_width_;
        int src_height_;
        int src_format_;
        int src_buf_size_;
        char *src_buf_;
        bool empty_flag_;
    };

}
