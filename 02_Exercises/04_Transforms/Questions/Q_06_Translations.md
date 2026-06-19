---
topic: Transforms
difficulty: Medium
tags: [exercise, question, translations, homogeneous-coordinates, affine-transformation]
---
# Question

## Part 1: Calculation
Suppose we have a translation vector $\vec{t}$, a point in space $\vec{p}$, and a direction vector $\vec{d}$:

$$
\vec{t} = \begin{bmatrix} 3 \\\\ -2 \\\\ 4 \end{bmatrix}, \quad \vec{p} = \begin{bmatrix} 1 \\\\ 2 \\\\ 3 \\\\ 1 \end{bmatrix}, \quad \vec{d} = \begin{bmatrix} 1 \\\\ 2 \\\\ 3 \\\\ 0 \end{bmatrix}
$$

1. **Construct the Translation Matrix:** Construct the $4 \times 4$ homogeneous translation matrix $\mathbf{T}(\vec{t})$ representing this translation.
2. **Point Translation:** Multiply $\mathbf{T}(\vec{t})$ by the point $\vec{p}$ to calculate the translated point $\vec{p}'$.
3. **Vector Translation:** Multiply $\mathbf{T}(\vec{t})$ by the direction vector $\vec{d}$ to calculate the translated vector $\vec{d}'$. Confirm whether the vector's coordinates changed.
4. **Inverse Translation:** Construct the inverse translation matrix $\mathbf{T}(\vec{t})^{-1}$ and multiply it by $\vec{p}'$ to show that it restores the original point $\vec{p}$.

## Part 2: Conceptual Understanding
1. Explain algebraically and geometrically the difference in behavior between points ($w = 1$) and vectors ($w = 0$) under translation.

---
**Check Answer:** [[S_06_Translations]] | **Related Concepts:** [[06_Translations]]
