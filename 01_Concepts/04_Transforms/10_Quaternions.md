# Quaternions

> [!NOTE]
> For a detailed geometric intuition and the dimensional build-up using 1D, 2D, and 3D stereographic projections, see the optional background note: [[09_Quaternion_Intuition]].

In graphics programming, game engines, physics simulations, and quantum mechanics, quaternions provide an elegant, compact, and computationally efficient way to represent and compute 3D rotations without suffering from **Gimbal Lock**.

---

## 1. Algebraic Representation & Operations

Quaternions ($\mathbb{H}$) extend 2D complex numbers into 4D space. Algebraically, they consist of a real scalar component and a 3D imaginary vector component.

### Scalar-Vector Representation
A quaternion $q$ is represented as:

$$
q = w + xi + yj + zk \quad \text{or} \quad q = s + \vec{v}
$$

Where:
*   $s$ (or $w$) is a real scalar representing the **scalar part**.
*   $\vec{v} = [x, y, z]^T$ is a 3D vector representing the **vector part** along the three orthogonal imaginary axes $i, j, k$.

---

### Basic Operations

#### 1. Addition
Quaternion addition is performed component-wise:

$$
q_1 + q_2 = (s_1 + s_2) + (\vec{v}_1 + \vec{v}_2)
$$

This operation is both associative and commutative.

#### 2. Multiplication
Quaternion multiplication is **non-commutative** (order of multiplication matters). It is defined by Hamilton's fundamental identities:

**(2.9)**

$$
i^2 = j^2 = k^2 = ijk = -1
$$

These identities define the cyclic multiplication rules:

$$
ij = k, \quad jk = i, \quad ki = j
$$

Reversing the multiplication order negates the product (similar to the vector cross product):

$$
ji = -k, \quad kj = -i, \quad ik = -j
$$

##### Component Multiplication
By expanding the product of two quaternions $(w_1 + x_1 i + y_1 j + z_1 k)(w_2 + x_2 i + y_2 j + z_2 k)$ using the rules above, we get the component-wise formula:

$$
q_1 q_2 = (w_1 w_2 - x_1 x_2 - y_1 y_2 - z_1 z_2) + (x_1 w_2 + y_1 z_2 - z_1 y_2 + w_1 x_2)i + (y_1 w_2 + z_1 x_2 + w_1 y_2 - x_1 z_2)j + (z_1 w_2 + w_1 z_2 + x_1 y_2 - y_1 x_2)k
$$

##### Vector Multiplication (The Grassmann Product)
Using vector algebra, we can write this product in a much more intuitive, compact form:

**(2.10)**

$$
q_1 q_2 = (s_1 s_2 - \vec{v}_1 \cdot \vec{v}_2) + (s_1 \vec{v}_2 + s_2 \vec{v}_1 + \vec{v}_1 \times \vec{v}_2)
$$

This splits the result into:
*   **Scalar part:** $s_1 s_2 - \vec{v}_1 \cdot \vec{v}_2$ (the product of the scalars minus the [[02_Dot_Product|dot product]] of the vectors).
*   **Vector part:** $s_1 \vec{v}_2 + s_2 \vec{v}_1 + \vec{v}_1 \times \vec{v}_2$ (the scaled vector parts plus their [[04_Cross_Product|cross product]]).

##### The Commutativity Difference
Because the vector part contains a cross product, reversing the order of multiplication yields a different result:

$$
q_2 q_1 = q_1 q_2 - 2(\vec{v}_1 \times \vec{v}_2)
$$

This reveals a key geometric property: two quaternions commute **if and only if** their vector parts are parallel (since their cross product $\vec{v}_1 \times \vec{v}_2$ is then $\vec{0}$).

#### 3. Conjugate ($q^*$)
The conjugate of a quaternion is found by negating its imaginary vector components (similar to complex conjugates):

$$
q^* = s - \vec{v} = w - xi - yj - zk
$$

Conjugating a product reverses the order of multiplication:

$$
(q_1 q_2)^* = q_2^* q_1^*
$$

#### 4. Magnitude ($\|q\|$)
The magnitude (or norm) of a quaternion is a real number defined by:

