#ifndef CHAOS_ARNOLD_H
#define CHAOS_ARNOLD_H

#include <opencv2/core.hpp>
#include <chaos-imp-base.h>

using namespace cv;

namespace chaos{
    class chaos_arnold{
    public:
        //Arnold 变换方法，不能原地变换，两个参数需要确定不同，没有内部检查
        static void arnold(Mat &image, Mat &out);
        //Arnold 逆变换方法，不能原地变换，两个参数需要确定不同，没有内部检查
        static void rarnold(Mat &image, Mat &out);
        //Arnold变换 迭代，不能原地变换，两个参数需要确定不同，没有内部检查
        static void arnold_n(Mat &image, Mat &out, int t);
        //Arnold逆变换 迭代，不能原地变换，两个参数需要确定不同，没有内部检查
        static void rarnold_n(Mat &image, Mat &out, int t);
    private:
        //欧几里得算法求最大公因数
        static int __gcd(int a, int b);
        //兼容负数取模算法
        static int __mod(int a, int b);
    };
}

#endif