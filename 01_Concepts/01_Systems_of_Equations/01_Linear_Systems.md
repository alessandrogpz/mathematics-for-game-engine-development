# Systems of Linear Equations

A system of linear equations is a collection of one or more linear equations involving the same set of variables.

## Matrix Representation
A system of $m$ equations with $n$ variables can be written as $A\vec{x} = \vec{b}$:

$$
\begin{bmatrix} a_{11} & a_{12} & \dots & a_{1n} \\\\ a_{21} & a_{22} & \dots & a_{2n} \\\\ \vdots & \vdots & \ddots & \vdots \\\\ a_{m1} & a_{m2} & \dots & a_{mn} \end{bmatrix} \begin{bmatrix} x_1 \\\\ x_2 \\\\ \vdots \\\\ x_n \end{bmatrix} = \begin{bmatrix} b_1 \\\\ b_2 \\\\ \vdots \\\\ b_m \end{bmatrix}
$$

- $A$ is the **coefficient matrix**.
- $\vec{x}$ is the **variable vector**.
- $\vec{b}$ is the **constant vector**.

## Augmented Matrix
To solve the system, we often combine $A$ and $\vec{b}$ into an **augmented matrix**:

$$
[A | \vec{b}] = \begin{bmatrix} a_{11} & a_{12} & \dots & a_{1n} & | & b_1 \\\\ a_{21} & a_{22} & \dots & a_{2n} & | & b_2 \\\\ \vdots & \vdots & \ddots & \vdots & | & \vdots \\\\ a_{m1} & a_{m2} & \dots & a_{mn} & | & b_m \end{bmatrix}
$$

## Ranks and System Consistency

The **rank** of a matrix is the maximum number of linearly independent row (or column) vectors it contains. Geometrically, it represents the dimensionality of the vector space spanned by its rows or columns. 

Practically, the rank is the number of **non-zero rows** after reducing the matrix to Row Echelon Form (REF).

### Rouché–Capelli Theorem

For any system of linear equations $A\vec{x} = \vec{b}$ with $n$ variables:

1. **Inconsistent System (No Solution):**
   The system is inconsistent if the rank of the coefficient matrix is less than the rank of the augmented matrix:
   
   $$
   \text{rank}(A) < \text{rank}([A | \vec{b}])
   $$
   
   *This occurs when row reduction yields a contradictory row, such as $[0 \ 0 \ \dots \ 0 \ | \ c]$ where $c \neq 0$ (implying $0 = c$).*

2. **Consistent System (At Least One Solution):**
   The system is consistent if and only if the rank of the coefficient matrix equals the rank of the augmented matrix:
   
   $$
   \text{rank}(A) = \text{rank}([A | \vec{b}]) = r
   $$
   
   - **Unique Solution:** Occurs when the rank $r$ equals the number of variables $n$ ($r = n$). There are no free variables.
   - **Infinitely Many Solutions:** Occurs when the rank $r$ is less than the number of variables $n$ ($r < n$). The system has $n - r$ free variables (degrees of freedom).

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

---

## Code Implementation

*   **C++ Source Code:** [[03_Code/01_Systems_of_Equations/01_Linear_Systems.cppm|01_Linear_Systems.cppm]]
