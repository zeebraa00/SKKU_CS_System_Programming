#include <stdio.h>

int float_ge(float x, float y) {
    unsigned ux = f2u(x);
    unsigned uy = f2u(y);
    // Get the sign bits
    unsigned sx = ux >> 31;
    unsigned sy = uy >> 31;

    return ((!sx&&sy)||(!sx&&!sy&&ux>=uy)||(sx&&sy&&ux<=uy)||(ux<<1==0&&uy<<1==0));
}