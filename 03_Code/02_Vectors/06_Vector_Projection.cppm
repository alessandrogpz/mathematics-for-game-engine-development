// Related Concept: [[01_Concepts/02_Vectors/06_Vector_Projection|06_Vector_Projection]]
module;

export module vectors_projection;

import vectors_basics;
import vectors_dot_product;


export namespace vectors {

    [[nodiscard]]
    double scalarProj ( const vector3 a, const vector3 b ) {

        const double magB = magnitude(b);
        if (magB == 0.0)
            return 0.0;

        return dot(a, b) / magB;
    }

    [[nodiscard]]
    vector3 vecProj ( const vector3 a, const vector3 b ) {
        const double magB = magnitude(b);
        if (magB == 0.0)
            return {0.0, 0.0, 0.0};

        const double sProj = scalarProj(a, b);
        return b * (sProj / magB);
    }

    [[nodiscard]]
    vector3 vecRej ( const vector3 a, const vector3 b) {
        return a - vecProj(a, b);
    }


}
