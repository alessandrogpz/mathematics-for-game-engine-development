# Homogeneous Coordinates (The Solution)

In Euclidean geometry, coordinates are unique: a point in 3D space is represented by a single coordinate vector $[x, y, z]^T \in \mathbb{R}^3$. However, to represent translation and perspective projection as linear matrix operations, we must transition to **Projective Geometry** using **Homogeneous Coordinates**. 

Homogeneous coordinates represent $n$-dimensional points using $n+1$ components, mapping our 3D space into a 4-dimensional projective space ($\mathbb{P}^3$).

---

## 1. Projective Space and Equivalence Classes

In 3D projective space $\mathbb{P}^3$, a point is defined by a 4-component vector:

$$
\vec{p} = \begin{bmatrix} x \\\\ y \\\\ z \\\\ w \end{bmatrix} \quad (\text{where } w \neq 0)
$$

Unlike Euclidean space, homogeneous coordinates are characterized by **scale invariance**. Multiplying the entire coordinate vector by any non-zero scalar $k$ does not change the geometric point it represents:

$$
\begin{bmatrix} x \\\\ y \\\\ z \\\\ w \end{bmatrix} \equiv \begin{bmatrix} kx \\\\ ky \\\\ kz \\\\ kw \end{bmatrix} \quad \text{for any } k \neq 0
$$

Because of this property, a single point in 3D Euclidean space corresponds to an **entire line (ray) passing through the origin in 4D space**.

---

## 2. The Projection Screen Analogy (The $w = 1$ Plane)

To visualize this projection, we can look at a lower-dimensional example: projecting a 3D homogeneous coordinate back into a 2D Euclidean coordinate. 

<center>
	<img src="../../98_Assets/Concepts/homogeneous_projection_2d_plane.webp" width="400" height="350">
</center>

In this scenario, our 2D Euclidean world is represented as the flat plane $w = 1$ embedded in 3D space. Any 3D homogeneous coordinate $[x, y, w]^T$ (where $w \neq 0$) represents a ray (line) passing through the origin in 3D space.

<center>
	<img src="../../98_Assets/Concepts/homogeneous_projection.webp" width="400" height="400">
</center>


Geometrically, converting back to 2D Euclidean coordinates is the equivalent of finding where this 3D ray intersects the $w = 1$ "screen" (plane). This process is called **Homogeneous Division** (or perspective division):

$$
\begin{bmatrix} x \\\\ y \\\\ w \end{bmatrix} \xrightarrow{\text{Divide by } w} \begin{bmatrix} x/w \\\\ y/w \\\\ 1 \end{bmatrix}
$$

Once $w = 1$, the first two components $[x/w, y/w]^T$ represent the standard 2D Euclidean coordinates of the point on our projection plane.

---

## 3. Points at Infinity ($w = 0$)

What happens if the $w$ component of a homogeneous coordinate is exactly $0$? 

If we take the limit as $w$ approaches $0$ for a point with a positive $w$:

$$
\lim_{w \to 0} \begin{bmatrix} x/w \\\\ y/w \\\\ z/w \end{bmatrix} = \infty \cdot \begin{bmatrix} x \\\\ y \\\\ z \end{bmatrix}
$$

The point moves infinitely far away along the direction vector $[x, y, z]^T$. Therefore, a homogeneous coordinate with $w = 0$:

$$
\vec{v} = \begin{bmatrix} x \\\\ y \\\\ z \\\\ 0 \end{bmatrix}
$$

represents a **Point at Infinity** (also known as an **Ideal Point**). 

### Connection to Vectors
In computer graphics, a direction vector (or velocity) has no defined position. It only has magnitude and direction. Since a point at infinity is infinitely far away, shifting it by a finite translation $\vec{t}$ has no effect on its position:

