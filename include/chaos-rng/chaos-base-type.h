/*
 * chaos-base-type
 * 基础类型实现，项目基础
 * 具体类型：定点数，基于long long超长整形，64位
 * 容纳空间：0.00--17-2^{-60}
 *         但若要使用乘法，则只能运算4以内的乘法
 * XXXX.XXX...XXXX，整数部分占4位，小数部分占60位
*/

#ifndef CHAOS_BASE_TYPE_H
#define CHAOS_BASE_TYPE_H

#include<iostream>

namespace chaos{
    class chaos_fpoint{
    public:
        chaos_fpoint(void);
        chaos_fpoint(const unsigned long long init);
        chaos_fpoint(const double init);
        
        chaos_fpoint operator+(const chaos_fpoint &a);
        chaos_fpoint operator-(const chaos_fpoint &a);
        chaos_fpoint operator*(const chaos_fpoint &a);

        bool operator>(const chaos_fpoint &a);
        bool operator>=(const chaos_fpoint &a);
        bool operator<(const chaos_fpoint &a);
        bool operator<=(const chaos_fpoint &a);
        //可以将类内部类型返回，即超长整形
        unsigned long long fpoint_to_c(void);

    private:
        unsigned long long fpoint;

        friend std::ostream& operator<<(std::ostream &os, const chaos_fpoint &a);
    };

    //chaos_fpoint打印函数
    std::ostream& operator<<(std::ostream &os, const chaos_fpoint &a);
}
#endif