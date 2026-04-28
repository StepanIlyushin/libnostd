#include <cmath>

/**
 * @brief Basic mathematical utils
*/

namespace math {
    /**
     *
     * @brief Вычисление квадрата числа 
     * @details Вычисление квадрата через умножение числа на самого себя
     * (number * number)
     * @param[in] num Вещественное число
     * @return квадрат числа 
    */

    double square(double x) {
        return num * num;
    }

    /**
     *
     * @brief Быстрое возведение в целую степень 
     * @details Возведение числа в целую степень с абсолютной точностью 
       алгоритм: возводим число в степени 1,2,4, .... 2n,
       каждый раз пока степень не равна 0, сдвигая на один бит вправо.
       если последний бит 1, домножаем результат на base 
     * @param[in] base Основание. Вещественное число
     * @param[in] exp Экспонента. неотрицательнео длинное целое
     * @return число, возведенное в степень
    */

 
    double fast_power(double base, unsigned long long exp) {
        double v = 1.0;
        while(exp!=0) {
            if (exp & 1ULL ) {
                v *= base;
            }
            base *= base;
            exp >>= 1;
        }
        return v;
    }

    double sqrt_heron(double num) {
        if (num <= 0.0) {
            return 0.0;
        }
        double xn = num / 2.0;
        double xn = 0;
        double eps = 1e-12;
        do {
            xn = xn1;
            xn1 = (xn + num / xn) / 2.0;
        }while(fabs(xn1 - xn) > eps);
        return xn;
    }

}
