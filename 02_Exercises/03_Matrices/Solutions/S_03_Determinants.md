---
topic: Matrices
tags: [exercise, solution, determinants, trace, rank-nullity]
---

# Solution: Determinants

This solution note provides the step-by-step calculations and conceptual answers for the determinants exercise.

---

## Part 1: Calculation

Consider the matrix:

$$
A = \begin{bmatrix} 2 & 0 & 1 \\\\ 0 & 3 & 0 \\\\ 1 & 0 & 2 \end{bmatrix}
$$

### 1. Calculate $\det(A)$
Using Sarrus' Rule (or row expansion along the second row):

$$
\det(A) = (2 \cdot 3 \cdot 2 + 0 \cdot 0 \cdot 1 + 1 \cdot 0 \cdot 0) - (1 \cdot 3 \cdot 1 + 0 \cdot 0 \cdot 2 + 2 \cdot 0 \cdot 0)
$$

$$
\det(A) = 12 - 3 = 9
$$

### 2. Find the Trace of $A$, $\text{tr}(A)$
The trace of a matrix is the sum of its main diagonal elements:

$$
\text{tr}(A) = A_{11} + A_{22} + A_{33} = 2 + 3 + 2 = 7
$$

### 3. Verify the property $\det(kA) = k^n \det(A)$ for $k=2$
Here, $k=2$ and the dimension $n=3$.
First, construct the scaled matrix $2A$:

$$
2A = \begin{bmatrix} 4 & 0 & 2 \\\\ 0 & 6 & 0 \\\\ 2 & 0 & 4 \end{bmatrix}
$$

Calculate $\det(2A)$ using Sarrus' Rule:

$$
\det(2A) = (4 \cdot 6 \cdot 4 + 0 + 0) - (2 \cdot 6 \cdot 2 + 0 + 0) = 96 - 24 = 72
$$

Now calculate using the algebraic property:

$$
2^3 \cdot \det(A) = 8 \cdot 9 = 72
$$

Since $72 = 72$, the property is verified.

### 4. Calculate $A^T$ and Check Symmetry
The transpose $A^T$ is formed by swapping rows and columns:

$$
A^T = \begin{bmatrix} 2 & 0 & 1 \\\\ 0 & 3 & 0 \\\\ 1 & 0 & 2 \end{bmatrix}
$$

Since $A^T = A$, the matrix $A$ is **symmetric**.

---

## Part 2: Conceptual Understanding

### 1. Determinant of $Q^T Q$ for Orthogonal $Q$
For an orthogonal matrix $Q$, the definition states that:

$$
Q^T Q = I
$$

Taking the determinant of both sides:

$$
\det(Q^T Q) = \det(I) = 1
$$

Alternatively, using determinant properties:

$$
\det(Q^T Q) = \det(Q^T) \det(Q) = \det(Q) \det(Q) = (\det(Q))^2
$$

Since the determinant of an orthogonal matrix represents a pure rotation or reflection, $\det(Q) = \pm 1$. Thus:

$$
\det(Q^T Q) = (\pm 1)^2 = 1
$$

### 2. Proof that $\text{tr}(AB) = \text{tr}(BA)$ for $2 \times 2$ Matrices
Let matrices $A$ and $B$ be:

$$
A = \begin{bmatrix} a_{11} & a_{12} \\\\ a_{21} & a_{22} \end{bmatrix}, \quad B = \begin{bmatrix} b_{11} & b_{12} \\\\ b_{21} & b_{22} \end{bmatrix}
$$

Compute the matrix products:

$$
AB = \begin{bmatrix} a_{11}b_{11} + a_{12}b_{21} & a_{11}b_{12} + a_{12}b_{22} \\\\ a_{21}b_{11} + a_{22}b_{21} & a_{21}b_{12} + a_{22}b_{22} \end{bmatrix}
$$

$$
BA = \begin{bmatrix} b_{11}a_{11} + b_{12}a_{21} & b_{11}a_{12} + b_{12}a_{22} \\\\ b_{21}a_{11} + b_{22}a_{21} & b_{21}a_{12} + b_{22}a_{22} \end{bmatrix}
$$

Sum the diagonal elements of both products to find the traces:

$$
\text{tr}(AB) = (a_{11}b_{11} + a_{12}b_{21}) + (a_{21}b_{12} + a_{22}b_{22}) = a_{11}b_{11} + a_{12}b_{21} + a_{21}b_{12} + a_{22}b_{22}
$$

$$
\text{tr}(BA) = (b_{11}a_{11} + b_{12}a_{21}) + (b_{21}a_{12} + b_{22}a_{22}) = a_{11}b_{11} + a_{21}b_{12} + a_{12}b_{21} + a_{22}b_{22}
$$

By comparison, the terms in the sums are identical, proving that:

$$
\text{tr}(AB) = \text{tr}(BA)
$$

### 3. Connection Between $\det(M) = 0$ and Nullity
*   **Singularity**: A square $n \times n$ matrix $M$ has a determinant of $0$ if and only if it is **singular** (not invertible).
*   **Rank**: A singular matrix has linearly dependent rows and columns. Consequently, the dimension of its column space (its rank) must be strictly less than $n$:
    
    $$
    \text{rank}(M) < n
    $$
    
*   **Rank-Nullity Theorem**: The theorem states that for any $n \times n$ matrix $M$:
    
    $$
    \text{rank}(M) + \text{nullity}(M) = n
    $$
    
    Rearranging for nullity:
    
    $$
    \text{nullity}(M) = n - \text{rank}(M)
    $$
    
    Since $\text{rank}(M) < n$, it follows that:
    
    $$
    \text{nullity}(M) > 0
    $$
    
    This guarantees the existence of a non-trivial null space (at least one non-zero vector $\vec{x} \neq \vec{0}$ such that $M\vec{x} = \vec{0}$).

---
**Back to Question:** [[Q_03_Determinants]] **Related Concepts:** [[03_Determinants]], [[01_Basics]], [[06_Rank_Nullity]]