#include <stdio.h>

int float_ge(float x, float y) {
    unsigned ux = f2u(x);
    unsigned uy = f2u(y);
    // Get the sign bits
    unsigned sx = ux >> 31;
    unsigned sy = uy >> 31;

     return (!(uy << 1 ^ ~0) && !(ux << 1 ^ ~0)) || /* uy = ux = +0 or -0 */
            (!sy && sx) ||                          /* sy >= 0, sx < 0    */
            (!sy && !sx && uy >= ux) ||             /* y >= 0, x >= 0     */
            (sy && sx && uy <= ux);                 /* y < 0, x < 0       */
}