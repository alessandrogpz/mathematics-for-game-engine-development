---
topic: Transforms
tags: [exercise, solution, rotations, rodrigues-rotation, matrix-derivation]
---
# Solution: 3D Rotations and Rodrigues' Rotation Formula

---

## Part 1: Coordinate Axis Rotation

### 1. Rotation Matrix ($\mathbf{M}_{\text{rot } y}$)

To rotate a vector $\vec{v} = v_x\vec{i} + v_y\vec{j} + v_z\vec{k}$ through a positive angle $\theta$ about the $y$-axis:
*   Because the rotation is centered on the $y$-axis, the basis vector $\vec{j}$ remains stationary:
    
$$
v_y' = v_y
$$

*   The rotation occurs strictly in the $zx$-plane. We project and rotate the basis vectors $\vec{i}$ (x-axis) and $\vec{k}$ (z-axis) relative to a local orthonormal 2D basis where the horizontal axis is $\vec{i}$ and the vertical axis is $\vec{k}$:

#### Step A: Rotating the $x$-component basis vector ($v_x\vec{i}$)
Rotating positive $\vec{i}$ by an angle $\theta$ counterclockwise in the $zx$-plane sweeps it into the first quadrant between $\vec{i}$ and $\vec{k}$:
*   

$$
\cos\theta = \frac{\text{Adjacent}}{\text{Hypotenuse}} \implies \text{Adjacent} = v_x\cos\theta \quad (\text{along } \vec{i})
$$

*   

$$
\sin\theta = \frac{\text{Opposite}}{\text{Hypotenuse}} \implies \text{Opposite} = v_x\sin\theta \quad (\text{along } \vec{k})
$$

Thus:

$$
\vec{v}_x\vec{i}' = v_x\cos\theta\vec{i} + v_x\sin\theta\vec{k}
$$

#### Step B: Rotating the $z$-component basis vector ($v_z\vec{k}$)
Rotating positive $\vec{k}$ by an angle $\theta$ counterclockwise sweeps it into the second quadrant, landing it between $\vec{k}$ and $-\vec{i}$:
*   

$$
\cos\theta = \frac{\text{Adjacent}}{\text{Hypotenuse}} \implies \text{Adjacent} = v_z\cos\theta \quad (\text{along } \vec{k})
$$

*   

$$
\sin\theta = \frac{\text{Opposite}}{\text{Hypotenuse}} \implies \text{Opposite} = v_z\sin\theta \quad (\text{along } -\vec{i})
$$

Thus:

$$
\vec{v}_z\vec{k}' = -v_z\sin\theta\vec{i} + v_z\cos\theta\vec{k}
$$

#### Step C: Combined Rotated Vector
Adding these rotated components together gives the final transformed vector $\vec{v}'$:

$$
\vec{v}' = \vec{i}(v_x\cos\theta - v_z\sin\theta) + v_y\vec{j} + \vec{k}(v_x\sin\theta + v_z\cos\theta)
$$

Expressed as a system of linear equations in matrix form:

$$
\begin{bmatrix} v'_x \\\\ v'_y \\\\ v'_z \end{bmatrix} = \begin{bmatrix} \cos\theta & 0 & -\sin\theta \\\\ 0 & 1 & 0 \\\\ \sin\theta & 0 & \cos\theta \end{bmatrix} \begin{bmatrix} v_x \\\\ v_y \\\\ v_z \end{bmatrix}
$$

This is the explicit **$3 \times 3$ Rotation Matrix about the $y$-axis ($\mathbf{M}_{\text{rot } y}$)**

---

### 2. Transformed Vector Calculation
Given the initial vector:

$$
\vec{v} = \begin{bmatrix} 1 \\\\ 0 \\\\ 1 \end{bmatrix}
$$

and a positive rotation angle of $\theta = 90^\circ$:
We have $\cos 90^\circ = 0$, $\sin 90^\circ = 1$

$$
\vec{v}' = \mathbf{M}_{\text{rot } y}\vec{v} = \begin{bmatrix} 0 & 0 & -1 \\\\ 0 & 1 & 0 \\\\ 1 & 0 & 0 \end{bmatrix} \begin{bmatrix} 1 \\\\ 0 \\\\ 1 \end{bmatrix} = \begin{bmatrix} (0)(1) + (0)(0) + (-1)(1) \\\\ (0)(1) + (1)(0) + (0)(1) \\\\ (1)(1) + (0)(0) + (0)(1) \end{bmatrix} = \begin{bmatrix} -1 \\\\ 0 \\\\ 1 \end{bmatrix}
$$

---

