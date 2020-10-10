#include <stdio.h>

int func_A(int x) {
    return !~x;
}

int func_B(int x) {
    return !x;
}

int func_C(int x) {
    return !~(x >> ( (sizeof(int)-1)<<3) | (~0xFF) );
}

int func_D(int x) {
    return !((x & 0xFF));
}

int main() {
    int x;
    printf("input any integer : ");
    scanf("%d", &x);

    printf("test A 결과 : %d\n", func_A(x));
    printf("test B 결과 : %d\n", func_B(x));
    printf("test C 결과 : %d\n", func_C(x));
    printf("test D 결과 : %d\n", func_D(x));

    return 0;
}