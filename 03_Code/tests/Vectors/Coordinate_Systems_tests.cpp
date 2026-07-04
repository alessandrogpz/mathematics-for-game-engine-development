#include <gtest/gtest.h>
import std;
import vectors_basics;
import vectors_coordinate_systems;

TEST(CoordinateSystems, HandednessConversion) {
    vectors::vector3 v(1.0, 2.0, 3.0);
    vectors::vector3 lh = vectors::convertHandedness(v);
    
    EXPECT_FLOAT_EQ(lh.x, 1.0);
    EXPECT_FLOAT_EQ(lh.y, 2.0);
    EXPECT_FLOAT_EQ(lh.z, -3.0);

    vectors::vector3 rh = vectors::convertHandedness(lh);
    EXPECT_FLOAT_EQ(rh.z, 3.0);
}

TEST(CoordinateSystems, HandednessCrossProduct) {
    vectors::vector3 x(1.0, 0.0, 0.0);
    vectors::vector3 y(0.0, 1.0, 0.0);

    // Right-Handed: X x Y = Z
    vectors::vector3 cross_rh = vectors::crossProduct(x, y, vectors::Handedness::RightHanded);
    EXPECT_FLOAT_EQ(cross_rh.z, 1.0);

    // Left-Handed: X x Y = -Z
    vectors::vector3 cross_lh = vectors::crossProduct(x, y, vectors::Handedness::LeftHanded);
    EXPECT_FLOAT_EQ(cross_lh.z, -1.0);
}

TEST(CoordinateSystems, SphericalCardinalDirections) {
    // Point along +Y: inclination should be 0, azimuth 0
    vectors::vector3 y_up(0.0, 5.0, 0.0);
    vectors::spherical s1 = vectors::cartesianToSpherical(y_up);
    EXPECT_FLOAT_EQ(s1.r, 5.0);
    EXPECT_FLOAT_EQ(s1.theta, 0.0);
    EXPECT_FLOAT_EQ(s1.phi, 0.0);

    // Point along +X: inclination polar should be 90 degrees (pi/2), azimuth 0
    vectors::vector3 x_dir(2.0, 0.0, 0.0);
    vectors::spherical s2 = vectors::cartesianToSpherical(x_dir);
    EXPECT_FLOAT_EQ(s2.r, 2.0);
    EXPECT_NEAR(s2.theta, std::numbers::pi / 2.0, 1e-5f);
    EXPECT_FLOAT_EQ(s2.phi, 0.0);

    // Convert back from Spherical (1, pi/2, 0) -> (1, 0, 0)
    vectors::spherical s3{1.0, std::numbers::pi / 2.0, 0.0};
    vectors::vector3 c3 = vectors::sphericalToCartesian(s3);
    EXPECT_NEAR(c3.x, 1.0, 1e-5f);
    EXPECT_NEAR(c3.y, 0.0, 1e-5f);
    EXPECT_NEAR(c3.z, 0.0, 1e-5f);
}

TEST(CoordinateSystems, SphericalRoundTrip) {
    vectors::vector3 p(3.5, -1.2, 4.8);
    vectors::spherical s = vectors::cartesianToSpherical(p);
    vectors::vector3 round_trip = vectors::sphericalToCartesian(s);

    EXPECT_NEAR(round_trip.x, p.x, 1e-5f);
    EXPECT_NEAR(round_trip.y, p.y, 1e-5f);
    EXPECT_NEAR(round_trip.z, p.z, 1e-5f);
}

TEST(CoordinateSystems, CylindricalRoundTrip) {
    vectors::vector3 p(-2.5, 6.1, 8.4);
    vectors::cylindrical c = vectors::cartesianToCylindrical(p);
    
    // rho = sqrt(x^2 + y^2)
    EXPECT_NEAR(c.rho, std::sqrt(2.5*2.5 + 6.1*6.1), 1e-5f);
    
    vectors::vector3 round_trip = vectors::cylindricalToCartesian(c);
    EXPECT_NEAR(round_trip.x, p.x, 1e-5f);
    EXPECT_NEAR(round_trip.y, p.y, 1e-5f);
    EXPECT_NEAR(round_trip.z, p.z, 1e-5f);
}
