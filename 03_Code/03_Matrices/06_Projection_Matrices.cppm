// Related Concept: [[01_Concepts/03_Matrices/06_Projection_Matrices|06_Projection_Matrices]]
module;

export module matrices_projection;

import vectors_basics;
import matrices_basics;

export namespace matrices {

    [[nodiscard]]
    Matrix3x3 projMatrix(const vectors::vector3 b)
    {
        const vectors::vector3 u = normalized(b);
        Matrix3x3 P{};

        P[0, 0] = u.x * u.x;
        P[0, 1] = u.x * u.y;
        P[0, 2] = u.x * u.z;

        P[1, 0] = u.y * u.x;
        P[1, 1] = u.y * u.y;
        P[1, 2] = u.y * u.z;

        P[2, 0] = u.z * u.x;
        P[2, 1] = u.z * u.y;
        P[2, 2] = u.z * u.z;

        return P;
    }

    [[nodiscard]]
    vectors::vector3 vecProj(const Matrix3x3& P, const vectors::vector3 a)
    {
        return P * a;
    }

    [[nodiscard]]
    Matrix3x3 orthogonalRejMatrix(const vectors::vector3 b)
    {
        return Matrix3x3::identity() - projMatrix(b);
    }

    [[nodiscard]]
    vectors::vector3 vecRej(const Matrix3x3& P_prep, const vectors::vector3 a)
    {
        return P_prep * a;
    }

}
