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

    struct MatSize
    {
        int width;
        int height;
    };

    class Size
    {
    public:
        Size(const int width, const int height) : width_(width), height_(height)
        {
        }

        Size &operator=(const Size &cpy_size)
        {
            // todo: 防止自我赋值
            return *this;
        }

        struct MatSize getSize() const
        {
            struct MatSize ms;
            ms.height = height_;
            ms.width = width_;
            return ms;
        }

        ~Size()
        {
        }

    private:
        Size()
        {
        }

    private:
        int width_;
        int height_;
    };

}
