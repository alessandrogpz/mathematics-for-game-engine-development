# Matrix Basics

A matrix is a rectangular array of numbers arranged in rows and columns.

## Basic Operations
For addition and subtraction, both matrices must have the same dimensions ($m \times n$).

- **Addition:** $(A + B)_{ij} = A_{ij} + B_{ij}$
- **Subtraction:** $(A - B)_{ij} = A_{ij} - B_{ij}$
- **Scalar Multiplication:** $(sA)_{ij} = s(A_{ij})$

## Basic Properties
| Property | Description | Formula |
| :--- | :--- | :--- |
| **Associative** | Matrix addition | $(A + B) + C = A + (B + C)$ |
| **Commutative** | Matrix addition | $A + B = B + A$ |
| **Associative** | Scalar-matrix | $s(tA) = (st)A$ |
| **Distributive** | Scalar-matrix | $(s + t)A = sA + tA$ |

## Matrix Transposition
The transpose of a matrix $M$, denoted as $M^T$, is created by swapping its rows and columns.
- Rows of $M$ become columns in $M^T$.
- $(M^T)_{ij} = M_{ji}$

**Example:**
If $A = \begin{bmatrix} a & b & c \\ d & e & f \end{bmatrix}$, then $A^T = \begin{bmatrix} a & d \\ b & e \\ c & f \end{bmatrix}$

## Identity Matrix
The identity matrix $I_n$ is a square ($n \times n$) matrix with ones on the main diagonal and zeros elsewhere.
$$I_3 = \begin{bmatrix} 1 & 0 & 0 \\\\ 0 & 1 & 0 \\\\ 0 & 0 & 1 \end{bmatrix}$$
**Property:** Multiplying any matrix $A$ by the identity matrix yields $A$ back:
$$A I = A \quad \text{and} \quad I B = B$$

## Trace of a Matrix
The trace of a square matrix $A$, denoted as $\text{tr}(A)$, is the sum of the elements on the main diagonal.
$$\text{tr}(A) = \sum_{i=1}^n A_{ii} = A_{11} + A_{22} + \dots + A_{nn}$$

### Properties of Trace
| Property | Formula / Description |
| :--- | :--- |
| **Linearity** | $\text{tr}(A + B) = \text{tr}(A) + \text{tr}(B)$ and $\text{tr}(cA) = c \cdot \text{tr}(A)$ |
| **Transpose** | $\text{tr}(A^T) = \text{tr}(A)$ |
| **Cyclic Property** | $\text{tr}(AB) = \text{tr}(BA)$ (even if $AB \neq BA$) |
