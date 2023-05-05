#include <opencv2/opencv.hpp>
#include <chaos-arnold.h>

using namespace chaos;
using namespace cv;

void chaos_arnold::arnold(Mat &image, Mat &out)
{
    int i, j;
    int row = image.rows;
    int col = image.cols;
    int gcd;
    uchar *p;
    
    gcd = __gcd(row, col);
    if(gcd == row)
        gcd = 1;

    gcd = row / gcd;

    for(j = 0; j < row; j++){
        p = image.ptr<uchar>(j);
        for(i = 0; i < col; i++){
            Vec3b &op = out.at<Vec3b>((gcd * i + (gcd + 1) * j) % row, (i + j) % col);
            op[0] = *p++;
            op[1] = *p++;
            op[2] = *p++;
        }
    }
}

int chaos_arnold::__gcd(const int _a, const int _b)
{
    int a = _a;
    int b = _b;
    int tmp;

    while(b){
        if(a < b){
            tmp = a;
            a = b;
            b = tmp;
        }
        a = a - b;
    }

    return a;
}