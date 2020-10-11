#include <stdio.h>

int main() {
    // Create some arbitrary values
    int x = random();
    int y = random();
    int z = random();
    // Convert to double
    double dx = (double) x;
    double dy = (double) y;
    double dz = (double) z;
    
    /*
    
    A. (double)(float)x == dx
    => False

    cf)) NOTE : dx will be exactly converted, but (float)x may be rounded.
        let x = 2^31-1 => it will be rounded when it converted to float.
    

    B. dx+dy == (double)(x+y)
    => False

    cf)) let x=-2^31, y=-1


    C. dx+dy+dz == dz+dy+dx
    => True

    Pf)) NOTE : in 64bit IEEE-format, we have 52bit to represent significand 
        Since each value ranges between -2^31 and 2^31-1,
        their sum also can represented exactly.


    D. dx*dy*dz == dz*dy*dx
    => False

    cf)) NOTE : in 64bit IEEE-format, we have 52bit to represent significand 
        let x = 2^31-1, y = 2^31-2, z = 2^31-3
        => then dx*dy already exceed 52bit.


    E. dx/dx == dy/dy
    => False

    cf)) let x=1, y=0

    */

    return 0;
}