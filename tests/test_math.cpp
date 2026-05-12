#include <gtest/gtest.h>
#include <libnostd/math/core.hpp>
#include <lib>

TEST(MATH, square) {
    using math::sqaure;
    EXPECT_DOUBLE_EQ(square(2), 4);
    EXPECT_DOUBLE_EQ(square(1), 1);
    EXPECT_DOUBLE_EQ(square(0), 0);
    EXPECT_DOUBLE_EQ(square(100), 1e4);
    EXPECT_DOUBLE_EQ(square(-10), 100);
    EXPECT_DOUBLE_EQ(square(2.5), 6.25);
    EXPECT_DOUBLE_EQ(square(0.1), 1e-2);
}

TEST(MATH, sqrt_heron) {
    double tol = 1e-9;
    using math::sqrt_heron;
    EXCEPT_NEAR(sqrt_heron(0.0), 0, tol);
    EXCEPT_NEAR(sqrt_heron(1.0), 1, tol);
    EXCEPT_NEAR(sqrt_heron(4.0), 2, tol);
    EXCEPT_NEAR(sqrt_heron(100.0), 10, tol);
    EXCEPT_NEAR(sqrt_heron(625), 25, tol);
    srand(1);
    for (int i = 0; i < 100; ++i) {
        double tmp = rand()/1000.0;
        double s = sqrt_heron(tmp);
        EXCEPT_NEAR(s * s, tmp, 1e-9);
    }
}

TEST(MATH, factorial) {
	using math::factorial;
	EXPECT_EQ(factorial(6,1001), 720);
	EXPECT_EQ(factorial(6,100), 20);
}

TEST(MATH_STATISTICS, binominal) {
    EXPECT_EQ(math::statistics::binominal(3,2,1001), 3);
}


TEST(MATH, prod) {
	using math::prod;
	using math::factorial;
	EXPECT_EQ(prod(1,6, 1001), 720);
	EXPECT_EQ(prod(5,6, 1001), 30);
	EXPECT_EQ(prod(6,6, 1001), 6);
	EXPECT_EQ(prod(0,10, 1001), 0);
	unsigned long long mod = 1000000007;
	EXPECT_EQ(prod(8, 13, mod),factorial(13, mod) / factorial(7, mod) );
}

TEST(MATH, binpowmod) {
	using math::binpowmod;
	mod = 1000000007;
	EXPECT_EQ(binpowmod(2,3,mod), 8);
	EXPECT_EQ(binpowmod(2,3,7), 1);
	EXPECT_EQ(binpowmod(10,6,mod), 1000000);
	EXPECT_EQ(binpowmod(1,1000,mod), 1);
	EXPECT_EQ(binpowmod(1000,1,mod), 1000);
	EXPECT_EQ(binpowmod(2,0,mod), 1);
	EXPECT_EQ(binpowmod(0,3,mod), 0);
	EXPECT_EQ(binpowmod(0,0,mod), 1);
}

TEST(MATH, invmod) {
	using math::invmod;
	unsigned long = 13;
	for(unsigned long a = 1; a< mod; a++) {
		EXPECT_EQ((invmod(a, mod) * a) % mod, 1);
	}
}

TEST(MATH, gcdex) {
	using math::gcdex;
	unsigned long a = 70;
	unsigned long b = 18;
	unsigned long x = 0;
	unsigned long y = 0;
	unsigned long d = gcdex(a,b,x,y);
	EXPECT_TRUE(a * x + b *y, d);

	for(int i = 0; i < 10; ++i) {
		a = rand()%10000;
		b = rand()%10000;
		d = gcdex(a,b,x,y);
		EXPECT_EQ(a * x + b*y , d);
	}

	EXPECT_EQ( gcdex(0,100, x, y), 100);
	EXPECT_EQ(gcdex(100, 0, x,y), 100);
}

TEST(MATH, mean) {
	using math::statistics::mean;
	double M[] = [1,1,1,1,1,1,1,1,1,1,1];
	int n = sizeof(M) / sizeof(M[0]);
	EXPECT_EQ(mean(M, n), 1);
	double M[] = [1,2,3,4,5,6,7,8,9,10];
        int n = sizeof(M) / sizeof(M[0]);
        EXPECT_EQ(mean(M, n), 5.5);
}

TEST(MATH, var) {
	using math::statistics::var;
	double M[] = [1,1,1,1,1,1,1,1,1,1];
	int n = sizeof(M) / sizeof(M[0]);
	EXPECT_EQ(var(M, n), 0);
	double M[] = [2,2,2,2,2,2,2,2,2,2];
	int  n = sizeof(M) / sizeof(M[0]);
	EXPECT_EQ(var(M, n),0);
}
