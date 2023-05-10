#ifndef CHAOS_ARNOLD_H
#define CHAOS_ARNOLD_H

#include <opencv2/core.hpp>
#include <chaos-imp-base.h>

using namespace cv;

namespace chaos{
    class chaos_arnold{
    public:
        static void arnold(Mat &image, Mat &out);

        static void rarnold(Mat &image, Mat &out);

        static void arnold_n(Mat &image, Mat &out, int t);

        static void rarnold_n(Mat &image, Mat &out, int t);
    private:
        static int __gcd(int a, int b);

        static int __mod(int a, int b);
    };
}

#endif