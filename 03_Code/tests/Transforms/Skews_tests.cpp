#include <gtest/gtest.h>
import std;
import vectors_basics;
import transforms_skews;

TEST(TransformsSkews, StandardSkew) {
    vectors::vector3 v(2.0, 3.0, 5.0);
    vectors::vector3 dir(1.0, 0.0, 0.0);   // along X-axis
    vectors::vector3 meas(0.0, 1.0, 0.0);  // relative to Y-axis

    // Skew 45 degrees -> tan(45) = 1.0
    // x' = x + y * tan(45) = 2 + 3 * 1 = 5
    vectors::vector3 res = transforms::skew(dir, meas, v, 45.0);
    EXPECT_NEAR(res.x, 5.0, 1e-9);
    EXPECT_NEAR(res.y, 3.0, 1e-9);
    EXPECT_NEAR(res.z, 5.0, 1e-9);
}
