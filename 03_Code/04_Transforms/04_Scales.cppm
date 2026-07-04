// Related Concept: [[01_Concepts/04_Transforms/04_Scales|04_Scales]]
export module transforms_scales;

import std;

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
        matrices::Matrix4x4 scaleArbitrary {};
        vectors::vector3 n = vectors::normalized(a);

        scaleArbitrary[0, 0] = ( s - 1 ) * ( n.x * n.x ) + 1;
        scaleArbitrary[0, 1] = ( s - 1 ) * ( n.x * n.y );
        scaleArbitrary[0, 2] = ( s - 1 ) * ( n.x * n.z );
        scaleArbitrary[0, 3] = 0.0;

        scaleArbitrary[1, 0] = ( s - 1 ) * ( n.x * n.y );
        scaleArbitrary[1, 1] = ( s - 1 ) * ( n.y * n.y ) + 1;
        scaleArbitrary[1, 2] = ( s - 1 ) * ( n.y * n.z );
        scaleArbitrary[1, 3] = 0.0;

        scaleArbitrary[2, 0] = ( s - 1 ) * ( n.x * n.z );
        scaleArbitrary[2, 1] = ( s - 1 ) * ( n.y * n.z );
        scaleArbitrary[2, 2] = ( s - 1 ) * ( n.z * n.z ) + 1;
        scaleArbitrary[2, 3] = 0.0;

        scaleArbitrary[3, 0] = 0.0;
        scaleArbitrary[3, 1] = 0.0;
        scaleArbitrary[3, 2] = 0.0;
        scaleArbitrary[3, 3] = 1.0;

        return scaleArbitrary * v;
    }


}
