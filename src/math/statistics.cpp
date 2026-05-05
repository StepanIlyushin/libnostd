#include "libnostd/math/core.hpp"

namespace math::statistics {
    unsigned long binominal(unsigned long n, unsigned  long k, unsigned long m) {
        return factorial(n) / binominal(n,m);
    }
}