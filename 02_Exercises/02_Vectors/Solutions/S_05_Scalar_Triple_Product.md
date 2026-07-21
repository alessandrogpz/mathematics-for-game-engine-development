---
topic: Vectors
tags: [exercise, solution, scalar-triple-product, volume]
---

# Solution: Scalar Triple Product

This solution note provides the step-by-step calculations and conceptual answers for the scalar triple product exercise.

---

## Part 1: Calculation

We calculate the volume of the parallelepiped formed by the following three vectors:

$$
\vec{u} = \begin{bmatrix} 1 \\\\ 2 \\\\ 3 \end{bmatrix}, \quad \vec{v} = \begin{bmatrix} -1 \\\\ 1 \\\\ 2 \end{bmatrix}, \quad \vec{w} = \begin{bmatrix} 2 \\\\ 1 \\\\ 4 \end{bmatrix}
$$

The volume $V$ of a parallelepiped is given by the absolute value of the scalar triple product:

$$
V = |(\vec{u} \times \vec{v}) \cdot \vec{w}|
$$

### Step 1: Compute the Cross Product $\vec{u} \times \vec{v}$

$$
\vec{u} \times \vec{v} = \begin{bmatrix} (u_y v_z - u_z v_y) \\\\ (u_z v_x - u_x v_z) \\\\ (u_x v_y - u_y v_x) \end{bmatrix} = \begin{bmatrix} (2)(2) - (3)(1) \\\\ (3)(-1) - (1)(2) \\\\ (1)(1) - (2)(-1) \end{bmatrix} = \begin{bmatrix} 4 - 3 \\\\ -3 - 2 \\\\ 1 + 2 \end{bmatrix} = \begin{bmatrix} 1 \\\\ -5 \\\\ 3 \end{bmatrix}
$$

### Step 2: Compute the Dot Product with $\vec{w}$

$$
(\vec{u} \times \vec{v}) \cdot \vec{w} = \begin{bmatrix} 1 \\\\ -5 \\\\ 3 \end{bmatrix} \cdot \begin{bmatrix} 2 \\\\ 1 \\\\ 4 \end{bmatrix} = (1)(2) + (-5)(1) + (3)(4) = 2 - 5 + 12 = 9
$$

Since the result is positive, the signed volume is equal to the absolute volume:

$$
V = 9
$$

---

## Part 2: Conceptual Understanding

### 1. Zero Scalar Triple Product
If the scalar triple product $(\vec{u} \times \vec{v}) \cdot \vec{w} = 0$, it means that the three vectors are **coplanar** (they all lie in the same 2D plane). 
*   **Geometric reasoning**: The cross product $\vec{u} \times \vec{v}$ yields a normal vector perpendicular to the plane of $\vec{u}$ and $\vec{v}$. If the dot product of this normal vector and $\vec{w}$ is $0$, then $\vec{w}$ is orthogonal to the normal vector, meaning $\vec{w}$ must lie within the plane spanned by $\vec{u}$ and $\vec{v}$.

### 2. Matrix Determinant Equivalence
Calculating the scalar triple product is completely equivalent to calculating the determinant of the $3 \times 3$ matrix whose rows (or columns) are the three vectors:

$$
(\vec{u} \times \vec{v}) \cdot \vec{w} = \det \begin{bmatrix} u_x & u_y & u_z \\\\ v_x & v_y & v_z \\\\ w_x & w_y & w_z \end{bmatrix}
$$

*   **Geometric Intuition**: The determinant of a matrix represents the volume scaling factor of the transformation. It measures how much the unit cube is stretched/distorted by the vectors. Thus, the determinant directly measures the volume of the parallelepiped spanned by the three vectors.

### 3. Order of Operations and Cyclic Order
*   **Order of Operations**: The expression $(\vec{u} \times \vec{v}) \cdot \vec{w}$ requires the cross product to be evaluated first because $\vec{v} \cdot \vec{w}$ yields a scalar, and a cross product between a vector and a scalar ($\vec{u} \times \text{scalar}$) is undefined. However, the dot and cross operator positions can be swapped:
    
    $$
    (\vec{u} \times \vec{v}) \cdot \vec{w} = \vec{u} \cdot (\vec{v} \times \vec{w})
    $$
    
*   **Cyclic Order**: As long as the cyclic order of the vectors is preserved ($\vec{u} \to \vec{v} \to \vec{w} \to \vec{u}$), the scalar triple product remains unchanged:
    
    $$
    (\vec{u} \times \vec{v}) \cdot \vec{w} = (\vec{v} \times \vec{w}) \cdot \vec{u} = (\vec{w} \times \vec{u}) \cdot \vec{v}
    $$
    
    If the cyclic order is reversed (e.g. swapping any two vectors), the sign of the result flips:
    
    $$
    (\vec{v} \times \vec{u}) \cdot \vec{w} = -9
    $$

---
**Back to Question:** [[Q_05_Scalar_Triple_Product]] | **Related Concepts:** [[05_Scalar_Triple_Product]]