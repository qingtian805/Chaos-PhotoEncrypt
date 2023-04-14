/*
 * chaos-base-type
 * 基础类型实现，项目基础
 * 具体类型：定点数，基于long long超长整形，64位
 * 容纳空间：0.00-16.00
 * XXXX.XXX...XXXX，整数部分占4位，小数部分占60位
*/

#ifndef CHAOS_BASE_TYPE
#define CHAOS_BASE_TYPE

namespace chaos{
    class chaos_fpoint{
    private:
        unsigned long long fpoint;

    public:
        chaos_fpoint(void);
        chaos_fpoint(unsigned long long init);
        chaos_fpoint(double init);
        
        //运算符
        chaos_fpoint operator+(const chaos_fpoint &a);
        chaos_fpoint operator-(const chaos_fpoint &a);
        chaos_fpoint operator*(const chaos_fpoint &a);

        friend std::ostream& operator<<(std::ostream &os, const chaos_fpoint &a);
    };

    std::ostream& operator<<(std::ostream &os, const chaos_fpoint &a);
}
#endif