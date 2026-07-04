// Related Concept: [[01_Concepts/02_Vectors/03_Coordinate_Systems|03_Coordinate_Systems]]
export module vectors_coordinate_systems;

import std;
import vectors_basics;
import vectors_cross_product;
import linear_algebra_util;

export namespace vectors {

    enum class Handedness
    {
        RightHanded,
        LeftHanded
    };

    struct spherical
    {
        float r{0.0};      // Radial distance
        float theta{0.0};  // Inclination / polar angle (from positive Y-axis) in radians
        float phi{0.0};    // Azimuthal angle (in XZ plane) in radians
    };

    struct cylindrical
    {
        float rho{0.0};    // Radial distance in XY plane
        float phi{0.0};    // Azimuthal angle in XY plane in radians
        float z{0.0};      // Height along Z-axis
    };

    // --- 1. Handedness Conversions ---

    // Converts a point/vector between Right-Handed and Left-Handed spaces by reversing the Z-axis.
    [[nodiscard]]
    vector3 convertHandedness(const vector3& v)
    {
        return { v.x, v.y, -v.z };
    }

    // Calculates the cross product depending on the coordinate system's handedness.
    // Right-handed: standard cross product direction.
    // Left-handed: negated cross product direction.
    [[nodiscard]]
    vector3 crossProduct(const vector3& a, const vector3& b, const Handedness h)
    {
        if (h == Handedness::RightHanded) {
            return crossProd(a, b);
        } else {
            return crossProd(b, a); // negated standard cross product
        }
    }

    // --- 2. Spherical Coordinate Conversions (Y-up convention) ---

    [[nodiscard]]
    spherical cartesianToSpherical(const vector3& v)
    {
        const float r = v.magnitude();
        if (util::floatEqual(r, 0.0f)) {
            return {0.0f, 0.0f, 0.0f};
        }
        
        // Inclination angle theta from positive Y-axis [0, pi]
        // y = r * cos(theta) => theta = acos(y/r)
        const float cosTheta = std::clamp(v.y / r, -1.0f, 1.0f);
        const float theta = std::acos(cosTheta);

        // Azimuthal angle phi in XZ plane [-pi, pi]
        // x = r * sin(theta) * cos(phi)
        // z = r * sin(theta) * sin(phi)
        // => phi = atan2(z, x)
        const float phi = std::atan2(v.z, v.x);

        return { r, theta, phi };
    }

    [[nodiscard]]
    vector3 sphericalToCartesian(const spherical& s)
    {
        const float sinTheta = std::sin(s.theta);
        const float cosTheta = std::cos(s.theta);
        const float sinPhi = std::sin(s.phi);
        const float cosPhi = std::cos(s.phi);

        return {
            s.r * sinTheta * cosPhi,
            s.r * cosTheta,
            s.r * sinTheta * sinPhi
        };
    }

    // --- 3. Cylindrical Coordinate Conversions (Z-up height) ---

    [[nodiscard]]
    cylindrical cartesianToCylindrical(const vector3& v)
    {
        const float rho = std::sqrt(v.x * v.x + v.y * v.y);
        const float phi = std::atan2(v.y, v.x);
        return { rho, phi, v.z };
    }

    [[nodiscard]]
    vector3 cylindricalToCartesian(const cylindrical& c)
    {
        return {
            c.rho * std::cos(c.phi),
            c.rho * std::sin(c.phi),
            c.z
        };
    }
}
