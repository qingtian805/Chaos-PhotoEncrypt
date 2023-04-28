#ifndef CHAOS_ARNOLD_H
#define CHAOS_ARNOLD_H

#include <opencv2/opencv.hpp>

namespace chaos{
    class chaos_arnold{
    public:
        static void arnold(Mat &image);
    };
}

#endif