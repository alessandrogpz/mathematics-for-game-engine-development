cmake_minimum_required(VERSION 3.28)
set(CMAKE_SUPPRESS_DEVELOPER_WARNINGS ON CACHE INTERNAL "Suppress dev warnings" FORCE)

if(CMAKE_VERSION VERSION_GREATER_EQUAL "4.3.0")
    set(CMAKE_EXPERIMENTAL_CXX_IMPORT_STD "451f2fe2-a8a2-47c3-bc32-94786d8fc91b")
else()
    set(CMAKE_EXPERIMENTAL_CXX_IMPORT_STD "d0edc3af-4c50-42ea-a356-e2862fe7a444")
endif()

project(LinearAlgebra C CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_MODULE_STD ON)

# Define static library for linear algebra modules
add_library(LinearAlgebraLib STATIC)

# Define target C++ module interface files (.cppm) on the library target
target_sources(LinearAlgebraLib
  PUBLIC
    FILE_SET CXX_MODULES FILES
        "linear_algebra.cppm"
        "00_Utils/util.cppm"
        "01_Systems_of_Equations/Linear_Systems.cppm"
        "02_Vectors/Basics.cppm"
        "02_Vectors/Dot_Product.cppm"
        "02_Vectors/Coordinate_Systems.cppm"
        "02_Vectors/Cross_Product.cppm"
        "02_Vectors/Scalar_Triple_Product.cppm"
        "02_Vectors/Vector_Projection.cppm"
        "03_Matrices/Basics.cppm"
        "03_Matrices/Matrix_Multiplication.cppm"
        "03_Matrices/Determinants.cppm"
        "03_Matrices/Matrix_Inversion.cppm"
        "03_Matrices/Orthogonal_Matrices.cppm"
        "03_Matrices/Projection_Matrices.cppm"
        "04_Transforms/Rotations.cppm"
        "04_Transforms/Reflections.cppm"
        "04_Transforms/Scales.cppm"
        "04_Transforms/Skews.cppm"
        "04_Transforms/Translations.cppm"
        "04_Transforms/Quaternions.cppm"
        "05_Geometry/Triangle_Meshes.cppm"
        "05_Geometry/Normal_Vectors.cppm"
)

# Set compile flags on the library target
if(MSVC)
    target_compile_options(LinearAlgebraLib PRIVATE /W4)
else()
    target_compile_options(LinearAlgebraLib PRIVATE -Wall -Wextra -Wpedantic -mavx)
endif()

# Define main application executable linking to our library
add_executable(LinearAlgebra main.cpp)
target_link_libraries(LinearAlgebra PRIVATE LinearAlgebraLib)

# Fetch GoogleTest
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        v1.15.2
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Enable testing and add tests subdirectory
enable_testing()
add_subdirectory(tests)
