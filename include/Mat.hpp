#pragma once

#include <dlfcn.h>
// #include "RgaApi.h"
#include <memory>
#include "rga.h"
#include "RgaUtils.h"
#include "im2d.hpp"
// #include "utils.h"
#include "opencv2/opencv.hpp"

namespace RGA
{
    struct MatInfo
    {
        int src_width;
        int src_height;
        int src_format;
        int src_buf_size;
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
        Mat(const Mat &src_mat)
        {
            cpyMat(src_mat);
        }

        void initEmptyMat(const int &width, const int &height, const int &format)
        {
            src_width_ = width;
            src_height_ = height;
            src_format_ = format;
            src_buf_size_ = width * height * get_bpp_from_format(format);

            //  防止本来就有数据没释放
            if (src_buf_ != nullptr)
            {
                delete[] src_buf_;
            }
            src_buf_ = new char[src_buf_size_];
            empty_flag_ = false;
        }

        Mat &operator=(const Mat &cpy_mat)
        {
            cpyMat(cpy_mat);
            // todo: 防止自我赋值
            return *this;
        }

        bool empty()
        {
            return src_buf_ == nullptr;
        }

        const char *getMatData() const
        {
            if (empty_flag_)
            {
                std::cerr << "Mat is empty!" << std::endl;
                return nullptr;
            }
            return src_buf_;
        }

        const struct MatInfo getMatInfo() const
        {
            struct MatInfo md;
            md.src_format = src_format_;
            md.src_height = src_height_;
            md.src_width = src_width_;
            md.src_buf_size = src_buf_size_;
            return md;
        }

        ~Mat()
        {
            delete[] src_buf_;
        }

    public:
        char *src_buf_;

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

        void cpyMat(const Mat &src_mat)
        {
            auto mat_info = src_mat.getMatInfo();
            src_format_ = mat_info.src_format;
            src_height_ = mat_info.src_height;
            src_width_ = mat_info.src_width;
            src_buf_size_ = mat_info.src_buf_size;
            src_buf_ = new char[src_buf_size_];
            memcpy(src_buf_, src_mat.getMatData(), src_buf_size_);
        }

    private:
        int src_width_;
        int src_height_;
        int src_format_;
        int src_buf_size_;
        bool empty_flag_;
    };

}
