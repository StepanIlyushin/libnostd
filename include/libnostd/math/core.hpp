#ifndef LIBNOSTD_CORE_HPP

namespace math {
    double square(double x);
    double fast_power(double base, unsigned long long exp);
    double sqrt_heron(double num);
    unsigned long factorial(unsigned long n, unsigned long m);
    unsigned long prod(unsigned long a, unsigned long b, unsigned long m);
    /**
     * @warning числа должны быть взаимнопростые
    */
    unsigned long invmod(unsigned long a, unsigned long m);
    unsigned long binpowmod(unsigned long a, unsigned long deg, unsigned long m);

    unsigned long gcdex(unsigned long a, unsigned long b, unsigned long &x, unsigned long &y);
}

#endif 
