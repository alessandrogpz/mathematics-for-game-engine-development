---
topic: Vectors
difficulty: Medium
tags: [exercise, question, projection, orthogonality, linearity, idempotency]
---
# Question: Properties of Vector Projections

This exercise explores the fundamental algebraic and geometric properties of vector projections, specifically **linearity**, **orthogonal decomposition**, **scaling invariance**, and **idempotency**.

## Part 1: Calculation
Let $\vec{u} = \begin{bmatrix} 1 \\ 2 \\ -1 \end{bmatrix}$ be the vector defining our line of projection. We want to project the following vectors onto $\vec{u}$:

$$
\vec{v} = \begin{bmatrix} 3 \\\\ 0 \\\\ 1 \end{bmatrix} \quad \text{and} \quad \vec{w} = \begin{bmatrix} -1 \\\\ 4 \\\\ 2 \end{bmatrix}
$$

1. **Individual Projections:** Calculate the vector projections $\vec{p}_v = \text{proj}_{\vec{u}}\vec{v}$ and $\vec{p}_w = \text{proj}_{\vec{u}}\vec{w}$.
2. **Linearity:** Calculate the projection of their sum: $\vec{p}_{v+w} = \text{proj}_{\vec{u}}(\vec{v} + \vec{w})$. Verify that $\vec{p}_{v+w} = \vec{p}_v + \vec{p}_w$.
3. **Double Projection (Idempotency):** Let $\vec{p}_v$ be the projection vector you calculated in Step 1. Calculate the projection of $\vec{p}_v$ onto $\vec{u}$ (i.e., $\text{proj}_{\vec{u}}\vec{p}_v$). What do you observe?

---

## Part 2: Conceptual Understanding & Proofs
1. **Scaling Invariance:** Prove algebraically that the vector projection of a vector $\vec{x}$ onto a non-zero vector $\vec{y}$ is identical to the projection of $\vec{x}$ onto $c\vec{y}$ for any non-zero scalar $c \in \mathbb{R}$ ($c \neq 0$). Explain the geometric intuition behind this property.
2. **Orthogonal Decomposition:** Prove that for any vector $\vec{v}$, the "error vector" (or orthogonal component) $\vec{e} = \vec{v} - \text{proj}_{\vec{u}}\vec{v}$ is orthogonal to $\vec{u}$. Why is this property critical in vector approximation and linear regression?
3. **Idempotency:** An operator $P$ is called a *projection operator* if applying it twice has the same effect as applying it once, i.e., $P(P(\vec{x})) = P(\vec{x})$. Using the algebraic formula:
   
$$
P(\vec{x}) = \text{proj}_{\vec{u}}\vec{x} = \frac{\vec{x} \cdot \vec{u}}{\|\vec{u}\|^2}\vec{u}
$$

   Prove that the vector projection operator is idempotent.

---
**Check Answer:** [[S_Projection_Properties]] | **Related Concepts:** [[06_Vector_Projection]]

