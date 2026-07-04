#include <gtest/gtest.h>
import std;
import vectors_basics;
import matrices_basics;

TEST(Vector3Basics, ConstructorsAndComponents) {
    vectors::vector3 v1;
    EXPECT_DOUBLE_EQ(v1.x, 0.0);
    EXPECT_DOUBLE_EQ(v1.y, 0.0);
    EXPECT_DOUBLE_EQ(v1.z, 0.0);

    vectors::vector3 v2(1.5, -2.0, 3.1);
    EXPECT_DOUBLE_EQ(v2.x, 1.5);
    EXPECT_DOUBLE_EQ(v2.y, -2.0);
    EXPECT_DOUBLE_EQ(v2.z, 3.1);
}

TEST(Vector3Basics, AdditionSubtraction) {
    vectors::vector3 v1(1.0, 2.0, 3.0);
    vectors::vector3 v2(4.0, 5.0, 6.0);

    vectors::vector3 sum = v1 + v2;
    EXPECT_DOUBLE_EQ(sum.x, 5.0);
    EXPECT_DOUBLE_EQ(sum.y, 7.0);
    EXPECT_DOUBLE_EQ(sum.z, 9.0);

    vectors::vector3 diff = v2 - v1;
    EXPECT_DOUBLE_EQ(diff.x, 3.0);
    EXPECT_DOUBLE_EQ(diff.y, 3.0);
    EXPECT_DOUBLE_EQ(diff.z, 3.0);
}

TEST(Vector3Basics, ScalarMultiplicationDivision) {
    vectors::vector3 v(2.0, -4.0, 8.0);

    vectors::vector3 prod = v * 2.5;
    EXPECT_DOUBLE_EQ(prod.x, 5.0);
    EXPECT_DOUBLE_EQ(prod.y, -10.0);
    EXPECT_DOUBLE_EQ(prod.z, 20.0);

    vectors::vector3 quot = v / 2.0;
    EXPECT_DOUBLE_EQ(quot.x, 1.0);
    EXPECT_DOUBLE_EQ(quot.y, -2.0);
    EXPECT_DOUBLE_EQ(quot.z, 4.0);

    // Division by zero edge case
    vectors::vector3 divZero = v / 0.0;
    EXPECT_DOUBLE_EQ(divZero.x, v.x);
    EXPECT_DOUBLE_EQ(divZero.y, v.y);
    EXPECT_DOUBLE_EQ(divZero.z, v.z);
}

TEST(Vector3Basics, MagnitudeAndNormalization) {
    vectors::vector3 v(3.0, 0.0, 4.0);
    EXPECT_DOUBLE_EQ(v.magnitude(), 5.0);

    vectors::vector3 v_norm = v.normalized();
    EXPECT_DOUBLE_EQ(v_norm.x, 0.6);
    EXPECT_DOUBLE_EQ(v_norm.y, 0.0);
    EXPECT_DOUBLE_EQ(v_norm.z, 0.8);

    // Zero vector magnitude and normalization
    vectors::vector3 zero;
    EXPECT_DOUBLE_EQ(zero.magnitude(), 0.0);
    vectors::vector3 zero_norm = zero.normalized();
    EXPECT_DOUBLE_EQ(zero_norm.x, 0.0);
    EXPECT_DOUBLE_EQ(zero_norm.y, 0.0);
    EXPECT_DOUBLE_EQ(zero_norm.z, 0.0);
}

TEST(Vector4Basics, ConstructorsAndArithmetic) {
    vectors::vector4 v1(1.0, 2.0, 3.0, 4.0);
    EXPECT_DOUBLE_EQ(v1.x, 1.0);
    EXPECT_DOUBLE_EQ(v1.w, 4.0);

    vectors::vector3 v3(5.0, 6.0, 7.0);
    vectors::vector4 v4(v3, 2.0);
    EXPECT_DOUBLE_EQ(v4.x, 5.0);
    EXPECT_DOUBLE_EQ(v4.w, 2.0);

    vectors::vector4 sum = v1 + v4;
    EXPECT_DOUBLE_EQ(sum.x, 6.0);
    EXPECT_DOUBLE_EQ(sum.w, 6.0);

    vectors::vector4 prod = v1 * 2.0;
    EXPECT_DOUBLE_EQ(prod.w, 8.0);
}

TEST(MatrixVectorMultiplication, AffinePointTransform) {
    matrices::Matrix4x4 m = matrices::Matrix4x4::identity();
    m[0, 3] = 10.0; // translation in x
    m[1, 3] = -5.0; // translation in y

    vectors::vector3 p(2.0, 3.0, 4.0);
    vectors::vector3 p_trans = m * p;
    EXPECT_DOUBLE_EQ(p_trans.x, 12.0);
    EXPECT_DOUBLE_EQ(p_trans.y, -2.0);
    EXPECT_DOUBLE_EQ(p_trans.z, 4.0);
}

TEST(MatrixVectorMultiplication, HomogeneousTransform) {
    matrices::Matrix4x4 m = matrices::Matrix4x4::identity();
    m[0, 3] = 10.0;

    vectors::vector4 p_point(2.0, 3.0, 4.0, 1.0);
    vectors::vector4 p_trans = m * p_point;
    EXPECT_DOUBLE_EQ(p_trans.x, 12.0);
    EXPECT_DOUBLE_EQ(p_trans.w, 1.0);

    vectors::vector4 p_dir(2.0, 3.0, 4.0, 0.0);
    vectors::vector4 p_dir_trans = m * p_dir;
    EXPECT_DOUBLE_EQ(p_dir_trans.x, 2.0); // translation ignored for direction w=0
    EXPECT_DOUBLE_EQ(p_dir_trans.w, 0.0);
}
