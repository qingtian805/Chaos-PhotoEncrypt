#ifndef CHAOS_RANENC_H
#define CHAOS_RANENC_H

#include <opencv2/core.hpp>
#include <chaos-rng.h>

using namespace chaos;
using namespace cv;

namespace chaos{
    class chaos_ranenc{
    public:
        //加解密函数。异或运算的性质使此方法可以同时兼顾两个功能
        static void rand_enc(Mat &image, chaos_rng &rng);
    };
}

#endif