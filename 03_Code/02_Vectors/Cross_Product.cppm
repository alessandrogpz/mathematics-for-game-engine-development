// Related Concept: [[01_Concepts/02_Vectors/04_Cross_Product|04_Cross_Product]]
module;

export module vectors_cross_product;

import vectors_basics;

export namespace vectors {

    [[nodiscard]]
    vector3 crossProd (const vector3 a, const vector3 b) {

        return { (a.y * b.z) - (a.z * b.y),
                    (a.z * b.x) - (a.x * b.z),
                    (a.x * b.y) - (a.y * b.x) };
    }
}
