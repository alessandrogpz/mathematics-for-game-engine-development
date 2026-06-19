---
topic: Transforms
difficulty: Hard
tags:
  - exercise
  - question
  - reflections
  - plane-reflection
  - axis-reflection
---
# Question: Reflections in 3D Space

This exercise explores reflections across a plane and reflections across an axis (involution) in 3D space, focusing on algebraic derivations and geometric preservation properties.

---

## Part 1: Calculation
Suppose we have an arbitrary vector $\vec{v}$ and a unit direction vector $\vec{a}$ representing the normal of a plane passing through the origin:

$$
\vec{v} = \begin{bmatrix} 2 \\\\ -1 \\\\ 3 \end{bmatrix} \quad \text{and} \quad \vec{a} = \begin{bmatrix} 0 \\\\ 0 \\\\ 1 \end{bmatrix}
$$

1.  **Plane Reflection Matrix:** Construct the $3 \times 3$ plane reflection matrix $\mathbf{M}_{\text{reflect}}(\vec{a})$ representing a mirror reflection across the plane perpendicular to $\vec{a}$ using:
    
$$
\mathbf{M}_{\text{reflect}}(\vec{a}) = \mathbf{I} - 2\vec{a}\vec{a}^T
$$

2.  **Plane Reflection Calculation:** Multiply this matrix by $\vec{v}$ to calculate the reflected vector $\vec{v}'_{\text{plane}}$.
3.  **Axis Reflection Matrix:** Construct the $3 \times 3$ axis reflection (involution) matrix $\mathbf{M}_{\text{invol}}(\vec{a})$ representing a reflection across the line defined by $\vec{a}$ (equivalent to a $180^\circ$ rotation about $\vec{a}$) using:
    
$$
\mathbf{M}_{\text{invol}}(\vec{a}) = 2\vec{a}\vec{a}^T - \mathbf{I}
$$

4.  **Axis Reflection Calculation:** Multiply this matrix by $\vec{v}$ to calculate the reflected vector $\vec{v}'_{\text{axis}}$.

---

## Part 2: Conceptual Understanding
1.  **Determinant Intuition:** Calculate the determinants $\det\big(\mathbf{M}_{\text{reflect}}(\vec{a})\big)$ and $\det\big(\mathbf{M}_{\text{invol}}(\vec{a})\big)$ for the matrices you constructed in Part 1. Explain the geometric significance of their signs ($+1$ vs. $-1$) in 3D space.
2.  **Composition of Reflections:** What geometric transformation is produced if you perform two plane reflections consecutively across the exact same plane? Prove this algebraically by calculating the matrix product $\mathbf{M}_{\text{reflect}}(\vec{a})\mathbf{M}_{\text{reflect}}(\vec{a})$.

---
**Check Answer:** [[S_03_Reflections]] | **Related Concepts:** [[03_Reflections]]
