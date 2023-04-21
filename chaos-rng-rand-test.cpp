#include<iostream>
#include<iomanip>
#include"chaos-rng.h"

int main(void)
{
    int i;
    chaos::chaos_rng rng = chaos::chaos_rng(3.7, 0.25);
    chaos::chaos_fpoint fpoint;
    unsigned long long internal;
    
    std::cout << "time,float,internal" << std::endl;

    //4K 分辨率 4096*3112=12746752 < 13000000
    for(i = 0; i < 10000; i++){ 
        fpoint = rng.get_next_status();
        internal = fpoint.fpoint_to_c();
        std::cout << std::setprecision(10) << i << "," << fpoint << "," << internal << std::endl;
    }

    return 0;
}