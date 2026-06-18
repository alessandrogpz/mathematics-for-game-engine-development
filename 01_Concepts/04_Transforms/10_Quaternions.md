# Quaternions

Quaternions are a four-dimensional extension of complex numbers. While complex numbers extend the real numbers into a 2D plane ($\mathbb{C} = \mathbb{R} + i\mathbb{R}$), quaternions extend them into a 4D space ($\mathbb{H} = \mathbb{R} + i\mathbb{R} + j\mathbb{R} + k\mathbb{R}$). 

In graphics programming, game engines, physics simulations, and quantum mechanics, quaternions provide an elegant, compact, and computationally efficient way to represent and compute 3D rotations without suffering from **Gimbal Lock**.

---

## 1. Geometric Intuition: Dimensional Projections

To build an intuitive understanding of a 4D object (like a quaternion) operating in our 3D world, we can study how rotation in $N$-dimensional space is viewed by projecting it down into $N-1$ dimensions using **Stereographic Projection**. This conformal (angle-preserving) mapping technique allows us to trace high-dimensional rotations as continuous motions and coordinate warping in lower-dimensional spaces.

### 1D Projection (Rotating a 2D Circle onto a Line)

Consider a 2D unit circle (a 1-sphere, $S^1$) sitting in a 2D plane defined by a real horizontal axis $w$ and an imaginary vertical axis $i$. The circle represents all complex numbers $z = w + xi$ with magnitude $\|z\| = 1$ (so $w^2 + x^2 = 1$). 

We project this circle onto the vertical 1D imaginary axis (the line $w = 0$) using a projection source at the "south pole" $(-1, 0)$, representing the point $-1$ on the real axis:
1. Draw a straight line from the projection source $(-1, 0)$ through any point $(w, x)$ on the circle.
2. The intersection of this line with the vertical axis ($w = 0$) is the stereographic projection of that point.

<center>
  <!-- Placeholder for 1D Projection Diagram: mapping_circle_to_line.webp -->
  <img src="../../98_Assets/Concepts/mapping_circle_to_line.webp" width="650" height="250" alt="Stereographic projection of a 2D circle onto a 1D line">
</center>

Algebraically, the stereographic projection $p$ of a point $w + xi$ is given by:

$$
p = \frac{x}{w + 1}i
$$

Under this mapping, specific reference points on the circle project as follows:
*   **The point $+1$ ($w = 1, x = 0$):** Projects to the origin ($0$) in the center of the vertical line.
*   **The point $i$ ($w = 0, x = 1$):** Projects to the point $i$ on the line.
*   **The point $-i$ ($w = 0, x = -1$):** Projects to the point $-i$ on the line.
*   **The point $-1$ ($w = -1, x = 0$):** Since this is the projection source, the projection line is horizontal and parallel to the vertical axis, projecting it to infinity ($\pm\infty$).

#### Visualizing Rotation as a Continuous Flow
If we rotate the circle counterclockwise (corresponding to successive multiplications by $i$: $1 \to i \to -1 \to -i \to 1$), we can watch how the projected points flow along the 1D line:

<center>
  <!-- Placeholder for 2D Projection Diagram: rotating_2D_streographic_projection.webp -->
  <img src="../../98_Assets/Concepts/rotating_2D_streographic_projection.webp" width="400" height="300" alt="Rotating stereographic projection of a 2D sphere onto a 1D line">
</center>

1. A point starting at the center (the projection of $+1$) flows **upwards** towards $i$.
2. As the circle continues to rotate towards $-1$, the projected point moves rapidly upwards past $i$ towards $+\infty$.
3. As the point on the circle crosses the south pole $-1$, its projection wraps around from $+\infty$ to $-\infty$.
4. The projected point then continues flowing upwards from $-\infty$ through $-i$, eventually returning to the center $0$.

Thus, a closed 2D rotation of the circle corresponds to a continuous, upward flow along the 1D line that wraps around at infinity.

### 2D Projection (Rotating a 3D Sphere onto a Plane)

We scale this concept up by projecting a 3D unit sphere (a 2-sphere, $S^2$) onto a 2D plane. Let the sphere be defined by $w^2 + x^2 + y^2 = 1$ in a 3D coordinate system where:
*   The vertical axis is the real axis ($w$, representing the scalar component).
*   The horizontal axes are the imaginary axes ($i$ and $j$, representing the vector components).

