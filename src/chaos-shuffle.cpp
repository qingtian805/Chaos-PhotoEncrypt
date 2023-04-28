#include <opencv2/opencv.hpp>
#include <chaos-shuffle.h>
#include <chaos-rng.h>

using namespace chaos;

inline void chaos_shuffle::__swap_pixel(int elemsize, uchar *p1, uchar *p2)
{
    int i;
    uchar tmp;

    for(i = 0; i < elemsize; i++){
        tmp = p1[i];
        p1[i] = p2[i];
        p2[i] = tmp;
    }
}

//knuth shuffle
void chaos_shuffle::__shuffle_row(Mat &im_row, chaos_rng &rng)
{
    int channel = im_row.elemSize();
    int i, rand;
    uchar *p = im_row.ptr<uchar>(0);

    for(i = im_row.cols - 1; i > 0; i--){
        rand = rng.get_next_status_c() % i;
        if( rand == i )
            continue;
        chaos_shuffle::__swap_pixel(channel, p + rand * channel, p + i * channel);
    }
}

int chaos_shuffle::shuffle(Mat &image, chaos_rng &rng)
{
    int i, j, rand;
    Mat row1, row2;
    uchar tmp;
    uchar *p1, *p2;

    for(i = image.rows - 1; i > 0; i--){
        rand = rng.get_next_status_c() % i;
        if( rand == i )
            continue;

        row1 = image.row(i);
        row2 = image.row(rand);

        p1 = row1.ptr<uchar>(0);
        p2 = row2.ptr<uchar>(0);

        for(j = row1.cols * 3; j >= 0; j--){
            tmp = p1[j];
            p1[j] = p2[j];
            p2[j] = tmp;
        }
        chaos_shuffle::__shuffle_row(row1, rng);
        chaos_shuffle::__shuffle_row(row2, rng);
    }

    return 0;
}

