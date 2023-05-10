#include <iostream>
#include "chaos-rng.h"
//#include "chaos-shuffle.h"

using namespace chaos;

int main(void)
{
    unsigned char uc[7];
    chaos_rng rng = chaos_rng(3.7, 0.27);
    int i,j;

    rng.spara_init();

    std::cout << "time,1,2,3,4,5,6,7" << std::endl;

    for(i = 0; i < 10000; i++){
        rng.get_next_uchars(7, &uc[0], &uc[1], &uc[2], &uc[3], &uc[4], &uc[5], &uc[6]);

        std::cout << i;
        for(j = 0; j < 7; j++){
            std::cout << "," << (short)uc[j];
        }
        std::cout << std::endl;
    }
    
    return 0;
}