<center>
  <!-- Placeholder for 2D Projection Diagram: mapping_sphere_to_plane_1.webp -->
  <img src="../../98_Assets/Concepts/mapping_sphere_to_plane_1.webp" width="900" height="200" alt="Stereographic projection of a 3D sphere onto a 2D plane">
</center>

We project the sphere from the south pole $S = -1$ (the point $(-1, 0, 0)$ where the real component $w = -1$) onto the horizontal $ij$-plane ($w = 0$).

1. Draw a line from the projection source $(-1, 0, 0)$ through any point $(w, x, y)$ on the sphere.
2. The intersection of this line with the $ij$-plane is its projected point.

<center>
  <!-- Placeholder for 2D Projection Diagram: mapping_sphere_to_plane.webp -->
  <img src="../../98_Assets/Concepts/mapping_sphere_to_plane.webp" width="450" height="300" alt="Stereographic projection of a 3D sphere onto a 2D plane">
</center>

Algebraically, the projection of a sphere point $q = w + xi + yj$ onto the $ij$-plane is:

$$
p = \frac{x}{w + 1}i + \frac{y}{w + 1}j
$$

Looking at the $ij$-plane from above, this projection divides the sphere into three distinct regions:
*   **The Equator ($w = 0$):** The equator contains the imaginary unit coordinates ($i, j, -i, -j$). Since $w = 0$, the projection simplifies to $p = xi + yj$, meaning the equator projects exactly onto the unit circle in the plane, staying fixed in place.
*   **The Northern Hemisphere ($w > 0$):** Because $w > 0$, the scaling factor $\frac{1}{w+1}$ is less than $1$. This compresses the hemisphere containing the north pole $+1$ entirely **inside** the unit circle. The north pole $+1$ itself projects directly to the origin.
*   **The Southern Hemisphere ($w < 0$):** Because $w < 0$, the scaling factor $\frac{1}{w+1}$ is greater than $1$. This stretches the hemisphere containing the south pole $-1$ entirely **outside** the unit circle, with the south pole $-1$ projecting to infinity.

<center>
  <!-- Placeholder for 2D Projection Diagram: mapping_sphere_to_plane_3.webp -->
  <img src="../../98_Assets/Concepts/mapping_sphere_to_plane_3.webp" width="400" height="300" alt="Stereographic projection of a 3D sphere onto a 2D plane">
</center>

#### Visualizing Sphere Rotations
*   **Rotation around the Real Axis ($w$):** Since this rotation occurs entirely within the horizontal $ij$-plane, it projects to a simple, un-warped 2D rotation of the $ij$-plane around the origin.
*   **Rotation around an Axis in the $ij$-Plane:** This rotation mixes the real component $w$ with the imaginary components $x$ and $y$. On the plane, the projected coordinate grid (latitude and longitude lines) warps, compressing towards the origin as points rotate towards the north pole, and expanding outwards to infinity as they rotate towards the south pole.

### 3D Projection (Rotating a 4D Hypersphere onto 3D Space)

By extension, a quaternion represents a point on a 4D unit hypersphere (a 3-sphere, $S^3$), defined by:
*   $w^2 + x^2 + y^2 + z^2 = 1$ in a 4D space with one real axis $w$ and three imaginary axes $i, j, k$.

We can visualize 4D rotations of this hypersphere by stereographically projecting it from the pole $w = -1$ (the point $(-1, 0, 0, 0)$) onto our 3D space (the $ijk$-space, where $w = 0$).

Algebraically, the projection of a quaternion $q = w + xi + yj + zk$ is:

$$
p = \frac{x}{w + 1}i + \frac{y}{w + 1}j + \frac{z}{w + 1}k
$$

Under this projection:
*   **The 3D Equator ($w = 0$):** The set of points where the real component is zero forms a 3D unit sphere ($x^2 + y^2 + z^2 = 1$). This projects exactly onto the 3D unit sphere in our space, staying fixed.
*   **The Hyper-hemisphere containing $+1$ ($w > 0$):** Projects entirely **inside** our 3D unit sphere, with $+1$ mapping to the origin.
*   **The Hyper-hemisphere containing $-1$ ($w < 0$):** Projects entirely **outside** our 3D unit sphere, with $-1$ mapping to infinity.

As the 4D hypersphere rotates:
*   Rotations that only mix $i, j, k$ (leaving the real component $w$ unchanged) project to pure 3D rotations of our space.
*   Rotations that mix the real component $w$ with the imaginary components cause our 3D space grid to warp, expanding from the origin and stretching out to infinity or compressing inwards.

---

## 2. Algebraic Representation

