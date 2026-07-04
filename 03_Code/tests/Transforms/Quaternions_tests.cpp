#include <gtest/gtest.h>
import std;
import vectors_basics;
import transforms_quaternions;

TEST(TransformsQuaternions, QuaternionBasics) {
    transforms::Quaternion q1(1.0, 2.0, 3.0, 4.0);
    EXPECT_DOUBLE_EQ(q1.w, 1.0);
    EXPECT_DOUBLE_EQ(q1.x, 2.0);
    EXPECT_DOUBLE_EQ(q1.y, 3.0);
    EXPECT_DOUBLE_EQ(q1.z, 4.0);

    vectors::vector3 v(2.0, 3.0, 4.0);
    transforms::Quaternion q2(1.0, v);
    EXPECT_DOUBLE_EQ(q2.w, 1.0);
    EXPECT_DOUBLE_EQ(q2.x, 2.0);
    EXPECT_DOUBLE_EQ(q2.y, 3.0);
    EXPECT_DOUBLE_EQ(q2.z, 4.0);
}

TEST(TransformsQuaternions, MagnitudeConjugateInverse) {
    transforms::Quaternion q(1.0, 1.0, 1.0, 1.0);
    EXPECT_DOUBLE_EQ(transforms::qMagnitude(q), 2.0); // sqrt(4) = 2

    transforms::Quaternion conj = transforms::qConjugate(q);
    EXPECT_DOUBLE_EQ(conj.w, 1.0);
    EXPECT_DOUBLE_EQ(conj.x, -1.0);

    transforms::Quaternion inv = transforms::qInverse(q);
    EXPECT_DOUBLE_EQ(inv.w, 0.25);
    EXPECT_DOUBLE_EQ(inv.x, -0.25);
}

TEST(TransformsQuaternions, QuaternionMultiplication) {
    transforms::Quaternion q1(1.0, 2.0, 3.0, 4.0);
    transforms::Quaternion q2(5.0, 6.0, 7.0, 8.0);

    transforms::Quaternion res = q1 * q2;
    // Real part: 1*5 - (2*6 + 3*7 + 4*8) = 5 - (12 + 21 + 32) = 5 - 65 = -60
    EXPECT_DOUBLE_EQ(res.w, -60.0);
}

TEST(TransformsQuaternions, VectorRotation) {
    vectors::vector3 axis(0.0, 0.0, 1.0); // Z axis
    vectors::vector3 v(0.0, 1.0, 0.0);    // Y axis
    
    // Rotate 90 degrees around Z axis sweeps Y to -X
    transforms::Quaternion q = transforms::qRotationAxisAngle(axis, 90.0);
    vectors::vector3 rot = transforms::qRotateVector(v, q);

    EXPECT_NEAR(rot.x, -1.0, 1e-9);
    EXPECT_NEAR(rot.y, 0.0, 1e-9);
    EXPECT_NEAR(rot.z, 0.0, 1e-9);
}
