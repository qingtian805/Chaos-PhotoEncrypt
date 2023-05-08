#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
//#include <chaos-shuffle.h>
#include <chaos-ranenc.h>
#include <iostream>

using namespace cv;
using namespace chaos;
int main(void)
{
    Mat image, out;
    chaos_rng rng = chaos_rng(3.7, 0.25);

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

    rng.spara_init();

    chaos::chaos_ranenc::rand_enc(image, rng);

    //std::cout << out << std::endl;

    namedWindow("Display Image", WINDOW_AUTOSIZE );
    imshow("Display Image", image);
    waitKey(0);

    rng.set_x(0.25);
    rng.spara_init();

    chaos::chaos_ranenc::rand_enc(image, rng);

    //std::cout << out << std::endl;

    namedWindow("Display Image", WINDOW_AUTOSIZE );
    imshow("Display Image", image);
    waitKey(0);

    return 0;
}