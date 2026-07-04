// Related Concept: [[01_Concepts/02_Vectors/01_Basics|01_Basics]]
export module vectors_basics;

import std;
import matrices_basics;
import linear_algebra_util;

export namespace vectors {

    struct alignas(16) vector3
    {
        float x{0.0}, y{0.0}, z{0.0};

        vector3() = default;

        vector3(const float xVal, const float yVal, const float zVal)
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
        vector3 operator*(const float value) const {
            return { x * value, y * value, z * value };
        }

        [[nodiscard]]
        vector3 operator/(const float value) const {
            if (util::floatEqual(value, 0.0f))
                return {x, y, z};

            const float reciprocal = 1.0 / value;
            return { x * reciprocal, y * reciprocal, z * reciprocal };
        }

        [[nodiscard]]
        float magnitude() const {
            return std::sqrt((x * x) + (y * y) + (z * z));
        }

        [[nodiscard]]
        vector3 normalized() const
        {
            const float m = magnitude();
            if (util::floatEqual(m, 0.0f))
                return {0.0f, 0.0f, 0.0f};

            const float reciprocal = 1.0 / m;
            return { x * reciprocal, y * reciprocal, z * reciprocal };
        }
    };

    struct alignas(16) vector4
    {
        float x{0.0}, y{0.0}, z{0.0}, w{0.0};

        vector4() = default;

        vector4(const float xVal, const float yVal, const float zVal, const float wVal)
            : x(xVal), y(yVal), z(zVal), w(wVal) {}

        vector4(const vector3& v, const float wVal = 1.0)
            : x(v.x), y(v.y), z(v.z), w(wVal) {}

        [[nodiscard]]
        vector4 operator+(const vector4 other) const {
            return { x + other.x, y + other.y, z + other.z, w + other.w };
        }

        [[nodiscard]]
        vector4 operator-(const vector4 other) const {
            return { x - other.x, y - other.y, z - other.z, w - other.w };
        }

        [[nodiscard]]
        vector4 operator*(const float value) const {
            return { x * value, y * value, z * value, w * value };
        }

        [[nodiscard]]
        vector4 operator/(const float value) const {
            if (util::floatEqual(value, 0.0f))
                return {x, y, z, w};

            const float reciprocal = 1.0 / value;
            return { x * reciprocal, y * reciprocal, z * reciprocal, w * reciprocal };
        }

        [[nodiscard]]
        float magnitude() const {
            return std::sqrt((x * x) + (y * y) + (z * z) + (w * w));
        }

        [[nodiscard]]
        vector4 normalized() const
        {
            const float m = magnitude();
            if (util::floatEqual(m, 0.0f))
                return {0.0f, 0.0f, 0.0f, 0.0f};

            const float reciprocal = 1.0 / m;
            return { x * reciprocal, y * reciprocal, z * reciprocal, w * reciprocal };
        }
    };

    [[nodiscard]]
    vector4 operator*(const matrices::Matrix4x4& m, const vector4& v)
    {
        return vector4{
            m[0, 0]*v.x + m[0, 1]*v.y + m[0, 2]*v.z + m[0, 3]*v.w,
            m[1, 0]*v.x + m[1, 1]*v.y + m[1, 2]*v.z + m[1, 3]*v.w,
            m[2, 0]*v.x + m[2, 1]*v.y + m[2, 2]*v.z + m[2, 3]*v.w,
            m[3, 0]*v.x + m[3, 1]*v.y + m[3, 2]*v.z + m[3, 3]*v.w
        };
    }

    [[nodiscard]]
    vector3 operator*(const matrices::Matrix4x4& m, const vector3& v)
    {
        // Apply affine transformation (3x3 linear part + translation 4th column)
        return vector3{
            m[0, 0]*v.x + m[0, 1]*v.y + m[0, 2]*v.z + m[0, 3],
            m[1, 0]*v.x + m[1, 1]*v.y + m[1, 2]*v.z + m[1, 3],
            m[2, 0]*v.x + m[2, 1]*v.y + m[2, 2]*v.z + m[2, 3]
        };
    }

    [[nodiscard]]
    float magnitude(const vector3 v) {
        return v.magnitude();
    }

    [[nodiscard]]
    vector3 normalized(const vector3 v) {
        return v.normalized();
    }

    [[nodiscard]]
    float magnitude(const vector4 v) {
        return v.magnitude();
    }

    [[nodiscard]]
    vector4 normalized(const vector4 v) {
        return v.normalized();
    }
}
