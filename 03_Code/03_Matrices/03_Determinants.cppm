// Related Concept: [[01_Concepts/03_Matrices/03_Determinants|03_Determinants]]
module;
#include <iostream>

export module matrices_determinants;

import matrices_basics;

export namespace matrices {

    [[nodiscard]]
    double subDeterminant3x3(const Matrix4x4& m,
                             const size_t r0, const size_t r1, const size_t r2,
                             const size_t c0, const size_t c1, const size_t c2)
    {
        double pos = m[r0, c0] * m[r1, c1] * m[r2, c2] +
                     m[r0, c1] * m[r1, c2] * m[r2, c0] +
                     m[r0, c2] * m[r1, c0] * m[r2, c1];
        double neg = m[r0, c2] * m[r1, c1] * m[r2, c0] +
                     m[r0, c1] * m[r1, c0] * m[r2, c2] +
                     m[r0, c0] * m[r1, c2] * m[r2, c1];
        return pos - neg;
    }

    // Matrix Determinant - Cofactor Expansion
    [[nodiscard]]
    double determinant(const Matrix4x4& m)
    {
        double c00 = subDeterminant3x3(m, 1, 2, 3, 1, 2, 3);
        double c01 = subDeterminant3x3(m, 1, 2, 3, 0, 2, 3);
        double c02 = subDeterminant3x3(m, 1, 2, 3, 0, 1, 3);
        double c03 = subDeterminant3x3(m, 1, 2, 3, 0, 1, 2);

        return m[0, 0] * c00 - m[0, 1] * c01 + m[0, 2] * c02 - m[0, 3] * c03;
    }


}
