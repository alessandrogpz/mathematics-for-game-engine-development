// Related Concept: [[01_Concepts/02_Vectors/01_Basics|01_Basics]]
module;
#include <cmath>
#include <iostream>

export module vectors_basics;

export namespace vectors {

    struct vector3
    {
        double x{0.0}, y{0.0}, z{0.0};

        vector3() = default;

        vector3(const double xVal, const double yVal, const double zVal)
            : x(xVal), y(yVal), z(zVal) {}

        [[nodiscard]]
        vector3 operator+(const vector3 other) const {
            return { x + other.x, y + other.y, z + other.z };
        }

        [[nodiscard]]
        vector3 operator-(const vector3 other) const {
            return { x - other.x, y - other.y, z - other.z };
        }

        [[nodiscard]]
        vector3 operator*(const double value) const {
            return { x * value, y * value, z * value };
        }

        [[nodiscard]]
        vector3 operator/(const double value) const {
            if (value == 0.0f)
                return {x, y, z};

            const double reciprocal = 1.0 / value;
            return { x * reciprocal, y * reciprocal, z * reciprocal };
        }

        [[nodiscard]]
        double magnitude() const {
            return std::sqrt((x * x) + (y * y) + (z * z));
        }

        [[nodiscard]]
        vector3 normalized() const
        {
            const double m = magnitude();
            if (m == 0.0)
                return {0.0, 0.0, 0.0};

            const double reciprocal = 1.0 / m;
            return { x * reciprocal, y * reciprocal, z * reciprocal };
        }


    };
}
