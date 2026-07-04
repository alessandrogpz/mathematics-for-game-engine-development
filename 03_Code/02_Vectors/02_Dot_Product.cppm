// Related Concept: [[01_Concepts/02_Vectors/02_Dot_Product|02_Dot_Product]]
export module vectors_dot_product;

import std;

import vectors_basics;

export namespace vectors {

    [[nodiscard]]
    double dot(const vector3 a, const vector3 b) {
        return (a.x * b.x) + (a.y * b.y) + (a.z * b.z);
    }

    [[nodiscard]]
    double dotGeo(const vector3 a, const vector3 b, const double theta) {
        return magnitude(a) * magnitude(b) * std::cos(theta);
    }

    [[nodiscard]]
    double angle(const vector3 a, const vector3 b)
    {
        const double magA = magnitude(a);
        const double magB = magnitude(b);
        if (magA == 0.0 || magB == 0.0) return 0.0;

        const double cosTheta = dot(a, b) / (magA * magB);

        // Prevent floating-point precision issues from pushing cosTheta outside [-1.0, 1.0]
        const double clampedCosTheta = std::clamp(cosTheta, -1.0, 1.0);
        return std::acos(clampedCosTheta);
    }
}