### 3. Geometric Intuition
Here is the geometric intuition explaining why the rotated vector $\vec{v}'$ makes complete sense:
1.  **Y-axis Invariance:** The $y$-coordinate remains completely unchanged ($0$) because we are rotating centered on the $y$-axis.
2.  **Rotation Conventions (Direction of Swing):**
    *   **Under the Counter-Cyclic Convention:**
        *   **The $Z$-axis swings to the negative $X$-axis:** The original $Z$ coordinate was $1$. It rotates $90^\circ$ and lands on the negative side of the $X$-axis, becoming $-1$.
        *   **The $X$-axis swings to the positive $Z$-axis:** The original $X$ coordinate was $1$. It rotates $90^\circ$ to become your new $Z$ coordinate ($1$).
        *   This matches the calculated result:
            
            $$
            \vec{v}' = \begin{bmatrix} -1 \\\\ 0 \\\\ 1 \end{bmatrix}
            $$
            
    *   **Under the Standard Cyclic Convention (Clockwise looking down $+y$):**
        *   **The $Z$-axis swings to the positive $X$-axis:** The original $Z$ coordinate was $1$. It rotates $90^\circ$ to become your new $X$ coordinate ($1$).
        *   **The $X$-axis swings to the negative $Z$-axis:** The original $X$ coordinate was $1$. It rotates $90^\circ$ and lands on the negative side of the $Z$-axis, becoming $-1$.
        *   This yields the standard cyclic result:
            
            $$
            \vec{v}' = \begin{bmatrix} 1 \\\\ 0 \\\\ -1 \end{bmatrix}
            $$

---

## Part 2: Rotation About an Arbitrary Axis

We rotate the vector:

$$
\vec{v} = \begin{bmatrix} 1 \\\\ 0 \\\\ 1 \end{bmatrix}
$$

by $\theta = 180^\circ$ (or $\pi$ radians) about the arbitrary unit axis:

$$
\vec{a} = \begin{bmatrix} 0 \\\\ \frac{\sqrt{2}}{2} \\\\ \frac{\sqrt{2}}{2} \end{bmatrix}
$$

### 1. Component Decomposition

#### A. Calculate the Parallel Component ($\vec{v}_{\parallel a}$)
Geometrically, the parallel component $\vec{v}_{\parallel a}$ is the vector projection of $\vec{v}$ onto the unit axis $\vec{a}$ ($\text{proj}_{\vec{a}} \vec{v}$):

$$
\vec{v} \cdot \vec{a} = \|\vec{v}\| \|\vec{a}\| \cos\phi
$$

$$
\text{comp}_{\vec{a}} \vec{v} = \|\vec{v}\| \cos\phi = \frac{\vec{v} \cdot \vec{a}}{\|\vec{a}\|}
$$

$$
\text{proj}_{\vec{a}} \vec{v} = \left(\frac{\vec{v} \cdot \vec{a}}{\|\vec{a}\|}\right)\frac{\vec{a}}{\|\vec{a}\|}
$$

Since $\vec{a}$ is a unit vector ($\|\vec{a}\| = 1$):

$$
\vec{v}_{\parallel a} = \text{proj}_{\vec{a}} \vec{v} = (\vec{v} \cdot \vec{a})\vec{a}
$$

Calculating the dot product:

$$
\vec{v} \cdot \vec{a} = (1)(0) + (0)\left(\frac{\sqrt{2}}{2}\right) + (1)\left(\frac{\sqrt{2}}{2}\right) = \frac{\sqrt{2}}{2}
$$

Thus, the parallel component is:

$$
\vec{v}_{\parallel a} = \left(\frac{\sqrt{2}}{2}\right) \begin{bmatrix} 0 \\\\ \frac{\sqrt{2}}{2} \\\\ \frac{\sqrt{2}}{2} \end{bmatrix} = \begin{bmatrix} 0 \\\\ \frac{1}{2} \\\\ \frac{1}{2} \end{bmatrix}
$$

#### B. Calculate the Perpendicular Component ($\vec{v}_{\perp a}$)
The total vector $\vec{v}$ is the sum of the parallel and perpendicular pieces:

$$
\vec{v} = \vec{v}_{\parallel a} + \vec{v}_{\perp a} \implies \vec{v}_{\perp a} = \vec{v} - \vec{v}_{\parallel a}
$$

Substituting our values:

$$
\vec{v}_{\perp a} = \begin{bmatrix} 1 \\\\ 0 \\\\ 1 \end{bmatrix} - \begin{bmatrix} 0 \\\\ \frac{1}{2} \\\\ \frac{1}{2} \end{bmatrix} = \begin{bmatrix} 1 \\\\ -\frac{1}{2} \\\\ \frac{1}{2} \end{bmatrix}
$$

---

