#include<iostream>
#include"chaos-base-type.h"

using namespace chaos;

chaos_fpoint::chaos_fpoint(void)
{
    this->fpoint = 0;
}

chaos_fpoint::chaos_fpoint(unsigned long long init)
{
    this->fpoint = init;
}

chaos_fpoint::chaos_fpoint(double init)
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
    unsigned long long tmp1, tmp2;

    tmp1 = this->fpoint >> 30;
    tmp2 = a.fpoint >> 30;

    return chaos_fpoint(tmp1 * tmp2);
}

std::ostream& chaos::operator<<(std::ostream &os, const chaos_fpoint &a)
{
    double print = (double)a.fpoint / (1ll << 60);

    os << print;

    return os;
}