---
topic: Transforms
difficulty: Medium
tags: [exercise, question, skew, shear, linear-transformation]
---

# Question: Skew (Shear) in 3D Space

This exercise explores skew (shear) transformations in 3D space, focusing on algebraic matrix construction, vector calculations, and conceptual understanding of their geometric properties.

---

## Part 1: Calculation

Suppose we want to perform a skew transformation along the unit direction vector $\vec{a}$ relative to the perpendicular measurement axis $\vec{b}$, with a skew angle of $\theta = 45^\circ$:

$$
\vec{a} = \begin{bmatrix} 1 \\\\ 0 \\\\ 0 \end{bmatrix}, \quad \vec{b} = \begin{bmatrix} 0 \\\\ 1 \\\\ 0 \end{bmatrix}, \quad \theta = 45^\circ
$$

1. **Construct the Skew Matrix:** Construct the explicit $3 \times 3$ skew matrix $\mathbf{M}_{\text{skew}}(\theta, \vec{a}, \vec{b})$ using the outer-product formulation:
   $$
   \mathbf{M}_{\text{skew}}(\theta, \vec{a}, \vec{b}) = \mathbf{I} + \tan\theta \, \vec{a}\vec{b}^T
   $$
2. **Transform a Vector:** Calculate the skewed vector $\vec{v}' = \mathbf{M}_{\text{skew}}(\theta, \vec{a}, \vec{b})\vec{v}$ for the input vector:
   $$
   \vec{v} = \begin{bmatrix} 2 \\\\ 3 \\\\ 5 \end{bmatrix}
   $$
3. **Geometric Verification:** Verify the result by calculating:
   $$
   \vec{v}' = \vec{v} + (\vec{b} \cdot \vec{v})\tan\theta \, \vec{a}
   $$
   and checking that it matches your matrix multiplication result.

---

## Part 2: Conceptual Understanding

1. **Determinant of Skew:** Geometrically explain why the determinant of a skew matrix is always $+1$ in 3D space.
2. **Composition of Opposite Skews:** Prove algebraically that performing a skew of angle $\theta$ followed by a skew of angle $-\theta$ (along the same vectors $\vec{a}$ and $\vec{b}$) yields the Identity matrix $\mathbf{I}$.
3. **Orthogonality Constraint:** Why is it mathematically and geometrically required that the slide direction $\vec{a}$ and the measurement axis $\vec{b}$ are perpendicular ($\vec{a} \cdot \vec{b} = 0$)? Explain what would happen if they were parallel.

---

**Check Answer:** [[S_Skews]] | **Related Concepts:** [[05_Skews]]
