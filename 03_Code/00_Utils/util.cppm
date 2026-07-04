export module linear_algebra_util;

import std;

export namespace util {

    constexpr float EPSILON = 1e-5f;

    // Epsilon-based absolute float equality comparison
    [[nodiscard]]
    inline bool floatEqual(const float a, const float b, const float epsilon = EPSILON)
    {
        return std::abs(a - b) <= epsilon;
    }
}
