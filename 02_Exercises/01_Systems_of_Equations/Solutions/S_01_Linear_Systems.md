---
topic: Systems of Equations
tags: [exercise, solution, ranks, consistency]
---

# Solution: Linear Systems

This solution note details the step-by-step calculations and conceptual answers for the linear systems exercise.

---

## Part 1: Calculation

We solve the following system of linear equations using Gauss-Jordan elimination:

$$
\begin{cases} 
x + 2y + z = 4 & \text{(Row 1)} \\\\
3x + 8y + 7z = 20 & \text{(Row 2)} \\\\
2x + 7y + 9z = 23 & \text{(Row 3)}
\end{cases}
$$

### Step 1: Forward Elimination (Gauss Elimination)

First, represent the system as an augmented matrix:

$$
\begin{bmatrix}
1 & 2 & 1 & | & 4 \\\\
3 & 8 & 7 & | & 20 \\\\
2 & 7 & 9 & | & 23
\end{bmatrix}
$$

Eliminate the $x$ terms in Row 2 and Row 3:
- Perform $R_2 \leftarrow R_2 - 3R_1$:
  - $R_2 = [3, 8, 7 | 20] - [3, 6, 3 | 12] = [0, 2, 4 | 8]$
- Perform $R_3 \leftarrow R_3 - 2R_1$:
  - $R_3 = [2, 7, 9 | 23] - [2, 4, 2 | 8] = [0, 3, 7 | 15]$

The augmented matrix becomes:

$$
\begin{bmatrix}
1 & 2 & 1 & | & 4 \\\\
0 & 2 & 4 & | & 8 \\\\
0 & 3 & 7 & | & 15
\end{bmatrix}
$$

Next, eliminate the $y$ term in Row 3. Perform $R_3 \leftarrow 2R_3 - 3R_2$:
- $R_3 = [0, 6, 14 | 30] - [0, 6, 12 | 24] = [0, 0, 2 | 6]$

This yields the row echelon form (REF):

$$
\begin{bmatrix}
1 & 2 & 1 & | & 4 \\\\
0 & 2 & 4 & | & 8 \\\\
0 & 0 & 2 & | & 6
\end{bmatrix}
$$

From Row 3, we have $2z = 6 \implies z = 3$.

Since we have one leading component for each variable, a unique solution exists.

### Step 2: Backward Substitution (Gauss-Jordan Elimination)

Normalize the leading coefficients to get leading 1s:
- Perform $R_2 \leftarrow R_2 / 2 \implies [0, 1, 2 | 4]$
- Perform $R_3 \leftarrow R_3 / 2 \implies [0, 0, 1 | 3]$

The matrix becomes:

$$
\begin{bmatrix}
1 & 2 & 1 & | & 4 \\\\
0 & 1 & 2 & | & 4 \\\\
0 & 0 & 1 & | & 3
\end{bmatrix}
$$

Eliminate elements above the leading 1 in column 3:
- Perform $R_2 \leftarrow R_2 - 2R_3$:
  - $R_2 = [0, 1, 2 | 4] - [0, 0, 2 | 6] = [0, 1, 0 | -2]$
- Perform $R_1 \leftarrow R_1 - R_3$:
  - $R_1 = [1, 2, 1 | 4] - [0, 0, 1 | 3] = [1, 2, 0 | 1]$

The matrix becomes:

$$
\begin{bmatrix}
1 & 2 & 0 & | & 1 \\\\
0 & 1 & 0 & | & -2 \\\\
0 & 0 & 1 & | & 3
\end{bmatrix}
$$

Eliminate the $y$ term in Row 1 above the leading 1 in column 2. Perform $R_1 \leftarrow R_1 - 2R_2$:
- $R_1 = [1, 2, 0 | 1] - [0, 2, 0 | -4] = [1, 0, 0 | 5]$

This gives the final reduced row echelon form (RREF):

$$
\begin{bmatrix}
1 & 0 & 0 & | & 5 \\\\
0 & 1 & 0 & | & -2 \\\\
0 & 0 & 1 & | & 3
\end{bmatrix}
$$

Thus, the final solution is:

$$
\begin{cases}
x = 5 \\\\
y = -2 \\\\
z = 3
\end{cases}
$$

---

## Part 2: Conceptual Understanding

### 1. Augmented Matrix $[A | \vec{b}]$
The augmented matrix is:

$$
[A | \vec{b}] = \begin{bmatrix}
1 & 2 & 1 & | & 4 \\\\
3 & 8 & 7 & | & 20 \\\\
2 & 7 & 9 & | & 23
\end{bmatrix}
$$

### 2. Rank of Coefficient Matrix $A$ and Augmented Matrix $[A | \vec{b}]$
- The rank of $A$ is **3**, since there are 3 non-zero rows in its row-echelon form.
- The rank of $[A | \vec{b}]$ is also **3**, as the constant column does not create any additional non-zero row.

$$
\text{rank}(A) = 3, \quad \text{rank}([A | \vec{b}]) = 3
$$

### 3. System Consistency & Type of Solution
- The system is **consistent** because $\text{rank}(A) = \text{rank}([A | \vec{b}])$.
- Since the rank is equal to the number of variables ($n = 3$), the system has a **unique solution**.

### 4. Impact of Changing the Third Constant to 25
If we change the constant of the third equation from $23$ to $25$, the augmented matrix becomes:

$$
[A | \vec{b}'] = \begin{bmatrix}
1 & 2 & 1 & | & 4 \\\\
3 & 8 & 7 & | & 20 \\\\
2 & 7 & 9 & | & 25
\end{bmatrix}
$$

Applying the same row operations:
1. $R_2 \leftarrow R_2 - 3R_1$
2. $R_3 \leftarrow R_3 - 2R_1$
3. $R_3 \leftarrow 2R_3 - 3R_2$

We get:

$$
\begin{bmatrix}
1 & 2 & 1 & | & 4 \\\\
0 & 2 & 4 & | & 8 \\\\
0 & 0 & 2 & | & 10
\end{bmatrix}
$$

From Row 3, $2z = 10 \implies z = 5$.
Substituting back:
- From Row 2: $2y + 4(5) = 8 \implies 2y = -12 \implies y = -6$.
- From Row 1: $x + 2(-6) + 5 = 4 \implies x - 7 = 4 \implies x = 11$.

- **Ranks**: The ranks do not change. We still have $\text{rank}(A) = 3$ and $\text{rank}([A | \vec{b}']) = 3$.
- **Implication**: The system remains **consistent** and still has a **unique solution** ($x = 11$, $y = -6$, $z = 5$).

---
**Back to Question:** [[Q_01_Linear_Systems]] | **Related Concepts:** [[01_Linear_Systems]], [[06_Rank_Nullity]]