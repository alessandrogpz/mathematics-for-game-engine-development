---
topic: Matrices
difficulty: Hard
tags: [exercise, question, transformation, scaling, rotation, translation, homogeneous-coordinates]
---
# Question
## Part 1: Calculation
A 2D point is located at $(2, 1)$. Using homogeneous coordinates, its column vector is $\vec{p} = \begin{bmatrix} 2 \\ 1 \\ 1 \end{bmatrix}$. Apply the following operations mathematically in the standard SRT order (Scale, Rotate, Translate):
1. Uniform scale by 3.
2. Rotate $90^\circ$ counter-clockwise.
3. Translate by $T_x = 5$ and $T_y = -2$.

Construct the three distinct $3 \times 3$ matrices, multiply them together to create a single transformation matrix $M$, and find the final coordinates.

## Part 2: Conceptual Understanding
1. Why do we use $3 \times 3$ matrices for 2D transformations instead of $2 \times 2$? What specific transformation is made possible by the third dimension?
2. If we changed the order of operations to TRS (Translate, Rotate, Scale), would the final position of the point be the same? Why or why not?
3. What is the geometric interpretation of the determinant of the combined transformation matrix $M$ (ignoring the translation component)?

---
**Check Answer:** [[S_Matrix_Transformations]]