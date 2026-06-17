# Transformation Matrices

In game engines, 3D graphics, and physical simulations, we frequently represent objects in multiple coordinate systems (e.g., local/object space, world space, camera/view space). Understanding how to move position vectors and linear operators between these systems is a core requirement of linear algebra.

---

## 1. Affine and Linear Transformations

### Affine Transformations
A position vector $\vec{p}_A$ in coordinate system $A$ is transformed to $\vec{p}_B$ in coordinate system $B$ by reorienting its axes and shifting its origin. This combined rotation, scaling, and translation is called an **affine transformation**:

**(2.1)**
$$
\vec{p}_B = \mathbf{M}\vec{p}_A + \vec{t}
$$

Where:
*   $\mathbf{M}$ is a $3 \times 3$ transformation matrix that rotates and scales the coordinate axes.
*   $\vec{t}$ is a $3\text{D}$ translation vector that shifts the origin of system $A$ to system $B$'s origin.

### The Inverse Affine Transformation
If the matrix $\mathbf{M}$ is invertible, we can solve Equation (2.1) for $\vec{p}_A$ to find the reverse transformation (from system $B$ back to system $A$):

**(2.2)**
$$
\vec{p}_A = \mathbf{M}^{-1}(\vec{p}_B - \vec{t})
$$

> [!NOTE]
> In game engine programming, we often combine $\mathbf{M}$ and $\vec{t}$ into a single $4 \times 4$ homogeneous transformation matrix so that translations can be treated as standard matrix multiplications. Until then, we assume coordinate systems share the same origin ($\vec{t} = \vec{0}$) and focus purely on linear transformations.

### Column-Vector Basis Interpretation
For a pure linear transformation $\vec{v}_B = \mathbf{M}\vec{v}_A$, the columns of $\mathbf{M}$ represent the basis vectors of system $A$ expressed relative to system $B$. If we define:

$$
\mathbf{M} = \begin{bmatrix} \vec{a} & \vec{b} & \vec{c} \end{bmatrix}
$$

then the transformation of the canonical basis vectors yields the columns of $\mathbf{M}$:

**(2.3)**
$$
\mathbf{M}\begin{bmatrix} 1 \\\\ 0 \\\\ 0 \end{bmatrix} = \vec{a}, \quad \mathbf{M}\begin{bmatrix} 0 \\\\ 1 \\\\ 0 \end{bmatrix} = \vec{b}, \quad \mathbf{M}\begin{bmatrix} 0 \\\\ 0 \\\\ 1 \end{bmatrix} = \vec{c}
$$

For any arbitrary vector:

$$
\vec{v} = \begin{bmatrix} v_x \\\\ v_y \\\\ v_z \end{bmatrix}
$$

the transformation $\mathbf{M}\vec{v}$ represents a **linear combination** of these new basis axes:

**(2.4)**
$$
\mathbf{M}\vec{v} = v_x\vec{a} + v_y\vec{b} + v_z\vec{c}
$$

---

## 2. Orthogonal Transforms

An **orthogonal matrix** is a square matrix whose columns form an orthonormal set (mutually perpendicular unit-length vectors). In game physics and graphics, pure rotation matrices are orthogonal.

Let $\mathbf{M}$ be a matrix with orthonormal columns:

$$
\mathbf{M} = \begin{bmatrix} \vec{a} & \vec{b} & \vec{c} \end{bmatrix}
$$

Computing $\mathbf{M}^T\mathbf{M}$ yields:

**(2.5)**
$$
\mathbf{M}^T\mathbf{M} = \begin{bmatrix} \leftarrow & \vec{a}^T & \rightarrow \\\\ \leftarrow & \vec{b}^T & \rightarrow \\\\ \leftarrow & \vec{c}^T & \rightarrow \end{bmatrix} \begin{bmatrix} \uparrow & \uparrow & \uparrow \\\\ \vec{a} & \vec{b} & \vec{c} \\\\ \downarrow & \downarrow & \downarrow \end{bmatrix} = \begin{bmatrix} \vec{a}^2 & \vec{a} \cdot \vec{b} & \vec{a} \cdot \vec{c} \\\\ \vec{b} \cdot \vec{a} & \vec{b}^2 & \vec{b} \cdot \vec{c} \\\\ \vec{c} \cdot \vec{a} & \vec{c} \cdot \vec{b} & \vec{c}^2 \end{bmatrix}
$$

