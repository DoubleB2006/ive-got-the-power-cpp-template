#pragma once
#include <cstdint>
using u64 = unsigned long long;

// three power functions for the lab
u64 naivePower(u64 x, int n);
u64 unoptimizedDCPower(u64 x, int n);
u64 optimizedDCPower(u64 x, int n);