**(2.11)**

$$
\|q\| = \sqrt{q q^*} = \sqrt{s^2 + \|\vec{v}\|^2} = \sqrt{w^2 + x^2 + y^2 + z^2}
$$

*   **Unit Quaternion:** A quaternion is a unit quaternion if $\|q\| = 1$. Only unit quaternions represent pure 3D rotations.
*   **Multiplicative Property:** The magnitude of a product is equal to the product of their magnitudes:

$$
\|q_1 q_2\| = \|q_1\| \|q_2\|
$$


#### 5. Multiplicative Inverse ($q^{-1}$)
For any non-zero quaternion, its multiplicative inverse $q^{-1}$ is the quaternion that satisfies $q q^{-1} = q^{-1} q = 1$:

$$
q^{-1} = \frac{q^*}{\|q\|^2} = \frac{s - \vec{v}}{s^2 + \|\vec{v}\|^2}
$$

*   For unit quaternions ($\|q\| = 1$), the inverse is simply the conjugate: $q^{-1} = q^*$.
*   Inverting a product reverses the multiplication order:

$$
(q_1 q_2)^{-1} = q_2^{-1} q_1^{-1}
$$


---

## 2. Quaternion Properties Summary

The algebraic properties of quaternion addition and multiplication are summarized in the table below. Here, $q, q_1, q_2, q_3$ are quaternions, and $s, t$ are real scalars.

| Property | Operation | Formula |
| :--- | :--- | :--- |
| **Associativity (Addition)** | Addition | $(q_1 + q_2) + q_3 = q_1 + (q_2 + q_3)$ |
| **Commutativity (Addition)** | Addition | $q_1 + q_2 = q_2 + q_1$ |
| **Associativity (Scalar)** | Scalar Multiplication | $(st)q = s(tq)$ |
| **Commutativity (Scalar)** | Scalar Multiplication | $tq = qt$ |
| **Distributivity (Scalar)** | Scalar Multiplication | $t(q_1 + q_2) = tq_1 + tq_2$ <br> $(s + t)q = sq + tq$ |
| **Associativity (Multiplication)** | Quaternion Multiplication | $q_1(q_2 q_3) = (q_1 q_2)q_3$ |
| **Distributivity (Multiplication)** | Quaternion Multiplication | $q_1(q_2 + q_3) = q_1 q_2 + q_1 q_3$ <br> $(q_1 + q_2)q_3 = q_1 q_3 + q_2 q_3$ |
| **Scalar Factorization** | Mixed Multiplication | $(tq_1)q_2 = q_1(tq_2) = t(q_1 q_2)$ |
| **Product Rule for Conjugates** | Conjugation | $(q_1 q_2)^* = q_2^* q_1^*$ |
| **Product Rule for Inverses** | Inversion | $(q_1 q_2)^{-1} = q_2^{-1} q_1^{-1}$ |

---

## 3. 3D Vector Rotation

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

> [!IMPORTANT]
> **Physical Interpretation:**
> *   The imaginary components $i, j, k$ represent the **axis of rotation** (scaled by $\sin(\theta/2)$). This axis vector is normalized to a length of 1.
> *   The real component $w$ represents the **rotation value** (specifically $\cos(\theta/2)$).
> *   The direction of rotation follows the **right-hand rule**: if you point your right thumb in the direction of the rotation axis $\vec{u}$, your fingers curl in the direction of positive rotation.

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


---

## References & Additional Resources

*   **Ben Eater & Grant Sanderson (3Blue1Brown) - Quaternions Interactive Visualizations:** [eater.net/quaternions](https://eater.net/quaternions)
*   **How to Use Quaternions:** [youtube.com/watch?v=bKd2lPjl92c](https://www.youtube.com/watch?v=bKd2lPjl92c)
*   **Godot's Quaternion Variant is Beautiful (and misunderstood):** [youtube.com/watch?v=Ri2xIhcii8I](https://www.youtube.com/watch?v=Ri2xIhcii8I)

---

## Code Implementation

*   **C++ Source Code:** [[03_Code/04_Transforms/Quaternions.cppm|Quaternions.cppm]]