A quaternion $q$ is defined as the sum of a real scalar part and three imaginary vector parts:

**Scalar-Vector Form**

$$
q = w + xi + yj + zk \quad \text{or} \quad q = s + \vec{v}
$$

Where:
*   $w$ (or $s$) is a real number representing the **scalar part**.
*   $x, y, z$ are real numbers, and $\vec{v} = [x, y, z]^T$ is the **vector part** representing the three imaginary dimensions.

### Fundamental Identities
The three imaginary dimensions are mutually perpendicular to the real axis and to each other. They satisfy the fundamental Hamilton relations:

**(2.9)**

$$
i^2 = j^2 = k^2 = ijk = -1
$$

Because multiplication is non-commutative, the order of multiplication determines the sign (similar to the cross product):

$$
ij = k \quad \implies \quad ji = -k
$$

$$
jk = i \quad \implies \quad kj = -i
$$

$$
ki = j \quad \implies \quad ik = -j
$$

<center>
  <!-- Placeholder for Quaternion Multiplication Circle: quaternion_multiplication_circle.webp -->
  <img src="../../98_Assets/Concepts/quaternion_multiplication_circle.webp" width="300" height="300" alt="Visual cycle of quaternion imaginary unit multiplication rules">
</center>

### The Grassmann Product (Quaternion Multiplication)
Using these identities, the product of two quaternions $q_1 = w_1 + x_1 i + y_1 j + z_1 k$ and $q_2 = w_2 + x_2 i + y_2 j + z_2 k$ can be expanded algebraically:

**(2.10)**

$$
q_1 q_2 = (w_1 w_2 - x_1 x_2 - y_1 y_2 - z_1 z_2) + (w_1 x_2 + x_1 w_2 + y_1 z_2 - z_1 y_2)i + (w_1 y_2 + y_1 w_2 + z_1 x_2 - x_1 z_2)j + (w_1 z_2 + z_1 w_2 + x_1 y_2 - y_1 x_2)k
$$

Using vector algebra, this product can be written compactly as:

$$
q_1 q_2 = (s_1 s_2 - \vec{v}_1 \cdot \vec{v}_2) + (s_1 \vec{v}_2 + s_2 \vec{v}_1 + \vec{v}_1 \times \vec{v}_2)
$$

---

## 3. Geometric Properties

### Magnitude
The magnitude (norm) of a quaternion is computed in the same way as complex numbers and Euclidean vectors:

**(2.11)**

$$
\|q\| = \sqrt{w^2 + x^2 + y^2 + z^2}
$$

A quaternion is a **unit quaternion** if $\|q\| = 1$. Unit quaternions represent pure rotations in 3D space.

### 4D Scaling and Rotation
Multiplying a quaternion $q_2$ by $q_1$ scales the magnitude of $q_2$ and rotates it in 4D space:

$$
q_1 q_2 = \|q_1\| \left( \frac{q_1}{\|q_1\|} q_2 \right)
$$

---

## 4. 3D Vector Rotation

To rotate a 3D vector $\vec{v}$ in space using a unit quaternion $q$, we use the sandwich product formula. This section explains the mathematical origin of the rotation quaternion, the inverse, and why this double multiplication is required.

### 1. Representing the Vector as a Pure Quaternion
First, we represent the 3D vector $\vec{v} = [v_x, v_y, v_z]^T$ as a "pure" quaternion $p$ (a quaternion with a real scalar part of zero):

$$
p = 0 + v_x i + v_y j + v_z k
$$

### 2. The Rotation Quaternion $q$: Origin of the Half-Angle
For a rotation of angle $\theta$ around a normalized unit axis $\vec{u} = [u_x, u_y, u_z]^T$, the unit quaternion $q$ is defined as:

$$
q = \cos\left(\frac{\theta}{2}\right) + \vec{u}\sin\left(\frac{\theta}{2}\right)
$$

#### Where does this formula come from?
This is the 4D generalization of **Euler's Formula** for 2D complex numbers:

$$
e^{i\theta} = \cos\theta + i\sin\theta
$$

In 2D, multiplying a complex number by $e^{i\theta}$ rotates it by the angle $\theta$. In 4D, the unit rotation axis $\vec{u} = u_x i + u_y j + u_z k$ behaves as a 3D imaginary unit ($\vec{u}^2 = -1$). Extending Euler's formula using the exponential map yields:

$$
e^{\vec{u}\phi} = \cos\phi + \vec{u}\sin\phi
$$

