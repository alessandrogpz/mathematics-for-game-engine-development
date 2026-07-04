// Related Concept: [[01_Concepts/04_Transforms/02_Rotations|02_Rotations]]
export module transforms_rotations;

import std;

import matrices_basics;
import vectors_basics;
import vectors_projection;
import vectors_cross_product;

export namespace transforms {

    [[nodiscard]]
    vectors::vector3 rotationX(const vectors::vector3 vec, const float degrees)
    {
        const float radians = degrees * std::numbers::pi / 180.0;
        matrices::Matrix4x4 M_rotX {};

        // Row 0
        M_rotX[0, 0] = 1.0;
        M_rotX[0, 1] = 0.0;
        M_rotX[0, 2] = 0.0;
        M_rotX[0, 3] = 0.0;

        // Row 1
        M_rotX[1, 0] = 0.0;
        M_rotX[1, 1] = std::cos(radians);
        M_rotX[1, 2] = -std::sin(radians);
        M_rotX[1, 3] = 0.0;

        // Row 2
        M_rotX[2, 0] = 0.0;
        M_rotX[2, 1] = std::sin(radians);
        M_rotX[2, 2] = std::cos(radians);
        M_rotX[2, 3] = 0.0;

        // Row 3
        M_rotX[3, 0] = 0.0;
        M_rotX[3, 1] = 0.0;
        M_rotX[3, 2] = 0.0;
        M_rotX[3, 3] = 1.0;

        return M_rotX * vec;
    }

    [[nodiscard]]
    vectors::vector3 rotationY(const vectors::vector3 vec, const float degrees)
    {
        const float radians = degrees * std::numbers::pi / 180.0;
        matrices::Matrix4x4 M_rotY {};

        // Row 0
        M_rotY[0, 0] = std::cos(radians);
        M_rotY[0, 1] = 0.0;
        M_rotY[0, 2] = std::sin(radians);
        M_rotY[0, 3] = 0.0;

        // Row 1
        M_rotY[1, 0] = 0.0;
        M_rotY[1, 1] = 1.0;
        M_rotY[1, 2] = 0.0;
        M_rotY[1, 3] = 0.0;

        // Row 2
        M_rotY[2, 0] = -std::sin(radians);
        M_rotY[2, 1] = 0.0;
        M_rotY[2, 2] = std::cos(radians);
        M_rotY[2, 3] = 0.0;

        // Row 3
        M_rotY[3, 0] = 0.0;
        M_rotY[3, 1] = 0.0;
        M_rotY[3, 2] = 0.0;
        M_rotY[3, 3] = 1.0;

        return M_rotY * vec;
    }

    [[nodiscard]]
    vectors::vector3 rotationZ(const vectors::vector3 vec, const float degrees)
    {
        const float radians = degrees * std::numbers::pi / 180.0;
        matrices::Matrix4x4 M_rotZ {};

        // Row 0
        M_rotZ[0, 0] = std::cos(radians);
        M_rotZ[0, 1] = -std::sin(radians);
        M_rotZ[0, 2] = 0.0;
        M_rotZ[0, 3] = 0.0;

        // Row 1
        M_rotZ[1, 0] = std::sin(radians);
        M_rotZ[1, 1] = std::cos(radians);
        M_rotZ[1, 2] = 0.0;
        M_rotZ[1, 3] = 0.0;

        // Row 2
        M_rotZ[2, 0] = 0.0;
        M_rotZ[2, 1] = 0.0;
        M_rotZ[2, 2] = 1.0;
        M_rotZ[2, 3] = 0.0;

        // Row 3
        M_rotZ[3, 0] = 0.0;
        M_rotZ[3, 1] = 0.0;
        M_rotZ[3, 2] = 0.0;
        M_rotZ[3, 3] = 1.0;

        return M_rotZ * vec;
    }

    [[nodiscard]]
    vectors::vector3 rotationArbitraryAxis( const vectors::vector3 v,
                                            const vectors::vector3 a,
                                            const float degrees)
    {
        const float radians = degrees * std::numbers::pi / 180.0;

        const vectors::vector3 axis = vectors::normalized(a);

        const vectors::vector3 v_parallel = vectors::vecProj(v, axis);
        const vectors::vector3 v_perpendicular = vectors::vecRej(v, axis);
        const vectors::vector3 w = vectors::crossProd(axis, v);

        return v_parallel + v_perpendicular * std::cos(radians) + w * std::sin(radians);
    }
}
