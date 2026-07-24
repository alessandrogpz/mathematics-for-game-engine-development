# Project TODO List

Use this list to track the remaining exercises and code implementations that need to be completed in this project.

## 1. Exercise Solution Notes (Placeholders)

These solution files still contain `[Insert ...]` placeholders that need LaTeX mathematics or conceptual descriptions.

### Geometry
- [x] Complete **Triangle Meshes** derivation (Euler's formula calculations & conceptual answers): [S_01_Triangle_Meshes.md](02_Exercises/05_Geometry/Solutions/S_01_Triangle_Meshes.md)
- [x] Complete **Normal Vectors** derivation (cross product calculation & normal-transformation proofs): [S_02_Normal_Vectors.md](02_Exercises/05_Geometry/Solutions/S_02_Normal_Vectors.md)
- [ ] Complete **Lines and Rays** derivation (point-to-line & skew line distance derivations): [S_03_Lines_and_Rays.md](02_Exercises/05_Geometry/Solutions/S_03_Lines_and_Rays.md)
- [ ] Complete **Planes** derivation (parametric plane & 4D implicit plane calculations): [S_04_Planes.md](02_Exercises/05_Geometry/Solutions/S_04_Planes.md)

---

## 2. Skeletal C++ Code Modules

These files contain only console-log helper tests and need their core mathematical functions and algorithms implemented.

### Systems of Equations
- [ ] Implement **Gaussian Elimination / Solver** logic: [Linear_Systems.cppm](03_Code/01_Systems_of_Equations/Linear_Systems.cppm)

### Geometry
- [ ] Implement **Triangle Mesh** representation (indexed vertex/index buffers, closed-mesh validation): [Triangle_Meshes.cppm](03_Code/05_Geometry/Triangle_Meshes.cppm)
- [ ] Implement **Normal Vector** calculation and transformation (face normal via cross product, inverse-transpose transform): [Normal_Vectors.cppm](03_Code/05_Geometry/Normal_Vectors.cppm)
- [ ] Implement **Lines and Rays** calculations (point-to-line & skew/parallel line distances): [Lines_and_Rays.cppm](03_Code/05_Geometry/Lines_and_Rays.cppm)
- [ ] Implement **Planes** representations (parametric plane, implicit plane dot product, 4D plane vector): [Planes.cppm](03_Code/05_Geometry/Planes.cppm)
