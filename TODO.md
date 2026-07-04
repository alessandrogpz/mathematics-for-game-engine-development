# Project TODO List

Use this list to track the remaining exercises and code implementations that need to be completed in this project.

## 1. Exercise Solution Notes (Placeholders)

These solution files still contain `[Insert ...]` placeholders that need LaTeX mathematics or conceptual descriptions.

### Systems of Equations
- [x] Complete **Linear Systems** derivation: [S_01_Linear_Systems.md](02_Exercises/01_Systems_of_Equations/Solutions/S_01_Linear_Systems.md)

### Vectors
- [x] Complete **Cross Product** derivation: [S_04_Cross_Product.md](02_Exercises/02_Vectors/Solutions/S_04_Cross_Product.md)
- [x] Complete **Scalar Triple Product** derivation: [S_05_Scalar_Triple_Product.md](02_Exercises/02_Vectors/Solutions/S_05_Scalar_Triple_Product.md)

- [x] Complete **Projection Orthogonality** proof: [S_06_Projection_Orthogonality.md](02_Exercises/02_Vectors/Solutions/S_06_Projection_Orthogonality.md)
- [x] Complete **Projection Properties** proof: [S_06_Projection_Properties.md](02_Exercises/02_Vectors/Solutions/S_06_Projection_Properties.md)

### Matrices
- [x] Complete **Projection Matrix** calculation & theory: [S_06_Projection_Matrix.md](02_Exercises/03_Matrices/Solutions/S_06_Projection_Matrix.md)
- [x] Complete **Matrix Multiplication** calculations: [S_02_Matrix_Multiplication.md](02_Exercises/03_Matrices/Solutions/S_02_Matrix_Multiplication.md)
- [x] Complete **Determinants** calculations: [S_03_Determinants.md](02_Exercises/03_Matrices/Solutions/S_03_Determinants.md)

### Transforms
- [x] Complete **Homogeneous Coordinates** calculations: [S_07_Homogeneous_Coordinates.md](02_Exercises/04_Transforms/Solutions/S_07_Homogeneous_Coordinates.md)
- [x] Complete **Matrix Composition 4x4** derivation & coding concepts: [S_08_Matrix_Composition_4x4.md](02_Exercises/04_Transforms/Solutions/S_08_Matrix_Composition_4x4.md)
- [x] Complete **Quaternions (Part 2)** conceptual understanding (Hamilton's identities proofs, origin of the half-angle): [S_10_Quaternions.md](02_Exercises/04_Transforms/Solutions/S_10_Quaternions.md)

---

## 2. Skeletal C++ Code Modules

These files contain only console-log helper tests and need their core mathematical functions and algorithms implemented.

### Systems of Equations
- [ ] Implement **Gaussian Elimination / Solver** logic: [Linear_Systems.cppm](03_Code/01_Systems_of_Equations/Linear_Systems.cppm)

### Vectors
- [x] Implement **Coordinate Conversion** routines: [Coordinate_Systems.cppm](03_Code/02_Vectors/Coordinate_Systems.cppm)

### Matrices
- [x] Implement **Orthogonality Check** logic: [Orthogonal_Matrices.cppm](03_Code/03_Matrices/Orthogonal_Matrices.cppm)

### Transforms
- [x] Implement **4x4 Transformation Matrices** representation and composition (integrated natively in Matrix4x4)
- [x] Implement **3D Translation Matrix** creation and vector translation: [Translations.cppm](03_Code/04_Transforms/Translations.cppm)
