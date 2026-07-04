# Projection Matrices

In graphics programming and game physics engines, vector projections are almost always performed onto **unit vectors** representing directions. Using matrices allows us to combine projection and rejection operators with other transformations (such as rotations and translations).

---

## 1. Matrix Representation of Vector Projection (Outer Product)

### The Outer Product
The **outer product** (denoted as $\vec{a}\vec{b}^T$ or $\vec{a} \otimes \vec{b}$) is a linear algebra operation that multiplies a column vector by a row vector to construct a matrix.

* **Conceptual Meaning:** While the dot product acts as a **compressor** (collapsing two vectors into a single scalar number based on their alignment), the outer product acts as an **expander** (generating a grid showing how every individual dimension of the first vector interacts with every individual dimension of the second vector).

---

> [!IMPORTANT]
> **Outer Product vs. Projection Matrix**
> * **Outer Product ($\vec{a}\vec{b}^T$):** A general operation that can be computed between *any* two vectors.
> * **Projection Matrix ($\mathbf{P} = \hat{u}\hat{u}^T$):** A specific $3 \times 3$ matrix constructed by taking the outer product of a **unit vector** $\hat{u}$ with itself. This matrix has the unique property of being *idempotent* ($\mathbf{P}^2 = \mathbf{P}$), meaning applying it multiple times does not change the result.

---

### Derivation of the Projection Matrix
For any vector $\vec{a}$ and a unit direction vector $\hat{u}$ (where $\|\hat{u}\|^2 = 1$), the vector projection is:

$$
\text{proj}_{\hat{u}}\vec{a} = (\vec{a} \cdot \hat{u})\hat{u}
$$

Using standard linear algebra, the dot product of two column vectors can be rewritten as multiplying a row vector by a column vector:

$$
(\vec{a} \cdot \hat{u}) = \hat{u}^T \vec{a}
$$

Substituting this back into the projection formula:

$$
\text{proj}_{\hat{u}}\vec{a} = (\hat{u}^T \vec{a})\hat{u} = \hat{u}(\hat{u}^T \vec{a})
$$

Applying the matrix associative property, we can regroup the terms to isolate the vector $\vec{a}$:

$$
\text{proj}_{\hat{u}}\vec{a} = (\hat{u}\hat{u}^T)\vec{a}
$$

Where the isolated term $(\hat{u}\hat{u}^T)$ is the **Projection Matrix** $\mathbf{P}$:

$$
\mathbf{P} = \hat{u}\hat{u}^T = \begin{bmatrix} u_x \\\\ u_y \\\\ u_z \end{bmatrix} \begin{bmatrix} u_x & u_y & u_z \end{bmatrix} = \begin{bmatrix} u_x^2 & u_x u_y & u_x u_z \\\\ u_x u_y & u_y^2 & u_y u_z \\\\ u_x u_z & u_y u_z & u_z^2 \end{bmatrix}
$$

Multiplying this matrix by any vector $\vec{a}$ projects it directly onto the direction of $\hat{u}$:

$$
\text{proj}_{\hat{u}}\vec{a} = \begin{bmatrix} u_x^2 & u_x u_y & u_x u_z \\\\ u_x u_y & u_y^2 & u_y u_z \\\\ u_x u_z & u_y u_z & u_z^2 \end{bmatrix}\vec{a}
$$

---

## 2. Matrix Representation of Vector Rejection (Orthogonal Rejection Operator)

Just like vector projection, vector rejection (finding the component of a vector orthogonal to a direction axis) can be represented as a matrix-vector multiplication using an **Orthogonal Rejection Matrix** $\mathbf{P}_{\perp}$.

### Derivation
Assuming projection onto a unit vector $\hat{u}$:
1. **Substitute the Projection Matrix:**
   
$$
\text{rej}_{\hat{u}}\vec{a} = \vec{a} - (\hat{u}\hat{u}^T)\vec{a}
$$
   
2. **Factor Out the Vector $\vec{a}$:**
   By inserting the identity matrix $\mathbf{I}$ (since $\vec{a} = \mathbf{I}\vec{a}$):
   
$$
\text{rej}_{\hat{u}}\vec{a} = \mathbf{I}\vec{a} - (\hat{u}\hat{u}^T)\vec{a} = (\mathbf{I} - \hat{u}\hat{u}^T)\vec{a}
$$

Where the isolated term $(\mathbf{I} - \hat{u}\hat{u}^T)$ is the **Orthogonal Rejection Matrix** $\mathbf{P}_{\perp u}$:

$$
\mathbf{P}_{\perp u} = \mathbf{I} - \hat{u}\hat{u}^T
$$

### Explicit Matrix Expansion
$$
\mathbf{P}_{\perp u} = \begin{bmatrix} 1 & 0 & 0 \\\\ 0 & 1 & 0 \\\\ 0 & 0 & 1 \end{bmatrix} - \begin{bmatrix} u_x^2 & u_x u_y & u_x u_z \\\\ u_x u_y & u_y^2 & u_y u_z \\\\ u_x u_z & u_y u_z & u_z^2 \end{bmatrix} = \begin{bmatrix} 1 - u_x^2 & -u_x u_y & -u_x u_z \\\\ -u_x u_y & 1 - u_y^2 & -u_y u_z \\\\ -u_x u_z & -u_y u_z & 1 - u_z^2 \end{bmatrix}
$$

Multiplying any vector $\vec{a}$ by this matrix filters out everything parallel to $\hat{u}$, leaving only the component orthogonal to $\hat{u}$.

---

## 3. Determinant and Trace of a Projection Matrix

A projection matrix $\mathbf{P} = \hat{u}\hat{u}^T$ has unique eigenvalues, determinant, and trace properties that carry significant geometric meaning.

### A. Determinant of a Projection Matrix ($\det(\mathbf{P})$)
For any projection matrix $\mathbf{P}$ that projects onto a proper subspace (like a 1D line or a 2D plane in 3D space), the determinant is always:

$$
\det(\mathbf{P}) = 0
$$

*   **Geometric Intuition**: The determinant represents the volume scaling factor of a transformation. A projection matrix flattens 3D space, squishing all 3D volume down to a lower-dimensional subspace (a 2D plane or a 1D line). Because a 1D line or a 2D plane has exactly zero volume in 3D space, the volume scaling factor is zero, meaning the matrix is singular and its determinant must be $0$.

### B. Trace of a Projection Matrix ($\text{tr}(\mathbf{P})$)
The trace of a projection matrix (the sum of its main diagonal elements) is always equal to the **dimension of the subspace** it projects onto:

$$
\text{tr}(\mathbf{P}) = \text{rank}(\mathbf{P}) = \text{dimension of projected subspace}
$$

*   **In 3D Space**:
    - $\text{tr}(\mathbf{P}) = 1$: Projects space onto a 1D line (e.g. $\mathbf{P} = \hat{u}\hat{u}^T$).
    - $\text{tr}(\mathbf{P}) = 2$: Projects space onto a 2D plane (e.g. the rejection matrix $\mathbf{P}_{\perp u} = \mathbf{I} - \hat{u}\hat{u}^T$, which projects onto the plane orthogonal to $\hat{u}$ and has trace $3 - 1 = 2$).
    - $\text{tr}(\mathbf{P}) = 3$: Leaves the entire 3D space intact (equivalent to the Identity matrix $\mathbf{I}$, which has trace $3$).

---

## Code Implementation

*   **C++ Source Code:** [[03_Code/03_Matrices/Projection_Matrices.cppm|Projection_Matrices.cppm]]
