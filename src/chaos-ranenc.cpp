#include <chaos-ranenc.h>
#include <opencv2/core.hpp>

using namespace chaos;
using namespace cv;

void chaos_ranenc::rand_enc(Mat &image, chaos_rng &rng)
{
    uchar rand[3];
    uchar *p;
    int row = image.rows;
    int col = image.cols;
    int i, j;

    if(image.isContinuous()){
        col *= row;
        row = 1;
    }

    for(i = 0; i < row; i++){
        p = image.ptr<uchar>(i);

        for(j = 0; j < col; j++){
            rng.get_next_uchars(3, &rand[0], &rand[1], &rand[2]);

            *p++ ^= rand[0];
            *p++ ^= rand[1];
            *p++ ^= rand[2];
        }
    }
}

