---
topic: Geometry
difficulty: Medium
tags: [exercise, question, parametric-line, skew-lines, line-distance]
---
# Question
## Part 1: Calculation
1. A parametric ray is defined by $L(t) = P + t \mathbf{v}$, where $P = (1, 2, 3)$ and $\mathbf{v} = \langle 2, -1, 2 \rangle$.
   * Calculate the coordinates of the point on the line corresponding to parameter $t = 3$.
   * Find the unit direction vector $\hat{v}$ parallel to the line.

2. Given a point $q = (4, 5, 6)$ and a parametric line $L(t) = P + t \mathbf{v}$ with $P = (1, 1, 1)$ and $\mathbf{v} = \langle 1, 0, 0 \rangle$:
   * Construct the displacement vector $\mathbf{u} = q - P$.
   * Compute the shortest distance $d$ from point $q$ to the line using both the **Rejection method** and the **Parallelogram area method**, verifying that both yield the same result.

3. Consider two 3D lines $L_1(t_1) = P_1 + t_1 \mathbf{v}_1$ and $L_2(t_2) = P_2 + t_2 \mathbf{v}_2$ with direction vectors $\mathbf{v}_1 = \langle 1, 2, 0 \rangle$ and $\mathbf{v}_2 = \langle 2, 4, 0 \rangle$.
   * Evaluate the quantity $(\mathbf{v}_1 \cdot \mathbf{v}_2)^2 - \mathbf{v}_1^2 \mathbf{v}_2^2$.
   * What does this result indicate about the relative orientation of the two lines?

## Part 2: Conceptual Understanding
1. Explain why two non-parallel lines in 2D space always intersect, whereas two non-parallel lines in 3D space might **not** intersect (forming skew lines).
2. When solving for the parameters $t_1, t_2$ of closest approach between two 3D lines, the matrix system involves the term $(\mathbf{v}_1 \cdot \mathbf{v}_2)^2 - \mathbf{v}_1^2 \mathbf{v}_2^2$ in its denominator. Explain geometrically why this denominator becomes zero when the lines are parallel.
3. In computer graphics applications, why is the point-to-line distance formula often written as $d = \sqrt{\frac{(\mathbf{u} \times \mathbf{v})^2}{v^2}}$ rather than $d = \frac{\|\mathbf{u} \times \mathbf{v}\|}{\|\mathbf{v}\|}$?

---
**Check Answer:** [[S_03_Lines_and_Rays]] | **Related Concepts:** [[03_Lines_and_Rays]]
