# Quaternions

Quaternions are a four-dimensional extension of complex numbers. While complex numbers extend the real numbers into a 2D plane ($\mathbb{C} = \mathbb{R} + i\mathbb{R}$), quaternions extend them into a 4D space ($\mathbb{H} = \mathbb{R} + i\mathbb{R} + j\mathbb{R} + k\mathbb{R}$). 

In graphics programming, game engines, physics simulations, and quantum mechanics, quaternions provide an elegant, compact, and computationally efficient way to represent and compute 3D rotations without suffering from **Gimbal Lock**.

---

## 1. Geometric Intuition: Dimensional Projections

To build an intuitive understanding of a 4D object (like a quaternion) operating in our 3D world, we can study how rotation in $N$-dimensional space is viewed by projecting it down into $N-1$ dimensions using **Stereographic Projection**.

### 1D Projection (Rotating a 2D Circle onto a Line)
Consider a 2D unit circle (a 1-sphere, $S^1$) sitting in a 2D plane. We can project this circle onto a 1D vertical line (the $y$-axis) using a projection source at the point $(-1, 0)$:
1. Draw a straight line from the projection source $(-1, 0)$ through any point on the circle.
2. The intersection of this line with the vertical $y$-axis is the stereographic projection of that point.

<center>
  <!-- Placeholder for 1D Projection Diagram: mapping_circle_to_line.webp -->
  <img src="../../98_Assets/Concepts/mapping_circle_to_line.webp" width="400" height="300" alt="Stereographic projection of a 2D circle onto a 1D line">
</center>

As the circle rotates in 2D space, the projected points run along the 1D line:
*   The point $+1$ on the circle projects to the origin ($0$) on the line.
*   The points $i$ and $-i$ project to $+1$ and $-1$ on the line, respectively.
*   The point $-1$ (the projection source itself) projects to infinity ($\pm\infty$).

Multiplying by the imaginary unit $i$ four times ($i^4 = 1$) corresponds to rotating the circle by $90^\circ$ four times in a row, which returns the point on the line to where it started.

### 2D Projection (Rotating a 3D Sphere onto a Plane)
We can scale this up by projecting a 3D unit sphere (a 2-sphere, $S^2$, defined by $w^2 + x^2 + y^2 = 1$) onto a 2D plane (the $xy$-plane) from the projection source $(-1, 0, 0)$:
1. Draw a line from the projection source $(-1, 0, 0)$ through any point on the sphere.
2. The intersection of this line with the 2D plane is its projected point.

<center>
  <!-- Placeholder for 2D Projection Diagram: mapping_sphere_to_plane.webp -->
  <img src="../../98_Assets/Concepts/mapping_sphere_to_plane.webp" width="400" height="300" alt="Stereographic projection of a 3D sphere onto a 2D plane">
</center>

Looking at the 2D plane from above:
*   All points on the unit circle that pass through $i, j, -i, -j$ stay fixed in place.
*   Points on the hemisphere containing the point $+1$ project **inside** the unit circle.
*   Points on the hemisphere containing the projection source $-1$ project **outside** the unit circle.

When we rotate the 3D sphere, the projected coordinate lines on the 2D plane warp and behave in the same way as they did in the 1D case, preserving angles (conformal mapping).

### 3D Projection (Rotating a 4D Hypersphere onto 3D Space)
By extension, a quaternion represents a point on a 4D unit hypersphere (a 3-sphere, $S^3$, defined by $w^2 + x^2 + y^2 + z^2 = 1$). 

We can visualize rotations of this 4D hypersphere by stereographically projecting it from the source $(-1, 0, 0, 0)$ onto our 3D space. 
*   Rotations in 4D space warp the projected 3D space grid.
*   The points on the 3D unit sphere stay fixed in place.
*   The hemisphere containing $+1$ projects inside the 3D unit sphere, while the hemisphere containing $-1$ projects outside it.

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

To rotate a 3D vector $\vec{v}$ using a unit quaternion $q$, we follow these steps:

1.  **Represent the Vector as a Pure Quaternion:**
    Convert $\vec{v} = [v_x, v_y, v_z]^T$ into a quaternion $p$ with a real part of zero:

$$
p = 0 + v_x i + v_y j + v_z k
$$

2.  **Define the Rotation Quaternion:**
    For a rotation of angle $\theta$ around a unit axis $\vec{u} = [u_x, u_y, u_z]^T$, the unit quaternion $q$ is:

$$
q = \cos\left(\frac{\theta}{2}\right) + \vec{u}\sin\left(\frac{\theta}{2}\right)
$$

3.  **Apply the Sandwich Rotation Formula:**
    The rotated vector $\vec{v}'$ is found by evaluating:

**(2.12)**

$$
p' = q p q^{-1}
$$

For a unit quaternion, the inverse is equal to its conjugate: $q^{-1} = q^* = \cos(\theta/2) - \vec{u}\sin(\theta/2)$.

### Why Double Multiplication ($qpq^{-1}$) is Required
If we only multiplied once (e.g. $qp$), the resulting quaternion would not be a pure quaternion; it would contain a non-zero real scalar component. Geometrically:
*   The first multiplication $qp$ rotates the vector in 4D space, pulling it out of the 3D imaginary subspace ($\mathbb{R} = 0$) into the real dimension.
*   The second multiplication by the inverse $q^{-1}$ (or conjugate $q^*$) acts as a key geometric correction, canceling out the displacement along the real dimension and projecting the vector back into the 3D imaginary subspace.
*   This double multiplication yields a pure quaternion $p' = 0 + \vec{v}'$, where the vector part contains the correctly rotated 3D vector.

<center>
  <!-- Placeholder for Sandwich Rotation Diagram: quaternion_sandwich_rotation.webp -->
  <img src="../../98_Assets/Concepts/quaternion_sandwich_rotation.webp" width="400" height="300" alt="Geometric visualization of the double multiplication pulling and projecting a vector back to 3D space">
</center>
