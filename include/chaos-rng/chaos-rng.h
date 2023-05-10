/*
 * chaos_rng
 * 基于logistic的随机数发生器，使用chaos-base-type以提升精度
 * x = lamb * x * (1 - x)
 * lamb in [3.57,4]
 * x in [0,1]
*/

#ifndef CHAOS_RNG_H
#define CHAOS_RNG_H

#include <chaos-base-type.h>

namespace chaos{
    class chaos_rng{
    public:
        chaos_rng(void);
        chaos_rng(const double lambda, const double x);
        chaos_rng(const chaos_fpoint &lambda, const chaos_fpoint &x);

        //短参数初始化函数，用于增强随机性
        //进行两次迭代将随机数扩散至全部比特位
        void spara_init(void);

        //lambda设置函数
        void set_lambda(const double &lambda);
        //lambda设置函数
        void set_lambda(const chaos_fpoint &lambda);
        //x设置函数
        void set_x(const double &x);
        //x设置函数
        void set_x(const chaos_fpoint &x);

        //获取当前向量
        chaos_fpoint get_status(void);
        //获取当前向量
        unsigned long long get_status_c(void);
        
        //计算并获取下一向量，以内部类型返回
        chaos_fpoint get_next_status(void);
        //计算并获取下一向量，以c++类型返回
        unsigned long long get_next_status_c(void);

        //设计用以与opencv整合
        //生成num个unsigned char类型的随机数
        //生成的随机数总数不能超过7个（chaos-rng的极限）
        //第七个随机数的随机性差一些
        int get_next_uchars(short num, ...);

    private:
        chaos_fpoint lambda;
        chaos_fpoint x;

        //内部函数，计算触发函数，计算下一个向量
        inline void __cal_next(void);
    };
}

#endif