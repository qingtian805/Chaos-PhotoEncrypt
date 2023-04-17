#include<iostream>
#include<iomanip>
#include"chaos-rng.h"

int main(void)
{
    chaos::chaos_rng rng = chaos::chaos_rng(3.7, 0.25);
    chaos::chaos_fpoint fpoint = chaos::chaos_fpoint();
    long long internal;
    int i;
    //double型对照组
    double lambda = 3.7;
    double x = 0.25;
    //获取初始向量数据
    fpoint = rng.get_status();
    internal = fpoint.fpoint_to_c();
    
    std::cout << std::setfill(' ') << std::setprecision(15) << x << "\t" << fpoint << "\t" << std::hex << internal << std::endl;

    //20次迭代精度测试
    for(i = 0; i <= 20; i++){
        fpoint = rng.get_next_status();
        internal = fpoint.fpoint_to_c();
        x = lambda * x * (1 - x);
        std::cout << std::setfill(' ') << std::setprecision(15) << x << "\t" << fpoint << "\t" << std::hex << internal << std::endl;
    }

    return 0;
}

/* 
 * 0.69375
 * 0.78610546875
 * 
*/