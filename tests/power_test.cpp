#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include "../src/power.hpp"

// quick sanity
TEST_CASE("power sanity") {
    REQUIRE( naivePower(2,10) == 1024 );
    REQUIRE( optimizedDCPower(3,5) == 243 );
    REQUIRE( naivePower(5,7) == unoptimizedDCPower(5,7) );
    REQUIRE( naivePower(5,7) == optimizedDCPower(5,7) );
}

// same vibe as your factorial BENCHMARKs
TEST_CASE("benchmarking the power functions") {
    BENCHMARK("naive        2^30") { return naivePower(2,30); };
    BENCHMARK("unoptimized  2^30") { return unoptimizedDCPower(2,30); };
    BENCHMARK("optimized    2^30") { return optimizedDCPower(2,30); };

    BENCHMARK("naive       11^28") { return naivePower(11,28); };
    BENCHMARK("unoptimized 11^28") { return unoptimizedDCPower(11,28); };
    BENCHMARK("optimized   11^28") { return optimizedDCPower(11,28); };
}
