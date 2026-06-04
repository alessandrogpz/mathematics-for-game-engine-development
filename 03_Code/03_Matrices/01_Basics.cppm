// Related Concept: [[01_Concepts/03_Matrices/01_Basics|01_Basics]]
module;
#include <iostream>
#include <format>

export module matrices_basics;

export namespace matrices {
    struct Matrix3x3
    {
        double data[9];

        Matrix3x3() : data{} {}

        [[nodiscard]]
        double& operator[](const size_t row, const size_t col) {
            return data[ row * 3 + col ];
        }

        [[nodiscard]]
        const double& operator[](const size_t row, const size_t col) const {
            return data[ row * 3 + col ];
        }

        // 1. Matrix Addition
        [[nodiscard]]
        Matrix3x3 operator+(const Matrix3x3& other) const {
            Matrix3x3 result{};
            for (size_t i = 0; i < 9; ++i) {
                result.data[i] = data[i] + other.data[i];
            }
            return result;
        }

        // 2. Matrix Subtraction
        [[nodiscard]]
        Matrix3x3 operator-(const Matrix3x3& other) const {
            Matrix3x3 result{};
            for (size_t i = 0; i < 9; ++i) {
                result.data[i] = data[i] - other.data[i];
            }
            return result;
        }

        // 3. Scalar Multiplication
        [[nodiscard]]
        Matrix3x3 operator*(const double scalar) const {
            Matrix3x3 result{};
            for (size_t i = 0; i < 9; ++i) {
                result.data[i] = data[i] * scalar;
            }
            return result;
        }

        // 5. Trace of a Matrix (Sum of main diagonal elements)
        [[nodiscard]]
        double trace() const {
            return data[0] + data[4] + data[8];
        }

        // 6. Identity Matrix
        static Matrix3x3 identity()
        {
            Matrix3x3 i{};
            i[0, 0] = 1.0;
            i[1, 1] = 1.0;
            i[2, 2] = 1.0;
            return i;
        }
    };

    // 4. Matrix Transposition
    [[nodiscard]]
    Matrix3x3 transpose(const Matrix3x3& m)
    {
        Matrix3x3 t{};
        for ( int row = 0; row < 3; row++ )
        {
            for ( int column = 0; column < 3; column++ )
            {
                t[column, row] = m[row, column];
            }
        }
        return t;
    }

    // 7. 3x3 ASCII Matrix Printer
    void print(const Matrix3x3& m)
    {
        for (size_t row = 0; row < 3; ++row)
        {
            std::cout << "[ ";
            for (size_t col = 0; col < 3; ++col)
            {
                std::cout << std::format("{:>8.4f} ", m[row, col]);
            }
            std::cout << "]" << std::endl;
        }
    }
}
