#include <gtest/gtest.h>
import std;
import matrices_basics;
import matrices_multiplication;
import matrices_inversion;

TEST(MatricesInversion, IdentityInverse) {
    matrices::Matrix4x4 i = matrices::Matrix4x4::identity();
    matrices::Matrix4x4 inv = matrices::inverse(i);
    for (int r = 0; r < 4; ++r) {
        for (int c = 0; c < 4; ++c) {
            EXPECT_NEAR((inv[r, c]), (i[r, c]), 1e-5f);
        }
    }
}

TEST(MatricesInversion, GeneralInverse) {
    matrices::Matrix4x4 b;
    b[0, 0] = 1.0; b[0, 1] = 0.0; b[0, 2] = 2.0; b[0, 3] = 0.0;
    b[1, 0] = 0.0; b[1, 1] = 3.0; b[1, 2] = 0.0; b[1, 3] = 0.0;
    b[2, 0] = 4.0; b[2, 1] = 0.0; b[2, 2] = 5.0; b[2, 3] = 0.0;
    b[3, 0] = 0.0; b[3, 1] = 0.0; b[3, 2] = 0.0; b[3, 3] = 1.0;

    matrices::Matrix4x4 b_inv = matrices::inverse(b);
    matrices::Matrix4x4 prod = matrices::matrixMultiplication4x4(b, b_inv);
    matrices::Matrix4x4 i = matrices::Matrix4x4::identity();

    for (int r = 0; r < 4; ++r) {
        for (int c = 0; c < 4; ++c) {
            EXPECT_NEAR((prod[r, c]), (i[r, c]), 1e-5f);
        }
    }
}

TEST(MatricesInversion, SingularMatrixReturnsZero) {
    matrices::Matrix4x4 a;
    a[0, 0] = 1.0; a[0, 1] = 2.0; a[0, 2] = 3.0;
    a[1, 0] = 4.0; a[1, 1] = 5.0; a[1, 2] = 6.0;
    a[2, 0] = 7.0; a[2, 1] = 8.0; a[2, 2] = 9.0;
    a[3, 3] = 1.0;

    matrices::Matrix4x4 inv = matrices::inverse(a);
    for (int r = 0; r < 4; ++r) {
        for (int c = 0; c < 4; ++c) {
            EXPECT_FLOAT_EQ((inv[r, c]), 0.0);
        }
    }
}
