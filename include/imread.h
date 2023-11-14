#pragma once
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <time.h>
#include <dlfcn.h>
// #include "RgaApi.h"
#include <string>
#include <iostream>
#include <stdexcept>
#include <opencv2/opencv.hpp>

#include "rga.h"
#include "RgaUtils.h"
#include "im2d.hpp"
// #include "utils.h"
#include "Mat.hpp"

#ifdef __cplusplus
extern "C"
{
#endif

    /*
    实现过于难了, 能力有限, 暂停开发
    */

    namespace RGA
    {

        RGA::Mat imread(const std::string &filename);
    }

#ifdef __cplusplus
}
#endif