// Related Concept: [[01_Concepts/03_Matrices/03_Determinants|03_Determinants]]
module;
#include <iostream>

export module matrices_determinants;

import matrices_basics;

export namespace matrices {

    // Matrix Determinant - Sarrus Rule
    [[nodiscard]]
    double determinant(const Matrix3x3& m)
    {
        // Positive diagonals (down-right)
        double r_diag = 0.0;
        r_diag += m[0, 0] * m[1, 1] * m[2, 2];
        r_diag += m[0, 1] * m[1, 2] * m[2, 0];
        r_diag += m[0, 2] * m[1, 0] * m[2, 1];

        // Negative diagonals (down-left)
        double l_diag = 0.0;
        l_diag += m[0, 2] * m[1, 1] * m[2, 0];
        l_diag += m[0, 1] * m[1, 0] * m[2, 2];
        l_diag += m[0, 0] * m[1, 2] * m[2, 1];

        return r_diag - l_diag;
    }


}
