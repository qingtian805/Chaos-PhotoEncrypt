#include<iostream>
#include"chaos-rng.h"

using namespace chaos;

chaos_rng::chaos_rng(void)
{
    this->lambda = chaos_fpoint(3.7);
    this->x = chaos_fpoint(0.25);
}

chaos_rng::chaos_rng(double lambda, double x)
{
    this->lambda = chaos_fpoint(lambda);
    this->x = chaos_fpoint(x);
}

chaos_rng::chaos_rng(const chaos_fpoint &lambda, const chaos_fpoint &x)
{
    this->lambda = lambda;
    this->x = x;
}