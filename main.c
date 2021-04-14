#include <stdio.h>

void swap(int *xPointer, int *yPointer);

int bitAnd(int x, int y);

int getByte(int x, int n);

int logicalShift(int x, int n);

int main() {
    int x = 5, y = 7;

    swap(&x, &y);
    return 0;
}

void swap(int *xPointer, int *yPointer) {//swaps between to integers variables using only ^(XOR)
    printf("x = %d\n", *xPointer);
    printf("y = %d", *yPointer);/*we know that a^a = 0 , a^0 = a for every a, and we know that ^ (Exclusive or)
 * has associative and Commutative properties that we will use to prove the value swap*/
                                        // x = A , y = B
    *xPointer = *xPointer ^ *yPointer;// x = A^B , y = B
    *yPointer = *xPointer ^ *yPointer;// x = A^B , y = (A^B)^B = A^(B^B) = A^(0) = A ,associative property
    *xPointer = *xPointer ^ *yPointer;// x = (A^B)^A = (A^A)^B = (0)^B = B , y = A ,associative + Commutative properties
                                        // x = B , y = A

    printf("\nx = %d\n", *xPointer);
    printf("y = %d", *yPointer);

}

int bitAnd(int x, int y) {
    return ~(~x | ~y);
}

int getByte(int x, int n) {
    return (x >> (n << 3)) & 0xff;
}

int logicalShift(int x, int n) {
    return (x >> n) & (~(((1 << 31) >> n) << 1));
}
