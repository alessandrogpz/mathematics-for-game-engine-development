// Related Concept: [[01_Concepts/03_Matrices/04_Matrix_Inversion|04_Matrix_Inversion]]
export module matrices_inversion;

import std;

import matrices_basics;
import matrices_determinants;

export namespace matrices {

    [[nodiscard]]
    [[nodiscard]]
    Matrix4x4 inverse(const Matrix4x4& m)
    {
        const double det = determinant(m);

        if (det == 0.0)
            return Matrix4x4{};

        const double inv_det = 1.0 / det;
        Matrix4x4 inverse{};

        // Lambda to get indices of rows/cols excluding a specific row/col
        auto get_indices_except = [](std::size_t idx, std::size_t& i0, std::size_t& i1, std::size_t& i2) {
            if (idx == 0) { i0 = 1; i1 = 2; i2 = 3; }
            else if (idx == 1) { i0 = 0; i1 = 2; i2 = 3; }
            else if (idx == 2) { i0 = 0; i1 = 1; i2 = 3; }
            else { i0 = 0; i1 = 1; i2 = 2; }
        };

        for (std::size_t r = 0; r < 4; ++r)
        {
            for (std::size_t c = 0; c < 4; ++c)
            {
                std::size_t r0, r1, r2;
                std::size_t c0, c1, c2;
                get_indices_except(r, r0, r1, r2);
                get_indices_except(c, c0, c1, c2);

                double sub_det = subDeterminant3x3(m, r0, r1, r2, c0, c1, c2);
                double sign = ((r + c) % 2 == 0) ? 1.0 : -1.0;

                // Transpose: inverse[c, r] is cofactor[r, c] * inv_det
                inverse[c, r] = sign * sub_det * inv_det;
            }
        }

        return inverse;
    }

}
