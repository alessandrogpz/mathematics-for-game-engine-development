---
topic: Matrices
tags: [exercise, solution, matrix-inversion, gauss-jordan, elementary-matrices]
---
# Solution: Gauss-Jordan 3x3 Matrix Inversion

---

## Part 1: Calculation

We want to find the inverse of the matrix $\mathbf{A}$ using the Gauss-Jordan elimination method:

$$
\mathbf{A} = \begin{bmatrix} 1 & 0 & 2 \\\\ 0 & 1 & 0 \\\\ 3 & 0 & 1 \end{bmatrix}
$$

### Step 1: Set up the Augmented Matrix $[\mathbf{A} \mid \mathbf{I}]$
We append the $3 \times 3$ Identity matrix to the right of $\mathbf{A}$:

$$
[\mathbf{A} \mid \mathbf{I}] = \left[\begin{array}{ccc|ccc} 1 & 0 & 2 & 1 & 0 & 0 \\\\ 0 & 1 & 0 & 0 & 1 & 0 \\\\ 3 & 0 & 1 & 0 & 0 & 1 \end{array}\right]
$$

### Step 2: Row Elimination to Reach Reduced Row Echelon Form (RREF)

*   **Operation 1:** Eliminate the $3$ in column 1, row 3.
    
$$
\text{Row}_3 - 3\text{Row}_1 \to \text{Row}_3
$$

    
$$
\left[\begin{array}{ccc|ccc} 1 & 0 & 2 & 1 & 0 & 0 \\\\ 0 & 1 & 0 & 0 & 1 & 0 \\\\ 0 & 0 & -5 & -3 & 0 & 1 \end{array}\right]
$$

*   **Operation 2:** Scale rows to eliminate fractional arithmetic during the next elimination step (an excellent technique!).
    
$$
5\text{Row}_1 \to \text{Row}_1 \quad \text{and} \quad 2\text{Row}_3 \to \text{Row}_3
$$

    
$$
\left[\begin{array}{ccc|ccc} 5 & 0 & 10 & 5 & 0 & 0 \\\\ 0 & 1 & 0 & 0 & 1 & 0 \\\\ 0 & 0 & -10 & -6 & 0 & 2 \end{array}\right]
$$

*   **Operation 3:** Eliminate the $10$ in column 3, row 1.
    
$$
\text{Row}_1 + \text{Row}_3 \to \text{Row}_1
$$

    
$$
\left[\begin{array}{ccc|ccc} 5 & 0 & 0 & -1 & 0 & 2 \\\\ 0 & 1 & 0 & 0 & 1 & 0 \\\\ 0 & 0 & -10 & -6 & 0 & 2 \end{array}\right]
$$

*   **Operation 4:** Normalize the diagonal elements back to $1$.
    
$$
\frac{1}{5}\text{Row}_1 \to \text{Row}_1 \quad \text{and} \quad -\frac{1}{10}\text{Row}_3 \to \text{Row}_3
$$

    
$$
\left[\begin{array}{ccc|ccc} 1 & 0 & 0 & -1/5 & 0 & 2/5 \\\\ 0 & 1 & 0 & 0 & 1 & 0 \\\\ 0 & 0 & 1 & 3/5 & 0 & -1/5 \end{array}\right]
$$

### Conclusion: The Inverse Matrix $\mathbf{A}^{-1}$
Since the left side has been successfully transformed into the Identity matrix $\mathbf{I}$, the right side is the inverse $\mathbf{A}^{-1}$:

$$
\mathbf{A}^{-1} = \begin{bmatrix} -1/5 & 0 & 2/5 \\\\ 0 & 1 & 0 \\\\ 3/5 & 0 & -1/5 \end{bmatrix} = \begin{bmatrix} -0.2 & 0 & 0.4 \\\\ 0 & 1 & 0 \\\\ 0.6 & 0 & -0.2 \end{bmatrix}
$$

---

## Part 2: Conceptual Understanding

### 1. Zero Row in Gauss-Jordan
**Question:** During the Gauss-Jordan process, if you find a row of zeros on the left side, what does that imply about matrix $\mathbf{A}$ and its determinant?