### 2. Rodrigues' Rotation Formula Application

We setup our local orthonormal coordinate frame in the plane of rotation:
*   **Local X-axis:** The perpendicular component $\vec{v}_{\perp a}$ (on local $x$).
*   **Local Y-axis:** The cross product $\vec{a} \times \vec{v}$ (on local $y$).
*   **Stationary component:** The parallel component $\vec{v}_{\parallel a}$ (on axis $\vec{a}$).

The rotated vector is:

$$
\vec{v}' = \vec{v}_{\parallel a} + \vec{v}_{\perp a}\cos\theta + (\vec{a} \times \vec{v})\sin\theta
$$

$$
\vec{v}' = (\vec{v} \cdot \vec{a})\vec{a} + \big(\vec{v} - (\vec{v} \cdot \vec{a})\vec{a}\big)\cos\theta + (\vec{a} \times \vec{v})\sin\theta
$$

#### A. Calculate the Cross Product ($\vec{a} \times \vec{v}$)

$$
\vec{a} \times \vec{v} = \begin{vmatrix} \vec{i} & \vec{j} & \vec{k} \\\\ a_x & a_y & a_z \\\\ v_x & v_y & v_z \end{vmatrix} = \begin{vmatrix} \vec{i} & \vec{j} & \vec{k} \\\\ 0 & \frac{\sqrt{2}}{2} & \frac{\sqrt{2}}{2} \\\\ 1 & 0 & 1 \end{vmatrix}
$$

$$
\vec{a} \times \vec{v} = \begin{bmatrix} \left(\frac{\sqrt{2}}{2}\right)(1) - \left(\frac{\sqrt{2}}{2}\right)(0) \\\\ \left(\frac{\sqrt{2}}{2}\right)(1) - (0)(1) \\\\ (0)(0) - \left(\frac{\sqrt{2}}{2}\right)(1) \end{bmatrix} = \begin{bmatrix} \frac{\sqrt{2}}{2} \\\\ \frac{\sqrt{2}}{2} \\\\ -\frac{\sqrt{2}}{2} \end{bmatrix}
$$

#### B. Evaluate the Formula
For $\theta = 180^\circ$ ($\cos 180^\circ = -1$ and $\sin 180^\circ = 0$):

$$
\vec{v}' = \begin{bmatrix} 0 \\\\ \frac{1}{2} \\\\ \frac{1}{2} \end{bmatrix} + \begin{bmatrix} 1 \\\\ -\frac{1}{2} \\\\ \frac{1}{2} \end{bmatrix}\cos(180^\circ) + \begin{bmatrix} \frac{\sqrt{2}}{2} \\\\ \frac{\sqrt{2}}{2} \\\\ -\frac{\sqrt{2}}{2} \end{bmatrix}\sin(180^\circ)
$$

$$
\vec{v}' = \begin{bmatrix} 0 \\\\ \frac{1}{2} \\\\ \frac{1}{2} \end{bmatrix} + \begin{bmatrix} 1 \\\\ -\frac{1}{2} \\\\ \frac{1}{2} \end{bmatrix}(-1) + \begin{bmatrix} \frac{\sqrt{2}}{2} \\\\ \frac{\sqrt{2}}{2} \\\\ -\frac{\sqrt{2}}{2} \end{bmatrix}(0)
$$

$$
\vec{v}' = \begin{bmatrix} 0 \\\\ \frac{1}{2} \\\\ \frac{1}{2} \end{bmatrix} + \begin{bmatrix} -1 \\\\ \frac{1}{2} \\\\ -\frac{1}{2} \end{bmatrix} = \begin{bmatrix} -1 \\\\ 1 \\\\ 0 \end{bmatrix}
$$

---

### 3. Matrix Multiplication Verification

We express Rodrigues' formula in matrix form:

$$
\vec{v}' = \mathbf{I}\vec{v}\cos\theta + \vec{a}\vec{a}^T\vec{v}(1 - \cos\theta) + [\vec{a}]_{\times}\vec{v}\sin\theta
$$

#### A. Skew-Symmetric Matrix ($[\vec{a}]_{\times}$)

$$
[\vec{a}]_{\times} = \begin{bmatrix} 0 & -a_z & a_y \\\\ a_z & 0 & -a_x \\\\ -a_y & a_x & 0 \end{bmatrix} = \begin{bmatrix} 0 & -\frac{\sqrt{2}}{2} & \frac{\sqrt{2}}{2} \\\\ \frac{\sqrt{2}}{2} & 0 & 0 \\\\ -\frac{\sqrt{2}}{2} & 0 & 0 \end{bmatrix}
$$

#### B. Outer Product Matrix ($\vec{a}\vec{a}^T$)

