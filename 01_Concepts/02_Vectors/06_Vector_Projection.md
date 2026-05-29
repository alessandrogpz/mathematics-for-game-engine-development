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
$$\text{comp}_{\vec{b}}\vec{a} = \frac{\vec{a} \cdot \vec{b}}{\|\vec{b}\|}$$

### Vector Projection
$$\text{proj}_{\vec{b}}\vec{a} = \frac{\vec{a} \cdot \vec{b}}{\|\vec{b}\|^2} \vec{b}$$

## Derivation of the Formula

To find the formula for the projection of $\vec{a}$ onto $\vec{b}$, we follow these logical steps:

### 1. The Geometric Setup
We want to find the component of $\vec{a}$ that lies in the direction of $\vec{b}$. Geometrically, this forms a right-angled triangle where:
- The hypotenuse is $\|\vec{a}\|$.
- The adjacent side (the shadow) is the **Scalar Projection** ($\text{comp}_{\vec{b}}\vec{a}$).
- The angle between the vectors is $\theta$.

From trigonometry:
$$\text{comp}_{\vec{b}}\vec{a} = \|\vec{a}\| \cos(\theta)$$

### 2. Connect to the Dot Product
We know the geometric definition of the dot product is:
$$\vec{a} \cdot \vec{b} = \|\vec{a}\| \|\vec{b}\| \cos(\theta)$$
Isolate the $\|\vec{a}\| \cos(\theta)$ part:
$$\|\vec{a}\| \cos(\theta) = \frac{\vec{a} \cdot \vec{b}}{\|\vec{b}\|}$$
This gives us the **Scalar Projection** formula.

### 3. Convert to a Vector
The **Vector Projection** ($\text{proj}_{\vec{b}}\vec{a}$) must have the magnitude we just found, but it must point in the direction of $\vec{b}$. To do this, we multiply the scalar magnitude by the **unit vector** of $\vec{b}$ ($\hat{u}_{\vec{b}}$):
$$\hat{u}_{\vec{b}} = \frac{\vec{b}}{\|\vec{b}\|}$$

Combine them:
$$\text{proj}_{\vec{b}}\vec{a} = \left( \text{comp}_{\vec{b}}\vec{a} \right) \cdot \hat{u}_{\vec{b}}$$
$$\text{proj}_{\vec{b}}\vec{a} = \left( \frac{\vec{a} \cdot \vec{b}}{\|\vec{b}\|} \right) \cdot \frac{\vec{b}}{\|\vec{b}\|}$$

### 4. Simplify
Multiplying the denominators ($\|\vec{b}\| \cdot \|\vec{b}\| = \|\vec{b}\|^2$):
$$\text{proj}_{\vec{b}}\vec{a} = \frac{\vec{a} \cdot \vec{b}}{\|\vec{b}\|^2} \vec{b}$$

---

## 5. Matrix Representation of Vector Projection (Outer Product)

In graphics programming and game physics engines, vector projections are almost always performed onto **unit vectors** representing directions.
### Description

The outer product is a linear algebra operation that multiplies a column vector by a row vector to construct a matrix. If you multiply a column vector of size $m$ by a row vector of size $n$, the outer product generates an $m \times n$ matrix.

### Conceptual Meaning

The outer product represents the complete interaction between every individual dimension of two vectors.

While the dot product acts as a compressor (collapsing two vectors into a single scalar number based on their alignment), the outer product acts as an expander. It maps out a grid showing exactly how each specific axis of the first vector scales against each specific axis of the second vector.
### Formula

Assuming a unit vector $\hat{u}$ (where $\|\hat{u}\|^2 = 1$), the vector projection of a vector $\vec{a}$ onto $\hat{u}$ is:
$$\text{proj}_{\hat{u}}\vec{a} = \frac{\vec{a} \cdot \hat{u}}{\|\hat{u}\|^2}\hat{u} = (\vec{a} \cdot \hat{u})\hat{u}$$

By standard definition, the dot product of two $3 \times 1$ column vectors $\vec{a}$ and $\hat{u}$ can be rewritten as multiplying a row vector by a column vector:
$$(\vec{a} \cdot \hat{u}) = \hat{u}^T \vec{a}$$

Substituting this expression back into the vector projection formula gives:
$$\text{proj}_{\hat{u}}\vec{a} = (\hat{u}^T \vec{a})\hat{u} = \hat{u}(\hat{u}^T \vec{a})$$

Applying the **matrix associative property**, where $A(BC) = (AB)C$, we can group the terms to separate the vector $\vec{a}$:
$$\text{proj}_{\hat{u}}\vec{a} = (\hat{u}\hat{u}^T)\vec{a}$$

Here, the isolated term $(\hat{u}\hat{u}^T)$ is an **outer product**—a $3 \times 1$ column vector multiplied by a $1 \times 3$ row vector:
$$\hat{u}\hat{u}^T = \begin{bmatrix} u_x \\\\ u_y \\\\ u_z \end{bmatrix} \begin{bmatrix} u_x & u_y & u_z \end{bmatrix} = \begin{bmatrix} u_x^2 & u_x u_y & u_x u_z \\\\ u_x u_y & u_y^2 & u_y u_z \\\\ u_x u_z & u_y u_z & u_z^2 \end{bmatrix}$$

This outer product is also denoted as the tensor product:
$$\hat{u}\hat{u}^T = \hat{u} \otimes \hat{u}$$

This $3 \times 3$ matrix represents the **projection operator** itself. Multiplying this matrix by any vector $\vec{a}$ projects it directly onto the direction of $\hat{u}$:
$$\text{proj}_{\hat{u}}\vec{a} = \begin{bmatrix} u_x^2 & u_x u_y & u_x u_z \\\\ u_x u_y & u_y^2 & u_y u_z \\\\ u_x u_z & u_y u_z & u_z^2 \end{bmatrix}\vec{a}$$
### Geometric Representation

In 3D math and game engines, the outer product is primarily used to represent a **subspace** (like a line or a plane) in matrix form.

When you calculate the outer product of a unit vector with itself ($\hat{u}\hat{u}^T$):

* The resulting matrix represents the 1D line defined by $\hat{u}$.
* It acts as a geometric filter.
* Multiplying any coordinate by this matrix strips away all spatial data perpendicular to the line, leaving only the exact shadow (projection) that rests on the line.

---

