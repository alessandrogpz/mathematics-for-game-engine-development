// Related Concept: [[01_Concepts/03_Matrices/03_Determinants|03_Determinants]]
export module matrices_determinants;

import std;

import matrices_basics;

export namespace matrices {

    [[nodiscard]]
    float subDeterminant3x3(const Matrix4x4& m,
                             const std::size_t r0, const std::size_t r1, const std::size_t r2,
                             const std::size_t c0, const std::size_t c1, const std::size_t c2)
    {
        float pos = m[r0, c0] * m[r1, c1] * m[r2, c2] +
                     m[r0, c1] * m[r1, c2] * m[r2, c0] +
                     m[r0, c2] * m[r1, c0] * m[r2, c1];
        float neg = m[r0, c2] * m[r1, c1] * m[r2, c0] +
                     m[r0, c1] * m[r1, c0] * m[r2, c2] +
                     m[r0, c0] * m[r1, c2] * m[r2, c1];
        return pos - neg;
    }

    // Matrix Determinant - Cofactor Expansion
    [[nodiscard]]
    float determinant(const Matrix4x4& m)
    {
        float c00 = subDeterminant3x3(m, 1, 2, 3, 1, 2, 3);
        float c01 = subDeterminant3x3(m, 1, 2, 3, 0, 2, 3);
        float c02 = subDeterminant3x3(m, 1, 2, 3, 0, 1, 3);
        float c03 = subDeterminant3x3(m, 1, 2, 3, 0, 1, 2);

        return m[0, 0] * c00 - m[0, 1] * c01 + m[0, 2] * c02 - m[0, 3] * c03;
    }


}
