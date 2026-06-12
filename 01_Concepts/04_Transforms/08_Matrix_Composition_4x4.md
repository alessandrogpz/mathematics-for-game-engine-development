# Matrix Composition in 4x4 (The Integration)

This note will bring everything together, showing how the $3 \times 3$ rotation, reflection, and scaling matrices combine with translation into a single unified $4 \times 4$ matrix.

---

## 1. Combining 3D Transforms with Translation
[Show how the $3 \times 3$ matrices from notes 02 through 05 combine with translation (06) into a single $4 \times 4$ matrix]

---

## 2. The Model-View-Projection (MVP) Pipeline

In a game, an object's vertex undergoes many changes before it hits the screen:
* **Model Transform:** Scale, rotate, and translate the object into the world.
* **View Transform:** Move and rotate it relative to the camera's position.
* **Projection Transform:** Apply perspective based on the camera lens.

Without a unified $4 \times 4$ system, the math would look like a messy chain of separate multiplications and additions for every single vertex:

$$
\text{Vertex}' = P \cdot (R_v \cdot (R_m \cdot v + t_m) + t_v)
$$

Because homogeneous coordinates allow every single one of these operations (including translation and perspective) to be written as a $4 \times 4$ matrix, you can multiply all the matrices together first, before touching any vertices:

$$
M_{\text{Total}} = M_{\text{Projection}} \times M_{\text{View}} \times M_{\text{Model}}
$$

The engine calculates $M_{\text{Total}}$ just once per object. Then, the graphics card only has to perform a single matrix-vector multiplication for each of the millions of vertices:

$$
\text{Vertex}' = M_{\text{Total}} \cdot v
$$

---

## 3. Perspective Projection
[Explain perspective projection here]

---

## Code Implementation

*   **C++ Source Code:** [[03_Code/04_Transforms/08_Matrix_Composition_4x4.cppm|08_Matrix_Composition_4x4.cppm]]
