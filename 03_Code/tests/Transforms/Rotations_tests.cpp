#include <gtest/gtest.h>
import std;
import vectors_basics;
import transforms_rotations;

TEST(TransformsRotations, RotationX) {
    vectors::vector3 v(0.0, 1.0, 0.0);
    // Rotate 90 degrees about X -> sweeps Y to Z
    vectors::vector3 res = transforms::rotationX(v, 90.0);
    EXPECT_NEAR(res.x, 0.0, 1e-9);
    EXPECT_NEAR(res.y, 0.0, 1e-9);
    EXPECT_NEAR(res.z, 1.0, 1e-9);
}

TEST(TransformsRotations, RotationY) {
    vectors::vector3 v(1.0, 0.0, 0.0);
    // Rotate 90 degrees about Y -> sweeps X to -Z
    vectors::vector3 res = transforms::rotationY(v, 90.0);
    EXPECT_NEAR(res.x, 0.0, 1e-9);
    EXPECT_NEAR(res.y, 0.0, 1e-9);
    EXPECT_NEAR(res.z, -1.0, 1e-9);
}

TEST(TransformsRotations, RotationZ) {
    vectors::vector3 v(1.0, 0.0, 0.0);
    // Rotate 90 degrees about Z -> sweeps X to Y
    vectors::vector3 res = transforms::rotationZ(v, 90.0);
    EXPECT_NEAR(res.x, 0.0, 1e-9);
    EXPECT_NEAR(res.y, 1.0, 1e-9);
    EXPECT_NEAR(res.z, 0.0, 1e-9);
}

TEST(TransformsRotations, RotationArbitrary) {
    vectors::vector3 v(0.0, 1.0, 0.0);
    vectors::vector3 axis(0.0, 0.0, 1.0); // Z-axis
    vectors::vector3 res = transforms::rotationArbitraryAxis(v, axis, 90.0);
    EXPECT_NEAR(res.x, -1.0, 1e-9);
    EXPECT_NEAR(res.y, 0.0, 1e-9);
    EXPECT_NEAR(res.z, 0.0, 1e-9);
}
