#include "factorial.hpp"

// 0^0 -> 1 here (because n==0 returns 1). 0^n -> 0 for n>0.

u64 naivePower(u64 x, int n) {
    if (n == 0) return 1;
    if (x == 0) return 0;
    return x * naivePower(x, n - 1);
}

// intentionally dumb (recomputes the half twice)
u64 unoptimizedDCPower(u64 x, int n) {
    if (n == 0) return 1;
    if (x == 0) return 0;
    if ((n & 1) == 0) {
        return unoptimizedDCPower(x, n/2) * unoptimizedDCPower(x, n/2);
    } else {
        return x * unoptimizedDCPower(x, n/2) * unoptimizedDCPower(x, n/2);
    }
}

// exponentiation by squaring
u64 optimizedDCPower(u64 x, int n) {
    if (n == 0) return 1;
    if (x == 0) return 0;
    u64 t = optimizedDCPower(x, n/2);
    return (n % 2 == 0) ? (t * t) : (x * t * t);
}
