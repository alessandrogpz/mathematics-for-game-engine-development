#include <gtest/gtest.h>
import std;
import matrices_basics;
import matrices_orthogonal;

TEST(MatricesOrthogonal, IdentityIsOrthogonal) {
    matrices::Matrix4x4 i = matrices::Matrix4x4::identity();
    EXPECT_TRUE(matrices::isOrthogonal(i));
}

TEST(MatricesOrthogonal, RotationIsOrthogonal) {
    // Manually construct a rotation matrix around X-axis by 30 degrees (which is orthogonal)
    matrices::Matrix4x4 rotX;
    float radians = 30.0f * std::numbers::pi / 180.0f;
    
    rotX[0, 0] = 1.0f;
    rotX[0, 1] = 0.0f;
    rotX[0, 2] = 0.0f;
    rotX[0, 3] = 0.0f;

    rotX[1, 0] = 0.0f;
    rotX[1, 1] = std::cos(radians);
    rotX[1, 2] = -std::sin(radians);
    rotX[1, 3] = 0.0f;

    rotX[2, 0] = 0.0f;
    rotX[2, 1] = std::sin(radians);
    rotX[2, 2] = std::cos(radians);
    rotX[2, 3] = 0.0f;

    rotX[3, 0] = 0.0f;
    rotX[3, 1] = 0.0f;
    rotX[3, 2] = 0.0f;
    rotX[3, 3] = 1.0f;

    EXPECT_TRUE(matrices::isOrthogonal(rotX));
}

TEST(MatricesOrthogonal, ScaleIsNotOrthogonal) {
    // Uniform scale by 2.0f makes column vectors have length 2.0f, so it shouldn't be orthogonal
    matrices::Matrix4x4 s;
    s[0, 0] = 2.0f;
    s[1, 1] = 2.0f;
    s[2, 2] = 2.0f;
    s[3, 3] = 1.0f;

    EXPECT_FALSE(matrices::isOrthogonal(s));
}

TEST(MatricesOrthogonal, NonOrthogonalMatrix) {
    matrices::Matrix4x4 m = matrices::Matrix4x4::identity();
    m[0, 1] = 1.0f; // Introduce skew / linear dependence
    EXPECT_FALSE(matrices::isOrthogonal(m));
}
