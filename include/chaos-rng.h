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
    public:
        chaos_rng(void);
        chaos_rng(const double lambda, const double x);
        chaos_rng(const chaos_fpoint &lambda, const chaos_fpoint &x);

        //lambda设置函数
        void set_lambda(const double &lambda);
        //lambda设置函数
        void set_lambda(const chaos_fpoint &lambda);
        //x设置函数
        void set_x(const double &x);
        //x设置函数
        void set_x(const chaos_fpoint &x);

        //内部函数，计算触发函数，计算下一个向量
        void inline __cal_next(void);
        
        //获取当前向量
        chaos_fpoint get_status(void);
        //获取当前向量
        long long get_status_c(void);
        
        //计算并获取下一向量，以内部类型返回
        chaos_fpoint get_next_status(void);
        //计算并获取下一向量，以c++类型返回
        long long get_next_status_c(void);

    private:
        chaos_fpoint lambda;
        chaos_fpoint x;
    };
}

#endif