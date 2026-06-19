---
topic: Transforms
difficulty: Medium
tags: [exercise, question, quaternions, stereographic-projection, dimension-projection]
---

# Question

## Part 1: Calculation
Suppose we have a point on a 3D unit sphere $S^2$ represented by:

$$
q = w + xi + yj = 0.6 + 0.48i + 0.64j
$$

1. Verify mathematically that $q$ has a unit magnitude ($\|q\| = 1$).
2. Calculate its stereographic projection $p$ onto the 2D $ij$-plane ($w = 0$), using the south pole $S = -1$ as the projection source.
3. Determine whether this projected point lies inside or outside the equator unit circle in the projection plane, and explain why based on the value of $w$.
4. Determine where the south pole ($w = -1, x = 0, y = 0$) projects under this mapping.

## Part 2: Conceptual Understanding
1. Under stereographic projection from the pole $w = -1$, describe where the following regions of a 4D unit hypersphere ($S^3$) map in our 3D space:
   * The 3D equator ($w = 0$).
   * The hyper-hemisphere containing the north pole $+1$ ($w > 0$).
   * The hyper-hemisphere containing the south pole $-1$ ($w < 0$).
2. Explain how a 4D rotation by the imaginary unit $i$ projects to our 3D space as a simultaneous **linear wrapping flow** along the $i$-axis, and a **pure 2D rotation** in the perpendicular $jk$-plane. (Specifically, trace what happens to points along the $i$-axis versus points in the $jk$-plane).
3. Suppose we define an unnormalized rotation axis in 3D space as:

$$
\vec{u}_{\text{raw}} = \begin{bmatrix} -2 \\\\ 2 \\\\ -1 \end{bmatrix}
$$

   * Calculate the magnitude of $\vec{u}_{\text{raw}}$.
   * Normalize $\vec{u}_{\text{raw}}$ to find the unit vector $\vec{u}$ that can be used in a unit quaternion rotation.

---
**Check Answer:** [[S_09_Quaternion_Intuition]] | **Related Concepts:** [[09_Quaternion_Intuition]]
