---
topic: Geometry
difficulty: Medium
tags: [exercise, question, normal-vector, cross-product, normal-transformation]
---
# Question
## Part 1: Calculation
A triangular mesh face lies entirely in the plane $x = 2$, with vertices $P_0 = (2, 0, 0)$, $P_1 = (2, 3, 0)$, and $P_2 = (2, 0, 4)$.

1. Calculate the edge vectors $\vec{P_0P_1}$ and $\vec{P_0P_2}$.
2. Compute the face normal $\vec{N} = \vec{P_0P_1} \times \vec{P_0P_2}$, its magnitude $\|\vec{N}\|$, and the unit normal $\hat{n}$.
3. Use $\|\vec{N}\|$ to compute the area of the triangle.
4. If the vertices were instead wound in the order $P_0, P_2, P_1$, what would the resulting normal be? What does this demonstrate about the importance of consistent winding order across a mesh?

## Part 2: Conceptual Understanding
Consider the same face and its unit normal $\hat{n}$ from Part 1. The mesh is transformed by the shear matrix:

$$
\mathbf{M} = \begin{bmatrix} 1 & 0 & 0 \\\\ 1 & 1 & 0 \\\\ 0 & 0 & 1 \end{bmatrix}
$$

1. Compute the naively transformed normal $\mathbf{M}\hat{n}$, and show that it fails to remain orthogonal to the face's (unchanged) edge vectors from Part 1.
2. Compute $\mathbf{M}^{-1}$ and use it to find the correctly transformed normal $(\mathbf{M}^{-1})^T \hat{n}$. Verify that it is orthogonal to both edge vectors.
3. If instead this face were transformed by the reflection $\mathbf{M} = \text{diag}(1, -1, 1)$, would the $\text{sign}(\det(\mathbf{M}))$ correction described in [[02_Normal_Vectors]] be necessary? Justify your answer using $\det(\mathbf{M})$.

---
**Check Answer:** [[S_02_Normal_Vectors]] | **Related Concepts:** [[02_Normal_Vectors]]
