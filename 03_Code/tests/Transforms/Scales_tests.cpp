#include <gtest/gtest.h>
import std;
import vectors_basics;
import transforms_scales;

TEST(TransformsScales, UniformScale) {
    vectors::vector3 v(2.0, -3.0, 4.0);
    vectors::vector3 res = transforms::scaleUniform(v, 2.5);
    EXPECT_FLOAT_EQ(res.x, 5.0);
    EXPECT_FLOAT_EQ(res.y, -7.5);
    EXPECT_FLOAT_EQ(res.z, 10.0);
}

TEST(TransformsScales, NonuniformScale) {
    vectors::vector3 v(1.0, 2.0, 3.0);
    vectors::vector3 res = transforms::scaleNonuniform(v, 3.0, 0.5, -2.0);
    EXPECT_FLOAT_EQ(res.x, 3.0);
    EXPECT_FLOAT_EQ(res.y, 1.0);
    EXPECT_FLOAT_EQ(res.z, -6.0);
}

TEST(TransformsScales, ArbitraryScale) {
    vectors::vector3 v(1.0, 2.0, 3.0);
    vectors::vector3 axis(0.0, 1.0, 0.0); // Y-axis
    // Scale along Y-axis by 4.0
    vectors::vector3 res = transforms::scaleArbitraryAxis(v, axis, 4.0);
    EXPECT_FLOAT_EQ(res.x, 1.0);
    EXPECT_FLOAT_EQ(res.y, 8.0);
    EXPECT_FLOAT_EQ(res.z, 3.0);
}
