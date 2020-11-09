typedef __int128 int128_t;

void store_prod(int128_t *dest, int64_t x, int64_t y) {
    *dest = x*(int128_t)y;
}

/*

store prod:
    movq %rdx, %rax         // %rax = y
    cqto                    // %rdx = -y_63
    movq %rsi, %rcx         // %rcx = x
    sarq $63, %rcx          // %rcx = -x_63
    imulq %rax, %rcx        // %rcx = y * (-x_63)
    imulq %rsi, %rdx        // %rdx = x * (-y_63)
    addq %rdx, %rcx         // %rcx = y * (-x_63) + x * (-y_63)
    mulq %rsi               // R[%rdx]:R[%rax] <- ux * uy
    addq %rcx, %rdx         // %rdx = (upper 64bits of ux*uy) + y * (-x_63) + x * (-y_63) 
    movq %rax, (%rdi)       // save lower 64bit
    movq %rdx, 8(%rdi)      // save higher 64bit
    ret                     // return

*/