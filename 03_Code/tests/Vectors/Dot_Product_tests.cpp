#include <gtest/gtest.h>
import std;
import vectors_basics;
import vectors_dot_product;

TEST(VectorsDotProduct, DotProduct3D) {
    vectors::vector3 a(1.0, 2.0, 3.0);
    vectors::vector3 b(4.0, 5.0, 6.0);
    EXPECT_DOUBLE_EQ(vectors::dot(a, b), 32.0);

    // Orthogonal case
    vectors::vector3 o1(1.0, 0.0, 0.0);
    vectors::vector3 o2(0.0, 1.0, 0.0);
    EXPECT_DOUBLE_EQ(vectors::dot(o1, o2), 0.0);
}

TEST(VectorsDotProduct, DotProduct4D) {
    vectors::vector4 a(1.0, 2.0, 3.0, 4.0);
    vectors::vector4 b(5.0, 6.0, 7.0, 8.0);
    EXPECT_DOUBLE_EQ(vectors::dot(a, b), 70.0);
}

TEST(VectorsDotProduct, GeometricDot) {
    vectors::vector3 a(2.0, 0.0, 0.0);
    vectors::vector3 b(0.0, 3.0, 0.0);
    // 90 degrees = pi / 2
    EXPECT_NEAR(vectors::dotGeo(a, b, std::numbers::pi / 2.0), 0.0, 1e-15);

    // Parallel case, 0 degrees
    EXPECT_DOUBLE_EQ(vectors::dotGeo(a, a, 0.0), 4.0);
}

TEST(VectorsDotProduct, AngleBetween) {
    vectors::vector3 a(1.0, 0.0, 0.0);
    vectors::vector3 b(0.0, 1.0, 0.0);
    EXPECT_NEAR(vectors::angle(a, b), std::numbers::pi / 2.0, 1e-9);

    // Collinear/Same direction
    EXPECT_NEAR(vectors::angle(a, a), 0.0, 1e-9);

    // Zero vector safety
    vectors::vector3 zero;
    EXPECT_DOUBLE_EQ(vectors::angle(a, zero), 0.0);
}
