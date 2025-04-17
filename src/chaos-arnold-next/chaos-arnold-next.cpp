#include <opencv2/core.hpp>
#include <chaos-arnold-next.h>
#include <iostream>

using namespace chaos;
using namespace cv;

void chaos_arnold::arnold(Mat &image, Mat &out, int t)
{

}

void chaos_arnold::rarnold(Mat &image, Mat &out, int t)
{

}

int chaos_arnold::__gcd(const int _a, const int _b)
{
    int a = _a;
    int b = _b;
    int tmp;
    
    //阿基米德算法
    while(b){
        a %= b;
        tmp = a;
        a = b;
        b = tmp;
    }

    return a;
}

int chaos_arnold::__mod(const int _a, const int mod)
{
    int a = _a % mod;

    if(a >= 0)
        return a;
    
    //负数情况修正
    return a + mod;
}

// inline void chaos_arnold::__m_mul(int m[], int n[], int ret[])
// {
//     ret[0] = m[0] * n[0] + m[1] * n[2];
//     ret[1] = m[0] * n[1] + m[1] * n[3];
//     ret[2] = m[2] * n[0] + m[3] * n[2];
//     ret[3] = m[2] * n[1] + m[3] * n[3];
// }

// inline void chaos_arnold::__m_copy(int res[], int dest[])
// {
//     dest[0] = res[0];
//     dest[1] = res[1];
//     dest[2] = res[2];
//     dest[3] = res[3];
// }


void chaos_arnold::__arnold_x(int size[], int q, int pos[])
{
    //q * i + (q + 1) * j) % row, (i + j) % col
    int matrix[4];
    int q;

    q = image.rows / __gcd(image.rows, image.cols);

    matrix[0] = 1;
    matrix[1] = 1;
    matrix[3] = q;
    matrix[4] = q + 1;
}

void chaos_arnold::__arnold_y(int size[], int q, int pos[])
{
    int matrix[4];
    int q;

    q = image.rows / __gcd(image.rows, image.cols);

    matrix[0] = 1;
    matrix[1] = 1;
    matrix[3] = q;
    matrix[4] = q + 1;
}

void chaos_arnold::__rarnold_x(int size[], int q, int pos[])
{
    int matrix[4];
    int q;

    q = image.rows / __gcd(image.rows, image.cols);

    matrix[0] = 1;
    matrix[1] = 1;
    matrix[3] = q;
    matrix[4] = q + 1;
}

void chaos_arnold::__rarnold_y(int size[], int q, int pos[])
{
    int matrix[4];
    int q;

    q = image.rows / __gcd(image.rows, image.cols);

    matrix[0] = 1;
    matrix[1] = 1;
    matrix[3] = q;
    matrix[4] = q + 1;
}

void chaos_arnold::__transform(Mat &image, Mat &out, void (*position)(int size[], int q, int pos[]), int t)
{
    int i;
}
