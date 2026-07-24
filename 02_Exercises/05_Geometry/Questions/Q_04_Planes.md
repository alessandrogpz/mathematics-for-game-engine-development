---
topic: Geometry
difficulty: Medium
tags: [exercise, question, planes, parametric-plane, implicit-plane]
---
# Question
## Part 1: Calculation
1. A parametric plane passes through starting position $\mathbf{p} = (1, 2, 3)$ with direction vectors $\mathbf{u} = \langle 1, 0, 2 \rangle$ and $\mathbf{v} = \langle 0, 3, 1 \rangle$:
   * Write down the parametric equation $Q(s, t)$ for this plane.
   * Compute the normal vector $\mathbf{n} = \mathbf{u} \times \mathbf{v}$.

2. A plane has a known point $\mathbf{q} = (2, -1, 4)$ lying on its surface and normal vector $\mathbf{n} = \langle 2, 3, -1 \rangle$:
   * Calculate the plane constant $d = -\mathbf{n} \cdot \mathbf{q}$.
   * Write down the implicit equation of the plane in the form $\mathbf{n} \cdot \mathbf{p} + d = 0$.
   * Represent the plane as a 4D vector $\mathbf{f} = [n_x, n_y, n_z, d]$.
   * Test whether the point $\mathbf{p}_1 = (1, 2, 2)$ lies on the plane by evaluating the 4D dot product $\mathbf{f} \cdot \mathbf{p}_1$.

## Part 2: Conceptual Understanding
1. Explain why two non-parallel direction vectors $\mathbf{u}$ and $\mathbf{v}$ are required to represent a parametric plane, whereas a parametric line requires only a single direction vector.
2. In implicit plane representation, explain why the quantity $d = -\mathbf{n} \cdot \mathbf{q}$ evaluates to the exact same constant value for every point $\mathbf{q}$ lying on the plane.
3. Why do 3D graphics applications and game engines prefer the 4D implicit representation $\mathbf{f} = [n_x, n_y, n_z, d]$ over storing an explicit reference point $\mathbf{q}$ and normal $\mathbf{n}$?

---
**Check Answer:** [[S_04_Planes]] | **Related Concepts:** [[04_Planes]]