Since the columns are unit vectors ($\|\vec{a}\|^2 = \vec{a}^2 = 1$) and mutually perpendicular ($\vec{a} \cdot \vec{b} = 0$), this simplifies directly to the Identity matrix $\mathbf{I}$:

$$
\mathbf{M}^T\mathbf{M} = \mathbf{I} \implies \mathbf{M}^{-1} = \mathbf{M}^T
$$

### Key Equivalent Statements
The following statements are mathematically identical for a square matrix $\mathbf{M}$:
1.  $\mathbf{M}$ is an orthogonal matrix.
2.  The inverse of $\mathbf{M}$ is equal to its transpose ($\mathbf{M}^{-1} = \mathbf{M}^T$).
3.  The columns of $\mathbf{M}$ are mutually perpendicular unit-length vectors.
4.  The rows of $\mathbf{M}$ are mutually perpendicular unit-length vectors.

### Preservation Properties
Orthogonal transformations preserve the geometric relationships between vectors:
*   **Preservation of Dot Product:** The dot product of two transformed vectors is equal to their original dot product:
    
**(2.6)**
$$
(\mathbf{M}\vec{a}) \cdot (\mathbf{M}\vec{b}) = (\mathbf{M}\vec{a})^T(\mathbf{M}\vec{b}) = \vec{a}^T\mathbf{M}^T\mathbf{M}\vec{b} = \vec{a}^T\vec{b} = \vec{a} \cdot \vec{b}
$$

*   **Preservation of Length:** Because dot products are preserved, the length of any vector is invariant under an orthogonal transform: $\|\mathbf{M}\vec{v}\| = \|\vec{v}\|$.
*   **Preservation of Angle:** The angle $\theta$ between any two vectors is invariant.
*   **Determinant:** The determinant of any orthogonal matrix is always $\det(\mathbf{M}) = \pm 1$.
    *   $\det(\mathbf{M}) = 1$: Represents a **pure rotation** (preserves the orientation handedness).
    *   $\det(\mathbf{M}) = -1$: Represents a **reflection** (reverses the handedness, e.g. switching right-handed to left-handed systems).

---

## 3. Transform Composition

When a vector $\vec{v}$ undergoes sequential transformations—first by $\mathbf{M}_1$, then by $\mathbf{M}_2$—we calculate the final vector $\vec{v}'$ as:

**(2.7)**
$$
\vec{v}' = \mathbf{M}_2(\mathbf{M}_1\vec{v})
$$

Because matrix multiplication is associative, we can group the matrices together first to pre-multiply them into a single transform matrix $\mathbf{N} = \mathbf{M}_2\mathbf{M}_1$:

$$
\vec{v}' = \mathbf{N}\vec{v}
$$

For $n$ consecutive transformations, the order of matrix multiplication is applied **right-to-left**:

$$
\mathbf{N} = \mathbf{M}_n\mathbf{M}_{n-1}\dots\mathbf{M}_2\mathbf{M}_1
$$

---

## 4. Change of Basis for Transformations (Similarity Transforms)

Suppose we have a transformation $\mathbf{A}$ that is defined and expressed in coordinate system $A$. If we want to apply the equivalent transformation in coordinate system $B$, we must perform a **similarity transformation**:

**(2.8)**
$$
\mathbf{B} = \mathbf{M}\mathbf{A}\mathbf{M}^{-1}
$$

Where $\mathbf{M}$ is the matrix that transforms vectors from coordinate system $A$ to coordinate system $B$ ($\vec{p}_B = \mathbf{M}\vec{p}_A$).

### Geometric Workflow of $\mathbf{B}\vec{v}_B$
To apply $\mathbf{B}$ to a vector $\vec{v}_B$ in system $B$, you can read the right side of Equation (2.8) from right-to-left:
1.  **$\mathbf{M}^{-1}\vec{v}_B$:** Transform the vector from system $B$ to system $A$.
2.  **$\mathbf{A}(\mathbf{M}^{-1}\vec{v}_B)$:** Apply the transform $\mathbf{A}$ in its native setting (system $A$).
3.  **$\mathbf{M}(\mathbf{A}\mathbf{M}^{-1}\vec{v}_B)$:** Transform the result back into system $B$.

This elegant formula is how operations themselves (such as scaling, rotations, or shears) are mapped between different coordinate frameworks.

---

## Code Implementation

*   **C++ Source Code:** [[03_Code/04_Transforms/01_Transformation_Matrices.cppm|01_Transformation_Matrices.cppm]]
