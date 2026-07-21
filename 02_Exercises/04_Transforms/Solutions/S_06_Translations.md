---
topic: Transforms
tags: [exercise, solution, translations, homogeneous-coordinates, affine-transformation]
---

# Solution: Translations

This solution note provides the step-by-step mathematical calculations, matrix derivations, and conceptual explanations for the translation exercise in homogeneous coordinates.

---

## Part 1: Calculation

We are given the following 3D translation vector $\vec{t}$, point $\vec{p}$, and direction vector $\vec{d}$:

$$
\vec{t} = \begin{bmatrix} 3 \\\\ -2 \\\\ 4 \end{bmatrix}, \quad \vec{p} = \begin{bmatrix} 1 \\\\ 2 \\\\ 3 \\\\ 1 \end{bmatrix}, \quad \vec{d} = \begin{bmatrix} 1 \\\\ 2 \\\\ 3 \\\\ 0 \end{bmatrix}
$$

### 1. Construct the Translation Matrix
A homogeneous translation matrix in 3D is a $4 \times 4$ matrix constructed by placing the $3 \times 3$ identity matrix $I_3$ in the top-left (representing no rotation, scale, or shear) and the 3D translation vector $\vec{t}$ in the top-right column:

$$
T(\vec{t}) = \begin{bmatrix} 1 & 0 & 0 & t_x \\\\ 0 & 1 & 0 & t_y \\\\ 0 & 0 & 1 & t_z \\\\ 0 & 0 & 0 & 1 \end{bmatrix}
$$

Substituting $t_x = 3$, $t_y = -2$, and $t_z = 4$ yields:

$$
T(\vec{t}) = \begin{bmatrix} 1 & 0 & 0 & 3 \\\\ 0 & 1 & 0 & -2 \\\\ 0 & 0 & 1 & 4 \\\\ 0 & 0 & 0 & 1 \end{bmatrix}
$$

### 2. Point Translation
To translate the point $\vec{p}$, we pre-multiply the column vector representing $\vec{p}$ by the translation matrix $T(\vec{t})$:

$$
\vec{p}' = T(\vec{t})\vec{p} = \begin{bmatrix} 1 & 0 & 0 & 3 \\\\ 0 & 1 & 0 & -2 \\\\ 0 & 0 & 1 & 4 \\\\ 0 & 0 & 0 & 1 \end{bmatrix} \begin{bmatrix} 1 \\\\ 2 \\\\ 3 \\\\ 1 \end{bmatrix} = \begin{bmatrix} 1 \cdot 1 + 0 \cdot 2 + 0 \cdot 3 + 3 \cdot 1 \\\\ 0 \cdot 1 + 1 \cdot 2 + 0 \cdot 3 - 2 \cdot 1 \\\\ 0 \cdot 1 + 0 \cdot 2 + 1 \cdot 3 + 4 \cdot 1 \\\\ 0 \cdot 1 + 0 \cdot 2 + 0 \cdot 3 + 1 \cdot 1 \end{bmatrix} = \begin{bmatrix} 1 + 3 \\\\ 2 - 2 \\\\ 3 + 4 \\\\ 1 \end{bmatrix} = \begin{bmatrix} 4 \\\\ 0 \\\\ 7 \\\\ 1 \end{bmatrix}
$$

The translated point is located at $\vec{p}' = [4, 0, 7, 1]^T$.

### 3. Vector Translation
To apply the transformation to the direction vector $\vec{d}$, we pre-multiply its column vector by $T(\vec{t})$:

$$
\vec{d}' = T(\vec{t})\vec{d} = \begin{bmatrix} 1 & 0 & 0 & 3 \\\\ 0 & 1 & 0 & -2 \\\\ 0 & 0 & 1 & 4 \\\\ 0 & 0 & 0 & 1 \end{bmatrix} \begin{bmatrix} 1 \\\\ 2 \\\\ 3 \\\\ 0 \end{bmatrix} = \begin{bmatrix} 1 \cdot 1 + 0 \cdot 2 + 0 \cdot 3 + 3 \cdot 0 \\\\ 0 \cdot 1 + 1 \cdot 2 + 0 \cdot 3 - 2 \cdot 0 \\\\ 0 \cdot 1 + 0 \cdot 2 + 1 \cdot 3 + 4 \cdot 0 \\\\ 0 \cdot 1 + 0 \cdot 2 + 0 \cdot 3 + 1 \cdot 0 \end{bmatrix} = \begin{bmatrix} 1 \\\\ 2 \\\\ 3 \\\\ 0 \end{bmatrix}
$$

As calculated, the direction vector's coordinates did not change ($\vec{d}' = \vec{d}$).

