// Related Concept: [[01_Concepts/04_Transforms/10_Quaternions|10_Quaternions]]
export module transforms_quaternions;

import std;

import vectors_basics;
import linear_algebra_util;

export namespace transforms {
    struct alignas(16) Quaternion
    {
        float w{0.0}, x{0.0}, y{0.0}, z{0.0};

        Quaternion() = default;

        Quaternion(const float wVal, const float xVal, const float yVal, const float zVal)
            : w(wVal), x(xVal), y(yVal), z(zVal) {}

        Quaternion(const float wVal, const vectors::vector3& vVal)
            : w(wVal), x(vVal.x), y(vVal.y), z(vVal.z) {}

        [[nodiscard]]
        Quaternion operator*(const Quaternion other) const
        {
            return {
                w * other.w - x * other.x - y * other.y - z * other.z,
                w * other.x + x * other.w + y * other.z - z * other.y,
                w * other.y - x * other.z + y * other.w + z * other.x,
                w * other.z + x * other.y - y * other.x + z * other.w
            };
        }

        Quaternion operator/(const float value) const
        {
            if (util::floatEqual(value, 0.0f)) {
                return *this;
            }
            const float reciprocal = 1.0 / value;
            return { w * reciprocal, x * reciprocal, y * reciprocal, z * reciprocal };
        }
    };

    [[nodiscard]]
    float qMagnitude(const Quaternion& q)
    {
        return std::sqrt(q.w * q.w + q.x * q.x + q.y * q.y + q.z * q.z);
    }

    [[nodiscard]]
    Quaternion qConjugate(const Quaternion& q)
    {
        return { q.w, -q.x, -q.y, -q.z };
    }

    [[nodiscard]]
    Quaternion qInverse(const Quaternion& q)
    {
        const float mag = qMagnitude(q);
        if (util::floatEqual(mag, 0.0f)) {
            return {};
        }
        return qConjugate(q) / (mag * mag);
    }

    // Constructs a unit rotation quaternion representing a rotation of 'degrees' about the given 'axis'.
    // The input axis does not need to be pre-normalized.
    [[nodiscard]]
    Quaternion qRotationAxisAngle(const vectors::vector3& axis, const float degrees)
    {
        const float radians = degrees * std::numbers::pi / 180.0;
        const float half_angle = radians * 0.5;
        const vectors::vector3 normalized_axis = vectors::normalized(axis);
        return { std::cos(half_angle), normalized_axis * std::sin(half_angle) };
    }

    // Rotates a 3D vector 'v' using the unit quaternion 'q' via the sandwich product formula: q * p * q^-1
    [[nodiscard]]
    vectors::vector3 qRotateVector(const vectors::vector3& v, const Quaternion& q)
    {
        const Quaternion p(0.0, v);
        const Quaternion q_inv = qInverse(q);
        const Quaternion p_prime = q * p * q_inv;
        return vectors::vector3(p_prime.x, p_prime.y, p_prime.z);
    }
}
