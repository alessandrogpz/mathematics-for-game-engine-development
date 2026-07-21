# Translations (The Problem)

In computer graphics, physics simulations, and geometric modeling, translation is the transformation that moves an object's position in space from one coordinate to another. Unlike rotation, scaling, reflection, and skew—which are all linear transformations that operate relative to the origin—translation is an affine transformation that shifts all points uniformly, regardless of their distance from the origin.

---

## 1. Geometric Definition of Translation

Until now, all our 3D transformations assumed that our object (or vector) was centered at the world origin. Translation moves an object within the coordinate system by adding a constant offset vector $\vec{t}$ to every point of the object:

$$
\vec{v}' = \vec{v} + \vec{t}
$$

### 2D Example
Consider a 2D square object $v$ defined by the following points:

$$
v_1 = \begin{bmatrix} 1 \\\\ 1 \end{bmatrix}, \quad v_2 = \begin{bmatrix} 2 \\\\ 1 \end{bmatrix}, \quad v_3 = \begin{bmatrix} 1 \\\\ 2 \end{bmatrix}, \quad v_4 = \begin{bmatrix} 2 \\\\ 2 \end{bmatrix}
$$

Let's translate this square $2$ units in the $x$-direction and $1$ unit in the $y$-direction, using the translation vector $\vec{t} = [2, 1]^T$:

$$
v'_i = v_i + \vec{t}
$$

Calculating the new points:

$$
v'_1 = \begin{bmatrix} 1+2 \\\\ 1+1 \end{bmatrix} = \begin{bmatrix} 3 \\\\ 2 \end{bmatrix}, \quad v'_2 = \begin{bmatrix} 4 \\\\ 2 \end{bmatrix}, \quad v'_3 = \begin{bmatrix} 3 \\\\ 3 \end{bmatrix}, \quad v'_4 = \begin{bmatrix} 4 \\\\ 3 \end{bmatrix}
$$

For any point on the object, adding $\vec{t}$ shifts it to its new corresponding position.

<center>
	<img src="../../98_Assets/Concepts/translation_2d_example.webp" width="400" height="300">
</center>

---

## 2. The Mathematical Bottleneck

We cannot represent translation using a standard $3 \times 3$ (or $2 \times 2$ in 2D) matrix multiplication. 

By definition, any linear transformation $f(\vec{v}) = \mathbf{M}\vec{v}$ must preserve the origin (i.e., mapping the origin to itself):

$$
f(\vec{0}) = \vec{0}
$$

If we attempt to represent a translation using a standard $3 \times 3$ matrix multiplication on the origin $\vec{0} = [0, 0, 0]^T$, it always yields the origin:

$$
\mathbf{M}\vec{0} = \begin{bmatrix} M_{00} & M_{01} & M_{02} \\\\ M_{10} & M_{11} & M_{12} \\\\ M_{20} & M_{21} & M_{22} \end{bmatrix} \begin{bmatrix} 0 \\\\ 0 \\\\ 0 \end{bmatrix} = \begin{bmatrix} 0 \\\\ 0 \\\\ 0 \end{bmatrix}
$$

However, a translation by a non-zero vector $\vec{t}$ must shift the origin to a new position:

$$
\vec{0}' = \vec{0} + \vec{t} = \vec{t} \neq \vec{0}
$$

Because translation does not preserve the origin, it is **not a linear transformation**. It is an **affine transformation** (a linear transformation followed by a vector addition):

$$
\vec{v}' = \mathbf{M}\vec{v} + \vec{t}
$$

This creates a major bottleneck: we cannot combine (compose) a sequence of rotations, scales, and translations into a single matrix multiplication using standard 3D vectors and $3 \times 3$ matrices.

---

## 3. The Solution: Introducing a New Dimension

To combine translations with other transformations into a single matrix operation, we must introduce an additional dimension. This leads to the concept of **[[07_Homogeneous_Coordinates|homogeneous coordinates]]**.

Let's see how this works for a 2D vector $[x, y]^T$. We start with the identity transformation:

$$
\begin{bmatrix} 1 & 0 \\\\ 0 & 1 \end{bmatrix} \begin{bmatrix} x \\\\ y \end{bmatrix} = \begin{bmatrix} x \\\\ y \end{bmatrix}
$$

We expand this matrix to $3 \times 3$ by adding a new row and column, and set the third component of the vector to $1$:

$$
\begin{bmatrix} 1 & 0 & 0 \\\\ 0 & 1 & 0 \\\\ 0 & 0 & 1 \end{bmatrix} \begin{bmatrix} x \\\\ y \\\\ 1 \end{bmatrix} = \begin{bmatrix} x \\\\ y \\\\ 1 \end{bmatrix}
$$

Now, we place our translation offsets $t_x, t_y$ in the upper-right column of the matrix:

$$
\mathbf{H} = \begin{bmatrix} 1 & 0 & t_x \\\\ 0 & 1 & t_y \\\\ 0 & 0 & 1 \end{bmatrix}
$$

