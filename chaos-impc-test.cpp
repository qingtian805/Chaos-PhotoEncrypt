#include <opencv2/opencv.hpp>
#include <chaos-shuffle.h>
#include <chaos-arnold.h>
#include <chaos-rng.h>

using namespace cv;
using namespace chaos;
int main(int argc, char** argv )
{
    if ( argc != 2 )
    {
        printf("usage: DisplayImage.out <Image_Path>\n");
        return -1;
    }
    Mat image;
    chaos_rng rng = chaos_rng(3.7, 0.25);

    image = imread( argv[1], 1 );
    if ( !image.data )
    {
        printf("No image data \n");
        return -1;
    }

    chaos_shuffle::shuffle(image, rng);

    namedWindow("Display Image", WINDOW_AUTOSIZE );
    imshow("Display Image", image);
    waitKey(0);

    return 0;
}