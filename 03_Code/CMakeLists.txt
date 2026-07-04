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

# Enable common compiler warnings for clean code
if(MSVC)
    add_compile_options(/W4)
else()
    add_compile_options(-Wall -Wextra -Wpedantic -mavx)
endif()

# Define the single main executable target
add_executable(LinearAlgebra main.cpp)

# Define target C++ module interface files (.cppm)
target_sources(LinearAlgebra
  PUBLIC
    FILE_SET CXX_MODULES FILES
        "linear_algebra.cppm"
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
        "04_Transforms/Quaternions.cppm"
        "04_Transforms/Translations.cppm"
)
