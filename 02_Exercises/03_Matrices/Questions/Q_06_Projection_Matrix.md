---
topic: Matrices
difficulty: Medium
tags: [exercise, question, projection, outer-product, matrix-representation]
---
# Question: Matrix Representation of Vector Projections

This exercise explores representing vector projections onto unit vectors using the **outer product** to form a $3 \times 3$ projection matrix.

---

## Part 1: Calculation
We are given a unit direction vector $\hat{u}$ and an arbitrary vector $\vec{a}$:

$$
\hat{u} = \begin{bmatrix} \frac{3}{5} \\\\ 0 \\\\ \frac{4}{5} \end{bmatrix} \quad \text{and} \quad \vec{a} = \begin{bmatrix} 2 \\\\ 5 \\\\ -1 \end{bmatrix}
$$

1.  **Outer Product Matrix Construction:** Compute the $3 \times 3$ projection matrix $\mathbf{P}$ representing the projection operator onto $\hat{u}$ using the outer product formula:
    
$$
\mathbf{P} = \hat{u}\hat{u}^T
$$

2.  **Matrix Projection Calculation:** Multiply this matrix by $\vec{a}$ to calculate the projected vector:
    
$$
\vec{p} = \mathbf{P}\vec{a}
$$

3.  **Classical Formula Verification:** Calculate the same vector projection using the classical dot product formula:
    
$$
\text{proj}_{\hat{u}}\vec{a} = (\vec{a} \cdot \hat{u})\hat{u}
$$

    Verify that both methods yield the exact same resulting vector.

---

## Part 2: Conceptual Understanding
1.  **Subspace Representation:** Explain geometrically what the $3 \times 3$ matrix $\mathbf{P} = \hat{u}\hat{u}^T$ represents and how it behaves as a "spatial filter."
2.  **Determinant of a Projection Matrix:** Calculate or argue what the determinant of $\mathbf{P}$ must be ($\det(\mathbf{P})$). Why is this result geometrically intuitive?
3.  **Trace of a Projection Matrix:** Find the trace of $\mathbf{P}$ (the sum of its diagonal entries). How does the trace of a projection matrix relate to the dimension of the subspace it projects onto?

---
**Check Answer:** [[S_06_Projection_Matrix]] | **Related Concepts:** [[06_Projection_Matrices]]
