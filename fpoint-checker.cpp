#include<stdio.h>

int fpoint_checker(double *fpoint){
    long long unsigned int *hack;
    char *chack;
    int s = 0x01020304;
    int e;
    unsigned long int m;

    if(sizeof(double) != sizeof(long int)){
        printf("Condition not met. Please check type define");
        return 0;
    }

    if(*(char*)&s != 04){
        printf("This program is designed for little endian!");
        return 0;
    }

    hack = (long long unsigned int*)fpoint;
    chack = (char*)hack;
    s = (*(chack + 7) & 0x80) >> 7;
    e = (*(chack + 7) & 0x7F) << 4 | (*(chack + 6) & 0xF0) >> 4;
    m = (*(chack + 6) & 0x0F);
    m = m << 8;
    m = m | (*(chack + 5) & 0xFF);
    m = m << 8;
    m = m | (*(chack + 4) & 0xFF);
    m = m << 8;
    m = m | (*(chack + 3) & 0xFF);
    m = m << 24;
    m = m | (*(chack + 2) & 0xFF) << 16 | (*(chack + 1) & 0xFF) << 8 | (*chack & 0xFF);

    printf("   float point:%f \n", *fpoint);
    printf("       address:%#lx \n", fpoint);
    printf("address hacked:%#lx \n", hack);
    printf("           hex:%#016lx \n", *hack);
    printf("s:%x\t", s);
    printf("e:%#x(%d)\t", e, e-0x3FF);
    printf("m:0x1.%013lx\t\n", m);

    return 0;
}

int main(void)
{
    double fpoint;

    scanf("%lf", &fpoint);
    fpoint = 0.000000000000001 * 3.8;

    return fpoint_checker(&fpoint);
}