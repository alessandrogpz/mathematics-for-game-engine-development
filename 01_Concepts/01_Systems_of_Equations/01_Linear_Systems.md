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

### Elementary Row Operations
To solve a linear system using matrix-based methods, we use three types of **elementary row operations** that do not alter the solution set of the system:
1. **Row Swapping:** Swap the positions of two rows ($R_i \leftrightarrow R_j$).
2. **Row Scaling:** Multiply all entries of a row by a non-zero scalar ($R_i \leftarrow cR_i$).
3. **Row Addition/Subtraction:** Add or subtract a multiple of one row to another ($R_i \leftarrow R_i + cR_j$).

---

### 1. Gaussian Elimination & Row Echelon Form (REF)

**Gaussian Elimination** is the algorithm that performs forward elimination to transform an augmented matrix into **Row Echelon Form (REF)**.

A matrix is in **Row Echelon Form (REF)** if it satisfies the following conditions:
*   All rows consisting entirely of zeros are at the bottom of the matrix.
*   The leading entry (the first non-zero number from the left, also called the pivot) of a row is strictly to the right of the leading entry of the row above it.
*   All entries in a column below a leading entry are zero.

For example, a matrix in REF looks like:

$$
\begin{bmatrix}
\mathbf{1} & 2 & 3 & 4 \\\\
0 & \mathbf{5} & 6 & 7 \\\\
0 & 0 & 0 & \mathbf{8} \\\\
0 & 0 & 0 & 0
\end{bmatrix}
$$

*Once a matrix is in REF, the system is solved using **backward substitution** (solving for the last variable first and substituting it back into the equations above).*

---

### 2. Gauss-Jordan Elimination & Reduced Row Echelon Form (RREF)

**Gauss-Jordan Elimination** extends Gaussian elimination by performing backward elimination to transform the matrix into **Reduced Row Echelon Form (RREF)**.

A matrix is in **Reduced Row Echelon Form (RREF)** if it satisfies all conditions of REF, plus:
*   The leading entry in every non-zero row is exactly **1** (called a leading 1).
*   Each leading 1 is the **only non-zero entry** in its column.

For example, a matrix in RREF looks like:

$$
\begin{bmatrix}
\mathbf{1} & 0 & 3 & 0 \\\\
0 & \mathbf{1} & 6 & 0 \\\\
0 & 0 & 0 & \mathbf{1} \\\\
0 & 0 & 0 & 0
\end{bmatrix}
$$

*When a system has a unique solution, its coefficient part in RREF becomes the identity matrix ($I$), and the constant column directly reveals the values of the variables without needing backward substitution.*

---

### 3. Other Methods
- **[[04_Matrix_Inversion|Matrix Inverse]]**: If $A$ is square and invertible, the system can be solved directly via $\vec{x} = A^{-1}\vec{b}$.
- **Cramer's Rule:** Uses [[03_Determinants|determinants]] to compute each variable individually (best suited for small systems).

---

## Code Implementation

*   **C++ Source Code:** [[03_Code/01_Systems_of_Equations/Linear_Systems.cppm|Linear_Systems.cppm]]
