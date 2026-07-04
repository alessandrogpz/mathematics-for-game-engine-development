// Related Concept: [[01_Concepts/02_Vectors/02_Dot_Product|02_Dot_Product]]
export module vectors_dot_product;

import std;

import vectors_basics;

export namespace vectors {

    [[nodiscard]]
    float dot(const vector3 a, const vector3 b) {
        return (a.x * b.x) + (a.y * b.y) + (a.z * b.z);
    }

    [[nodiscard]]
    float dot(const vector4 a, const vector4 b) {
        return (a.x * b.x) + (a.y * b.y) + (a.z * b.z) + (a.w * b.w);
    }

    [[nodiscard]]
    float dotGeo(const vector3 a, const vector3 b, const float theta) {
        return magnitude(a) * magnitude(b) * std::cos(theta);
    }

    [[nodiscard]]
    float angle(const vector3 a, const vector3 b)
    {
        const float magA = magnitude(a);
        const float magB = magnitude(b);
        if (magA == 0.0 || magB == 0.0) return 0.0;

        const float cosTheta = dot(a, b) / (magA * magB);

        // Prevent floating-point precision issues from pushing cosTheta outside [-1.0, 1.0]
        const float clampedCosTheta = std::clamp(cosTheta, -1.0f, 1.0f);
        return std::acos(clampedCosTheta);
    }
}
