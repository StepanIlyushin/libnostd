#include "libnostd/math/core.hpp"

namespace math::statistics {
    unsigned long binominal(unsigned long n, unsigned  long k, unsigned long m) {
	if ((k == 0) || (k == n)) return 1UL;
	if (k > n) return 0UL;
        return (prod(k+1, n, m) * invmod(factorial(n-k, m), m)) % m;
    }
    double mean(const double M[], int n) {
	double sum = 0;
	//if n = 0
	for(int i = 0; i < n; i++) {
		sum += M[i];
	}
	return sum/n;
    }

    double var(const double M[], int n) {
	double arg = mean(M[], n);
	double sum = 0;
        for(int i = 0; i < n; i++) {
		double k = M[i] - arg;
		sum += k*k;
	}
	double d = sum / n;
	return sqrt_heron(d);
    }
}
