cmake_minimum_required(VERSION 3.28)
set(CMAKE_EXPERIMENTAL_CXX_IMPORT_STD "451f2fe2-a8a2-47c3-bc32-94786d8fc91b")

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
        "01_Systems_of_Equations/01_Linear_Systems.cppm"
        "02_Vectors/01_Basics.cppm"
        "02_Vectors/02_Dot_Product.cppm"
        "02_Vectors/03_Coordinate_Systems.cppm"
        "02_Vectors/04_Cross_Product.cppm"
        "02_Vectors/05_Scalar_Triple_Product.cppm"
        "02_Vectors/06_Vector_Projection.cppm"
        "03_Matrices/01_Basics.cppm"
        "03_Matrices/02_Matrix_Multiplication.cppm"
        "03_Matrices/03_Determinants.cppm"
        "03_Matrices/04_Matrix_Inversion.cppm"
        "03_Matrices/05_Orthogonal_Matrices.cppm"
        "03_Matrices/06_Projection_Matrices.cppm"
        "04_Transforms/01_Transformation_Matrices.cppm"
        "04_Transforms/02_Rotations.cppm"
        "04_Transforms/03_Reflections.cppm"
        "04_Transforms/04_Scales.cppm"
        "04_Transforms/05_Skews.cppm"
        "04_Transforms/10_Quaternions.cppm"
        "04_Transforms/06_Translations.cppm"
)
