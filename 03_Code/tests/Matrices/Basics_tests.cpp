#include <gtest/gtest.h>
import std;
import matrices_basics;

TEST(MatricesBasics, DefaultConstructorIsZero) {
    matrices::Matrix4x4 m;
    for (int r = 0; r < 4; ++r) {
        for (int c = 0; c < 4; ++c) {
            EXPECT_FLOAT_EQ((m[r, c]), 0.0);
        }
    }
}

TEST(MatricesBasics, IdentityMatrix) {
    matrices::Matrix4x4 m = matrices::Matrix4x4::identity();
    for (int r = 0; r < 4; ++r) {
        for (int c = 0; c < 4; ++c) {
            if (r == c) {
                EXPECT_FLOAT_EQ((m[r, c]), 1.0);
            } else {
                EXPECT_FLOAT_EQ((m[r, c]), 0.0);
            }
        }
    }
}

TEST(MatricesBasics, MatrixAdditionSubtraction) {
    matrices::Matrix4x4 a = matrices::Matrix4x4::identity();
    matrices::Matrix4x4 b = matrices::Matrix4x4::identity();

    matrices::Matrix4x4 sum = a + b;
    EXPECT_FLOAT_EQ((sum[0, 0]), 2.0);
    EXPECT_FLOAT_EQ((sum[0, 1]), 0.0);

    matrices::Matrix4x4 diff = a - b;
    EXPECT_FLOAT_EQ((diff[0, 0]), 0.0);
}

TEST(MatricesBasics, ScalarMultiplication) {
    matrices::Matrix4x4 a = matrices::Matrix4x4::identity();
    matrices::Matrix4x4 prod = a * 3.5;
    EXPECT_FLOAT_EQ((prod[0, 0]), 3.5);
    EXPECT_FLOAT_EQ((prod[1, 1]), 3.5);
    EXPECT_FLOAT_EQ((prod[0, 1]), 0.0);
}

TEST(MatricesBasics, Transpose) {
    matrices::Matrix4x4 m;
    m[0, 1] = 2.0;
    m[1, 0] = 5.0;

    matrices::Matrix4x4 mt = matrices::transpose(m);
    EXPECT_FLOAT_EQ((mt[0, 1]), 5.0);
    EXPECT_FLOAT_EQ((mt[1, 0]), 2.0);
}

TEST(MatricesBasics, Trace) {
    matrices::Matrix4x4 m = matrices::Matrix4x4::identity();
    EXPECT_FLOAT_EQ(matrices::trace(m), 4.0);

    m[0, 0] = 10.0;
    m[3, 3] = -2.5;
    EXPECT_FLOAT_EQ(matrices::trace(m), 9.5);
}