**Answer:**
If a row of zeros is encountered on the left side of the augmented matrix during the Gauss-Jordan elimination process, it implies:
1.  **Determinant:** The determinant of $\mathbf{A}$ is exactly $0$ ($\det(\mathbf{A}) = 0$). This is because elementary row operations do not alter whether a determinant is zero or non-zero, and any matrix with a row of zeros has a determinant of $0$.
2.  **Invertibility:** The matrix $\mathbf{A}$ is **singular** (non-invertible). An inverse matrix $\mathbf{A}^{-1}$ does not exist.
3.  **System of Equations:** For a system of linear equations represented by $\mathbf{A}\vec{x} = \vec{b}$, a row of zeros indicates that the equations are linearly dependent. Depending on the vector $\vec{b}$, the system will either have **infinitely many solutions** (if the system is consistent) or **no solution** (if it is inconsistent).

---

### 2. Why the Augmented Matrix Approach Works
**Question:** Explain why the augmented matrix approach $[\mathbf{A} \mid \mathbf{I}] \to [\mathbf{I} \mid \mathbf{A}^{-1}]$ works. What fundamental property of matrix multiplication are we exploiting?

**Answer:**
The augmented matrix method exploits two core properties of linear algebra:

1.  **Elementary Matrices and Associativity:**
    Every elementary row operation (scaling, swapping, or adding rows) is mathematically equivalent to left-multiplying the matrix by an **elementary matrix** $\mathbf{E}_i$.
    If we can reduce $\mathbf{A}$ to the Identity matrix $\mathbf{I}$ using a chain of row operations, it means there exists a sequence of elementary matrices such that:
    
$$
(\mathbf{E}_r \dots \mathbf{E}_2 \mathbf{E}_1) \mathbf{A} = \mathbf{I}
$$

    By the associative property of matrix multiplication, the combined product of these matrices is the inverse of $\mathbf{A}$:
    
$$
\mathbf{E}_r \dots \mathbf{E}_2 \mathbf{E}_1 = \mathbf{A}^{-1}
$$

2.  **Block Matrix Multiplication (Distributivity):**
    We exploit partitioned block multiplication. When we perform these operations on the augmented matrix $[\mathbf{A} \mid \mathbf{I}]$, we are applying the same elementary matrices to both blocks simultaneously:
    
$$
(\mathbf{E}_r \dots \mathbf{E}_2 \mathbf{E}_1) [\mathbf{A} \mid \mathbf{I}] = [(\mathbf{E}_r \dots \mathbf{E}_2 \mathbf{E}_1)\mathbf{A} \mid (\mathbf{E}_r \dots \mathbf{E}_2 \mathbf{E}_1)\mathbf{I}] = [\mathbf{I} \mid \mathbf{A}^{-1}]
$$

    Because matrix multiplication distributes across augmented columns, the exact same operations that reduce $\mathbf{A}$ to $\mathbf{I}$ will simultaneously transform $\mathbf{I}$ into $\mathbf{A}^{-1}$.

---

### 3. Maximum Number of Row Operations
**Question:** If $\mathbf{A}$ is an $n \times n$ matrix, how many row operations (at most) would you expect to perform to reach $\mathbf{I}$?

**Answer:**
To transform an $n \times n$ matrix $\mathbf{A}$ into the identity matrix $\mathbf{I}$ using Gauss-Jordan elimination, we perform three types of row operations:
1.  **Pivot Normalization (Scaling):** We scale the pivot row so the leading entry is $1$. We do this once for each of the $n$ rows. (Total: $n$ scaling operations).
2.  **Row Elimination (Replacements):** In each of the $n$ columns, we must eliminate all entries above and below the pivot. For each column, this requires at most $n-1$ row replacement operations. (Total: $n(n-1) = n^2 - n$ replacement operations).
3.  **Row Swaps (Pivoting):** In the worst-case scenario, we may need to swap rows to position a non-zero pivot. This happens at most $n-1$ times.

Excluding pivoting, the maximum number of row operations required is:

$$
\text{Total Operations} = n + (n^2 - n) = n^2 \text{ operations}
$$

---
## Code Implementation
```cpp
// Optional C++ snippet here
```

**Back to Question:** [[Q_Gauss_Jordan_3x3]] | **Related Concepts:** [[03_Matrices]]