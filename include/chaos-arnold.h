#ifndef CHAOS_ARNOLD_H
#define CHAOS_ARNOLD_H

#include <opencv2/opencv.hpp>
#include <chaos-imp-base.h>

using namespace cv;

namespace chaos{
    class chaos_arnold{
    public:
        static void arnold(Mat &image, Mat &out);
    private:
        static int __gcd(int a, int b);
    };
}

#endif