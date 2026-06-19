---
topic: Transforms
difficulty: Hard
tags:
  - exercise
  - question
  - rotations
  - rodrigues-rotation
  - matrix-derivation
---
# Question: 3D Rotations and Rodrigues' Rotation Formula

This exercise covers standard 3D rotation matrix calculation, vector rotation about coordinate axes, and the derivation and application of **Rodrigues' Rotation Formula** to rotate a vector about an arbitrary axis.

---

## Part 1: Coordinate Axis Rotation
Suppose we have a vector $\vec{v}$ in our standard right-handed coordinate system:

$$
\vec{v} = \begin{bmatrix} 1 \\\\ 0 \\\\ 1 \end{bmatrix}
$$

1.  **Rotation Matrix:** Write down the explicit $3 \times 3$ rotation matrix $\mathbf{M}_{\text{rot } y}$ for a positive rotation angle of $\theta = 90^\circ$ (or $\frac{\pi}{2}$ radians) about the $y$-axis.
2.  **Calculation:** Compute the rotated vector $\vec{v}' = \mathbf{M}_{\text{rot } y}\vec{v}$.
3.  **Geometric Intuition:** Explain why the resulting vector $\vec{v}'$ makes intuitive geometric sense.

---

## Part 2: Rotation About an Arbitrary Axis
We want to rotate the vector:

$$
\vec{v} = \begin{bmatrix} 1 \\\\ 0 \\\\ 1 \end{bmatrix}
$$

by $\theta = 180^\circ$ (or $\pi$ radians) about the arbitrary unit axis $\vec{a}$ defined as:

$$
\vec{a} = \begin{bmatrix} 0 \\\\ \frac{\sqrt{2}}{2} \\\\ \frac{\sqrt{2}}{2} \end{bmatrix}
$$

1.  **Component Decomposition:**
    *   Calculate the parallel component $\vec{v}_{\parallel a} = (\vec{v} \cdot \vec{a})\vec{a}$.
    *   Calculate the perpendicular component $\vec{v}_{\perp a} = \vec{v} - \vec{v}_{\parallel a}$.
2.  **Rodrigues' Rotation Formula:** Apply Rodrigues' Rotation Formula directly to compute the rotated vector $\vec{v}'$:
    
$$
\vec{v}' = \vec{v}\cos\theta + (\vec{v} \cdot \vec{a})\vec{a}(1 - \cos\theta) + (\vec{a} \times \vec{v})\sin\theta
$$

3.  **Matrix Multiplication Method:**
    *   Compute the $3 \times 3$ skew-symmetric matrix $[\vec{a}]_{\times}$ and the outer product matrix $\vec{a}\vec{a}^T$.
    *   Evaluate the complete rotation matrix $\mathbf{M}_{\text{rot}}(\theta, \vec{a})$.
    *   Multiply $\mathbf{M}_{\text{rot}}(\theta, \vec{a})\vec{v}$ to verify it yields the same rotated vector $\vec{v}'$ calculated in Step 2.

---
**Check Answer:** [[S_02_Rotations]] | **Related Concepts:** [[02_Rotations]]
