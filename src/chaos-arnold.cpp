#include <opencv2/opencv.hpp>
#include <chaos-arnold.h>

using namespace chaos;
using namespace cv;

inline void chaos_arnold::arnold(Mat &image)
{
    int i, j;
    int row = image.rows;
    int col = image.cols;
    Mat out;
    uchar *p;

    out.create(row, col, CV_8UC3);

    if(image.isContinuous()){
        row = 1;
    }
    
    for(i = 0; i < row; i++){
        for
    }
}