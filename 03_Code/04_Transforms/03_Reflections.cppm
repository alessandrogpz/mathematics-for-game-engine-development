// Related Concept: [[01_Concepts/04_Transforms/03_Reflections|03_Reflections]]
module;
#include <iostream>

export module transforms_reflections;

import vectors_basics;
import matrices_basics;

export namespace transforms {
    [[nodiscard]]
    vectors::vector3 reflection(const vectors::vector3 a, const vectors::vector3 v)
    {
        const vectors::vector3 n = a.normalized();
        matrices::Matrix3x3 reflect = {};

        reflect[0, 0] = 1 - 2 * (n.x * n.x);
        reflect[0, 1] = -2 * (n.x * n.y);
        reflect[0, 2] = -2 * (n.x * n.z);

        reflect[1, 0] = -2 * (n.x * n.y);
        reflect[1, 1] = 1 - 2 * (n.y * n.y);
        reflect[1, 2] = -2 * (n.y * n.z);

        reflect[2, 0] = -2 * (n.x * n.z);
        reflect[2, 1] = -2 * (n.z * n.y);
        reflect[2, 2] = 1 - 2 * (n.z * n.z);

        return reflect * v;
    }


    [[nodiscard]]
    vectors::vector3 involution(const vectors::vector3 a, const vectors::vector3 v)
    {
        const vectors::vector3 n = a.normalized();
        matrices::Matrix3x3 reflect = {};

        reflect[0, 0] = 2 * (n.x * n.x) - 1;
        reflect[0, 1] = 2 * (n.x * n.y);
        reflect[0, 2] = 2 * (n.x * n.z);

        reflect[1, 0] = 2 * (n.x * n.y);
        reflect[1, 1] = 2 * (n.y * n.y) - 1;
        reflect[1, 2] = 2 * (n.y * n.z);

        reflect[2, 0] = 2 * (n.x * n.z);
        reflect[2, 1] = 2 * (n.z * n.y);
        reflect[2, 2] = 2 * (n.z * n.z) - 1;

        return reflect * v;
    }
}
