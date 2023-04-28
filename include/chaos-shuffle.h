#ifndef CHAOS_SHUFFLE_H
#define CHAOS_SHUFFLE_H

#include <opencv2/opencv.hpp>
#include <chaos-rng.h>

using namespace cv;

namespace chaos{
    class chaos_shuffle{
    public:
        static int shuffle(Mat &image, chaos_rng &rng);

        static int encrypt(Mat &image, chaos_rng &rng);

    private:
        static void __shuffle_row(Mat &im_row, chaos_rng &rng);
        static inline void __swap_pixel(int elemsize, uchar *p1, uchar *p2);
    };
}

#endif