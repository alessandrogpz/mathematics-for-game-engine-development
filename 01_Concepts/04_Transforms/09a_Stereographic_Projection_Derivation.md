# Derivation & Intuition: Stereographic Projection

Stereographic projection is a conformal mapping that projects points from a sphere (or circle) onto a flat plane (or line) through a projection source (or pole). This note provides both the geometric intuition of the line equation and the step-by-step linear algebra derivations for 1D and 2D projections.

---

## 1. Intuition: The Parametric Line Equation

In the equation $\text{Line}(t)$, **$t$ is a scalar parameter**. You can think of it as a slider or a timeline that tracks your position as you move along an infinite straight line.

A parametric line equation always follows this structure:

$$
\text{Line}(t) = \text{Start Point} + t \times (\text{Direction Vector})
$$

In our stereographic projection example, the line represents the path of the light beam:

* **When $t = 0$:** You are exactly at the starting point (the light source/pole).
* **When $t = 1$:** You are exactly at the destination point on the sphere's surface.
* **When $t$ is any other number:** You are moving along that same light beam. If $t > 1$, you have passed through the sphere and are continuing out into space.

By setting the $w$ component of the line to $0$, we are asking the math: *"At what exact value of $t$ does this light beam slice through the flat $w=0$ plane?"* Solving for $t$ gives us the exact scale factor needed to find the coordinates on the screen.

---

## 2. 1D Projection: 2D Circle to 1D Line

We start with a 2D unit circle defined by $w^2 + x^2 = 1$ in the real-imaginary plane $(w, x)$. We want to find where a line connecting the projection pole (light source) and a point on the circle $(w, x)$ intersects the vertical axis $w = 0$.

### Case 1: South Pole Source $(-1, 0)$

The line starting at the South Pole and passing through the circle point $(w, x)$ is:

$$
\text{Line}(t) = \begin{bmatrix} -1 \\\\ 0 \end{bmatrix} + t \left( \begin{bmatrix} w \\\\ x \end{bmatrix} - \begin{bmatrix} -1 \\\\ 0 \end{bmatrix} \right) = \begin{bmatrix} -1 + t(w + 1) \\\\ tx \end{bmatrix}
$$

To find where this line intersects the $w = 0$ axis, we set the first component ($w$-component) of the vector to $0$:

$$
-1 + t(w + 1) = 0 \implies t = \frac{1}{w + 1}
$$

Plugging this scale factor $t$ back into the vertical $x$-component yields the projection point:

$$
p = \frac{x}{w + 1}i
$$

---

### Case 2: North Pole Source $(1, 0)$

If the light source is at the North Pole, the line equation starts at $+1$ on the real axis:

$$
\text{Line}(t) = \begin{bmatrix} 1 \\\\ 0 \end{bmatrix} + t \left( \begin{bmatrix} w \\\\ x \end{bmatrix} - \begin{bmatrix} 1 \\\\ 0 \end{bmatrix} \right) = \begin{bmatrix} 1 + t(w - 1) \\\\ tx \end{bmatrix}
$$

Setting the $w$-component to $0$ to solve for the intersection with $w = 0$:

$$
1 + t(w - 1) = 0 \implies 1 = t(1 - w) \implies t = \frac{1}{1 - w}
$$

Plugging this scale factor $t$ back into the vertical $x$-component yields the modified projection point:

$$
p = \frac{x}{1 - w}i
$$

---

## 3. 2D Projection: 3D Sphere to 2D Plane

We scale this up to a 3D unit sphere defined by $w^2 + x^2 + y^2 = 1$ in coordinates $(w, x, y)$. We project from a pole on the real axis $w$ onto the horizontal $ij$-plane defined by $w = 0$.

### Case 1: South Pole Source $(-1, 0, 0)$

The line starting at the South Pole and passing through the sphere point $(w, x, y)$ is:

$$
\text{Line}(t) = \begin{bmatrix} -1 \\\\ 0 \\\\ 0 \end{bmatrix} + t \left( \begin{bmatrix} w \\\\ x \\\\ y \end{bmatrix} - \begin{bmatrix} -1 \\\\ 0 \\\\ 0 \end{bmatrix} \right) = \begin{bmatrix} -1 + t(w + 1) \\\\ tx \\\\ ty \end{bmatrix}
$$

