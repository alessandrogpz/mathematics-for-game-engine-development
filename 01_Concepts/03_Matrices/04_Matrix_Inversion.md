# Matrix Inversion

The primary purpose of a matrix inverse is to reverse a transformation. If $M$ transforms vector $\vec{v}$ into $\vec{u}$, then $M^{-1}$ transforms $\vec{u}$ back into $\vec{v}$.

## Fundamental Properties
| Property | Description |
| :--- | :--- |
| **Right Inverse** | $M M^{-1} = I$ |
| **Left Inverse** | $M^{-1} M = I$ |
| **Existence** | An inverse exists if and only if $\det(M) \neq 0$. |

## Method 1: The Adjugate Matrix Method (Laplace Inversion)

This method calculates the inverse of a matrix algebraically using the **matrix of cofactors** and its transpose, the **adjugate matrix**. It is particularly useful for $2 \times 2$ and $3 \times 3$ matrices and is the basis of Cramer's Rule.

$$
A^{-1} = \frac{1}{\det(A)} \text{adj}(A)
$$

To understand this formula, we must break down three core concepts: **minors**, **cofactors**, and the **adjugate**.

---

### 1. Minors ($M_{ij}$)
The **minor** $M_{ij}$ of an element $a_{ij}$ in an $n \times n$ matrix $A$ is the determinant of the $(n-1) \times (n-1)$ submatrix that remains after deleting the $i$-th row and $j$-th column.

For example, in a $3 \times 3$ matrix, the minor of $a_{11}$ is:

$$
A = \begin{bmatrix} \color{red}{a_{11}} & \color{gray}{a_{12}} & \color{gray}{a_{13}} \\\\ \color{gray}{a_{21}} & a_{22} & a_{23} \\\\ \color{gray}{a_{31}} & a_{32} & a_{33} \end{bmatrix} \implies M_{11} = \det\begin{bmatrix} a_{22} & a_{23} \\\\ a_{32} & a_{33} \end{bmatrix}
$$

---

### 2. Cofactors ($C_{ij}$) and the Cofactor Matrix ($C$)
A **cofactor** $C_{ij}$ is simply a "signed minor." It is obtained by multiplying the minor by a positional sign factor based on its grid position:

$$
C_{ij} = (-1)^{i+j} M_{ij}
$$

The signs follow a checkerboard pattern:

$$
\begin{bmatrix} + & - & + \\\\ - & + & - \\\\ + & - & + \end{bmatrix}
$$

The **Cofactor Matrix** $C$ is the matrix formed by replacing every element $a_{ij}$ of the original matrix $A$ with its corresponding cofactor $C_{ij}$:

$$
C = \begin{bmatrix} C_{11} & C_{12} & \dots & C_{1n} \\\\ C_{21} & C_{22} & \dots & C_{2n} \\\\ \vdots & \vdots & \ddots & \vdots \\\\ C_{n1} & C_{n2} & \dots & C_{nn} \end{bmatrix}
$$

---

### 3. The Adjugate Matrix ($\text{adj}(A)$)
The **adjugate matrix** (historically called the *adjoint matrix*) is defined as the **transpose of the cofactor matrix**:

$$
\text{adj}(A) = C^T
$$

This transposes the row and column of each cofactor, such that:

$$
[\text{adj}(A)]_{ij} = C_{ji}
$$

> [!NOTE]
> **Why do we transpose the cofactor matrix?**
> The transposition is required to satisfy the algebraic properties of Laplace expansion:
> 1.  **Row and Cofactor Dot Product:** If you multiply elements of row $i$ by the cofactors of the **same** row, you get the determinant:
>     
$$
\sum_{k=1}^n a_{ik} C_{ik} = \det(A)
$$

> 2.  **Dummy Row Expansion:** If you multiply elements of row $i$ by the cofactors of a **different** row $j$ ($i \neq j$), the result is always $0$:
>     
$$
\sum_{k=1}^n a_{ik} C_{jk} = 0
$$

> 
> To express this as a matrix multiplication $A \cdot X = \det(A)I$, the row of $A$ must multiply a column of $X$ containing that row's matching cofactors. Because the cofactors of row $i$ are written as a row in $C$, we must **transpose** $C$ to align them as a column in $C^T$.
> 
> Therefore:
> 
$$
A \cdot C^T = \det(A)I \implies A \cdot \left(\frac{1}{\det(A)} C^T\right) = I
$$

## Method 2: Gauss-Jordan Elimination
This method uses an **augmented matrix** $[M | I]$:
1. Write the matrix $M$ on the left and the identity matrix $I$ on the right.
2. Apply row operations to transform the left side into the identity matrix.
3. Apply the *same* operations to the right side simultaneously.
4. When the left side becomes $I$, the right side will have become $M^{-1}$.

### Possible Row Operations
| Operation | Effect on Determinant (Optional Info) |
| :--- | :--- |
| **Row Swap** | Swapping two rows. |
| **Scalar Mult** | Multiplying a row by a non-zero scalar. |
| **Row Addition** | Adding or subtracting a multiple of one row from another. |
