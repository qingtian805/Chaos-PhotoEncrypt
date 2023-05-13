#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
//#include <chaos-shuffle.h>
#include <chaos-arnold.h>
#include <iostream>

using namespace cv;
using namespace chaos;
int main(void)
{
    Mat image, out, outd;

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
    outd = Mat::zeros(image.rows, image.cols, CV_8UC3);

    if(outd.empty()){
        printf("Not enough memory \n");
        return -1;
    }

    chaos::chaos_arnold::arnold(image, out);

    //std::cout << out << std::endl;

    namedWindow("Display Image", WINDOW_AUTOSIZE );
    imshow("Display Image", out);
    waitKey(0);

    chaos::chaos_arnold::rarnold(out, outd);

    namedWindow("Display Image", WINDOW_AUTOSIZE );
    imshow("Display Image", outd);
    waitKey(0);

    chaos::chaos_arnold::arnold_n(image, out, 2);

    //std::cout << out << std::endl;

    namedWindow("Display Image", WINDOW_AUTOSIZE );
    imshow("Display Image", out);
    waitKey(0);

    chaos::chaos_arnold::rarnold_n(out, outd, 2);

    namedWindow("Display Image", WINDOW_AUTOSIZE );
    imshow("Display Image", outd);
    waitKey(0);

    return 0;
}