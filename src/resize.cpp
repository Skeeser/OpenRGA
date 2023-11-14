#include "resize.h"

namespace RGA
{

    void resize(const Mat &src_image, Mat &dst_image, const Size &target_size)
    {
        // init rga context
        rga_buffer_t src;
        rga_buffer_t dst;
        memset(&src, 0, sizeof(src));
        memset(&dst, 0, sizeof(dst));

        im_rect src_rect;
        im_rect dst_rect;
        memset(&src_rect, 0, sizeof(src_rect));
        memset(&dst_rect, 0, sizeof(dst_rect));

        auto mat_info = src_image.getMatInfo();
        size_t img_width = mat_info.src_width;
        size_t img_height = mat_info.src_height;
        size_t img_format = mat_info.src_format;

        auto target_size_info = target_size.getSize();
        size_t target_width = target_size_info.width;
        size_t target_height = target_size_info.height;

        src = wrapbuffer_virtualaddr((void *)src_image.src_buf_, img_width, img_height, img_format);
        dst_image.initEmptyMat(target_width, target_height, img_format);
        dst = wrapbuffer_virtualaddr((void *)dst_image.src_buf_, target_width, target_height, img_format);

        int ret = imcheck(src, dst, src_rect, dst_rect);
        if (IM_STATUS_NOERROR != ret)
        {
            fprintf(stderr, "rga check error! %s", imStrError((IM_STATUS)ret));
            return;
        }

        IM_STATUS STATUS = imresize(src, dst);
        return;
    }

}