$$
\vec{a}\vec{a}^T = \begin{bmatrix} a_x \\\\ a_y \\\\ a_z \end{bmatrix} \begin{bmatrix} a_x & a_y & a_z \end{bmatrix} = \begin{bmatrix} a_x^2 & a_x a_y & a_x a_z \\\\ a_x a_y & a_y^2 & a_y a_z \\\\ a_x a_z & a_y a_z & a_z^2 \end{bmatrix}
$$

Substituting $a_x = 0$, $a_y = \frac{\sqrt{2}}{2}$, $a_z = \frac{\sqrt{2}}{2}$:

$$
\vec{a}\vec{a}^T = \begin{bmatrix} 0 & 0 & 0 \\\\ 0 & \frac{1}{2} & \frac{1}{2} \\\\ 0 & \frac{1}{2} & \frac{1}{2} \end{bmatrix}
$$

#### C. Evaluate the Rotation Matrix $\mathbf{M}_{\text{rot}}(\theta, \vec{a})$

$$
\mathbf{M}_{\text{rot}}(\theta, \vec{a}) = \begin{bmatrix} \cos\theta + (1 - \cos\theta)a_x^2 & (1 - \cos\theta)a_x a_y - \sin\theta a_z & (1 - \cos\theta)a_x a_z + \sin\theta a_y \\\\ (1 - \cos\theta)a_x a_y + \sin\theta a_z & \cos\theta + (1 - \cos\theta)a_y^2 & (1 - \cos\theta)a_y a_z - \sin\theta a_x \\\\ (1 - \cos\theta)a_x a_z - \sin\theta a_y & (1 - \cos\theta)a_y a_z + \sin\theta a_x & \cos\theta + (1 - \cos\theta)a_z^2 \end{bmatrix}
$$

For $\theta = 180^\circ$ ($\cos 180^\circ = -1$, $\sin 180^\circ = 0$, and $1 - \cos 180^\circ = 2$):
*   $(1, 1) = -1 + 2(0)^2 = -1$
*   $(1, 2) = 2(0)\left(\frac{\sqrt{2}}{2}\right) - (0)\left(\frac{\sqrt{2}}{2}\right) = 0$
*   $(1, 3) = 2(0)\left(\frac{\sqrt{2}}{2}\right) + (0)\left(\frac{\sqrt{2}}{2}\right) = 0$
*   $(2, 1) = 2(0)\left(\frac{\sqrt{2}}{2}\right) + (0)\left(\frac{\sqrt{2}}{2}\right) = 0$
*   $(2, 2) = -1 + 2\left(\frac{\sqrt{2}}{2}\right)^2 = -1 + 2\left(\frac{1}{2}\right) = 0$
*   $(2, 3) = 2\left(\frac{\sqrt{2}}{2}\right)\left(\frac{\sqrt{2}}{2}\right) - (0)(0) = 2\left(\frac{1}{2}\right) = 1$
*   $(3, 1) = 2(0)\left(\frac{\sqrt{2}}{2}\right) - (0)\left(\frac{\sqrt{2}}{2}\right) = 0$
*   $(3, 2) = 2\left(\frac{\sqrt{2}}{2}\right)\left(\frac{\sqrt{2}}{2}\right) + (0)(0) = 2\left(\frac{1}{2}\right) = 1$
*   $(3, 3) = -1 + 2\left(\frac{\sqrt{2}}{2}\right)^2 = -1 + 2\left(\frac{1}{2}\right) = 0$

Thus, the complete rotation matrix $\mathbf{M}_{\text{rot}}(\theta, \vec{a})$ becomes:

$$
\mathbf{M}_{\text{rot}}(180^\circ, \vec{a}) = \begin{bmatrix} -1 & 0 & 0 \\\\ 0 & 0 & 1 \\\\ 0 & 1 & 0 \end{bmatrix}
$$

#### D. Product ($\mathbf{M}_{\text{rot}}\vec{v}$)
Let's verify by multiplying our matrix by the vector $\vec{v}$:

$$
\vec{v}' = \mathbf{M}_{\text{rot}}(180^\circ, \vec{a})\vec{v} = \begin{bmatrix} -1 & 0 & 0 \\\\ 0 & 0 & 1 \\\\ 0 & 1 & 0 \end{bmatrix} \begin{bmatrix} 1 \\\\ 0 \\\\ 1 \end{bmatrix} = \begin{bmatrix} -1 \\\\ 1 \\\\ 0 \end{bmatrix}
$$

This perfectly verifies the rotated vector computed using Rodrigues' Formula.

---

**Back to Question:** [[Q_Rotations]] | **Related Concepts:** [[02_Rotations]]
