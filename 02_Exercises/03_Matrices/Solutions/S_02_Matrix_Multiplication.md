---
topic: Matrices
tags: [exercise, solution, transformation, homogeneous-coordinates]
---

# Solution: Matrix Multiplication

This solution note provides the step-by-step calculations and conceptual answers for the 2D homogeneous matrix transformation exercise.

---

## Part 1: Calculation

We start with a 2D point at $(2, 1)$, represented in homogeneous coordinates as:

$$
\vec{p} = \begin{bmatrix} 2 \\\\ 1 \\\\ 1 \end{bmatrix}
$$

We apply three transformations in the standard **SRT (Scale $\to$ Rotate $\to$ Translate)** order.

### 1. Construction of Individual Transformation Matrices

*   **Scale Matrix ($\mathbf{S}$):** Uniform scale by 3.
    
    $$
    \mathbf{S} = \begin{bmatrix} 3 & 0 & 0 \\\\ 0 & 3 & 0 \\\\ 0 & 0 & 1 \end{bmatrix}
    $$

*   **Rotation Matrix ($\mathbf{R}$):** Rotate $90^\circ$ counter-clockwise (about the $z$-axis).
    
    $$
    \mathbf{R} = \begin{bmatrix} \cos(90^\circ) & -\sin(90^\circ) & 0 \\\\ \sin(90^\circ) & \cos(90^\circ) & 0 \\\\ 0 & 0 & 1 \end{bmatrix} = \begin{bmatrix} 0 & -1 & 0 \\\\ 1 & 0 & 0 \\\\ 0 & 0 & 1 \end{bmatrix}
    $$

*   **Translation Matrix ($\mathbf{T}$):** Translate by $T_x = 5$ and $T_y = -2$.
    
    $$
    \mathbf{T} = \begin{bmatrix} 1 & 0 & 5 \\\\ 0 & 1 & -2 \\\\ 0 & 0 & 1 \end{bmatrix}
    $$

### 2. Sequential Application of Operations

To evaluate the operations sequentially:

1.  **Scale ($\mathbf{S}\vec{p}$):**
    
    $$
    \vec{p}_{\text{scaled}} = \mathbf{S}\vec{p} = \begin{bmatrix} 3 & 0 & 0 \\\\ 0 & 3 & 0 \\\\ 0 & 0 & 1 \end{bmatrix} \begin{bmatrix} 2 \\\\ 1 \\\\ 1 \end{bmatrix} = \begin{bmatrix} 6 \\\\ 3 \\\\ 1 \end{bmatrix}
    $$

2.  **Rotate ($\mathbf{R}\vec{p}_{\text{scaled}}$):**
    
    $$
    \vec{p}_{\text{rotated}} = \mathbf{R}\vec{p}_{\text{scaled}} = \begin{bmatrix} 0 & -1 & 0 \\\\ 1 & 0 & 0 \\\\ 0 & 0 & 1 \end{bmatrix} \begin{bmatrix} 6 \\\\ 3 \\\\ 1 \end{bmatrix} = \begin{bmatrix} -3 \\\\ 6 \\\\ 1 \end{bmatrix}
    $$

3.  **Translate ($\mathbf{T}\vec{p}_{\text{rotated}}$):**
    
    $$
    \vec{p}_{\text{final}} = \mathbf{T}\vec{p}_{\text{rotated}} = \begin{bmatrix} 1 & 0 & 5 \\\\ 0 & 1 & -2 \\\\ 0 & 0 & 1 \end{bmatrix} \begin{bmatrix} -3 \\\\ 6 \\\\ 1 \end{bmatrix} = \begin{bmatrix} (-3 + 5) \\\\ (6 - 2) \\\\ 1 \end{bmatrix} = \begin{bmatrix} 2 \\\\ 4 \\\\ 1 \end{bmatrix}
    $$

The final transformed point is **$(2, 4)$**.

### 3. Construction of the Combined Transformation Matrix $\mathbf{M}$

