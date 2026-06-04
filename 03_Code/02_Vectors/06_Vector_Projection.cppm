// Related Concept: [[01_Concepts/02_Vectors/06_Vector_Projection|06_Vector_Projection]]
module;

export module vectors_projection;

import vectors_basics;
import vectors_dot_product;
import matrices_basics;

export namespace vectors {

    [[nodiscard]]
    double scalarProj ( const vector3 a, const vector3 b ) {

        const double magB = b.magnitude();
        if (magB == 0.0)
            return 0.0;

        return dot(a, b) / magB;
    }

    [[nodiscard]]
    vector3 vecProj ( const vector3 a, const vector3 b ) {
        const double magB = b.magnitude();
        if (magB == 0.0)
            return {0.0, 0.0, 0.0};

        const double sProj = scalarProj(a, b);
        return b * (sProj / magB);
    }

    [[nodiscard]]
    vector3 vecRej ( const vector3 a, const vector3 b) {
        return a - vecProj(a, b);
    }

    [[nodiscard]]
    matrices::Matrix3x3 projMatrix(const vector3 b)
    {
        const vector3 u = b.normalized();
        matrices::Matrix3x3 P{};

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

}
