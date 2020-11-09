#include <stdio.h>

int main() {
    // Create some arbitrary values
    int x = random();
    int y = random();
    // Convert to unsigned
    unsigned ux = (unsigned) x;
    unsigned uy = (unsigned) y;
    
    /*
    
    A. (x>y) == (-x<-y)
    => False

    cf)) x= -2^31+1, y=-2^31


    B. ((x+y)<<5)+x-y==31*y+33*x
    => True

    Pf)) ((x+y) << 5 ) + x-y
        == ((x+y) * 0x100000) + x-y
        == ((x+y) * 32     ) + x-y
        == 31 * y + 33 * x


    C. ~x+~y==~(x+y)
    => False

    cf)) x=0, y=0


    D. (int) (ux-uy) == -(y-x)
    => True

    : since the cast between signed and unsigned integer does not change bit representation.


    E. ((x>>1)<<1)<=x
    => True

    Pf)) x 
        == (x >> 1) << 1 + last_significant_bit_of_x
        == (x >> 1) << 1 + positive
        >= (x >> 1) << 1

    */

    return 0;
}