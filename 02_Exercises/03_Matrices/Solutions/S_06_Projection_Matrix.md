---
topic: Matrices
tags: [exercise, solution, projection, outer-product, matrix-representation]
---

# Solution: Matrix Representation of Vector Projections

This solution note provides the step-by-step calculations and conceptual answers for the projection matrix exercise.

---

## Part 1: Calculation

We are given a unit direction vector $\hat{u}$ and an arbitrary vector $\vec{a}$:

$$
\hat{u} = \begin{bmatrix} \frac{3}{5} \\\\ 0 \\\\ \frac{4}{5} \end{bmatrix} \quad \text{and} \quad \vec{a} = \begin{bmatrix} 2 \\\\ 5 \\\\ -1 \end{bmatrix}
$$

### 1. Outer Product Matrix Construction

Compute the $3 \times 3$ projection matrix $\mathbf{P}$ representing the projection operator onto $\hat{u}$ using the outer product formula:

$$
\mathbf{P} = \hat{u}\hat{u}^T
$$

$$
\mathbf{P} = \begin{bmatrix} 3/5 \\\\ 0 \\\\ 4/5 \end{bmatrix} \begin{bmatrix} 3/5 & 0 & 4/5 \end{bmatrix} = \begin{bmatrix} (3/5)(3/5) & (3/5)(0) & (3/5)(4/5) \\\\ (0)(3/5) & (0)(0) & (0)(4/5) \\\\ (4/5)(3/5) & (4/5)(0) & (4/5)(4/5) \end{bmatrix}
$$

$$
\mathbf{P} = \begin{bmatrix} 9/25 & 0 & 12/25 \\\\ 0 & 0 & 0 \\\\ 12/25 & 0 & 16/25 \end{bmatrix}
$$

### 2. Matrix Projection Calculation

Multiply this matrix by $\vec{a}$ to calculate the projected vector:

$$
\vec{p} = \mathbf{P}\vec{a}
$$

$$
\vec{p} = \begin{bmatrix} 9/25 & 0 & 12/25 \\\\ 0 & 0 & 0 \\\\ 12/25 & 0 & 16/25 \end{bmatrix} \begin{bmatrix} 2 \\\\ 5 \\\\ -1 \end{bmatrix} = \begin{bmatrix} (9/25)(2) + (0)(5) + (12/25)(-1) \\\\ (0)(2) + (0)(5) + (0)(-1) \\\\ (12/25)(2) + (0)(5) + (16/25)(-1) \end{bmatrix}
$$

$$
\vec{p} = \begin{bmatrix} 18/25 - 12/25 \\\\ 0 \\\\ 24/25 - 16/25 \end{bmatrix} = \begin{bmatrix} 6/25 \\\\ 0 \\\\ 8/25 \end{bmatrix}
$$

### 3. Classical Formula Verification

Calculate the same vector projection using the classical dot product formula:

$$
\text{proj}_{\hat{u}}\vec{a} = (\vec{a} \cdot \hat{u})\hat{u}
$$

First, compute the dot product $\vec{a} \cdot \hat{u}$:

$$
\vec{a} \cdot \hat{u} = \begin{bmatrix} 2 \\\\ 5 \\\\ -1 \end{bmatrix} \cdot \begin{bmatrix} 3/5 \\\\ 0 \\\\ 4/5 \end{bmatrix} = (2)(3/5) + (5)(0) + (-1)(4/5) = \frac{6}{5} - \frac{4}{5} = \frac{2}{5}
$$

Now multiply this scalar factor by the unit vector $\hat{u}$:

$$
\text{proj}_{\hat{u}}\vec{a} = \frac{2}{5} \begin{bmatrix} 3/5 \\\\ 0 \\\\ 4/5 \end{bmatrix} = \begin{bmatrix} 6/25 \\\\ 0 \\\\ 8/25 \end{bmatrix}
$$

Both methods yield the exact same resulting vector $\vec{p} = [6/25, \, 0, \, 8/25]^T$, verifying the mathematical equivalency.

---

## Part 2: Conceptual Understanding

### 1. Subspace Representation
*   **Geometric interpretation**: The projection matrix $\mathbf{P} = \hat{u}\hat{u}^T$ represents a mathematical operator that flattens (projects) any 3D vector onto the 1D line spanned by the unit vector $\hat{u}$.
*   **Special spatial filter**: It behaves like a filter because it completely "blocks" (ignores) any components of a vector that are perpendicular to the target axis $\hat{u}$ ($\vec{a}_{\perp}$), while letting the component parallel to $\hat{u}$ ($\vec{a}_{\parallel}$) pass through. For our vector $\vec{a}$, the $y$-axis component and other parts perpendicular to $\hat{u}$ are filtered out (resulting in $y = 0$).

### 2. Determinant of a Projection Matrix
The determinant of this projection matrix is:

$$
\det(\mathbf{P}) = 0
$$

*   **Algebraic Proof**: The columns of any projection matrix of the form $\mathbf{P} = \vec{v}\vec{v}^T$ are linearly dependent. For example, if we take $\vec{v} = [1, 2, 3]^T$, the matrix is:
    
    $$
    \mathbf{P} = \begin{bmatrix} 1 & 2 & 3 \\\\ 2 & 4 & 6 \\\\ 3 & 6 & 9 \end{bmatrix}
    $$
    
    Row 2 is $2 \times$ Row 1, and Row 3 is $3 \times$ Row 1. Because the rows are linearly dependent, the matrix is singular (rank 1), meaning its determinant must be 0.
*   **Geometric Intuition**: The determinant represents the volume scaling factor of the transformation. A projection matrix collapses 3D space onto a 1D line, shrinking all 3D volume down to exactly zero. Since the transformed volume is zero, the determinant must be $0$ (the object's volume has completely vanished).

### 3. Trace of a Projection Matrix
The trace of a matrix is the sum of its main diagonal elements:

$$
\text{tr}(\mathbf{P}) = \sum_{i=1}^3 P_{ii} = \frac{9}{25} + 0 + \frac{16}{25} = \frac{25}{25} = 1
$$

*   **Relation to Subspace Dimension**: The trace of a projection matrix is always equal to the **dimension of the subspace** it projects onto ($\text{tr}(\mathbf{P}) = \text{rank}(\mathbf{P})$).
    - **Trace = 1**: Squishes the space onto a 1D line ($\hat{u}\hat{u}^T$).
    - **Trace = 2**: Flattens the space onto a 2D plane.
    - **Trace = 3**: Leaves all dimensions intact (equivalent to the Identity matrix $\mathbf{I}$).

---

**Back to Question:** [[Q_06_Projection_Matrix]] | **Related Concepts:** [[06_Projection_Matrices]]
