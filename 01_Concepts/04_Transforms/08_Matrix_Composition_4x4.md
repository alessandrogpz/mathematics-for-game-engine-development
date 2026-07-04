# Matrix Composition in 4x4 (The Integration)

This note will bring everything together, showing how the $3 \times 3$ rotation, reflection, and scaling matrices combine with translation into a single unified $4 \times 4$ matrix.

---

## 1. Combining 3D Transforms with Translation

To represent 3D affine transformations (rotation, scale, reflection) alongside translation as a single matrix multiplication, we expand our coordinates to 4D homogeneous coordinates $[x, y, z, 1]^T$ and use a $4 \times 4$ matrix.

For a 3D transformation represented by a $3 \times 3$ matrix $\mathbf{M}_{3 \times 3}$ and a translation represented by a vector $\vec{t} = [t_x, t_y, t_z]^T$:
*   The $3 \times 3$ transformation matrix occupies the top-left submatrix.
*   The translation vector occupies the rightmost column.
*   The bottom row is filled with $[0, 0, 0, 1]$ to preserve the homogeneous coordinate $w=1$.

$$
\mathbf{T}_{\text{combined}} = \begin{bmatrix} M_{11} & M_{12} & M_{13} & | & t_x \\\\ M_{21} & M_{22} & M_{23} & | & t_y \\\\ M_{31} & M_{32} & M_{33} & | & t_z \\\\ - & - & - & + & - \\\\ 0 & 0 & 0 & | & 1 \end{bmatrix}
$$

Multiplying this matrix by a point $[x, y, z, 1]^T$ yields:

$$
\mathbf{T}_{\text{combined}} \begin{bmatrix} x \\\\ y \\\\ z \\\\ 1 \end{bmatrix} = \begin{bmatrix} M_{11}x + M_{12}y + M_{13}z + t_x \\\\ M_{21}x + M_{22}y + M_{23}z + t_y \\\\ M_{31}x + M_{32}y + M_{33}z + t_z \\\\ 1 \end{bmatrix} = \mathbf{M}_{3 \times 3}\vec{v} + \vec{t}
$$

This embeds the vector addition $\mathbf{M}_{3\times3}\vec{v} + \vec{t}$ directly into a single matrix multiplication, enabling us to chain translations together with other transformations.

---

## 2. The Model-View-Projection (MVP) Pipeline

In a game, an object's vertex undergoes many changes before it hits the screen:
* **Model Transform:** Scale, rotate, and translate the object into the world.
* **View Transform:** Move and rotate it relative to the camera's position.
* **Projection Transform:** Apply perspective based on the camera lens.

Without a unified $4 \times 4$ system, the math would look like a messy chain of separate multiplications and additions for every single vertex:

$$
\text{Vertex}' = P \cdot (R_v \cdot (R_m \cdot v + t_m) + t_v)
$$

Because homogeneous coordinates allow every single one of these operations (including translation and perspective) to be written as a $4 \times 4$ matrix, you can multiply all the matrices together first, before touching any vertices:

$$
M_{\text{Total}} = M_{\text{Projection}} \times M_{\text{View}} \times M_{\text{Model}}
$$

The engine calculates $M_{\text{Total}}$ just once per object. Then, the graphics card only has to perform a single matrix-vector multiplication for each of the millions of vertices:

$$
\text{Vertex}' = M_{\text{Total}} \cdot v
$$

---

## 3. Perspective Projection

Perspective projection models how a 3D scene is projected onto a 2D viewport, replicating the human eye where objects that are further away appear smaller.

### A. The Similar Triangles Problem
Geometrically, if a point $P(x, y, z)$ in camera space is projected onto a screen at a distance $d$ along the $z$-axis, we can calculate the projected coordinates $(x_p, y_p)$ using similar triangles:

$$
x_p = \frac{d \cdot x}{z}, \quad y_p = \frac{d \cdot y}{z}
$$

Because this requires division by the depth coordinate $z$, it is a non-linear operation. We cannot write this directly as a standard linear matrix multiplication on Euclidean coordinates.

### B. Perspective Projection Matrix and Homogeneous Division
Homogeneous coordinates solve this problem by allowing us to delay the division. We construct a $4 \times 4$ projection matrix that places the depth coordinate $z$ (or a value proportional to it) into the $w$-component of the output vector:

$$
\mathbf{P}_{\text{persp}} = \begin{bmatrix} 1 & 0 & 0 & 0 \\\\ 0 & 1 & 0 & 0 \\\\ 0 & 0 & 1 & 0 \\\\ 0 & 0 & \frac{1}{d} & 0 \end{bmatrix}
$$

Multiplying this matrix by our point $[x, y, z, 1]^T$:

$$
\vec{p}' = \mathbf{P}_{\text{persp}} \begin{bmatrix} x \\\\ y \\\\ z \\\\ 1 \end{bmatrix} = \begin{bmatrix} x \\\\ y \\\\ z \\\\ \frac{z}{d} \end{bmatrix}
$$

After the matrix multiplication, the graphics hardware automatically performs **Homogeneous Division** (perspective division), dividing the first three coordinates by the $w$-coordinate ($w = z/d$):

$$
\vec{p}_{\text{Euclidean}}' = \begin{bmatrix} \frac{x}{z/d} \\\\ \frac{y}{z/d} \\\\ \frac{z}{z/d} \end{bmatrix} = \begin{bmatrix} \frac{d \cdot x}{z} \\\\ \frac{d \cdot y}{z} \\\\ d \end{bmatrix}
$$

This division squishes objects as they move further away, creating the perspective effect.

---

## Code Implementation

*   **C++ Source Code:** [[03_Code/04_Transforms/09_Matrix_Composition_4x4.cppm|09_Matrix_Composition_4x4.cppm]]