### 4. Inverse Translation
The inverse of a translation matrix represents the opposite displacement. For a translation vector $\vec{t}$, its inverse translation is simply $-\vec{t}$:

$$
T(\vec{t})^{-1} = T(-\vec{t}) = \begin{bmatrix} 1 & 0 & 0 & -3 \\\\ 0 & 1 & 0 & 2 \\\\ 0 & 0 & 1 & -4 \\\\ 0 & 0 & 0 & 1 \end{bmatrix}
$$

We can verify this algebraically by using row operations to invert the augmented matrix $[T(\vec{t}) \mid I]$:

$$
[T(\vec{t}) \mid I] = \begin{bmatrix} 1 & 0 & 0 & 3 & \mid & 1 & 0 & 0 & 0 \\\\ 0 & 1 & 0 & -2 & \mid & 0 & 1 & 0 & 0 \\\\ 0 & 0 & 1 & 4 & \mid & 0 & 0 & 1 & 0 \\\\ 0 & 0 & 0 & 1 & \mid & 0 & 0 & 0 & 1 \end{bmatrix}
$$

Applying row operations to eliminate the fourth column:
*   $R_1 \leftarrow R_1 - 3R_4$
*   $R_2 \leftarrow R_2 + 2R_4$
*   $R_3 \leftarrow R_3 - 4R_4$

Yields the identity matrix on the left and the inverse matrix on the right:

$$
\begin{bmatrix} 1 & 0 & 0 & 0 & \mid & 1 & 0 & 0 & -3 \\\\ 0 & 1 & 0 & 0 & \mid & 0 & 1 & 0 & 2 \\\\ 0 & 0 & 1 & 0 & \mid & 0 & 0 & 1 & -4 \\\\ 0 & 0 & 0 & 1 & \mid & 0 & 0 & 0 & 1 \end{bmatrix}
$$

Now, we multiply the inverse matrix $T(\vec{t})^{-1}$ by the translated point $\vec{p}'$:

$$
\vec{p} = T(\vec{t})^{-1}\vec{p}' = \begin{bmatrix} 1 & 0 & 0 & -3 \\\\ 0 & 1 & 0 & 2 \\\\ 0 & 0 & 1 & -4 \\\\ 0 & 0 & 0 & 1 \end{bmatrix} \begin{bmatrix} 4 \\\\ 0 \\\\ 7 \\\\ 1 \end{bmatrix} = \begin{bmatrix} 4 - 3 \\\\ 0 + 2 \\\\ 7 - 4 \\\\ 1 \end{bmatrix} = \begin{bmatrix} 1 \\\\ 2 \\\\ 3 \\\\ 1 \end{bmatrix}
$$

The multiplication successfully restores our original point $\vec{p}$.

---

## Part 2: Conceptual Understanding

### 1. Behavior Difference: Points ($w=1$) vs. Vectors ($w=0$)

#### Algebraic Explanation
When performing homogeneous $4 \times 4$ matrix operations, a 3D coordinate is extended to a 4D column vector $[x, y, z, w]^T$. Pre-multiplying this vector by the translation matrix $T(\vec{t})$ resolves to the following system of linear equations:

$$
\begin{aligned}
x' &= 1 \cdot x + 0 \cdot y + 0 \cdot z + t_x \cdot w \\\\
y' &= 0 \cdot x + 1 \cdot y + 0 \cdot z + t_y \cdot w \\\\
z' &= 0 \cdot x + 0 \cdot y + 1 \cdot z + t_z \cdot w \\\\
w' &= 0 \cdot x + 0 \cdot y + 0 \cdot z + 1 \cdot w
\end{aligned}
$$

*   **For vectors ($w = 0$):** The translation components in the matrix are multiplied by $w = 0$, nullifying the translation parameters ($t_x \cdot 0 = 0$, etc.). The resulting coordinates remain unchanged:

$$
x' = x, \quad y' = y, \quad z' = z
$$

*   **For points ($w = 1$):** The translation components are multiplied by $w = 1$, adding the displacement offset directly to the coordinate components:

$$
x' = x + t_x, \quad y' = y + t_y, \quad z' = z + t_z
$$


#### Geometric Explanation
*   A **point** represents a specific position in space. Translating a point shifts its location, which geometrically requires modifying its coordinates.
*   A **vector** represents a direction and a magnitude (such as a displacement offset, a velocity, or a surface normal), independent of any origin. Moving or shifting a vector's starting location does not change its direction or length. Geometrically, vectors are invariant under translation, which homogeneous coordinates handle automatically by setting the $w$ component to $0$.

---
**Back to Question:** [[Q_06_Translations]] | **Related Concepts:** [[06_Translations]]
