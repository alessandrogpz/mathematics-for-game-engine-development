# Solution: Matrix Properties & Determinants

## Part 1: Calculation
$A = \begin{bmatrix} 2 & 0 & 1 \\ 0 & 3 & 0 \\ 1 & 0 & 2 \end{bmatrix}$

1. **Determinant:** Expanding along the second row/column (easiest):
   $\det(A) = 3 \cdot \det\begin{bmatrix} 2 & 1 \\ 1 & 2 \end{bmatrix} = 3(4 - 1) = 9$.
2. **Trace:** $\text{tr}(A) = 2 + 3 + 2 = 7$.
3. **Property Check ($k=2$):** $\det(2A) = 2^3 \det(A) = 8 \cdot 9 = 72$.
4. **Transpose:** $A^T = \begin{bmatrix} 2 & 0 & 1 \\ 0 & 3 & 0 \\ 1 & 0 & 2 \end{bmatrix}$. Yes, $A = A^T$, so it is symmetric.

## Part 2: Conceptual Understanding
1. **Orthogonal Matrix:** $Q^T Q = I$. Therefore, $\det(Q^T Q) = \det(I) = 1$.
2. **Trace Property:** 
   Let $A = \begin{bmatrix} a & b \\ c & d \end{bmatrix}, B = \begin{bmatrix} e & f \\ g & h \end{bmatrix}$.
   - Diagonal of $AB$: $(ae+bg), (cf+dh) \implies \text{tr}(AB) = ae+bg+cf+dh$.
   - Diagonal of $BA$: $(ea+fc), (gb+hd) \implies \text{tr}(BA) = ea+fc+gb+hd$.
   - The sums are identical.
3. **Rank-Nullity:** If $\det(A) = 0$, the matrix is not invertible, meaning its columns are linearly dependent. Thus, $\text{rank}(A) < n$. Since $\text{rank}(A) + \text{nullity}(A) = n$, if rank decreases, nullity must be at least 1.
