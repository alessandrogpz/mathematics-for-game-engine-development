# Lines and Rays

Lines and rays are basically the same thing mathematically, with one distinction: a **line** extends to infinity in both ends, while a **ray** starts at one point and then extends to infinity in one direction.

---

## Parametric Lines

A **parametric line** is a line whose points are expressed as functions of a single parameter.

$$
L(t) = (1 - t) P_1 + t P_2
$$

When $0 \le t \le 1$, the line bounds exactly at the segment connecting $P_1$ and $P_2$, where $P_1$ and $P_2$ are two points. Otherwise, the points fall elsewhere on the line extending to infinity.

The formula can be rewritten as:

$$
L(t) = P + t \mathbf{v}
$$

where:
* **$L(t)$** is the position on the line at any point $t$.
* **$P$** is a known point on the line.
* **$t \in \mathbb{R}$** is a scalar parameter.
* **$\mathbf{v} = \langle a, b, c \rangle$** is the direction vector parallel to the line.

<center>
	<img src="../../98_Assets/Concepts/parametric_line.webp" width="500" height="250" alt="Parametric Line Diagram">
</center>

---

## Distance Between a Point and a Line

To find the shortest distance $d$ from a point $q$ to a line $P + t\mathbf{v}$, we first construct the vector from $P$ to $q$:

$$
\mathbf{u} = q - P
$$

Geometrically, $d$ can be found directly without squaring. However, textbook formulas often start with $d^2$ or use a single large square root due to **Pythagorean relations** and **code performance optimizations**.

---

### Method 1: Rejection & Pythagorean Formula

The distance $d$ is equal to the magnitude of the [[06_Vector_Projection|rejection vector]] of $\mathbf{u}$ from $\mathbf{v}$:

$$
d = \|\mathbf{u} - \text{proj}_{\mathbf{v}}\mathbf{u}\|
$$

Because the projection, rejection, and hypotenuse $\mathbf{u}$ form a right triangle, the **Pythagorean theorem** ($a^2 + b^2 = c^2$) gives:

$$
\|\mathbf{u}\|^2 = u_{\|r}\|^2 + u_{\perp r}^2 \implies d^2 = u^2 - u_{\|r}\|^2
$$

Substituting the projection $u_{\|r} = \frac{\mathbf{u} \cdot \mathbf{v}}{v^2}\mathbf{v}$:

$$
d^2 = u^2 - \frac{(\mathbf{u} \cdot \mathbf{v})^2}{v^2} \implies d = \sqrt{u^2 - \frac{(\mathbf{u} \cdot \mathbf{v})^2}{v^2}}
$$

---

### Method 2: Parallelogram Area / Base Formula

Geometrically, the area of the parallelogram formed by $\mathbf{u}$ and $\mathbf{v}$ ([[04_Cross_Product|cross product]]) is $\text{Area} = \text{base} \times \text{height} = \|\mathbf{v}\| \times d$. 

Rearranging directly yields the un-squared formula for $d$:

$$
d = \frac{\|\mathbf{u} \times \mathbf{v}\|}{\|\mathbf{v}\|}
$$

<center>
	<img src="../../98_Assets/Concepts/distance_point_line_parallelogram.webp" width="350" height="300" alt="Distance between Point and Line via Parallelogram">
</center>

#### Why Books Write $d = \sqrt{\frac{(\mathbf{u} \times \mathbf{v})^2}{v^2}}$ (Code Optimization):
Calculating vector magnitudes in computer graphics requires `sqrt()`, which is a slow instruction. Computing $\|\mathbf{u} \times \mathbf{v}\| / \|\mathbf{v}\|$ directly requires **two separate `sqrt()` calls**. Keeping terms squared inside a single radical reduces this to a **single `sqrt()` call** at the very end.

---

### Summary

| Method | Pure Geometric Formula (Direct $d$) | Code-Optimized / Pythagorean Formula |
| :--- | :--- | :--- |
| **Rejection** | $d = \|\mathbf{u} - \text{proj}_{\mathbf{v}}\mathbf{u}\|$ | $d = \sqrt{u^2 - \frac{(\mathbf{u} \cdot \mathbf{v})^2}{v^2}}$ |
| **Area / Base** | $d = \frac{\|\mathbf{u} \times \mathbf{v}\|}{\|\mathbf{v}\|}$ | $d = \sqrt{\frac{(\mathbf{u} \times \mathbf{v})^2}{v^2}}$ |
