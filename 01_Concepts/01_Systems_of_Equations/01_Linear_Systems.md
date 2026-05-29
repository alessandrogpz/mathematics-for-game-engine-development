# Systems of Linear Equations

A system of linear equations is a collection of one or more linear equations involving the same set of variables.

## Matrix Representation
A system of $m$ equations with $n$ variables can be written as $A\vec{x} = \vec{b}$:
$$\begin{bmatrix} a_{11} & a_{12} & \dots & a_{1n} \\\\ a_{21} & a_{22} & \dots & a_{2n} \\\\ \vdots & \vdots & \ddots & \vdots \\\\ a_{m1} & a_{m2} & \dots & a_{mn} \end{bmatrix} \begin{bmatrix} x_1 \\\\ x_2 \\\\ \vdots \\\\ x_n \end{bmatrix} = \begin{bmatrix} b_1 \\\\ b_2 \\\\ \vdots \\\\ b_m \end{bmatrix}$$
- $A$ is the **coefficient matrix**.
- $\vec{x}$ is the **variable vector**.
- $\vec{b}$ is the **constant vector**.

## Augmented Matrix
To solve the system, we often combine $A$ and $\vec{b}$ into an **augmented matrix**:
$$[A | \vec{b}] = \begin{bmatrix} a_{11} & a_{12} & \dots & a_{1n} & | & b_1 \\\\ a_{21} & a_{22} & \dots & a_{2n} & | & b_2 \\\\ \vdots & \vdots & \ddots & \vdots & | & \vdots \\\\ a_{m1} & a_{m2} & \dots & a_{mn} & | & b_m \end{bmatrix}$$

## Types of Solutions
1. **Consistent System:** Has at least one solution.
   - **Unique Solution:** Exactly one point of intersection.
   - **Infinitely Many Solutions:** The equations represent the same line/plane (dependent).
2. **Inconsistent System:** Has no solution (parallel lines/planes that never meet).

## Solving Methods
- **Gaussian Elimination:** Transform the augmented matrix into **Row Echelon Form (REF)** using row operations.
- **Gauss-Jordan Elimination:** Transform the augmented matrix into **Reduced Row Echelon Form (RREF)**.
- **Matrix Inverse:** If $A$ is square and invertible, $\vec{x} = A^{-1}\vec{b}$.
- **Cramer's Rule:** Uses determinants (useful for small systems).
