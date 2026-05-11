#include "libnostd/math/core.hpp"

namespace math::statistics {
    unsigned long binominal(unsigned long n, unsigned  long k, unsigned long m) {
	if ((k == 0) || (k == n)) return 1UL;
	if (k > n) return 0UL;
        return (prod(k+1, n, m) * invmod(factorial(n-k, m), m)) % m;;
    }
}