Since operations are applied right-to-left ($\vec{p}' = \mathbf{T}\mathbf{R}\mathbf{S}\vec{p}$), the combined transformation matrix is:

$$
\mathbf{M} = \mathbf{T}\mathbf{R}\mathbf{S}
$$

First, multiply $\mathbf{T}$ and $\mathbf{R}$:

$$
\mathbf{T}\mathbf{R} = \begin{bmatrix} 1 & 0 & 5 \\\\ 0 & 1 & -2 \\\\ 0 & 0 & 1 \end{bmatrix} \begin{bmatrix} 0 & -1 & 0 \\\\ 1 & 0 & 0 \\\\ 0 & 0 & 1 \end{bmatrix} = \begin{bmatrix} 0 & -1 & 5 \\\\ 1 & 0 & -2 \\\\ 0 & 0 & 1 \end{bmatrix}
$$

Next, multiply $(\mathbf{T}\mathbf{R})$ by $\mathbf{S}$:

$$
\mathbf{M} = (\mathbf{T}\mathbf{R})\mathbf{S} = \begin{bmatrix} 0 & -1 & 5 \\\\ 1 & 0 & -2 \\\\ 0 & 0 & 1 \end{bmatrix} \begin{bmatrix} 3 & 0 & 0 \\\\ 0 & 3 & 0 \\\\ 0 & 0 & 1 \end{bmatrix} = \begin{bmatrix} 0 & -3 & 5 \\\\ 3 & 0 & -2 \\\\ 0 & 0 & 1 \end{bmatrix}
$$

### 4. Verification using $\mathbf{M}$

$$
\vec{p}' = \mathbf{M}\vec{p} = \begin{bmatrix} 0 & -3 & 5 \\\\ 3 & 0 & -2 \\\\ 0 & 0 & 1 \end{bmatrix} \begin{bmatrix} 2 \\\\ 1 \\\\ 1 \end{bmatrix} = \begin{bmatrix} 0(2) - 3(1) + 5(1) \\\\ 3(2) + 0(1) - 2(1) \\\\ 0(2) + 0(1) + 1(1) \end{bmatrix} = \begin{bmatrix} 2 \\\\ 4 \\\\ 1 \end{bmatrix}
$$

This matches the sequential calculations, verifying that matrix multiplication correctly aggregates individual transformations.

---

## Part 2: Conceptual Understanding

### 1. Purpose of $3 \times 3$ Matrices in 2D
*   **Translation Limitation**: A translation of a 2D vector (shifting it by $T_x, T_y$) is an **affine transformation**, which cannot be represented as a standard linear mapping using a $2 \times 2$ matrix multiplication (as translation adds a constant term rather than scaling coordinates).
*   **Homogeneous Coordinates**: Embedding 2D points into a 3D space by adding a third coordinate ($w=1$) turns translation into a 3D shear transformation. Using a $3 \times 3$ matrix allows us to perform translation, rotation, and scaling in a single matrix-vector multiplication, making it possible to chain transformations through matrix multiplication.

### 2. Commutativity & Order of Operations
If the order is changed to **TRS (Translate $\to$ Rotate $\to$ Scale)**:
*   The final position **will not** be the same.
*   **Reason**: Matrix multiplication is non-commutative ($\mathbf{A}\mathbf{B} \neq \mathbf{B}\mathbf{A}$). 
    *   In the SRT order, scaling and rotation occur about the origin, and translation shifts the final shape.
    *   In the TRS order, the point is first translated away from the origin, meaning the subsequent rotation and scaling will occur about the origin relative to the shifted position (resulting in orbital rotation and scaling relative to the origin rather than the local shape center).

### 3. Geometric Interpretation of the Determinant
For the combined matrix $\mathbf{M}$:
*   The absolute value of the determinant ($|\det(\mathbf{M})|$) represents the **area scaling factor** of the transformation on 2D shapes. Here, the scale factor is 3 in both directions, meaning the area scales by a factor of $3^2 = 9$.
    
    $$
    \det(\mathbf{M}) = 0(0 - 0) - (-3)(3 - 0) + 5(0 - 0) = 9
    $$
    
*   The sign of the determinant indicates whether **orientation** is preserved (positive) or flipped/reflected (negative). Since $\det(\mathbf{M}) = 9 > 0$, the orientation is preserved.

---

**Back to Question:** [[Q_02_Matrix_Multiplication]] **Related Concepts:** [[02_Matrix_Multiplication]]