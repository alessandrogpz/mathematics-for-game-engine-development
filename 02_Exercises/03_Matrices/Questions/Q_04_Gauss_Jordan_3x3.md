---
topic: Matrices
difficulty: Medium
tags: [exercise, question, gauss-jordan, inverse, identity-matrix]
---
# Question
## Part 1: Calculation
Set up an augmented matrix $[A | I]$ and use Gauss-Jordan elimination row operations to find the inverse of matrix $A$:

$$
A = \begin{bmatrix} 1 & 0 & 2 \\\\ 0 & 1 & 0 \\\\ 3 & 0 & 1 \end{bmatrix}
$$

## Part 2: Conceptual Understanding
1. During the Gauss-Jordan process, if you encounter a row of zeros on the left side, what does that imply about the matrix $A$ and its determinant?
2. Explain why the augmented matrix approach $[A | I] \to [I | A^{-1}]$ works. What fundamental property of matrix multiplication are we exploiting?
3. If $A$ is an $n \times n$ matrix, how many row operations (at most) would you expect to perform to reach the identity matrix?

---
**Check Answer:** [[S_04_Gauss_Jordan_3x3]] | **Related Concepts:** [[03_Matrices]]