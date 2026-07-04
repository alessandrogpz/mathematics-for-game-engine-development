# GoogleTest integration
include(GoogleTest)

# Define test executable containing all unit test files
add_executable(LinearAlgebraTests
    Systems_of_Equations/Linear_Systems_tests.cpp
    Vectors/Basics_tests.cpp
    Vectors/Coordinate_Systems_tests.cpp
    Vectors/Dot_Product_tests.cpp
    Vectors/Cross_Product_tests.cpp
    Vectors/Vector_Projection_tests.cpp
    Matrices/Basics_tests.cpp
    Matrices/Multiplication_tests.cpp
    Matrices/Determinants_tests.cpp
    Matrices/Inversion_tests.cpp
    Transforms/Rotations_tests.cpp
    Transforms/Scales_tests.cpp
    Transforms/Reflections_tests.cpp
    Transforms/Skews_tests.cpp
    Transforms/Translations_tests.cpp
    Transforms/Quaternions_tests.cpp
)

# Set standards and modules
target_compile_features(LinearAlgebraTests PRIVATE cxx_std_23)
set_target_properties(LinearAlgebraTests PROPERTIES CXX_MODULE_STD ON)

# Compiler options
if(MSVC)
    target_compile_options(LinearAlgebraTests PRIVATE /W4)
else()
    target_compile_options(LinearAlgebraTests PRIVATE -Wall -Wextra -Wpedantic -mavx)
endif()

# Link with our C++ module library and GoogleTest
target_link_libraries(LinearAlgebraTests
    PRIVATE
        LinearAlgebraLib
        GTest::gtest_main
)

# Discover tests automatically
gtest_discover_tests(LinearAlgebraTests)
