---
topic: Transforms
difficulty: Medium
tags: [exercise, question, homogeneous-coordinates, projective-space, projective-geometry]
---
# Question

## Part 1: Calculation and Conversions
1. **Homogeneous to Euclidean Conversion:** Convert the following 4D homogeneous coordinates to 3D Euclidean coordinates:
   
$$
\vec{a}_h = \begin{bmatrix} 4 \\\\ -8 \\\\ 12 \\\\ 2 \end{bmatrix}, \quad \vec{b}_h = \begin{bmatrix} -2 \\\\ 4 \\\\ -6 \\\\ -1 \end{bmatrix}, \quad \vec{c}_h = \begin{bmatrix} 5 \\\\ 3 \\\\ -1 \\\\ 0 \end{bmatrix}
$$
   
   Verify if $\vec{a}_h$ and $\vec{b}_h$ represent the same point in 3D Euclidean space, and describe what $\vec{c}_h$ represents geometrically.

2. **Euclidean to Homogeneous Representation:** For the 3D Euclidean point $P(3, -2, 5)$, write three distinct 4D homogeneous coordinate vectors that represent it.

3. **High-Dimensional Translation Calculation:** 
   Consider a point $P$ in 3D space with homogeneous coordinates $\vec{p}_h = [3, -6, 9, 3]^T$. We want to translate this point by the vector $\vec{t} = [2, -1, 4]^T$.
   - Find the Euclidean coordinates of $P$.
   - Construct the $4 \times 4$ homogeneous translation matrix $\mathbf{T}(\vec{t})$.
   - Multiply $\mathbf{T}(\vec{t})$ by $\vec{p}_h$ to find the translated homogeneous vector $\vec{p}'_h$.
   - Perform homogeneous division on $\vec{p}'_h$ to find the final translated Euclidean coordinates, and show that they match standard vector addition $P + \vec{t}$.

## Part 2: Conceptual Understanding
1. Explain geometrically why scale invariance ($[x, y, z, w]^T \equiv [kx, ky, kz, kw]^T$ for $k \neq 0$) means that a single point in 3D Euclidean space corresponds to a line (ray) in 4D space.
2. In computer graphics, how do we mathematically distinguish a point from a direction vector using homogeneous coordinates? Why are direction vectors invariant under translation matrices?

---
**Check Answer:** [[S_Homogeneous_Coordinates]] | **Related Concepts:** [[07_Homogeneous_Coordinates]]
