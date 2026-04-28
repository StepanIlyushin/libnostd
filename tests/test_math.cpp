#include <gtest/gtest.h>
#include <libnostd/math/core.hpp>

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