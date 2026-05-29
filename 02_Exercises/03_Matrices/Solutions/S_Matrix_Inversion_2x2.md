---
topic: Matrices
tags: [exercise, solution, matrix-inversion, determinant, singular-matrix]
---
# Solution: 2x2 Matrix Inversion

This solution contains the complete, step-by-step mathematical calculations and conceptual proofs transcribed from your handwritten notes, formatted in LaTeX and polished for grammatical and mathematical precision.

---

## Part 1: Calculations

We are given the matrix:
$$\mathbf{M} = \begin{bmatrix} 4 & 7 \\\\ 2 & 6 \end{bmatrix}$$

### 1. Calculate $\det(\mathbf{M})$
For any $2 \times 2$ matrix, the determinant formula is:
$$\det\left(\begin{bmatrix} a & b \\\\ c & d \end{bmatrix}\right) = ad - bc$$

Substituting our values:
$$\det(\mathbf{M}) = (4)(6) - (2)(7) = 24 - 14 = 10$$
Thus, $\det(\mathbf{M}) = 10$.

---

### 2. Construct $\mathbf{M}^{-1}$ using the Adjugate Method
The algebraic formula for the inverse using the adjugate matrix is:
$$\mathbf{M}^{-1} = \frac{1}{\det(\mathbf{M})} \text{adj}(\mathbf{M})$$

For a $2 \times 2$ matrix, we use the standard shortcut to find the adjugate: swap the diagonal elements and negate the off-diagonal elements:
$$\text{adj}\left(\begin{bmatrix} a & b \\\\ c & d \end{bmatrix}\right) = \begin{bmatrix} d & -b \\\\ -c & a \end{bmatrix} \implies \text{adj}(\mathbf{M}) = \begin{bmatrix} 6 & -7 \\\\ -2 & 4 \end{bmatrix}$$

Now, substitute $\det(\mathbf{M}) = 10$ and $\text{adj}(\mathbf{M})$ into the inverse formula:
$$\mathbf{M}^{-1} = \frac{1}{10} \begin{bmatrix} 6 & -7 \\\\ -2 & 4 \end{bmatrix} = \begin{bmatrix} 6/10 & -7/10 \\\\ -2/10 & 4/10 \end{bmatrix} = \begin{bmatrix} 3/5 & -7/10 \\\\ -1/5 & 2/5 \end{bmatrix} = \begin{bmatrix} 0.6 & -0.7 \\\\ -0.2 & 0.4 \end{bmatrix}$$

---

### 3. Verification: $\mathbf{M}\mathbf{M}^{-1} = \mathbf{I}$
We verify our inverse matrix by direct multiplication:
$$\mathbf{M}\mathbf{M}^{-1} = \begin{bmatrix} 4 & 7 \\\\ 2 & 6 \end{bmatrix} \begin{bmatrix} 6/10 & -7/10 \\\\ -2/10 & 4/10 \end{bmatrix}$$
$$\mathbf{M}\mathbf{M}^{-1} = \begin{bmatrix} 4(6/10) + 7(-2/10) & 4(-7/10) + 7(4/10) \\\\ 2(6/10) + 6(-2/10) & 2(-7/10) + 6(4/10) \end{bmatrix}$$
$$\mathbf{M}\mathbf{M}^{-1} = \begin{bmatrix} 24/10 - 14/10 & -28/10 + 28/10 \\\\ 12/10 - 12/10 & -14/10 + 24/10 \end{bmatrix} = \begin{bmatrix} 10/10 & 0 \\\\ 0 & 10/10 \end{bmatrix} = \begin{bmatrix} 1 & 0 \\\\ 0 & 1 \end{bmatrix} = \mathbf{I}$$
The product yields the Identity matrix $\mathbf{I}$, confirming our calculation is correct.

---

## Part 2: Conceptual Understanding

### 1. Singularity of $\mathbf{M}$
**Question:** Based on your calculation of $\det(\mathbf{M})$, is $\mathbf{M}$ a singular or non-singular matrix?

**Answer:**
$\mathbf{M}$ is a **non-singular matrix** because its determinant is non-zero ($\det(\mathbf{M}) = 10 \neq 0$). 
*   A square matrix is defined as **singular** if and only if its determinant is exactly $0$. 
*   Singular matrices are non-invertible (their inverse does not exist). Because $\mathbf{M}$ has a non-zero determinant, its inverse exists and is unique.

