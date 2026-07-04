// Related Concept: [[01_Concepts/04_Transforms/06_Translations|06_Translations]]
module;
#include <iostream>

export module transforms_translations;

import matrices_basics;
import vectors_basics;

export namespace transforms {
    [[nodiscard]]
    matrices::Matrix4x4 translationMatrix(const vectors::vector3 t)
    {
        matrices::Matrix4x4 T = matrices::Matrix4x4::identity();
        T[0, 3] = t.x;
        T[1, 3] = t.y;
        T[2, 3] = t.z;
        return T;
    }

    [[nodiscard]]
    vectors::vector3 translate(const vectors::vector3 t, const vectors::vector3 v)
    {
        return translationMatrix(t) * v;
    }

    void test_translations() {
        std::cout << "Transforms - Translations Module Initialized" << std::endl;
    }
}
