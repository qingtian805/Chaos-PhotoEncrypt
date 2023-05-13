#include<iostream>
#include<iomanip>
#include <cstdarg>

//设计变长函数的实验文件，是哟你cstdarg库

int v_arg(int num, ...)
{
    int i;
    char a;
    va_list va;

    va_start(va, num);

    for(i = 0; i < num; i++){
        a = va_arg(va, int);
        std::cout << a << std::endl;
    }
    va_end(va);
    return 0;
}

int main(void)
{
    int i;
    unsigned char c1 = 'a';
    unsigned char c2 = 'b';
    
    v_arg(2, c1, c2);

    return 0;
}