Performing the matrix multiplication:

$$
\mathbf{H}\begin{bmatrix} x \\\\ y \\\\ 1 \end{bmatrix} = \begin{bmatrix} 1(x) + 0(y) + t_x(1) \\\\ 0(x) + 1(y) + t_y(1) \\\\ 0(x) + 0(y) + 1(1) \end{bmatrix} = \begin{bmatrix} x + t_x \\\\ y + t_y \\\\ 1 \end{bmatrix}
$$

This yields the exact same translated coordinates. For 3D space, this generalizes to a $4 \times 4$ **Translation Matrix** acting on 4-component vectors $[x, y, z, 1]^T$:

$$
\mathbf{T}(\vec{t}) = \begin{bmatrix} 1 & 0 & 0 & t_x \\\\ 0 & 1 & 0 & t_y \\\\ 0 & 0 & 1 & t_z \\\\ 0 & 0 & 0 & 1 \end{bmatrix}
$$

---

## 4. Unifying Transformations (Affine Block Form)

By using homogeneous matrices, we can represent any combination of 3D linear transformations (rotation, scale, reflection, skew) and 3D translation as a single, unified $4 \times 4$ matrix:

$$
\mathbf{H} = \begin{bmatrix} \mathbf{M} & \vec{t} \\\\ \vec{0}^T & 1 \end{bmatrix} = \begin{bmatrix} M_{00} & M_{01} & M_{02} & t_x \\\\ M_{10} & M_{11} & M_{12} & t_y \\\\ M_{20} & M_{21} & M_{22} & t_z \\\\ 0 & 0 & 0 & 1 \end{bmatrix}
$$

Where:
*   $\mathbf{M}$ is the $3 \times 3$ linear transformation matrix.
*   $\vec{t}$ is the $3 \times 1$ translation vector.

### Order of Operations
Because matrix multiplication is non-commutative, the order in which we apply transformations matters. Algebraically, the standard transformation order applies scale first, then rotation, and finally translation:

$$
\vec{v}' = \mathbf{T}(\vec{t}) \cdot \mathbf{R} \cdot \mathbf{S} \cdot \vec{v}
$$

In homogeneous matrix composition, this corresponds to:

$$
\mathbf{M}_{\text{total}} = \mathbf{T} \times \mathbf{R} \times \mathbf{S}
$$

---

## 5. Points vs. Vectors ($w = 1$ vs. $w = 0$)

Introducing the 4th component ($w$) allows us to distinguish between **points** (positions in space) and **vectors** (directions/velocities):

1.  **Points ($w = 1$):** Positions that *should* be moved by translation.
    
$$
\begin{bmatrix} 1 & 0 & 0 & t_x \\\\ 0 & 1 & 0 & t_y \\\\ 0 & 0 & 1 & t_z \\\\ 0 & 0 & 0 & 1 \end{bmatrix} \begin{bmatrix} x \\\\ y \\\\ z \\\\ 1 \end{bmatrix} = \begin{bmatrix} x + t_x \\\\ y + t_y \\\\ z + t_z \\\\ 1 \end{bmatrix} \quad (\text{Translated})
$$

2.  **Vectors ($w = 0$):** Directions or displacements that are position-independent and *should not* be affected by translation.
    
$$
\begin{bmatrix} 1 & 0 & 0 & t_x \\\\ 0 & 1 & 0 & t_y \\\\ 0 & 0 & 1 & t_z \\\\ 0 & 0 & 0 & 1 \end{bmatrix} \begin{bmatrix} x \\\\ y \\\\ z \\\\ 0 \end{bmatrix} = \begin{bmatrix} x \\\\ y \\\\ z \\\\ 0 \end{bmatrix} \quad (\text{Not Translated})
$$

Setting the $w$ component to $0$ zeroes out the translation column during multiplication, ensuring directions/vectors remain invariant under translation.

---

## 6. Inverse Translation Matrix

To undo a translation by a vector $\vec{t}$, we apply a translation in the opposite direction by $-\vec{t}$. The inverse of the translation matrix is:

$$
\mathbf{T}(\vec{t})^{-1} = \mathbf{T}(-\vec{t}) = \begin{bmatrix} 1 & 0 & 0 & -t_x \\\\ 0 & 1 & 0 & -t_y \\\\ 0 & 0 & 1 & -t_z \\\\ 0 & 0 & 0 & 1 \end{bmatrix}
$$

---

## References & Resources

*   **YouTube Video:** [Quick Understanding of Homogeneous Coordinates for Computer Graphics](https://www.youtube.com/watch?v=o-xwmTODTUI)
*   **YouTube Video:** [4D Thinking for 3D Graphics](https://www.youtube.com/watch?v=naatDSe6v1c)

---
## Code Implementation

*   **C++ Source Code:** [[03_Code/04_Transforms/Translations.cppm|Translations.cppm]]
