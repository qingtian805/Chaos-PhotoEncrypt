#include<iostream>
#include"chaos-base-type.h"

using namespace chaos;

//chaos_fpoint内部函数
chaos_fpoint::chaos_fpoint(void)
{
    this->fpoint = 0;
}

chaos_fpoint::chaos_fpoint(const unsigned long long init)
{
    this->fpoint = init;
}

chaos_fpoint::chaos_fpoint(const double init)
{
    this->fpoint = init * (1ll << 60); //init * 2^60
}

chaos_fpoint chaos_fpoint::operator+(const chaos_fpoint &a)
{
    return chaos_fpoint(this->fpoint + a.fpoint);
}

chaos_fpoint chaos_fpoint::operator-(const chaos_fpoint &a)
{
    return chaos_fpoint(this->fpoint - a.fpoint);
}

chaos_fpoint chaos_fpoint::operator*(const chaos_fpoint &a)
{
    unsigned long long res0, res1;

    res0 = this->fpoint << 2;
    res1 = a.fpoint << 2;

    asm(//op src, dst
        "movq %1, %%rax;\n"
        "movq %2, %%rdx;\n"
        "mulq %%rdx; \n"
        "movq %%rdx, %0\n"
        :"=r"(res0)
        :"r"(res0), "r"(res1)
        :"%rax", "%rdx"
    );

    return chaos_fpoint(res0);
}

bool chaos_fpoint::operator>(const chaos_fpoint &a)
{
    return this->fpoint > a.fpoint;
}

bool chaos_fpoint::operator>=(const chaos_fpoint &a)
{
    return this->fpoint >= a.fpoint;
}

bool chaos_fpoint::operator<(const chaos_fpoint &a)
{
    return this->fpoint < a.fpoint;
}

bool chaos_fpoint::operator<=(const chaos_fpoint &a)
{
    return this->fpoint <= a.fpoint;
}

unsigned long long chaos_fpoint::fpoint_to_c(void)
{
    return this->fpoint;
}

//友元函数
std::ostream& chaos::operator<<(std::ostream &os, const chaos_fpoint &a)
{
    double print = (double)a.fpoint / (1ll << 60);

    os << print;

    return os;
}