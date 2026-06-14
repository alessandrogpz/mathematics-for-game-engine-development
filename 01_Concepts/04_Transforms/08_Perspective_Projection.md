# Perspective Projection

Perspective projection is the transformation that maps a 3D scene onto a 2D viewport (screen), mimicking how the human eye and camera lenses perceive the world: objects that are farther away appear smaller than objects close to the viewer. 

Because perspective projection scales coordinates inversely with depth ($z$), it is non-linear in Euclidean space $\mathbb{R}^3$. Homogeneous coordinates allow us to represent this non-linear division as a linear $4 \times 4$ matrix transformation.

---

## 1. The Geometry of Perspective (The Pinhole Camera)

To project a 3D point onto a 2D screen, we look at similar triangles. Suppose the camera is placed at the origin looking down the negative $z$-axis. The projection screen (near plane) is placed at a distance $d$ (representing focal length) along the viewing axis.

For any point $P(x, y, z)$, its projection $P'(x', y')$ on the screen is determined by the intersection of the ray from $P$ to the camera center with the near plane $z = -d$.

<center>
	<img src="../../98_Assets/Concepts/perspective_similar_triangles.webp" width="600" height="350">
</center>

Using the property of similar triangles along the vertical plane:

$$
\frac{y'}{d} = \frac{y}{-z} \implies y' = -d \frac{y}{z}
$$

Similarly, along the horizontal plane:

$$
\frac{x'}{d} = \frac{x}{-z} \implies x' = -d \frac{x}{z}
$$

Both projected coordinates $x'$ and $y'$ are divided by the depth coordinate $z$. This division by depth is the non-linear aspect of perspective projection.

---

## 2. Deriving the Perspective Matrix

In a standard matrix multiplication, we cannot directly divide one coordinate by another. However, homogeneous coordinates resolve this:
1.  We construct a matrix that copies the depth information into the $w$ component of the output vector (specifically, setting $w' = -z$).
2.  We perform the standard **Homogeneous Division** (division by $w$) after the matrix multiplication, which automatically divides all coordinates by depth.

Suppose we want a matrix $\mathbf{P}$ that transforms our point such that:

$$
\mathbf{P}\begin{bmatrix} x \\\\ y \\\\ z \\\\ 1 \end{bmatrix} = \begin{bmatrix} dx \\\\ dy \\\\ Az + B \\\\ -z \end{bmatrix}
$$

Applying homogeneous division (dividing by the output $w' = -z$) yields the projected coordinate:

$$
\begin{bmatrix} dx / -z \\\\ dy / -z \\\\ (Az+B) / -z \\\\ 1 \end{bmatrix} = \begin{bmatrix} -d \frac{x}{z} \\\\ -d \frac{y}{z} \\\\ \text{depth} \\\\ 1 \end{bmatrix}
$$

This matches the similar triangle formulas exactly! We can write this linear matrix equation as:

$$
\mathbf{P} = \begin{bmatrix} d & 0 & 0 & 0 \\\\ 0 & d & 0 & 0 \\\\ 0 & 0 & A & B \\\\ 0 & 0 & -1 & 0 \end{bmatrix}
$$

---

## 3. The Standard Perspective Projection Matrix

To fully define the matrix, we must find the values $A$ and $B$. In computer graphics, we want the depth range $[n, f]$ (where $n$ is the near plane and $f$ is the far plane along the negative $z$-axis) to map to a normalized depth range $[-1, 1]$ (or $[0, 1]$ in DirectX).

For normalized device coordinates (NDC) range $[-1, 1]$ in OpenGL:
1.  A point at the near plane ($z = -n$) must map to depth $-1$.
2.  A point at the far plane ($z = -f$) must map to depth $1$.

Substituting these conditions into the depth equation:

$$
\frac{A(-n) + B}{n} = -1 \implies -An + B = -n
$$

$$
\frac{A(-f) + B}{f} = 1 \implies -Af + B = f
$$

Solving this system of linear equations for $A$ and $B$:

$$
A = -\frac{f+n}{f-n}, \quad B = -\frac{2fn}{f-n}
$$

Additionally, to account for field of view ($\theta$) and the aspect ratio ($r = \text{width}/\text{height}$), the focal length is defined as $d = \cot(\theta/2)$, and the horizontal scale is adjusted by $1/r$. This yields the standard **Perspective Projection Matrix**:

$$
\mathbf{P} = \begin{bmatrix} \frac{\cot(\theta/2)}{r} & 0 & 0 & 0 \\\\ 0 & \cot(\theta/2) & 0 & 0 \\\\ 0 & 0 & -\frac{f+n}{f-n} & -\frac{2fn}{f-n} \\\\ 0 & 0 & -1 & 0 \end{bmatrix}
$$

---

## References & Resources

*   **YouTube Video:** [Quick Understanding of Homogeneous Coordinates for Computer Graphics](https://www.youtube.com/watch?v=o-xwmTODTUI)
*   **YouTube Video:** [4D Thinking for 3D Graphics](https://www.youtube.com/watch?v=naatDSe6v1c)

---

## Code Implementation

*   **C++ Source Code:** [[03_Code/04_Transforms/08_Perspective_Projection.cppm|08_Perspective_Projection.cppm]]
