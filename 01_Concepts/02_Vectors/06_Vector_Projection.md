# Vector Projection

Vector projection allows us to decompose one vector into a component that lies along the direction of another vector.

## Conceptual Understanding: "Shadow and Influence"
Think of vector projection as finding the "shadow" that vector $\vec{a}$ casts onto vector $\vec{b}$.
- **What it tells us:** It tells us how much of $\vec{a}$ is acting in the same direction as $\vec{b}$.
- **Components:**
  - **Scalar Projection (Length):** Just the magnitude of the shadow.
  - **Vector Projection (Vector):** The actual vector that represents that shadow.

## Formulas

### Scalar Projection (Component)

$$
\text{comp}_{\vec{b}}\vec{a} = \frac{\vec{a} \cdot \vec{b}}{\|\vec{b}\|}
$$

### Vector Projection

$$
\text{proj}_{\vec{b}}\vec{a} = \frac{\vec{a} \cdot \vec{b}}{\|\vec{b}\|^2} \vec{b}
$$

## Derivation of the Formula

To find the formula for the projection of $\vec{a}$ onto $\vec{b}$, we follow these logical steps:

### 1. The Geometric Setup
We want to find the component of $\vec{a}$ that lies in the direction of $\vec{b}$. Geometrically, this forms a right-angled triangle where:
- The hypotenuse is $\|\vec{a}\|$.
- The adjacent side (the shadow) is the **Scalar Projection** ($\text{comp}_{\vec{b}}\vec{a}$).
- The angle between the vectors is $\theta$.

From trigonometry:

$$
\text{comp}_{\vec{b}}\vec{a} = \|\vec{a}\| \cos(\theta)
$$

### 2. Connect to the Dot Product
We know the geometric definition of the dot product is:

$$
\vec{a} \cdot \vec{b} = \|\vec{a}\| \|\vec{b}\| \cos(\theta)
$$

Isolate the $\|\vec{a}\| \cos(\theta)$ part:

$$
\|\vec{a}\| \cos(\theta) = \frac{\vec{a} \cdot \vec{b}}{\|\vec{b}\|}
$$

This gives us the **Scalar Projection** formula.

### 3. Convert to a Vector
The **Vector Projection** ($\text{proj}_{\vec{b}}\vec{a}$) must have the magnitude we just found, but it must point in the direction of $\vec{b}$. To do this, we multiply the scalar magnitude by the **unit vector** of $\vec{b}$ ($\hat{u}_{\vec{b}}$):

$$
\hat{u}_{\vec{b}} = \frac{\vec{b}}{\|\vec{b}\|}
$$

Combine them:

$$
\text{proj}_{\vec{b}}\vec{a} = \left( \text{comp}_{\vec{b}}\vec{a} \right) \cdot \hat{u}_{\vec{b}}
$$

$$
\text{proj}_{\vec{b}}\vec{a} = \left( \frac{\vec{a} \cdot \vec{b}}{\|\vec{b}\|} \right) \cdot \frac{\vec{b}}{\|\vec{b}\|}
$$

### 4. Simplify
Multiplying the denominators ($\|\vec{b}\| \cdot \|\vec{b}\| = \|\vec{b}\|^2$):

$$
\text{proj}_{\vec{b}}\vec{a} = \frac{\vec{a} \cdot \vec{b}}{\|\vec{b}\|^2} \vec{b}
$$

---

## 5. Matrix Representation of Vector Projection (Outer Product)

In graphics programming and game physics engines, vector projections are almost always performed onto **unit vectors** representing directions.

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

### Determinant and Trace of a Projection Matrix

A projection matrix $\mathbf{P} = \hat{u}\hat{u}^T$ has unique eigenvalues, determinant, and trace properties that carry significant geometric meaning.

#### 1. Determinant of a Projection Matrix ($\det(\mathbf{P})$)
For any projection matrix $\mathbf{P}$ that projects onto a proper subspace (like a 1D line or a 2D plane in 3D space), the determinant is always:

$$
\det(\mathbf{P}) = 0
$$

*   **Geometric Intuition**: The determinant represents the volume scaling factor of a transformation. A projection matrix flattens 3D space, squishing all 3D volume down to a lower-dimensional subspace (a 2D plane or a 1D line). Because a 1D line or a 2D plane has exactly zero volume in 3D space, the volume scaling factor is zero, meaning the matrix is singular and its determinant must be $0$.

#### 2. Trace of a Projection Matrix ($\text{tr}(\mathbf{P})$)
The trace of a projection matrix (the sum of its main diagonal elements) is always equal to the **dimension of the subspace** it projects onto:

$$
\text{tr}(\mathbf{P}) = \text{rank}(\mathbf{P}) = \text{dimension of projected subspace}
$$

*   **In 3D Space**:
    - $\text{tr}(\mathbf{P}) = 1$: Projects space onto a 1D line (e.g. $\mathbf{P} = \hat{u}\hat{u}^T$).
    - $\text{tr}(\mathbf{P}) = 2$: Projects space onto a 2D plane (e.g. the rejection matrix $\mathbf{P}_{\perp u} = \mathbf{I} - \hat{u}\hat{u}^T$, which projects onto the plane orthogonal to $\hat{u}$ and has trace $3 - 1 = 2$).
    - $\text{tr}(\mathbf{P}) = 3$: Leaves the entire 3D space intact (equivalent to the Identity matrix $\mathbf{I}$, which has trace $3$).

---

## 6. Vector Rejection

While vector projection finds the component of a vector $\vec{a}$ that is parallel to the direction of $\vec{b}$, **vector rejection** finds the component of $\vec{a}$ that is **perpendicular** (orthogonal) to $\vec{b}$.

### Conceptual Understanding: "The Sliding Component"
Think of vector rejection as removing the parallel projection component from the original vector.
* **Physical Meaning:** In game physics (like collision response), if $\vec{b}$ is a surface normal vector, the vector projection is the component pushing *into* the surface (penetration), while the vector rejection is the component **parallel to the surface** (the sliding direction along the plane).

### Algebraic Formula
$$
\text{rej}_{\vec{b}}\vec{a} = \vec{a} - \text{proj}_{\vec{b}}\vec{a}
$$

---

## 7. Matrix Representation of Vector Rejection (Orthogonal Rejection Operator)

Just like vector projection, vector rejection can be represented as a matrix-vector multiplication using an **Orthogonal Rejection Matrix** $\mathbf{P}_{\perp}$.

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

## Code Implementation

*   **C++ Source Code:** [[03_Code/02_Vectors/06_Vector_Projection.cppm|06_Vector_Projection.cppm]]
