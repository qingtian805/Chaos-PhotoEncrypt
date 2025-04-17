#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <chaos-ranenc.h>
#include <chaos-arnold.h>
#include <chaos-rng.h>
#include <iostream>

using namespace cv;
using namespace chaos;
int main(int argc, char** argv)
{
    Mat image, out;
    chaos_rng rng = chaos_rng(3.99, 0.25);

    if (argc != 3){
        std::cout << "usage: DisplayImage.out <Image_Path> <Enc_Image_Path>" << std::endl;
        return 0;
    }

    image = imread(argv[1]);
    
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

    chaos::chaos_arnold::arnold_n(image, out, 3);

    chaos::chaos_ranenc::rand_enc(out, rng);

    //namedWindow("Display Image", WINDOW_AUTOSIZE );
    //imshow("Display Image", out);
    //waitKey(0);

    imwrite(argv[2], out);

    return 0;
}