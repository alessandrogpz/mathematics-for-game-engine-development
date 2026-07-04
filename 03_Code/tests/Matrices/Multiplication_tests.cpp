#include <gtest/gtest.h>
import std;
import matrices_basics;
import matrices_multiplication;

TEST(MatricesMultiplication, IdentityMultiplication) {
    matrices::Matrix4x4 m;
    m[0, 0] = 1.0; m[0, 1] = 2.0; m[0, 2] = 3.0; m[0, 3] = 4.0;
    m[1, 0] = 5.0; m[1, 1] = 6.0; m[1, 2] = 7.0; m[1, 3] = 8.0;
    
    matrices::Matrix4x4 i = matrices::Matrix4x4::identity();
    
    // M * I == M
    matrices::Matrix4x4 res = matrices::matrixMultiplication4x4(m, i);
    for (int r = 0; r < 4; ++r) {
        for (int c = 0; c < 4; ++c) {
            EXPECT_FLOAT_EQ((res[r, c]), (m[r, c]));
        }
    }
}

TEST(MatricesMultiplication, GeneralMultiplication) {
    matrices::Matrix4x4 a;
    a[0, 0] = 1.0; a[0, 1] = 2.0; a[0, 2] = 3.0; a[0, 3] = 0.0;
    a[1, 0] = 4.0; a[1, 1] = 5.0; a[1, 2] = 6.0; a[1, 3] = 0.0;
    a[2, 0] = 7.0; a[2, 1] = 8.0; a[2, 2] = 9.0; a[2, 3] = 0.0;
    a[3, 0] = 0.0; a[3, 1] = 0.0; a[3, 2] = 0.0; a[3, 3] = 1.0;

    // Multiply by itself (squared)
    matrices::Matrix4x4 res = matrices::matrixMultiplication4x4(a, a);
    
    // Row 0 x Col 0 = 30
    EXPECT_FLOAT_EQ((res[0, 0]), 30.0);
    // Row 0 x Col 1 = 36
    EXPECT_FLOAT_EQ((res[0, 1]), 36.0);
    // Row 3 x Col 3 = 1.0
    EXPECT_FLOAT_EQ((res[3, 3]), 1.0);
}
