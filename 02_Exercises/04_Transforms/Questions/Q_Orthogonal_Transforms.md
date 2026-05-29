---
topic: Transforms
difficulty: Medium
tags: [exercise, question, orthogonal-matrix, similarity-transform, change-of-basis]
---
# Question: Orthogonal and Similarity Transformations

This exercise explores the geometric and algebraic properties of **orthogonal transformations** (length/angle preservation and determinants) and **similarity transformations** (changing the basis of a linear operator).

---

## Part 1: Orthogonal Transforms and Geometric Preservation
Let $\mathbf{M}$ be a $3 \times 3$ matrix representing a $45^\circ$ rotation around the z-axis:
$$\mathbf{M} = \begin{bmatrix} \frac{\sqrt{2}}{2} & -\frac{\sqrt{2}}{2} & 0 \\\\ \frac{\sqrt{2}}{2} & \frac{\sqrt{2}}{2} & 0 \\\\ 0 & 0 & 1 \end{bmatrix}$$

Suppose we have two vectors in our initial coordinate system:
$$\vec{v} = \begin{bmatrix} 2 \\\\ 2 \\\\ 1 \end{bmatrix} \quad \text{and} \quad \vec{w} = \begin{bmatrix} 0 \\\\ 4 \\\\ -3 \end{bmatrix}$$

1.  **Orthonormality:** Prove that $\mathbf{M}$ is an orthogonal matrix by checking that its columns are mutually perpendicular unit vectors, or by showing that $\mathbf{M}^T\mathbf{M} = \mathbf{I}$.
2.  **Vector Transformation:** Calculate the transformed vectors $\vec{v}' = \mathbf{M}\vec{v}$ and $\vec{w}' = \mathbf{M}\vec{w}$.
3.  **Preservation Verification:**
    *   Calculate the original dot product $\vec{v} \cdot \vec{w}$ and the transformed dot product $\vec{v}' \cdot \vec{w}'$. Verify that they are equal.
    *   Calculate the lengths $\|\vec{v}\|$ and $\|\vec{v}'\|$. Verify that they are equal.
4.  **Orientation:** Calculate $\det(\mathbf{M})$. Does this transformation represent a pure rotation or does it involve a reflection? Explain your reasoning.

---

## Part 2: Composition and Change of Basis (Similarity Transforms)
Imagine we have two coordinate systems, $A$ and $B$. Let $\mathbf{M}$ be the orthogonal matrix that transforms vectors from system $A$ to system $B$ ($\vec{p}_B = \mathbf{M}\vec{p}_A$), representing a $-90^\circ$ rotation around the z-axis:
$$\mathbf{M} = \begin{bmatrix} 0 & 1 & 0 \\\\ -1 & 0 & 0 \\\\ 0 & 0 & 1 \end{bmatrix}$$

In coordinate system $A$, we define a scaling transform $\mathbf{S}_A$ that stretches space by a factor of 3 along the local x-axis:
$$\mathbf{S}_A = \begin{bmatrix} 3 & 0 & 0 \\\\ 0 & 1 & 0 \\\\ 0 & 0 & 1 \end{bmatrix}$$

1.  **Similarity Transform:** Calculate the equivalent scaling matrix $\mathbf{S}_B$ in coordinate system $B$ using the similarity transformation formula:
    $$\mathbf{S}_B = \mathbf{M}\mathbf{S}_A\mathbf{M}^{-1}$$
    *(Hint: Since $\mathbf{M}$ is orthogonal, use its transpose for the inverse).*
2.  **Geometric Intuition:** Explain the geometric meaning of your resulting matrix $\mathbf{S}_B$. Why does stretching space along the x-axis in system $A$ correspond to this specific operation in system $B$?

---
**Check Answer:** [[S_Orthogonal_Transforms]]
