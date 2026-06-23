---
topic: Transforms
difficulty: Medium
tags: [exercise, question, quaternions, rotation, sandwich-product, inverse]
---

# Question

## Part 1: Calculation

### 1. Quaternion Multiplication (Grassmann Product)
Given two quaternions:

$$
q_1 = 1 + 2i - j + k
$$

$$
q_2 = 2 - i + 2j - k
$$

1. Compute the product $q_1 q_2$ using the vector-based Grassmann product formula:

$$
q_1 q_2 = (s_1 s_2 - \vec{v}_1 \cdot \vec{v}_2) + (s_1 \vec{v}_2 + s_2 \vec{v}_1 + \vec{v}_1 \times \vec{v}_2)
$$

2. Show that quaternion multiplication is non-commutative by computing $q_2 q_1$ and verifying that $q_1 q_2 \neq q_2 q_1$.

### 2. Magnitude and Multiplicative Inverse
For the quaternion $q_1 = 1 + 2i - j + k$:
1. Calculate its magnitude $\|q_1\|$.
2. Calculate its multiplicative inverse $q_1^{-1}$ using the formula:

$$
q_1^{-1} = \frac{q_1^*}{\|q_1\|^2}
$$

### 3. 3D Vector Rotation
Suppose we want to rotate a 3D vector $\vec{v} = \begin{bmatrix} 0 \\\\ 1 \\\\ 0 \end{bmatrix}$ by an angle $\theta = 90^\circ$ counterclockwise around the normalized vertical axis $\vec{u} = \begin{bmatrix} 0 \\\\ 0 \\\\ 1 \end{bmatrix}$ (the $z$-axis).
1. Construct the unit rotation quaternion $q$ using the formula:

$$
q = \cos\left(\frac{\theta}{2}\right) + \vec{u}\sin\left(\frac{\theta}{2}\right)
$$

2. Represent $\vec{v}$ as a pure quaternion $p$.
3. Compute the rotated vector using the sandwich product formula:

$$
p' = q p q^{-1}
$$

Verify that the scalar part of the resulting quaternion $p'$ is exactly $0$, and extract the rotated 3D vector $\vec{v}'$.

---

## Part 2: Conceptual Understanding

### 1. Hamilton's Identities & Cyclic Rules
Hamilton's fundamental identities are defined as:

$$
i^2 = j^2 = k^2 = ijk = -1
$$

Using only these identities (specifically $ijk = -1$ and properties of imaginary units), prove mathematically that:
1. $ij = k$
2. $ji = -k$

### 2. Why Single Multiplication Fails
Explain why a single quaternion multiplication (e.g., $p' = qp$) cannot be used to rotate a 3D vector $\vec{v}$. Provide:
1. **An Algebraic Explanation:** Show what happens to the scalar part of the Grassmann product when we compute $qp$.
2. **A Geometric Explanation:** Explain the effect of a 4D rotation on the extra real dimension, and how the sandwich product acts as a geometric correction.

### 3. The Half-Angle Origin
Explain why we construct the rotation quaternion using the half-angle $\frac{\theta}{2}$ in $q = \cos(\theta/2) + \vec{u}\sin(\theta/2)$ instead of the full angle $\theta$. How does this relate to the double multiplication in the sandwich product $qpq^{-1}$?

---
**Check Answer:** [[S_10_Quaternions]] | **Related Concepts:** [[10_Quaternions]]
