#pragma once
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <time.h>
#include <dlfcn.h>
// #include "RgaApi.h"

#include "rga.h"
#include "RgaUtils.h"
#include "im2d.hpp"
// #include "utils.h"
#include "Mat.hpp"
#include "Size.hpp"

namespace RGA
{
    void resize(const Mat &src, Mat &dst, const Size &target_size);
}
