#include <iostream>
#include "src/power.hpp"   

int main() {
    u64 x = 2;
    int n = 10;

    std::cout << x << "^" << n << "\n";
    std::cout << "  naive        = " << naivePower(x, n) << "\n";
    std::cout << "  unoptimized  = " << unoptimizedDCPower(x, n) << "\n";
    std::cout << "  optimized    = " << optimizedDCPower(x, n) << "\n";

    return 0;
}



























