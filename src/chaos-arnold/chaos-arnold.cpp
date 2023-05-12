#include <opencv2/core.hpp>
#include <chaos-arnold.h>
#include <iostream>

using namespace chaos;
using namespace cv;

void chaos_arnold::arnold(Mat &image, Mat &out)
{
    int i, j;
    int row = image.rows;
    int col = image.cols;
    int q;
    uchar *p;
    
    q = __gcd(row, col);

    q = row / q;

    //j for y, i for x
    for(j = 0; j < row; j++){
        p = image.ptr<uchar>(j);
        for(i = 0; i < col; i++){
            Vec3b &op = out.at<Vec3b>((q * i + (q + 1) * j) % row, (i + j) % col);
            op[0] = *p++;
            op[1] = *p++;
            op[2] = *p++;
        }
    }
}

void chaos_arnold::arnold_n(Mat &image, Mat &out, int t)
{
    int i;
    Mat tmp;

    if(t < 1)
        return;

    image.copyTo(tmp);

    if(tmp.empty()){
        std::cout << "Not enough memory" << std::endl;
        return;
    }

    i = 0;
    while(i < t){
        arnold(tmp, out);
        i++;
        if(i > t){
            goto ODD_OUT;
        }
        arnold(out, tmp);
        i++;
    }

    out.release();
    out = tmp;
ODD_OUT:
    return;
}

void chaos_arnold::rarnold(Mat &image, Mat &out)
{
    int i, j;
    int y;
    int row = image.rows;
    int col = image.cols;
    int q;
    uchar *p;
    
    q = __gcd(row, col);

    q = row / q;

    // j/row for y/N, i/col for x/M
    for(j = 0; j < row; j++){
        p = image.ptr<uchar>(j);
        for(i = 0; i < col; i++){
            y = __mod(j - q * i, row);
            Vec3b &op = out.at<Vec3b>(y, __mod(i - y, col));
            op[0] = *p++;
            op[1] = *p++;
            op[2] = *p++;
        }
    }
}

void chaos_arnold::rarnold_n(Mat &image, Mat &out, int t)
{
    int i;
    Mat tmp;

    if(t < 1)
        return;

    image.copyTo(tmp);

    if(tmp.empty()){
        std::cout << "Not enough memory" << std::endl;
        return;
    }

    i = 0;
    while(i < t){
        rarnold(tmp, out);
        i++;
        if(i > t){
            goto ODD_OUT;
        }
        rarnold(out, tmp);
        i++;
    }

    out.release();
    out = tmp;
ODD_OUT:
    return;
}

int chaos_arnold::__gcd(const int _a, const int _b)
{
    int a = _a;
    int b = _b;
    int tmp;
    
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

    return a + mod;
}