Setting the first component ($w$-component) to $0$:

$$
-1 + t(w + 1) = 0 \implies t = \frac{1}{w + 1}
$$

Substituting $t$ into the $x$ and $y$ components gives the projection onto the $ij$-plane:

$$
p = \frac{x}{w + 1}i + \frac{y}{w + 1}j
$$

---

### Case 2: North Pole Source $(1, 0, 0)$

For a North Pole source, the line equation starts at $+1$ on the real axis:

$$
\text{Line}(t) = \begin{bmatrix} 1 \\\\ 0 \\\\ 0 \end{bmatrix} + t \left( \begin{bmatrix} w \\\\ x \\\\ y \end{bmatrix} - \begin{bmatrix} 1 \\\\ 0 \\\\ 0 \end{bmatrix} \right) = \begin{bmatrix} 1 + t(w - 1) \\\\ tx \\\\ ty \end{bmatrix}
$$

Setting the first component ($w$-component) to $0$:

$$
1 + t(w - 1) = 0 \implies 1 = t(1 - w) \implies t = \frac{1}{1 - w}
$$

Substituting $t$ into the $x$ and $y$ components gives the projection:

$$
p = \frac{x}{1 - w}i + \frac{y}{1 - w}j
$$

---

## 4. 3D Projection: 4D Hypersphere to 3D Space

By extension, a quaternion represents a point on a 4D unit hypersphere (a 3-sphere, $S^3$) defined by $w^2 + x^2 + y^2 + z^2 = 1$ in coordinates $(w, x, y, z)$. We project from a pole on the real axis $w$ onto the 3D hyperplane defined by $w = 0$ (our 3D space, spanned by $i, j, k$).

### Case 1: South Pole Source $(-1, 0, 0, 0)$

The line starting at the South Pole and passing through the hypersphere point $(w, x, y, z)$ is:

$$
\text{Line}(t) = \begin{bmatrix} -1 \\\\ 0 \\\\ 0 \\\\ 0 \end{bmatrix} + t \left( \begin{bmatrix} w \\\\ x \\\\ y \\\\ z \end{bmatrix} - \begin{bmatrix} -1 \\\\ 0 \\\\ 0 \\\\ 0 \end{bmatrix} \right) = \begin{bmatrix} -1 + t(w + 1) \\\\ tx \\\\ ty \\\\ tz \end{bmatrix}
$$

Setting the first component ($w$-component) to $0$ to find the intersection with the $w = 0$ hyperplane:

$$
-1 + t(w + 1) = 0 \implies t = \frac{1}{w + 1}
$$

Substituting this scale factor $t$ into the $x$, $y$, and $z$ components gives the projection onto our 3D space:

$$
p = \frac{x}{w + 1}i + \frac{y}{w + 1}j + \frac{z}{w + 1}k
$$

---

### Case 2: North Pole Source $(1, 0, 0, 0)$

For a North Pole source, the line equation starts at $+1$ on the real axis:

$$
\text{Line}(t) = \begin{bmatrix} 1 \\\\ 0 \\\\ 0 \\\\ 0 \end{bmatrix} + t \left( \begin{bmatrix} w \\\\ x \\\\ y \\\\ z \end{bmatrix} - \begin{bmatrix} 1 \\\\ 0 \\\\ 0 \\\\ 0 \end{bmatrix} \right) = \begin{bmatrix} 1 + t(w - 1) \\\\ tx \\\\ ty \\\\ tz \end{bmatrix}
$$

Setting the first component ($w$-component) to $0$:

$$
1 + t(w - 1) = 0 \implies 1 = t(1 - w) \implies t = \frac{1}{1 - w}
$$

Substituting this scale factor $t$ into the $x$, $y$, and $z$ components gives the projection:

$$
p = \frac{x}{1 - w}i + \frac{y}{1 - w}j + \frac{z}{1 - w}k
$$

---

## Related Concepts

* [[09_Quaternion_Intuition]]
* [[10_Quaternions]]
