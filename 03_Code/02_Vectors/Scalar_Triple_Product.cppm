// Related Concept: [[01_Concepts/02_Vectors/05_Scalar_Triple_Product|05_Scalar_Triple_Product]]
module;

export module vectors_scalar_triple_product;

import vectors_basics;
import vectors_dot_product;
import vectors_cross_product;

export namespace vectors {

    [[nodiscard]]
    float tripleScalarProd ( const vector3 a, const vector3 b, const vector3 c) {

        return dot(c,crossProd(a, b));
    }
}
