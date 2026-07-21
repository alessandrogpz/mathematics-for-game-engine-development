---
topic: Transforms
tags: [exercise, solution, matrix-composition]
---

# Solution: Matrix Composition in 4x4

This solution note provides the step-by-step calculations and answers for the 4x4 matrix composition exercise.

---

## Part 1: Calculation

We want to construct a $4 \times 4$ Model Matrix $\mathbf{M}$ for a 3D object that undergoes the following transformations in order:
1.  **Scale:** Uniform scaling by a factor of $s = 2$.
2.  **Rotation:** Rotation by $90^\circ$ around the vertical $z$-axis.
3.  **Translation:** Translation by $\vec{t} = [3, -1, 4]^T$.

### 1. Individual Matrices

*   **Scaling Matrix ($\mathbf{S}$):**
    
    $$
    \mathbf{S} = \begin{bmatrix} 2 & 0 & 0 & 0 \\\\ 0 & 2 & 0 & 0 \\\\ 0 & 0 & 2 & 0 \\\\ 0 & 0 & 0 & 1 \end{bmatrix}
    $$

*   **Rotation Matrix ($\mathbf{R}$):** Rotation of $90^\circ$ about the $z$-axis.
    
    $$
    \mathbf{R} = \begin{bmatrix} \cos(90^\circ) & -\sin(90^\circ) & 0 & 0 \\\\ \sin(90^\circ) & \cos(90^\circ) & 0 & 0 \\\\ 0 & 0 & 1 & 0 \\\\ 0 & 0 & 0 & 1 \end{bmatrix} = \begin{bmatrix} 0 & -1 & 0 & 0 \\\\ 1 & 0 & 0 & 0 \\\\ 0 & 0 & 1 & 0 \\\\ 0 & 0 & 0 & 1 \end{bmatrix}
    $$

*   **Translation Matrix ($\mathbf{T}$):**
    
    $$
    \mathbf{T} = \begin{bmatrix} 1 & 0 & 0 & 3 \\\\ 0 & 1 & 0 & -1 \\\\ 0 & 0 & 1 & 4 \\\\ 0 & 0 & 0 & 1 \end{bmatrix}
    $$

### 2. Combined Model Matrix $\mathbf{M}$

Since transformations are applied right-to-left ($\vec{v}' = \mathbf{T}\mathbf{R}\mathbf{S}\vec{v}$), the combined Model Matrix is:

$$
\mathbf{M} = \mathbf{T}\mathbf{R}\mathbf{S}
$$

First, compute the product $\mathbf{R}\mathbf{S}$:

$$
\mathbf{R}\mathbf{S} = \begin{bmatrix} 0 & -1 & 0 & 0 \\\\ 1 & 0 & 0 & 0 \\\\ 0 & 0 & 1 & 0 \\\\ 0 & 0 & 0 & 1 \end{bmatrix} \begin{bmatrix} 2 & 0 & 0 & 0 \\\\ 0 & 2 & 0 & 0 \\\\ 0 & 0 & 2 & 0 \\\\ 0 & 0 & 0 & 1 \end{bmatrix} = \begin{bmatrix} 0 & -2 & 0 & 0 \\\\ 2 & 0 & 0 & 0 \\\\ 0 & 0 & 2 & 0 \\\\ 0 & 0 & 0 & 1 \end{bmatrix}
$$

Next, multiply $\mathbf{T}$ by $(\mathbf{R}\mathbf{S})$:

$$
\mathbf{M} = \mathbf{T}(\mathbf{R}\mathbf{S}) = \begin{bmatrix} 1 & 0 & 0 & 3 \\\\ 0 & 1 & 0 & -1 \\\\ 0 & 0 & 1 & 4 \\\\ 0 & 0 & 0 & 1 \end{bmatrix} \begin{bmatrix} 0 & -2 & 0 & 0 \\\\ 2 & 0 & 0 & 0 \\\\ 0 & 0 & 2 & 0 \\\\ 0 & 0 & 0 & 1 \end{bmatrix} = \begin{bmatrix} 0 & -2 & 0 & 3 \\\\ 2 & 0 & 0 & -1 \\\\ 0 & 0 & 2 & 4 \\\\ 0 & 0 & 0 & 1 \end{bmatrix}
$$

### 3. Vertex Transformation $\mathbf{M}\vec{v}$

Using the Model Matrix $\mathbf{M}$, we transform the vertex $\vec{v} = [1, 2, -1, 1]^T$:

$$
\vec{v}' = \mathbf{M}\vec{v} = \begin{bmatrix} 0 & -2 & 0 & 3 \\\\ 2 & 0 & 0 & -1 \\\\ 0 & 0 & 2 & 4 \\\\ 0 & 0 & 0 & 1 \end{bmatrix} \begin{bmatrix} 1 \\\\ 2 \\\\ -1 \\\\ 1 \end{bmatrix} = \begin{bmatrix} 0(1) - 2(2) + 0(-1) + 3(1) \\\\ 2(1) + 0(2) + 0(-1) - 1(1) \\\\ 0(1) + 0(2) + 2(-1) + 4(1) \\\\ 0(1) + 0(2) + 0(-1) + 1(1) \end{bmatrix} = \begin{bmatrix} -4 + 3 \\\\ 2 - 1 \\\\ -2 + 4 \\\\ 1 \end{bmatrix} = \begin{bmatrix} -1 \\\\ 1 \\\\ 2 \\\\ 1 \end{bmatrix}
$$

Thus, the transformed homogeneous vector is:

$$
\vec{v}' = \begin{bmatrix} -1 \\\\ 1 \\\\ 2 \\\\ 1 \end{bmatrix}
$$

Which corresponds to the Euclidean coordinate point **$(-1, 1, 2)$**.

---

## Part 2: Conceptual Understanding

### 1. Order of Matrix Composition (Right-to-Left)
*   **Sequential Application**: Operations evaluate from right-to-left because vectors are represented as column vectors and multiplied on the right side of the matrices ($\vec{v}' = \mathbf{T}\mathbf{R}\mathbf{S}\vec{v}$).
*   **Geometric Difference (SRT vs TRS)**: 
    *   In the **SRT** (Scale $\to$ Rotate $\to$ Translate) order, the scaling and rotation occur in local object space (relative to the object's origin/center). The object scales and spins locally first, and is then placed into the world via translation.
    *   If we computed **TRS** instead, the object would translate first, shifting its local origin away from the world origin. Subsequent rotation and scaling would occur relative to the world origin rather than the object's center, causing the object to orbit the world origin and stretch non-uniformly across space.

### 2. MVP Pipeline Optimization
Vertex shaders process millions of vertices per frame in modern game engines. The Model-View-Projection (MVP) pipeline optimizes this through pre-multiplication:
*   Because matrix multiplication is associative, the engine multiplies the projection, view, and model matrices together once on the CPU per object (or per frame) to form a single combined transformation matrix:
    
    $$
    \mathbf{M}_{\text{Total}} = \mathbf{M}_{\text{Projection}} \cdot \mathbf{M}_{\text{View}} \cdot \mathbf{M}_{\text{Model}}
    $$
    
*   Instead of performing three separate matrix-vector multiplications per vertex on the GPU, the shader only has to perform a **single matrix-vector multiplication** ($\vec{v}' = \mathbf{M}_{\text{Total}}\vec{v}$) for each of the millions of vertices. This reduces arithmetic operations per vertex by two-thirds, saving substantial computational time and preventing bottlenecks.

---
**Back to Question:** [[Q_08_Matrix_Composition_4x4]] | **Related Concepts:** [[08_Matrix_Composition_4x4]]