$$
\mathbf{T}(\vec{t})\vec{v} = \begin{bmatrix} 1 & 0 & 0 & t_x \\\\ 0 & 1 & 0 & t_y \\\\ 0 & 0 & 1 & t_z \\\\ 0 & 0 & 0 & 1 \end{bmatrix} \begin{bmatrix} x \\\\ y \\\\ z \\\\ 0 \end{bmatrix} = \begin{bmatrix} x \\\\ y \\\\ z \\\\ 0 \end{bmatrix}
$$

This provides the mathematical explanation for why directions (vectors) are defined with $w = 0$ and remain invariant under translation.

---

## 4. The Mathematical Bridge

Homogeneous coordinates act as a bridge that unifies different classes of transformations under a single linear algebra framework:
1.  **Linear Transformations:** Rotations, scales, reflections, and skews are represented in the upper-left $3 \times 3$ portion of the matrix.
2.  **Affine Transformations:** Translations are embedded using the 4th column.
3.  **Projective Transformations:** Perspective distortions are achieved by placing scaling values in the bottom row (which alters the $w$ component, forcing a non-uniform division by $w$).

By representing all of these operations as $4 \times 4$ matrices, they can be composed (multiplied together) into a single matrix before being applied to vertices.

---

## 5. Geometric Insight: Translation as a High-Dimensional Shear

The mathematical link between affine translations in $N$ dimensions and linear transformations in $N+1$ dimensions can be understood through **shearing (skewing)**. 

Consider the $3 \times 3$ matrix:

$$
\mathbf{H} = \begin{bmatrix} 1 & 0 & T_x \\\\ 0 & 1 & T_y \\\\ 0 & 0 & 1 \end{bmatrix}
$$

Depending on how you interpret the vectors it acts upon, this matrix has two identical algebraic but distinct geometric meanings:

1. **In 2D Homogeneous Coordinates ($w=1$):**
   It represents a **2D Translation** by the vector $[T_x, T_y]^T$:
   $$
   \begin{bmatrix} 1 & 0 & T_x \\\\ 0 & 1 & T_y \\\\ 0 & 0 & 1 \end{bmatrix} \begin{bmatrix} x \\\\ y \\\\ 1 \end{bmatrix} = \begin{bmatrix} x + T_x \\\\ y + T_y \\\\ 1 \end{bmatrix}
   $$

   <center>
   	<img src="../../98_Assets/Concepts/translation_2d_homogeneous.webp" width="500" height="350">
   </center>

2. **In 3D Euclidean Coordinates:**
   It represents a **3D Shear (Skew)** transformation along the $xy$-plane, where the shear displacement is proportional to the $z$ coordinate:
   $$
   \begin{bmatrix} 1 & 0 & T_x \\\\ 0 & 1 & T_y \\\\ 0 & 0 & 1 \end{bmatrix} \begin{bmatrix} x \\\\ y \\\\ z \end{bmatrix} = \begin{bmatrix} x + T_x z \\\\ y + T_y z \\\\ z \end{bmatrix}
   $$
   Here, points are shifted parallel to the $x$-axis by $T_x \cdot z$ and parallel to the $y$-axis by $T_y \cdot z$.

   <center>
   	<img src="../../98_Assets/Concepts/shear_3d_euclidean.webp" width="500" height="350">
   </center>

### The Equivalence
This equivalence is the fundamental secret of homogeneous coordinates: **a translation in $N$ dimensions is mathematically identical to a shear transformation in $(N+1)$-dimensional space.**

By lifting our 3D coordinates to 4D projective space and fixing the last coordinate to $w = 1$, we convert a non-linear translation into a linear shear transformation in the higher dimension.

---

## References & Resources

*   **YouTube Video:** [Quick Understanding of Homogeneous Coordinates for Computer Graphics](https://www.youtube.com/watch?v=o-xwmTODTUI)
*   **YouTube Video:** [4D Thinking for 3D Graphics](https://www.youtube.com/watch?v=naatDSe6v1c)

---

## Code Implementation

*   **C++ Source Code:** [[03_Code/04_Transforms/07_Homogeneous_Coordinates.cppm|07_Homogeneous_Coordinates.cppm]]
