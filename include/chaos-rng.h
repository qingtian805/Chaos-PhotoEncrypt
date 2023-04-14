/*
 * chaos_rng
 * 基于logistic的随机数发生器，使用chaos-base-type以提升精度
 * x = lamb * x * (1 - x)
 * lamb in [3.57,4]
 * x in [0,1]
*/

#ifndef CHAOS_RNG
#define CHAOS_RNG

#include"chaos-base-type.h"

namespace chaos{
    class chaos_rng{
    private:
        chaos_fpoint lambda;
        chaos_fpoint x;

    public:
        chaos_rng(void);
        chaos_rng(double lambda, double x);
        chaos_rng(const chaos_fpoint &lambda, const chaos_fpoint &x);

        void set_lambda(double lambda);
        void set_lambda(chaos_fpoint lambda);
        void set_x(double x);
        void set_x(chaos_fpoint x);
    };
}

#endif