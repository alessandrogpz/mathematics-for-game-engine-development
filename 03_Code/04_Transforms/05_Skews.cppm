// Related Concept: [[01_Concepts/04_Transforms/05_Skews|05_Skews]]
module;
#include <cmath>
#include <numbers>

export module transforms_skews;

import matrices_basics;
import vectors_basics;

export namespace transforms
{

    [[nodiscard]]
    vectors::vector3 skew ( const vectors::vector3 a,
                            const vectors::vector3 b,
                            const vectors::vector3 v,
                            const double degrees )
    {
        const vectors::vector3 n = vectors::normalized(a);
        const vectors::vector3 m = vectors::normalized(b);
        const double radians = degrees * std::numbers::pi / 180.0;
        const double tan_t = std::tan(radians);
        matrices::Matrix4x4 M_SKEW{};

        M_SKEW[0, 0] = 1.0 + n.x * m.x * tan_t;
        M_SKEW[0, 1] = n.x * m.y * tan_t;
        M_SKEW[0, 2] = n.x * m.z * tan_t;
        M_SKEW[0, 3] = 0.0;

        M_SKEW[1, 0] = n.y * m.x * tan_t;
        M_SKEW[1, 1] = 1.0 + n.y * m.y * tan_t;
        M_SKEW[1, 2] = n.y * m.z * tan_t;
        M_SKEW[1, 3] = 0.0;

        M_SKEW[2, 0] = n.z * m.x * tan_t;
        M_SKEW[2, 1] = n.z * m.y * tan_t;
        M_SKEW[2, 2] = 1.0 + n.z * m.z * tan_t;
        M_SKEW[2, 3] = 0.0;

        M_SKEW[3, 0] = 0.0;
        M_SKEW[3, 1] = 0.0;
        M_SKEW[3, 2] = 0.0;
        M_SKEW[3, 3] = 1.0;

        return M_SKEW * v;
    }

}