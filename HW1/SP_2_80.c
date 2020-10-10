#include <stdio.h>

int func_A(int x, int n) {
    return ((~(x>>sizeof(int)))<<n);
}

int func_B(int x, int m, int n) {
    return (~((~(x>>4))<<(m+n)))&((~(x>>4))<<m);
}

int main() {
    int x = 0xF;
    int n,m;
    printf("input integer n : ");
    scanf("%d", &n);
    printf("input integer m : ");
    scanf("%d", &m);
    
    printf("%x\n", func_A(x,n));
    printf("%x\n", func_B(x,m,n));

    return 0;
}