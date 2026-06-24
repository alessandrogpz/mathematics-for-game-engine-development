// Related Concept: [[01_Concepts/04_Transforms/10_Quaternions|10_Quaternions]]
module;
#include <iostream>
#include <cmath>
#include <numbers>

export module transforms_quaternions;

import vectors_basics;
import vectors_cross_product;
import vectors_dot_product;

export namespace transforms {
    struct Quaternion
    {
        double scalar{};
        vectors::vector3 v_comp{};

        Quaternion() = default;

        Quaternion(const double sVal, const double iVal, const double jVal, const double kVal)
            : scalar(sVal), v_comp(iVal, jVal, kVal) {}

        Quaternion(const double sVal, const vectors::vector3& vVal)
            : scalar(sVal), v_comp(vVal) {}

        [[nodiscard]]
        Quaternion operator*(const Quaternion other) const
        {
            const double s = (scalar * other.scalar) - vectors::dot(v_comp, other.v_comp);
            const vectors::vector3 v = (other.v_comp * scalar) +
                                       (v_comp * other.scalar) +
                                       vectors::crossProd(v_comp, other.v_comp);
            return { s, v };
        }

        Quaternion operator/(const double value) const
        {
            if (value == 0.0) {
                return *this;
            }
            const double reciprocal = 1.0 / value;
            return { scalar * reciprocal, v_comp * reciprocal };
        }
    };

    [[nodiscard]]
    double qMagnitude(const Quaternion& q)
    {
        const double vec_mag = q.v_comp.magnitude();
        return sqrt(q.scalar * q.scalar + vec_mag * vec_mag);
    }

    [[nodiscard]]
    Quaternion qConjugate(const Quaternion& q)
    {
        return {q.scalar, -q.v_comp.x, -q.v_comp.y, -q.v_comp.z};
    }

    [[nodiscard]]
    Quaternion qInverse(const Quaternion& q)
    {
        const double mag = qMagnitude(q);
        if (mag == 0.0) {
            return {};
        }
        return qConjugate(q) / (mag * mag);
    }

    // Constructs a unit rotation quaternion representing a rotation of 'degrees' about the given 'axis'.
    // The input axis does not need to be pre-normalized.
    [[nodiscard]]
    Quaternion qRotationAxisAngle(const vectors::vector3& axis, const double degrees)
    {
        const double radians = degrees * std::numbers::pi / 180.0;
        const double half_angle = radians * 0.5;
        const vectors::vector3 normalized_axis = axis.normalized();
        return { std::cos(half_angle), normalized_axis * std::sin(half_angle) };
    }

    // Rotates a 3D vector 'v' using the unit quaternion 'q' via the sandwich product formula: q * p * q^-1
    [[nodiscard]]
    vectors::vector3 qRotateVector(const vectors::vector3& v, const Quaternion& q)
    {
        const Quaternion p(0.0, v);
        const Quaternion q_inv = qInverse(q);
        const Quaternion p_prime = q * p * q_inv;
        return p_prime.v_comp;
    }
}
