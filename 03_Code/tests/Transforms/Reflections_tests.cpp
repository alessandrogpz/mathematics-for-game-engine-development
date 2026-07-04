#include <gtest/gtest.h>
import std;
import vectors_basics;
import transforms_reflections;

TEST(TransformsReflections, PlaneReflection) {
    vectors::vector3 v(2.0, -1.0, 3.0);
    vectors::vector3 normal(0.0, 0.0, 1.0); // Z normal

    vectors::vector3 res = transforms::reflection(normal, v);
    EXPECT_DOUBLE_EQ(res.x, 2.0);
    EXPECT_DOUBLE_EQ(res.y, -1.0);
    EXPECT_DOUBLE_EQ(res.z, -3.0);
}

TEST(TransformsReflections, AxisReflection) {
    vectors::vector3 v(2.0, -1.0, 3.0);
    vectors::vector3 normal(0.0, 0.0, 1.0); // Z normal -> 180 degrees rotate around Z axis

    vectors::vector3 res = transforms::involution(normal, v);
    EXPECT_DOUBLE_EQ(res.x, -2.0);
    EXPECT_DOUBLE_EQ(res.y, 1.0);
    EXPECT_DOUBLE_EQ(res.z, 3.0);
}
