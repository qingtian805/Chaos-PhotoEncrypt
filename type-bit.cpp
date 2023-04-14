#include<stdio.h>

#define print_type(a) printf("%s:\t%d\n", #a, sizeof(a)) //#将形参名作为字符串变量传入

int main(){
    print_type(short);
    print_type(int);
    print_type(long);
    print_type(long long);
    print_type(float);
    print_type(double);

    return 0;
}