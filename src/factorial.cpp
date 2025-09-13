#include <cstdint>

// 1) Naive recursion: x^n = x * x^(n-1)
long long naivePower(int x, int n) {
    if (x == 0) return 0;
    if (n == 0) return 1;
    return static_cast<long long>(x) * naivePower(x, n - 1);
}

// 2) Divide & Conquer (UNOPTIMIZED):
//    Recursively compute x^(n/2) twice (intentionally redundant).
long long unoptimizedDCPower(int x, int n) {
    if (x == 0) return 0;
    if (n == 0) return 1;
    if (n % 2 == 0) {
        return unoptimizedDCPower(x, n / 2) * unoptimizedDCPower(x, n / 2);
    } else {
        return static_cast<long long>(x)
             * unoptimizedDCPower(x, n / 2)
             * unoptimizedDCPower(x, n / 2);
    }
}

// 3) Divide & Conquer (OPTIMIZED):
//    Reuse the half-power result to avoid duplicate work.
long long optimizedDCPower(int x, int n) {
    if (x == 0) return 0;
    if (n == 0) return 1;
    long long temp = optimizedDCPower(x, n / 2);
    if (n % 2 == 0) {
        return temp * temp;
    } else {
        return static_cast<long long>(x) * temp * temp;
    }
}
