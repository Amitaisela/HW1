#include <stdio.h>
void swap(int *x , int *y);
int bitAnd(int x, int y);
int getByte(int x, int n);
int logicalShift(int x, int n);

int main()
{
    return 0;
}

void swap(int *x , int *y){
    *x = *x ^ *y;
    *y = *x ^ *y;
    *x = *x ^ *y;
}

int bitAnd(int x, int y){
    return ~(~x | ~y);
}

int getByte(int x, int n){
    return (x >> (n << 3)) & 0xff;
}

int logicalShift(int x, int n){
    return (x >> n) & (~(((1 << 31) >> n) << 1));
}
