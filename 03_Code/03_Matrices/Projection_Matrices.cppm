// Related Concept: [[01_Concepts/03_Matrices/06_Projection_Matrices|06_Projection_Matrices]]
module;

export module matrices_projection;

import vectors_basics;
import matrices_basics;

export namespace matrices {

    [[nodiscard]]
    Matrix4x4 projMatrix(const vectors::vector3 b)
    {
        const vectors::vector3 u = normalized(b);
        Matrix4x4 P{};

        P[0, 0] = u.x * u.x;
        P[0, 1] = u.x * u.y;
        P[0, 2] = u.x * u.z;
        P[0, 3] = 0.0;

        P[1, 0] = u.y * u.x;
        P[1, 1] = u.y * u.y;
        P[1, 2] = u.y * u.z;
        P[1, 3] = 0.0;

        P[2, 0] = u.z * u.x;
        P[2, 1] = u.z * u.y;
        P[2, 2] = u.z * u.z;
        P[2, 3] = 0.0;

        P[3, 0] = 0.0;
        P[3, 1] = 0.0;
        P[3, 2] = 0.0;
        P[3, 3] = 1.0;

        return P;
    }

    [[nodiscard]]
    vectors::vector3 vecProj(const Matrix4x4& P, const vectors::vector3 a)
    {
        return P * a;
    }

    [[nodiscard]]
    Matrix4x4 orthogonalRejMatrix(const vectors::vector3 b)
    {
        return Matrix4x4::identity() - projMatrix(b);
    }

    [[nodiscard]]
    vectors::vector3 vecRej(const Matrix4x4& P_prep, const vectors::vector3 a)
    {
        return P_prep * a;
    }

}
