// Related Concept: [[01_Concepts/03_Matrices/05_Orthogonal_Matrices|05_Orthogonal_Matrices]]
export module matrices_orthogonal;

import std;

import matrices_basics;
import vectors_basics;
import vectors_dot_product;
import linear_algebra_util;

export namespace matrices {

    [[nodiscard]]
    bool isOrthogonal(const matrices::Matrix4x4 &m)
    {
        vectors::vector4 c0(m[0, 0], m[1, 0], m[2, 0], m[3, 0]);
        vectors::vector4 c1(m[0, 1], m[1, 1], m[2, 1], m[3, 1]);
        vectors::vector4 c2(m[0, 2], m[1, 2], m[2, 2], m[3, 2]);
        vectors::vector4 c3(m[0, 3], m[1, 3], m[2, 3], m[3, 3]);

        // Check Column Magnitudes (Must be ~1)
        if (std::abs(vectors::dot(c0, c0) - 1.0f) > util::EPSILON) return false;
        if (std::abs(vectors::dot(c1, c1) - 1.0f) > util::EPSILON) return false;
        if (std::abs(vectors::dot(c2, c2) - 1.0f) > util::EPSILON) return false;
        if (std::abs(vectors::dot(c3, c3) - 1.0f) > util::EPSILON) return false;

        // Check Perpendicularity (Must be ~0)
        if (std::abs(vectors::dot(c0, c1)) > util::EPSILON) return false;
        if (std::abs(vectors::dot(c0, c2)) > util::EPSILON) return false;
        if (std::abs(vectors::dot(c0, c3)) > util::EPSILON) return false;
        if (std::abs(vectors::dot(c1, c2)) > util::EPSILON) return false;
        if (std::abs(vectors::dot(c1, c3)) > util::EPSILON) return false;
        if (std::abs(vectors::dot(c2, c3)) > util::EPSILON) return false;

        return true;
    }
}
