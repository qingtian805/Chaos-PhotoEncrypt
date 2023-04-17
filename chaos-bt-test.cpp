#include<iostream>
#include"chaos-base-type.h"

using namespace chaos;

int main(void)
{
    //fpoint的可接受范围为0.00--(17-2^{-60})，无负数，无更大的数
    double test1 = 2.0;
    double test2 = 0.25;
    
    chaos_fpoint fpoint1 = chaos_fpoint(test1);
    chaos_fpoint fpoint2 = chaos_fpoint(test2);
    chaos_fpoint fpoint3;

    std::cout << fpoint1 << std::endl;
    std::cout << fpoint2 << std::endl;

    fpoint3 = fpoint1 + fpoint2;
    std::cout << fpoint1 + fpoint2 << '\t' << fpoint3 << std::endl;

    fpoint3 = fpoint1 - fpoint2;
    std::cout << fpoint1 - fpoint2 << '\t' << fpoint3 << std::endl;

    fpoint3 = fpoint1 * fpoint2;
    std::cout << fpoint1 * fpoint2 << '\t' << fpoint3 << std::endl;

    return 0;
}