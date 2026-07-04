// Related Concept: [[01_Concepts/03_Matrices/01_Basics|01_Basics]]
module;
#include <iostream>
#include <format>

export module matrices_basics;

export namespace matrices {
    struct Matrix4x4
    {
        double data[16];

        Matrix4x4() : data{} {}

        [[nodiscard]]
        double& operator[](const size_t row, const size_t col) {
            return data[ row * 4 + col ];
        }

        [[nodiscard]]
        const double& operator[](const size_t row, const size_t col) const {
            return data[ row * 4 + col ];
        }

        // 1. Matrix Addition
        [[nodiscard]]
        Matrix4x4 operator+(const Matrix4x4& other) const {
            Matrix4x4 result{};
            for (size_t i = 0; i < 16; ++i) {
                result.data[i] = data[i] + other.data[i];
            }
            return result;
        }

        // 2. Matrix Subtraction
        [[nodiscard]]
        Matrix4x4 operator-(const Matrix4x4& other) const {
            Matrix4x4 result{};
            for (size_t i = 0; i < 16; ++i) {
                result.data[i] = data[i] - other.data[i];
            }
            return result;
        }

        // 3. Scalar Multiplication
        [[nodiscard]]
        Matrix4x4 operator*(const double scalar) const {
            Matrix4x4 result{};
            for (size_t i = 0; i < 16; ++i) {
                result.data[i] = data[i] * scalar;
            }
            return result;
        }

        // 5. Trace of a Matrix (Sum of main diagonal elements)
        [[nodiscard]]
        double trace() const {
            return data[0] + data[5] + data[10] + data[15];
        }

        // 6. Identity Matrix
        static Matrix4x4 identity()
        {
            Matrix4x4 i{};
            i[0, 0] = 1.0;
            i[1, 1] = 1.0;
            i[2, 2] = 1.0;
            i[3, 3] = 1.0;
            return i;
        }
    };

    // 4. Matrix Transposition
    [[nodiscard]]
    Matrix4x4 transpose(const Matrix4x4& m)
    {
        Matrix4x4 t{};
        for ( int row = 0; row < 4; row++ )
        {
            for ( int column = 0; column < 4; column++ )
            {
                t[column, row] = m[row, column];
            }
        }
        return t;
    }

    // 7. 4x4 ASCII Matrix Printer
    void print(const Matrix4x4& m)
    {
        for (size_t row = 0; row < 4; ++row)
        {
            std::cout << "[ ";
            for (size_t col = 0; col < 4; ++col)
            {
                std::cout << std::format("{:>8.4f} ", m[row, col]);
            }
            std::cout << "]" << std::endl;
        }
    }

    [[nodiscard]]
    double trace(const Matrix4x4& m) {
        return m.trace();
    }
}
