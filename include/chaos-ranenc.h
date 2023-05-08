#ifndef CHAOS_RANENC_H
#define CHAOS_RANENC_H

#include <opencv2/core.hpp>
#include <chaos-rng.h>

using namespace chaos;
using namespace cv;

namespace chaos{
    class chaos_ranenc{
    public:
        static void rand_enc(Mat &image, chaos_rng &rng);
    };
}

#endif