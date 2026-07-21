---
topic: Vectors
tags: [exercise, solution, cross-product, triangle-area]
---

# Solution: Cross Product

This solution note provides the step-by-step calculations and conceptual answers for the cross product exercise.

---

## Part 1: Calculation

A triangle is defined in 3D space by the points $A(1, 0, 1)$, $B(3, 2, 1)$, and $C(1, 2, 3)$.

### 1. Calculate vectors $\vec{AB}$ and $\vec{AC}$
Subtract the coordinates of the starting point from the ending point:

$$
\vec{AB} = B - A = (3 - 1, \, 2 - 0, \, 1 - 1) = (2, \, 2, \, 0)
$$

$$
\vec{AC} = C - A = (1 - 1, \, 2 - 0, \, 3 - 1) = (0, \, 2, \, 2)
$$

Thus, the vectors are:

$$
\vec{AB} = \begin{bmatrix} 2 \\\\ 2 \\\\ 0 \end{bmatrix}, \quad \vec{AC} = \begin{bmatrix} 0 \\\\ 2 \\\\ 2 \end{bmatrix}
$$

### 2. Compute their cross product $\vec{AB} \times \vec{AC}$
Using the algebraic formula for the cross product:

$$
\vec{a} \times \vec{b} = \begin{bmatrix} a_y b_z - a_z b_y \\\\ a_z b_x - a_x b_z \\\\ a_x b_y - a_y b_x \end{bmatrix}
$$

Applying this to our vectors:

$$
\vec{AB} \times \vec{AC} = \begin{bmatrix} (2)(2) - (0)(2) \\\\ (0)(0) - (2)(2) \\\\ (2)(2) - (2)(0) \end{bmatrix} = \begin{bmatrix} 4 - 0 \\\\ 0 - 4 \\\\ 4 - 0 \end{bmatrix} = \begin{bmatrix} 4 \\\\ -4 \\\\ 4 \end{bmatrix}
$$

So the cross product is:

$$
\vec{AB} \times \vec{AC} = 4\hat{i} - 4\hat{j} + 4\hat{k}
$$

### 3. Use the result to find the area of the triangle
The area of the triangle is equal to half the magnitude of the cross product of its spanning vectors:

$$
\text{Area} = \frac{1}{2} \|\vec{AB} \times \vec{AC}\|
$$

First, compute the magnitude of $\vec{AB} \times \vec{AC}$:

$$
\|\vec{AB} \times \vec{AC}\| = \sqrt{4^2 + (-4)^2 + 4^2} = \sqrt{16 + 16 + 16} = \sqrt{48} = 4\sqrt{3}
$$

Now calculate the area:

$$
\text{Area} = \frac{1}{2} (4\sqrt{3}) = 2\sqrt{3} \approx 3.464
$$

---

## Part 2: Conceptual Understanding

### 1. Reversing the order ($\vec{AC} \times \vec{AB}$)
If we calculate $\vec{AC} \times \vec{AB}$ instead, the resulting vector will point in the **opposite direction** (negated components):

$$
\vec{AC} \times \vec{AB} = -(\vec{AB} \times \vec{AC}) = \begin{bmatrix} -4 \\\\ 4 \\\\ -4 \end{bmatrix}
$$

This demonstrates that the cross product is **anti-commutative**:

$$
\vec{a} \times \vec{b} = -(\vec{b} \times \vec{a})
$$

### 2. Geometric relation to the magnitude & the factor of $1/2$
*   **Parallelogram Area**: The magnitude of the cross product $\|\vec{a} \times \vec{b}\|$ represents the exact area of the parallelogram formed by vectors $\vec{a}$ and $\vec{b}$.
*   **Factor of $1/2$**: A triangle formed by connecting the endpoints of the two vectors is exactly half of the area of that parallelogram. Thus, we halve the magnitude to find the triangle's area.
*   **Cross Product Vector**: The cross product itself yields a third vector perpendicular (orthogonal) to the plane containing the original two vectors.

### 3. Cross Product in 2D Space
Strictly speaking, the mathematical cross product is only defined for **3D vectors** (resulting in a 3D vector). It does not exist as a binary vector operation in 2D space.
*   **In 2D Physics/Graphics**: We often define a pseudo 2D cross product of two vectors $\vec{u} = (u_x, u_y)$ and $\vec{v} = (v_x, v_y)$ that yields a **scalar**:
    
    $$
    \vec{u} \times_{\text{2D}} \vec{v} = u_x v_y - u_y v_x
    $$
    
    This scalar represents the signed area of the 2D parallelogram, and corresponds to the $z$-component of a 3D cross product if the 2D vectors were placed in the $xy$-plane (with $z = 0$).

---
**Back to Question:** [[Q_04_Cross_Product]] | **Related Concepts:** [[04_Cross_Product]]