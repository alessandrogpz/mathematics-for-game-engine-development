// Related Concept: [[01_Concepts/04_Transforms/04_Scales|04_Scales]]
module;
#include <iostream>

export module transforms_scales;

import matrices_basics;
import vectors_basics;

export namespace transforms {

    [[nodiscard]]
    vectors::vector3 scaleUniform (const vectors::vector3 v, const double s)
    {
        return { v.x * s, v.y * s, v.z * s };
    }

    [[nodiscard]]
    vectors::vector3 scaleNonuniform (  const vectors::vector3 v,
                                        const double sx,
                                        const double sy,
                                        const double sz )
    {
        return { v.x * sx, v.y * sy, v.z * sz };
    }

    [[nodiscard]]
    vectors::vector3 scaleArbitraryAxis ( const vectors::vector3 v, const vectors::vector3 a, const double s)
    {
        matrices::Matrix3x3 scaleArbitrary {};
        vectors::vector3 n = a.normalized();

        scaleArbitrary[0, 0] = ( s - 1 ) * ( n.x * n.x ) + 1;
        scaleArbitrary[0, 1] = ( s - 1 ) * ( n.x * n.y );
        scaleArbitrary[0, 2] = ( s - 1 ) * ( n.x * n.z );

        scaleArbitrary[1, 0] = ( s - 1 ) * ( n.x * n.y );
        scaleArbitrary[1, 1] = ( s - 1 ) * ( n.y * n.y ) + 1;
        scaleArbitrary[1, 2] = ( s - 1 ) * ( n.y * n.z );

        scaleArbitrary[2, 0] = ( s - 1 ) * ( n.x * n.z );
        scaleArbitrary[2, 1] = ( s - 1 ) * ( n.y * n.z );
        scaleArbitrary[2, 2] = ( s - 1 ) * ( n.z * n.z ) + 1;

        return scaleArbitrary * v;
    }


}
