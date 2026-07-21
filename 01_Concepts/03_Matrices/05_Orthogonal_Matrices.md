# Orthogonal Matrices

An orthogonal matrix is a square matrix whose columns and rows are orthogonal unit vectors (orthonormal vectors).

## Definition
A square matrix $Q$ is orthogonal if:

$$
Q^T Q = Q Q^T = I
$$

This implies that the transpose of an orthogonal matrix is equal to its inverse:

$$
Q^{-1} = Q^T
$$

## Key Properties
| Property | Formula / Description |
| :--- | :--- |
| **Determinant** | $\det(Q) = \pm 1$ |
| **Preservation of Norm** | $\|Q\vec{v}\| = \|\vec{v}\|$ (Length is unchanged) |
| **Preservation of Angle** | $(Q\vec{u}) \cdot (Q\vec{v}) = \vec{u} \cdot \vec{v}$ (Dot product is preserved) |
| **Efficient Inverse** | $Q^{-1} = Q^T$ (Inversion is just transposition) |

## Examples
- **[[02_Rotations|Rotation Matrices]]**: In 2D, the rotation matrix:
  
$$
R_\theta = \begin{bmatrix} \cos\theta & -\sin\theta \\\\ \sin\theta & \cos\theta \end{bmatrix}
$$
  
  is orthogonal.
- **[[03_Reflections|Reflection Matrices]]**: Matrices that reflect vectors across a line or plane.

---

## Code Implementation

*   **C++ Source Code:** [[03_Code/03_Matrices/Orthogonal_Matrices.cppm|Orthogonal_Matrices.cppm]]
