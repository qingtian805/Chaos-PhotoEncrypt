#include <opencv2/opencv.hpp>
//#include <chaos-shuffle.h>
#include <chaos-arnold.h>
#include <iostream>

using namespace cv;
using namespace chaos;
int main(void)
{
    Mat image, out;

    image = imread("/home/kevin/git-chaos-cpp/test.jpg");
    if ( !image.data )
    {
        printf("No image data \n");
        return -1;
    }

    out = Mat::zeros(image.rows, image.cols, CV_8UC3);

    if(out.empty()){
        printf("Not enough memory \n");
        return -1;
    }

    chaos::chaos_arnold::arnold(image, out);

    //std::cout << out << std::endl;

    namedWindow("Display Image", WINDOW_AUTOSIZE );
    imshow("Display Image", out);
    waitKey(0);

    return 0;
}