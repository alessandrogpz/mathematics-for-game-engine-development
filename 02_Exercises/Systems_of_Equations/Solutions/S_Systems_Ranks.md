# Solution: Systems of Equations & Solution Types

## Part 1: Calculation
Augmented Matrix:
$$
\begin{bmatrix} 
1 & 2 & 1 & | & 4 \\
3 & 8 & 7 & | & 20 \\
2 & 7 & 9 & | & 23 
\end{bmatrix}
$$

1. $R_2 \leftarrow R_2 - 3R_1$ and $R_3 \leftarrow R_3 - 2R_1$:
$$
\begin{bmatrix} 
1 & 2 & 1 & | & 4 \\
0 & 2 & 4 & | & 8 \\
0 & 3 & 7 & | & 15 
\end{bmatrix}
$$

2. $R_2 \leftarrow \frac{1}{2}R_2$:
$$
\begin{bmatrix} 
1 & 2 & 1 & | & 4 \\
0 & 1 & 2 & | & 4 \\
0 & 3 & 7 & | & 15 
\end{bmatrix}
$$

3. $R_3 \leftarrow R_3 - 3R_2$:
$$
\begin{bmatrix} 
1 & 2 & 1 & | & 4 \\
0 & 1 & 2 & | & 4 \\
0 & 0 & 1 & | & 3 
\end{bmatrix}
$$ (This is REF)

4. Back-substitution (RREF):
- $z = 3$
- $y + 2(3) = 4 \implies y = -2$
- $x + 2(-2) + 3 = 4 \implies x - 1 = 4 \implies x = 5$

**Solution:** $(5, -2, 3)$

## Part 2: Conceptual Understanding
1. **Ranks:** Both $\text{rank}(A) = 3$ and $\text{rank}([A|\vec{b}]) = 3$.
2. **Consistency:** Since $\text{rank}(A) = \text{rank}([A|\vec{b}]) = n$ (number of variables), the system is **consistent** and has a **unique solution**.
3. **Modified System:** If $R_3$ became $[0, 0, 0 | 2]$, then $\text{rank}(A)=2$ but $\text{rank}([A|\vec{b}])=3$. This would mean the system is **inconsistent** (no solution).
