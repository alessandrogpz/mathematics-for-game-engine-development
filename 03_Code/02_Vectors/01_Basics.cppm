// Related Concept: [[01_Concepts/02_Vectors/01_Basics|01_Basics]]
module;
#include <cmath>
#include <iostream>

export module vectors_basics;

import matrices_basics;

export namespace vectors {

    struct alignas(32) vector3
    {
        double x{0.0}, y{0.0}, z{0.0}, w{0.0};

        vector3() = default;

        vector3(const double xVal, const double yVal, const double zVal, const double wVal = 0.0)
            : x(xVal), y(yVal), z(zVal), w(wVal) {}

        [[nodiscard]]
        vector3 operator+(const vector3 other) const {
            return { x + other.x, y + other.y, z + other.z, w + other.w };
        }

        [[nodiscard]]
        vector3 operator-(const vector3 other) const {
            return { x - other.x, y - other.y, z - other.z, w - other.w };
        }

        [[nodiscard]]
        vector3 operator*(const double value) const {
            return { x * value, y * value, z * value, w * value };
        }

        [[nodiscard]]
        vector3 operator/(const double value) const {
            if (value == 0.0)
                return {x, y, z, w};

            const double reciprocal = 1.0 / value;
            return { x * reciprocal, y * reciprocal, z * reciprocal, w * reciprocal };
        }

        [[nodiscard]]
        double magnitude() const {
            return std::sqrt((x * x) + (y * y) + (z * z) + (w * w));
        }

        [[nodiscard]]
        vector3 normalized() const
        {
            const double m = magnitude();
            if (m == 0.0)
                return {0.0, 0.0, 0.0, 0.0};

            const double reciprocal = 1.0 / m;
            return { x * reciprocal, y * reciprocal, z * reciprocal, w * reciprocal };
        }
    };

    [[nodiscard]]
    vector3 operator*(const matrices::Matrix4x4& m, const vector3& v)
    {
        return vector3{
            m[0, 0]*v.x + m[0, 1]*v.y + m[0, 2]*v.z + m[0, 3]*v.w,
            m[1, 0]*v.x + m[1, 1]*v.y + m[1, 2]*v.z + m[1, 3]*v.w,
            m[2, 0]*v.x + m[2, 1]*v.y + m[2, 2]*v.z + m[2, 3]*v.w,
            m[3, 0]*v.x + m[3, 1]*v.y + m[3, 2]*v.z + m[3, 3]*v.w
        };
    }

    [[nodiscard]]
    double magnitude(const vector3 v) {
        return v.magnitude();
    }

    [[nodiscard]]
    vector3 normalized(const vector3 v) {
        return v.normalized();
    }
}