#### Why do we use the half-angle $\frac{\theta}{2}$ instead of the full angle $\theta$?
Because of the sandwich product $q p q^{-1}$, the rotation is applied **twice**: once as a pre-multiplication by $q$, and once as a post-multiplication by $q^{-1}$. 
* Each multiplication rotates the vector in 4D space by the angle $\phi$.
* These two rotations combine to produce a net rotation of $2\phi$.
* Therefore, to rotate by a target angle $\theta$, we must set the half-angle $\phi = \frac{\theta}{2}$.

### 3. The Inverse Quaternion $q^{-1}$: Definition and Role
The inverse of a quaternion $q$, denoted as $q^{-1}$, is the quaternion that satisfies:

$$
q q^{-1} = q^{-1} q = 1
$$

#### How is it calculated?
In general, the inverse of any quaternion is its conjugate divided by its squared magnitude: $q^{-1} = \frac{q^*}{\|q\|^2}$. However, for **unit quaternions** (which have a magnitude of $\|q\| = 1$), the inverse is simply equal to its **conjugate** $q^*$:

$$
q^{-1} = q^* = \cos\left(\frac{\theta}{2}\right) - \vec{u}\sin\left(\frac{\theta}{2}\right)
$$

The conjugate $q^*$ is found by negating the imaginary vector components. Geometrically, negating the vector part is equivalent to:
* Reversing the rotation axis: $-\vec{u}$
* Or equivalently, rotating by a negative angle: $\cos(-\theta/2) + \vec{u}\sin(-\theta/2) = \cos(\theta/2) - \vec{u}\sin(\theta/2)$.
Thus, $q^{-1}$ represents the exact **inverse rotation** (rotating by the same angle in the opposite direction).

### 4. The Sandwich Rotation Formula
To find the rotated vector $\vec{v}'$, we evaluate the sandwich product:

**(2.12)**

$$
p' = q p q^{-1}
$$

The result $p'$ is guaranteed to be a pure quaternion $p' = 0 + \vec{v}'$, where the vector part contains the correctly rotated 3D vector.

### 5. Why the Sandwich Product $qpq^{-1}$ is Required
If we only multiplied once (e.g. $p' = qp$), the operation would fail both algebraically and geometrically.

#### Algebraic Reason: Subspace Containment
Let's look at the result of a single multiplication $qp$ using the Grassmann product. Since $p$ is a pure vector ($s_p = 0$) and $q = s_q + \vec{v}_q$:

$$
q p = (s_q \cdot 0 - \vec{v}_q \cdot \vec{v}_p) + (s_q \vec{v}_p + 0 \cdot \vec{v}_q + \vec{v}_q \times \vec{v}_p)
$$

$$
q p = (-\vec{v}_q \cdot \vec{v}_p) + (s_q \vec{v}_p + \vec{v}_q \times \vec{v}_p)
$$

Notice that the real scalar part of the resulting quaternion is $-\vec{v}_q \cdot \vec{v}_p$. Because the dot product of the rotation axis and the vector is generally non-zero, **the result is not a 3D vector**. The single multiplication has pulled the vector out of our 3D imaginary space ($\mathbb{R} = 0$) and given it a real component.

By post-multiplying the result by $q^{-1}$, the real component is algebraically canceled out:

$$
\text{Re}(q p q^{-1}) = 0
$$

This ensures the final output remains in the 3D imaginary subspace.

#### Geometric Reason: 4D Hyperspace Projection
* **First Multiplication ($qp$):** Rotates the vector in 4D space by $\theta/2$. Because a 4D rotation occurs in a 2D plane, this rotation displaces the vector along the extra 4th dimension (the real axis).
* **Second Multiplication ($q^{-1}$):** Acts as a geometric correction. Because it multiplies from the right, it rotates the vector in the opposite direction in the real axis plane, canceling out the real-axis displacement while adding another $\theta/2$ rotation in the 3D plane. 
* **Net Result:** The vector is projected back into the 3D space, having completed a full rotation of $\theta$.

<center>
  <!-- Placeholder for Sandwich Rotation Diagram: quaternion_sandwich_rotation.webp -->
  <img src="../../98_Assets/Concepts/quaternion_sandwich_rotation.webp" width="400" height="300" alt="Geometric visualization of the double multiplication pulling and projecting a vector back to 3D space">
</center>

---

## References & Additional Resources

*   **Ben Eater & Grant Sanderson (3Blue1Brown) - Quaternions Interactive Visualizations:** [eater.net/quaternions](https://eater.net/quaternions)

