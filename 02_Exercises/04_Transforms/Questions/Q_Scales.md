---
topic: Transforms
difficulty: Medium
tags: [exercise, question, scaling, arbitrary-scale, uniform-scale]
---

# Question: Scaling in 3D Space

This exercise explores uniform, non-uniform, and arbitrary scaling in 3D space, focusing on algebraic matrix construction, vector calculations, and conceptual operator connections.

---

## Part 1: Calculation

Suppose we want to scale space by a factor of $s = 3$ along the arbitrary axis defined by the unit vector:

$$
\vec{a} = \begin{bmatrix} 0 \\\\ \frac{\sqrt{2}}{2} \\\\ \frac{\sqrt{2}}{2} \end{bmatrix}
$$

1. **Construct the Scale Matrix:** Construct the explicit $3 \times 3$ arbitrary scale matrix $\mathbf{M}_{\text{scale}}(s, \vec{a})$ using the outer-product formulation:
   $$
   \mathbf{M}_{\text{scale}}(s, \vec{a}) = \mathbf{I} + (s-1)\vec{a}\vec{a}^T
   $$
2. **Transform a Vector:** Calculate the scaled vector $\vec{v}' = \mathbf{M}_{\text{scale}}(s, \vec{a})\vec{v}$ for the input vector:
   $$
   \vec{v} = \begin{bmatrix} 4 \\\\ 1 \\\\ -1 \end{bmatrix}
   $$
3. **Geometric Verification:** Calculate the parallel component $\vec{v}_{\parallel a}$ and perpendicular component $\vec{v}_{\perp a}$ of $\vec{v}$ relative to $\vec{a}$, and verify that:
   $$
   \vec{v}' = s\vec{v}_{\parallel a} + \vec{v}_{\perp a}
   $$
   matches the matrix-vector multiplication result from Step 2.

---

## Part 2: Conceptual Understanding

1. **Determinant of Scaling:** Explain geometrically why the determinant of the arbitrary scaling matrix $\mathbf{M}_{\text{scale}}(s, \vec{a})$ is exactly $s$.
2. **Operator Unification ($s = 0$):** What transformation is produced if you set the scale factor $s = 0$? Write down the resulting matrix equation and identify its geometric relationship to vector projections.
3. **Operator Unification ($s = -1$):** What transformation is produced if you set the scale factor $s = -1$? Compare the resulting matrix formula to the plane reflection matrix $\mathbf{M}_{\text{reflect}}(\vec{a})$.

---

**Check Answer:** [[S_Scales]] | **Related Concepts:** [[04_Scales]]
