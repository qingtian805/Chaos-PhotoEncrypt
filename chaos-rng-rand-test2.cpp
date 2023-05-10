#include<iostream>
#include<iomanip>
#include<bitset>
#include"chaos-rng.h"

int main(void)
{
    int i;
    chaos::chaos_rng rng = chaos::chaos_rng(3.7, 0.25);
    chaos::chaos_fpoint fpoint;
    unsigned long long internal;

    rng.spara_init();
    
    //std::cout << "time,float,internal" << std::endl;

    for(i = 0; i < 10000; i++){ //生成1万个随机数，输出为csv格式
        fpoint = rng.get_next_status();
        internal = fpoint.fpoint_to_c() ^ 0xFFFFFFFFFFFF;
        std::cout << std::bitset<48>(internal);
    }

    std::cout << std::endl;

    return 0;
}