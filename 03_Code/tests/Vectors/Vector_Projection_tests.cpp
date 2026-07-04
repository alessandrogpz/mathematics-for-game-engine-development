#include <gtest/gtest.h>
import std;
import vectors_basics;
import vectors_projection;

TEST(VectorProjection, ProjectionAxes) {
    vectors::vector3 v(3.0, 4.0, 5.0);
    vectors::vector3 axis(1.0, 0.0, 0.0); // X-axis

    double s = vectors::scalarProj(v, axis);
    EXPECT_DOUBLE_EQ(s, 3.0);

    vectors::vector3 p = vectors::vecProj(v, axis);
    EXPECT_DOUBLE_EQ(p.x, 3.0);
    EXPECT_DOUBLE_EQ(p.y, 0.0);
    EXPECT_DOUBLE_EQ(p.z, 0.0);

    vectors::vector3 r = vectors::vecRej(v, axis);
    EXPECT_DOUBLE_EQ(r.x, 0.0);
    EXPECT_DOUBLE_EQ(r.y, 4.0);
    EXPECT_DOUBLE_EQ(r.z, 5.0);
}

TEST(VectorProjection, OrthogonalRejection) {
    vectors::vector3 v(0.0, 5.0, 0.0);
    vectors::vector3 axis(1.0, 0.0, 0.0); // X-axis

    // orthogonal vector -> projection should be 0, rejection should be original vector
    vectors::vector3 p = vectors::vecProj(v, axis);
    EXPECT_DOUBLE_EQ(p.magnitude(), 0.0);

    vectors::vector3 r = vectors::vecRej(v, axis);
    EXPECT_DOUBLE_EQ(r.x, 0.0);
    EXPECT_DOUBLE_EQ(r.y, 5.0);
    EXPECT_DOUBLE_EQ(r.z, 0.0);
}
