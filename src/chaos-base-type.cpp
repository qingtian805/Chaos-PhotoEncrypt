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

    //res = tmp1 * tmp3;
    //res += tmp1 * tmp4 + tmp2 * tmp3 >> 30;
    //res += tmp2 * tmp4 >> 60;

    asm(
        "movq %2, %%rax;\n"
        "movq %3, %%rdx;\n"
        "mulq %%rdx; \n"
        "movq %%rdx, %0\n"
        "movq %%rax, %1"
        :"=r"(res0), "=r"(res1)
        :"r"(this->fpoint), "r"(a.fpoint)
        :"%rax", "%rdx"
    );

    res0 = res0 << 4;
    res0 += res1 >> 60 & 0xF;
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