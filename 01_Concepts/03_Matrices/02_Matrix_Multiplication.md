# Matrix Multiplication

Matrix multiplication is a more complex operation than element-wise addition.

## Compatibility Rule
Two matrices $A$ and $B$ can only be multiplied if the number of columns in $A$ is equal to the number of rows in $B$.
- If $A$ is $m \times n$ and $B$ is $n \times p$, the resulting matrix $C = AB$ will be $m \times p$.

## General Formula
The entry $(AB)_{ij}$ is calculated by taking the dot product of the $i$-th row of $A$ and the $j$-th column of $B$:

$$
(AB)_{ij} = \sum_{k=1}^n A_{ik} B_{kj}
$$

## Key Properties
| Property | Formula / Description |
| :--- | :--- |
| **Non-Commutative** | In general, $AB \neq BA$. |
| **Associative** | $(AB)C = A(BC)$ |
| **Distributive** | $A(B + C) = AB + AC$ |
| **Scalar Factorization** | $s(AB) = (sA)B = A(sB)$ |
| **Transpose Rule** | $(AB)^T = B^T A^T$ (The order is reversed!) |