---

### 2. Scalar Multiplication and Determinants
**Question:** If we multiply every element in $\mathbf{M}$ by a scalar $2$, how would $\det(\mathbf{M})$ relate to the original one?

Since $\mathbf{M}$ is a **$2 \times 2$ matrix** ($n = 2$), multiplying every element of the matrix by a scalar $k = 2$ multiplies the determinant by $2^2 = 4$:
$$\det(2\mathbf{M}) = 2^2 \det(\mathbf{M}) = 4 \det(\mathbf{M})$$

Substituting our original determinant ($\det(\mathbf{M}) = 10$):
$$\det(2\mathbf{M}) = 4 \times 10 = 40$$

**Numerical Proof:**
$$2\mathbf{M} = \begin{bmatrix} 8 & 14 \\\\ 4 & 12 \end{bmatrix}$$
$$\det(2\mathbf{M}) = (8)(12) - (4)(14) = 96 - 56 = 40$$
This confirms that the determinant is scaled by $2^2$

The general formula for this operation is:
$$\det(k A) = k^n \det(A)$$
---

### 3. Invertibility Proof: $ad - bc \neq 0$
**Question:** Prove that for any $2 \times 2$ matrix, the matrix inverse exists if and only if $ad - bc \neq 0$.

**Proof:**
To prove this "if and only if" statement, we must show both directions of the logical implication:

1.  **"Only If" Direction (Necessity - If the inverse exists, then $ad - bc \neq 0$):**
    Assume the $2 \times 2$ matrix $\mathbf{A} = \begin{bmatrix} a & b \\ c & d \end{bmatrix}$ is invertible. By definition, there exists an inverse matrix $\mathbf{A}^{-1}$ such that:
    $$\mathbf{A}\mathbf{A}^{-1} = \mathbf{I}$$
    Taking the determinant of both sides and utilizing the multiplicative property of determinants ($\det(XY) = \det(X)\det(Y)$):
    $$\det(\mathbf{A}\mathbf{A}^{-1}) = \det(\mathbf{I}) \implies \det(\mathbf{A}) \cdot \det(\mathbf{A}^{-1}) = 1$$
    Since the product of these two real numbers is $1$, neither number can be $0$. Therefore:
    $$\det(\mathbf{A}) \neq 0$$
    Since the determinant of a $2 \times 2$ matrix is defined as $\det(\mathbf{A}) = ad - bc$, it must be true that:
    $$ad - bc \neq 0$$

2.  **"If" Direction (Sufficiency - If $ad - bc \neq 0$, then the inverse exists):**
    Assume $ad - bc \neq 0$. We can explicitly construct a candidate inverse matrix $\mathbf{X}$:
    $$\mathbf{X} = \frac{1}{ad - bc} \begin{bmatrix} d & -b \\\\ -c & a \end{bmatrix}$$
    We verify $\mathbf{X}$ is the inverse by direct matrix multiplication:
    $$\mathbf{A}\mathbf{X} = \begin{bmatrix} a & b \\\\ c & d \end{bmatrix} \left( \frac{1}{ad - bc} \begin{bmatrix} d & -b \\\\ -c & a \end{bmatrix} \right) = \frac{1}{ad - bc} \begin{bmatrix} ad - bc & -ab + ab \\\\ cd - cd & -bc + ad \end{bmatrix} = \frac{1}{ad - bc} \begin{bmatrix} ad - bc & 0 \\\\ 0 & ad - bc \end{bmatrix} = \begin{bmatrix} 1 & 0 \\\\ 0 & 1 \end{bmatrix} = \mathbf{I}$$
    Similarly, $\mathbf{X}\mathbf{A} = \mathbf{I}$. Since $\mathbf{X}$ satisfies all conditions of a matrix inverse, $\mathbf{A}^{-1}$ is proven to exist.

---

## Code Implementation
```cpp
// Optional C++ snippet here
```

**Back to Question:** [[Q_Matrix_Inversion_2x2]] | **Related Concepts:** [[03_Determinants]], [[04_Matrix_Inversion]]