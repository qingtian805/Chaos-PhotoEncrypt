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
    if (lambda < 3.57 || lambda > 4){
        std::cout << "Wrong num of lambda, restoring default" << std::endl;
        lambda = 3.7;
    }
    if (x < 0 || x > 1){
        std::cout << "Wrong num of x, restoring default" << std::endl;
        x = 0.25;
    }

    this->lambda = chaos_fpoint(lambda);
    this->x = chaos_fpoint(x);
}

chaos_rng::chaos_rng(const chaos_fpoint &lambda, const chaos_fpoint &x)
{
    this->lambda = lambda;
    this->x = x;
}

void chaos_rng::set_lambda(const double &lambda)
{
    this->lambda = chaos_fpoint(lambda);
}

void chaos_rng::set_lambda(const chaos_fpoint &lambda)
{
    this->lambda = lambda;
}

void chaos_rng::set_x(const double &x)
{
    this->x = chaos_fpoint(x);
}

void chaos_rng::set_x(const chaos_fpoint &x)
{
    this->x = x;
}

void chaos_rng::__cal_next(void)
{
    chaos_fpoint one = chaos_fpoint(1.0);
    this->x = this->lambda * this->x * (one - this->x);
}

chaos_fpoint chaos_rng::get_status(void)
{
    return this->x;
}

unsigned long long chaos_rng::get_status_c(void)
{
    return this->x.fpoint_to_c();
}

chaos_fpoint chaos_rng::get_next_status(void)
{
    this->__cal_next();
    return this->x;
}

unsigned long long chaos_rng::get_next_status_c(void)
{
    this->__cal_next();
    return this->x.fpoint_to_c();
}