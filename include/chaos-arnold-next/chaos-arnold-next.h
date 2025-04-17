#ifndef CHAOS_ARNOLD_H
#define CHAOS_ARNOLD_H

#include <opencv2/core.hpp>
#include <chaos-imp-base.h>

using namespace cv;

namespace chaos{
    class chaos_arnold{
    public:
        //Arnold 变换方法，用户API
        static void arnold(Mat &image, Mat &out, int t);
        //Arnold 逆变换方法，用户API
        static void rarnold(Mat &image, Mat &out, int t);
    private:
        //欧几里得算法求最大公因数
        static int __gcd(int a, int b);
        //兼容负数取模算法
        static int __mod(int a, int b);

        //标准Arnold变换坐标计算函数
        static void __arnold_x(int size[], int q, int pos[]);
        //交换Arnold变换坐标计算函数，x,y公式交换改进横向长于纵向图像的置乱效率
        static void __arnold_y(int size[], int q, int pos[]);
        //标准Arnold变换(arnold_x)的逆坐标计算函数
        static void __rarnold_x(int size[], int q, int pos[]);
        //交换Arnold变换(arnold_y)的逆坐标计算函数
        static void __rarnold_y(int size[], int q, int pos[]);

        //通用变换函数，使用指定的参数进行变换
        static void __transform(Mat &image, //输入图像
                              Mat &out,   //输出图像
                              void (*position)(int size[], int q, int pos[]), //坐标计算函数
                              int t);     //迭代次数

    };
}

#endif