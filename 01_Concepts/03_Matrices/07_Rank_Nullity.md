# Rank and Nullity

Rank and nullity are fundamental properties of matrices that describe the dimensions of the vector subspaces associated with a matrix (specifically, its range and its kernel). They play a central role in determining the solvability of linear systems.

---

## 1. Fundamental Subspaces of a Matrix

For any $m \times n$ matrix $\mathbf{A}$:

### A. Column Space (Range)
The **column space** of $\mathbf{A}$ (denoted $\text{Col}(\mathbf{A})$ or $\text{Range}(\mathbf{A})$) is the span of the column vectors of $\mathbf{A}$. It represents all possible vectors $\vec{b}$ that can be reached by the transformation $\mathbf{A}\vec{x}$.
*   **Dimension**: The dimension of the column space is the **rank** of $\mathbf{A}$.

### B. Null Space (Kernel)
The **null space** of $\mathbf{A}$ (denoted $\text{Null}(\mathbf{A})$ or $\text{Ker}(\mathbf{A})$) is the set of all vectors $\vec{x}$ that are mapped to the zero vector by $\mathbf{A}$:

$$
\text{Null}(\mathbf{A}) = \{ \vec{x} \in \mathbb{R}^n \mid \mathbf{A}\vec{x} = \vec{0} \}
$$

*   **Dimension**: The dimension of the null space is the **nullity** of $\mathbf{A}$.

---

## 2. Definitions of Rank and Nullity

### Rank ($\text{rank}(\mathbf{A})$)
The **rank** of a matrix is the maximum number of linearly independent column vectors (or row vectors) in the matrix.
*   **Computation**: It is equal to the number of **pivots** (non-zero rows) when the matrix is reduced to Row Echelon Form (REF).
*   **Property**: The rank cannot exceed the dimensions of the matrix: $\text{rank}(\mathbf{A}) \le \min(m, n)$.

### Nullity ($\text{nullity}(\mathbf{A})$)
The **nullity** of a matrix is the dimension of its null space.
*   **Computation**: It is equal to the number of **free variables** in the Row Echelon Form of the matrix (columns without pivots).

---

## 3. The Rank-Nullity Theorem

The **Rank-Nullity Theorem** states that for any $m \times n$ matrix $\mathbf{A}$ (with $n$ columns/variables):

$$
\text{rank}(\mathbf{A}) + \text{nullity}(\mathbf{A}) = n
$$

This theorem represents a fundamental conservation law in linear algebra: every column of a matrix must either contribute to the rank (as a pivot column) or to the nullity (as a free variable column).

---

## 4. Connection to Systems of Equations

For a linear system $\mathbf{A}\vec{x} = \vec{b}$ with $n$ variables:

1.  **Unique Solution:**
    If $\text{nullity}(\mathbf{A}) = 0$, there are no free variables, meaning $\text{rank}(\mathbf{A}) = n$. If the system is consistent, it has a **unique solution**.
2.  **Infinitely Many Solutions:**
    If $\text{nullity}(\mathbf{A}) = k > 0$, there are $k$ free variables. If the system is consistent, it has **infinitely many solutions** parameterized by $k$ free variables (degrees of freedom).
3.  **No Solution:**
    If the system is inconsistent ($\text{rank}(\mathbf{A}) < \text{rank}([\mathbf{A} | \vec{b}])$), it has **no solution**, regardless of the nullity.

---

## 5. Connection to Matrix Invertibility (Square Matrices)

For an $n \times n$ square matrix $\mathbf{A}$, the following statements are equivalent:
*   $\mathbf{A}$ is [[04_Matrix_Inversion|invertible]] ($\mathbf{A}^{-1}$ exists).
*   $\det(\mathbf{A}) \neq 0$ (its [[03_Determinants|determinant]] is non-zero).
*   $\mathbf{A}$ has full rank: $\text{rank}(\mathbf{A}) = n$.
*   $\mathbf{A}$ has zero nullity: $\text{nullity}(\mathbf{A}) = 0$.

If $\det(\mathbf{A}) = 0$, then the matrix is singular:
*   $\text{rank}(\mathbf{A}) < n$ (the columns are linearly dependent).
*   $\text{nullity}(\mathbf{A}) = n - \text{rank}(\mathbf{A}) > 0$.
*   There exists a non-zero vector $\vec{x} \neq \vec{0}$ such that $\mathbf{A}\vec{x} = \vec{0}$.
