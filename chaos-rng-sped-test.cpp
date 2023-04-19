#include<chrono>
#include<iostream>
#include"chaos-rng.h"

int main(void)
{
    int i;
    double x = 0.25;
    double lamb = 3.7;
    chaos::chaos_rng rng = chaos::chaos_rng(3.7, 0.25);
    unsigned long long internal;
    std::chrono::time_point<std::chrono::system_clock> start, end;
    std::chrono::microseconds period;

    start = std::chrono::system_clock::now();
    for(i = 0; i < 6220800; i++){
        internal = rng.get_next_status_c();
    }
    end = std::chrono::system_clock::now();

    period = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    std::cout << period.count() << std::endl;

    start = std::chrono::system_clock::now();
    for(i = 0; i < 6220800; i++){
        x = lamb * x * (1 - x);
    }
    end = std::chrono::system_clock::now();

    period = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    std::cout << period.count() << std::endl;

    return 0;
}