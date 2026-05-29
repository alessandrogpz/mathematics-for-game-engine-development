# Matrix Determinants

The determinant is a scalar value that can be thought of as a "magnitude" for a square matrix. A matrix has an inverse if and only if its determinant is non-zero.

## 2x2 Matrix
For $A = \begin{bmatrix} a & b \\ c & d \end{bmatrix}$:

$$
\det(A) = ad - bc
$$

## 3x3 Matrix (Rule of Sarrus)
For $A = \begin{bmatrix} a & b & c \\ d & e & f \\ g & h & i \end{bmatrix}$:

$$
\det(A) = (aei + bfg + cdh) - (ceg + bdi + afh)
$$

## Laplace Expansion (Cofactor Expansion)
This method can be used for any $n \times n$ matrix. You choose any row or column and sum the products of its elements and their corresponding cofactors.

$$
\det(A) = \sum_{j=1}^n A_{ij} C_{ij}
$$

Where $C_{ij} = (-1)^{i+j} M_{ij}$, and $M_{ij}$ is the **minor** (the determinant of the submatrix after removing row $i$ and column $j$).

### Sign Table for Cofactors

$$
\begin{bmatrix} + & - & + \\\\ - & + & - \\\\ + & - & + \end{bmatrix}
$$

## Gauss-Jordan Elimination Method
You can transform a matrix into **row echelon form** using row operations. The determinant is then the product of the diagonal elements, adjusted for the operations performed:
1. **Row Swap:** Multiplies the determinant by $-1$.
2. **Row Addition:** Adding a multiple of one row to another does **not** change the determinant.
3. **Scalar Multiplication:** Multiplying a row by a scalar $k$ multiplies the determinant by $k$.

## Properties of Determinants
| Property | Formula |
| :--- | :--- |
| **Identity** | $\det(I) = 1$ |
| **Transpose** | $\det(A^T) = \det(A)$ |
| **Inverse** | $\det(A^{-1}) = \frac{1}{\det(A)}$ |
| **Product Rule** | $\det(AB) = \det(A) \det(B)$ |
| **Scalar Mult** | $\det(kA) = k^n \det(A)$ (where $n$ is the dimension) |
