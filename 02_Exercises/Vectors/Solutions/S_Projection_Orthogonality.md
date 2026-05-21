# Solution: Vector Projections & Orthogonality

## Part 1: Calculation
$\vec{a} = (3, -1, 2)$, $\vec{b} = (1, 2, 2)$

1. **Dot Product:** $\vec{a} \cdot \vec{b} = (3)(1) + (-1)(2) + (2)(2) = 3 - 2 + 4 = 5$
2. **Magnitude squared of b:** $\|\vec{b}\|^2 = 1^2 + 2^2 + 2^2 = 9$
3. **Scalar Projection:** $\text{comp}_{\vec{b}}\vec{a} = \frac{5}{\sqrt{9}} = \frac{5}{3}$
4. **Vector Projection:** $\text{proj}_{\vec{b}}\vec{a} = \frac{5}{9}(1, 2, 2) = (\frac{5}{9}, \frac{10}{9}, \frac{10}{9})$
5. **Vector c:** $\vec{c} = (3, -1, 2) - (\frac{5}{9}, \frac{10}{9}, \frac{10}{9}) = (\frac{22}{9}, -\frac{19}{9}, \frac{8}{9})$

## Part 2: Conceptual Understanding
1. **Orthogonality Check:** $\vec{c} \cdot \vec{b} = \frac{1}{9}(22(1) - 19(2) + 8(2)) = \frac{1}{9}(22 - 38 + 16) = \frac{0}{9} = 0$. Confirmed.
2. **Interpretation:** $\vec{c}$ is the component of $\vec{a}$ **perpendicular** to $\vec{b}$. We have decomposed $\vec{a}$ into two orthogonal parts: one parallel to $\vec{b}$ ($\text{proj}_{\vec{b}}\vec{a}$) and one perpendicular to $\vec{b}$ ($\vec{c}$).
3. **Negative Dot Product:** The projection would point in the opposite direction of $\vec{b}$ (the angle $\theta$ is obtuse).
