#include <gtest/gtest.h>
import std;
import matrices_basics;
import matrices_determinants;

TEST(MatricesDeterminants, IdentityDeterminant) {
    matrices::Matrix4x4 i = matrices::Matrix4x4::identity();
    EXPECT_FLOAT_EQ(matrices::determinant(i), 1.0);
}

TEST(MatricesDeterminants, SubDeterminants) {
    matrices::Matrix4x4 m;
    m[0, 0] = 1.0; m[0, 1] = 0.0; m[0, 2] = 2.0;
    m[1, 0] = 0.0; m[1, 1] = 3.0; m[1, 2] = 0.0;
    m[2, 0] = 4.0; m[2, 1] = 0.0; m[2, 2] = 5.0;

    // Sub-determinant of the top-left 3x3 submatrix
    float sub = matrices::subDeterminant3x3(m, 0, 1, 2, 0, 1, 2);
    // 3x3 determinant is: 1 * (15 - 0) - 0 + 2 * (0 - 12) = 15 - 24 = -9
    EXPECT_FLOAT_EQ(sub, -9.0);
}

TEST(MatricesDeterminants, GeneralDeterminant) {
    matrices::Matrix4x4 b;
    b[0, 0] = 1.0; b[0, 1] = 0.0; b[0, 2] = 2.0; b[0, 3] = 0.0;
    b[1, 0] = 0.0; b[1, 1] = 3.0; b[1, 2] = 0.0; b[1, 3] = 0.0;
    b[2, 0] = 4.0; b[2, 1] = 0.0; b[2, 2] = 5.0; b[2, 3] = 0.0;
    b[3, 0] = 0.0; b[3, 1] = 0.0; b[3, 2] = 0.0; b[3, 3] = 1.0;

    EXPECT_FLOAT_EQ(matrices::determinant(b), -9.0);
}

TEST(MatricesDeterminants, SingularMatrix) {
    matrices::Matrix4x4 a;
    a[0, 0] = 1.0; a[0, 1] = 2.0; a[0, 2] = 3.0;
    a[1, 0] = 4.0; a[1, 1] = 5.0; a[1, 2] = 6.0;
    a[2, 0] = 7.0; a[2, 1] = 8.0; a[2, 2] = 9.0;
    a[3, 3] = 1.0; // linearly dependent rows in top-left 3x3, det should be 0

    EXPECT_FLOAT_EQ(matrices::determinant(a), 0.0);
}
