#include <gtest/gtest.h>
import std;
import vectors_basics;
import vectors_cross_product;
import vectors_scalar_triple_product;

TEST(VectorsCrossProduct, CrossProductAxes) {
    vectors::vector3 x(1.0, 0.0, 0.0);
    vectors::vector3 y(0.0, 1.0, 0.0);
    vectors::vector3 z = vectors::crossProd(x, y);

    EXPECT_FLOAT_EQ(z.x, 0.0);
    EXPECT_FLOAT_EQ(z.y, 0.0);
    EXPECT_FLOAT_EQ(z.z, 1.0);

    // Y x X = -Z
    vectors::vector3 neg_z = vectors::crossProd(y, x);
    EXPECT_FLOAT_EQ(neg_z.z, -1.0);
}

TEST(VectorsCrossProduct, ParallelVectors) {
    vectors::vector3 a(1.5, -2.0, 3.0);
    vectors::vector3 b(3.0, -4.0, 6.0); // b = 2*a
    vectors::vector3 cross = vectors::crossProd(a, b);

    EXPECT_FLOAT_EQ(cross.x, 0.0);
    EXPECT_FLOAT_EQ(cross.y, 0.0);
    EXPECT_FLOAT_EQ(cross.z, 0.0);
}

TEST(VectorsCrossProduct, ScalarTripleProduct) {
    vectors::vector3 a(1.0, 0.0, 0.0);
    vectors::vector3 b(0.0, 2.0, 0.0);
    vectors::vector3 c(0.0, 0.0, 3.0);

    // Box volume = a . (b x c) = 1 * (2 * 3) = 6
    EXPECT_FLOAT_EQ(vectors::tripleScalarProd(a, b, c), 6.0);

    // Coplanar vectors -> volume = 0
    EXPECT_FLOAT_EQ(vectors::tripleScalarProd(a, b, a), 0.0);
}
