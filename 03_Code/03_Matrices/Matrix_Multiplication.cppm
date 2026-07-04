// Related Concept: [[01_Concepts/03_Matrices/02_Matrix_Multiplication|02_Matrix_Multiplication]]
export module matrices_multiplication;

import std;

import vectors_basics;
import matrices_basics;
import vectors_dot_product;

export namespace matrices {

    [[nodiscard]]
    Matrix4x4 matrixMultiplication4x4(const Matrix4x4& a, const Matrix4x4& b)
    {
        Matrix4x4 result{};

        for (std::size_t r = 0; r < 4; ++r)
        {
            for (std::size_t c = 0; c < 4; ++c)
            {
                result[r, c] = a[r, 0] * b[0, c] +
                               a[r, 1] * b[1, c] +
                               a[r, 2] * b[2, c] +
                               a[r, 3] * b[3, c];
            }
        }
        return result;
    }
}
