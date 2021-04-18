#include <stdio.h>

void swap(int *xPointer, int *yPointer);

int bitAnd(int x, int y);

int getByte(int x, int n);

int logicalShift(int x, int n);

int main() {
    return 0;
}

// question 3
void swap(int *xPointer, int *yPointer) {//swaps between to integers variables using only ^(XOR)
    printf("x = %d\n", *xPointer);
    printf("y = %d", *yPointer);
    /*we know that a^a = 0 , a^0 = a for every a, and we know that ^ (Exclusive or)
 * has associative and Commutative properties that we will use to prove the value swap*/

    // x = A , y = B
    *xPointer = *xPointer ^ *yPointer;// x = A^B , y = B
    *yPointer = *xPointer ^ *yPointer;// x = A^B , y = (A^B)^B = A^(B^B) = A^(0) = A ,associative property
    *xPointer = *xPointer ^ *yPointer;// x = (A^B)^A = (A^A)^B = (0)^B = B , y = A ,associative + Commutative properties
    // x = B , y = A

    printf("\nx = %d\n", *xPointer);
    printf("y = %d", *yPointer);

}

// question 4


/*
* bitAnd ‐ x&y using only ~ and |
* Example: bitAnd(6,5) = 4
* Legal ops: ~ |
* Max ops: 8 */
int bitAnd(int x, int y) {
    return ~(~x | ~y); // x&y <-> ~(~x|~y)
}


/*
 *  255 is mask and is (1111 1111) in base 2 , (x >> (n << 3)) is res.
 *  n << 3 = n*(2pow3) = n*8 converting byte to bit for shifting x's bites
 */
int getByte(int x, int n) {
    return (x >> (n << 3)) & 255;
}
/*
 * ~(((1 << 31) >> n) << 1) is the mask
 * (x >> n) is res
 *
 * (1 << 31) to get 1000 00...00 0000 31 zeros
 * (1 << 31) >> n) means 1111 11...00 0000 (n-1) ones
 * (((1 << 31) >> n) << 1) means 1111 10...00 0000 n ones
 * ~(((1 << 31) >> n) << 1) means 0000 01...11 1111 n zeros
 *  we use & operator and the mask to get rid of all the the other bits that come form the arithmetic shift
 */
int logicalShift(int x, int n) {
    return (x >> n) & ~(((1 << 31) >> n) << 1);
}
