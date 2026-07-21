# Rotations in 3D Space

In 3D game engines and graphics programming, rotations are fundamental transformations. A rotation typically occurs within a local coordinate system where the axis of rotation is aligned with one of the coordinate axes ($x$, $y$, or $z$), though they can also be performed about an arbitrary axis specified by a unit direction vector.

## 1. Handedness and Rotation Conventions
To ensure consistency across calculations, we follow standard convention:
*   **Right-Handed Coordinate System:** A positive rotation angle $\theta$ represents a **counterclockwise** rotation when looking down the axis of rotation toward the origin (i.e., when the axis points directly toward the viewer).

---

## 2. Derivation: Rotation About a Coordinate Axis
A rotation about the $x$, $y$, or $z$ axis occurs in the plane formed by the *other* two axes. 

Let's derive the transformation matrix for a vector $\vec{v}$ rotated through an angle $\theta$ **about the $z$-axis**:
*   Using the standard orthogonal basis vectors $\vec{i}$, $\vec{j}$, and $\vec{k}$ parallel to the coordinate axes, we express any vector $\vec{v}$ as:
    
$$
\vec{v} = v_x \vec{i} + v_y \vec{j} + v_z \vec{k}
$$

*   Since the rotation is *about* the $z$-axis, the basis vector $\vec{k}$ is parallel to the axis of rotation. Therefore, **the $z$-component $v_z$ remains unchanged**.
*   The basis vectors $\vec{i}$ and $\vec{j}$ lie in the $xy$-plane of rotation and are both rotated by the angle $\theta$.

### Step 1: Rotating the $\vec{i}$ Basis Component ($v_x\vec{i}$)
Rotating the positive x-axis basis vector $\vec{i}$ by an angle $\theta$ sweeps it into the first quadrant. Using right-triangle trigonometry, we decompose the rotated vector into its new components along $\vec{i}$ and $\vec{j}$:

$$
\cos\theta = \frac{\text{Adjacent}}{\text{Hypotenuse}} \implies \text{Adjacent} = v_x\cos\theta \quad (\text{along } \vec{i})
$$

$$
\sin\theta = \frac{\text{Opposite}}{\text{Hypotenuse}} \implies \text{Opposite} = v_x\sin\theta \quad (\text{along } \vec{j})
$$

Thus, the rotated $x$-component is:

$$
v_x\vec{i}' = v_x\cos\theta\vec{i} + v_x\sin\theta\vec{j}
$$

<center>
	<img src="../../98_Assets/Concepts/vxi.webp" width="400" height="300">
</center>

---

### Step 2: Rotating the $\vec{j}$ Basis Component ($v_y\vec{j}$)
Rotating the positive y-axis basis vector $\vec{j}$ by an angle $\theta$ sweeps it into the second quadrant. 
*   **Sign Correction:** Because the vector swings to the left of the positive y-axis, its new component along the $\vec{i}$ axis points in the negative direction:

$$
\cos\theta = \frac{\text{Adjacent}}{\text{Hypotenuse}} \implies \text{Adjacent} = v_y\cos\theta \quad (\text{along } \vec{j})
$$

$$
\sin\theta = \frac{\text{Opposite}}{\text{Hypotenuse}} \implies \text{Opposite} = v_y\sin\theta \quad (\text{along } -\vec{i})
$$

Thus, the rotated $y$-component is:

$$
v_y\vec{j}' = -v_y\sin\theta\vec{i} + v_y\cos\theta\vec{j}
$$

<center>
	<img src="../../98_Assets/Concepts/vyj.webp" width="400" height="300">
</center>

---

### Step 3: Combining the Rotated Components
By summing the transformed parts, the final rotated vector $\vec{v}'$ is:

$$
\vec{v}' = v_x\vec{i}' + v_y\vec{j}' + v_z\vec{k}
$$

$$
\vec{v}' = (v_x\cos\theta - v_y\sin\theta)\vec{i} + (v_x\sin\theta + v_y\cos\theta)\vec{j} + v_z\vec{k}
$$

We can express this system of linear equations as a matrix-vector product:

$$
\begin{bmatrix} v'_x \\\\ v'_y \\\\ v'_z \end{bmatrix} = \begin{bmatrix} \cos\theta & -\sin\theta & 0 \\\\ \sin\theta & \cos\theta & 0 \\\\ 0 & 0 & 1 \end{bmatrix} \begin{bmatrix} v_x \\\\ v_y \\\\ v_z \end{bmatrix}
$$

This $3 \times 3$ matrix is the **general transformation matrix for rotating through an angle $\theta$ about the $z$-axis**.

---

## 3. Standard 3D Rotation Matrices

Applying this identical geometric derivation to rotations about the other coordinate axes yields the three principal rotation matrices:

### Rotation About the $x$-Axis ($\mathbf{M}_{\text{rot } x}$)
Rotates vectors within the $yz$-plane:

$$
\mathbf{M}_{\text{rot } x} = \begin{bmatrix} 1 & 0 & 0 \\\\ 0 & \cos\theta & -\sin\theta \\\\ 0 & \sin\theta & \cos\theta \end{bmatrix}
$$

### Rotation About the $y$-Axis ($\mathbf{M}_{\text{rot } y}$)
Rotates vectors within the $zx$-plane:

$$
\mathbf{M}_{\text{rot } y} = \begin{bmatrix} \cos\theta & 0 & \sin\theta \\\\ 0 & 1 & 0 \\\\ -\sin\theta & 0 & \cos\theta \end{bmatrix}
$$

### Rotation About the $z$-Axis ($\mathbf{M}_{\text{rot } z}$)
Rotates vectors within the $xy$-plane:

$$
\mathbf{M}_{\text{rot } z} = \begin{bmatrix} \cos\theta & -\sin\theta & 0 \\\\ \sin\theta & \cos\theta & 0 \\\\ 0 & 0 & 1 \end{bmatrix}
$$

> [!IMPORTANT]
> Because coordinate systems are cyclic ($x \to y \to z \to x$), rotating in the $zx$-plane causes the negative sign to appear in the bottom-left entry $(3, 1)$ instead of the top-right entry $(1, 3)$ in $\mathbf{M}_{\text{rot } y}$.

---

## 4. Properties of Rotation Matrices
All principal rotation matrices are **orthogonal matrices**, meaning they exhibit the following key properties:
1.  **Inverse equals Transpose:** $\mathbf{M}^{-1} = \mathbf{M}^T$. This makes inverting a rotation incredibly cheap computationally.
2.  **Determinant equals 1:** $\det(\mathbf{M}) = 1$. This confirms they are orientation-preserving pure rotations.
3.  **Preservation:** They preserve vector lengths, angles, and dot products.

> [!NOTE]
> **General $N \times N$ Rotation Matrix Criteria:**
> A square matrix $\mathbf{M}$ of any dimension ($N \times N$) represents a pure orientation-preserving rotation if and only if:
> *   **Column Orthonormality:** The columns are mutually perpendicular unit vectors (the magnitude of each column is $1$, and the dot product between any two distinct columns is $0$). Mathematically, this is expressed as $\mathbf{M}^T\mathbf{M} = \mathbf{I}$, certifying it as an **orthogonal matrix**.
> *   **Orientation Preservation:** The determinant (which represents the spatial volume scaling factor) is exactly $+1$ ($\det(\mathbf{M}) = +1$), confirming that the transform does not involve a reflection.
> 
> **Concrete Dimensional Cases:**
> *   **In 2D ($2 \times 2$):** For the matrix:
>     $$
>     \mathbf{M} = \begin{bmatrix} a & b \\\\ c & d \end{bmatrix}
>     $$
>     the determinant is represented exactly by your formula—the **difference of its cross-multiplication products** must be $+1$ ($ad - bc = 1$).
> *   **In 3D ($3 \times 3$):** The determinant represents the volume of the unit box formed by the three columns. It is evaluated by summing three weighted $2 \times 2$ cross-multiplication differences, and must also equal $+1$.

---

## 5. Rotation About an Arbitrary Axis

We want to construct a transform that rotates a vector around an arbitrary axis $\vec{a}$.

<center>
	<img src="../../98_Assets/Concepts/rotation_arbitrary_axis.webp" width="400" height="300">
</center>

### Step 1: Component Breakdown

We need to break $\vec{v}$ into two distinct components:

- **Parallel Piece ($v_{\parallel a}$):** The shadow that $\vec{v}$ casts on $\vec{a}$. This piece does not move since it is located on the axis of rotation.
    
- **Perpendicular Piece ($v_{\perp a}$):** The rejection of $\vec{v}$ from $\vec{a}$ (the piece shooting off at $90^\circ$ from $\vec{a}$). This is the piece that rotates.
    
<center>
	<img src="../../98_Assets/Concepts/decomposing_v.webp" width="350" height="350">
</center>

### Step 2: Rotating the Perpendicular Piece

Now we need to rotate $v_{\perp a}$. We need a local x-axis and y-axis:

- **Local x-axis:** The starting position of $v_{\perp a}$.
    
- **Local y-axis:** It is the cross product of $\vec{a} \times \vec{v}$.
    

<center>
	<img src="../../98_Assets/Concepts/localx_localy.webp" width="400" height="300">
</center>

By applying standard 2D rotation ($\cos\theta$ for the x-axis and $\sin\theta$ for the y-axis), the new position of the rotating piece is defined as:

$$
v' = v_{\parallel a} + v_{\perp a}\cos\theta + (\vec{a} \times \vec{v})\sin\theta
$$

<center>
	<img src="../../98_Assets/Concepts/decomosing_rotated_v.webp" width="400" height="300">
</center>
### Step 3: Creating the Equation

We know that $v = v_{\parallel a} + v_{\perp a}$, therefore $v_{\perp a} = v - v_{\parallel a}$. The parallel component of $\vec{v}$ onto a unit vector is defined as $v_{\parallel a} = (\vec{v} \cdot \vec{a})\vec{a}$. This gives us $v_{\perp a} = \vec{v} - (\vec{v} \cdot \vec{a})\vec{a}$.

Making the necessary substitutions to the formula, we get the final rotation formula:

$$
v' = (\vec{v} \cdot \vec{a})\vec{a} + (\vec{v} - (\vec{v} \cdot \vec{a})\vec{a})\cos\theta + (\vec{a} \times \vec{v})\sin\theta
$$

Further reduction yields:

$$
v' = \vec{v}\cos\theta + (\vec{v} \cdot \vec{a})\vec{a}(1 - \cos\theta) + (\vec{a} \times \vec{v})\sin\theta
$$

### Step 4: Matrix Formulation

To convert the vector equation into matrix-vector products and isolate the final rotation matrix, we follow three steps:

#### Sub-Step 1: Rearrange the Vector Equation
First, distribute the $\cos\theta$ term in the middle of the first equation:

$$
\vec{v}' = (\vec{v} \cdot \vec{a})\vec{a} + \vec{v}\cos\theta - (\vec{v} \cdot \vec{a})\vec{a}\cos\theta + (\vec{a} \times \vec{v})\sin\theta
$$

Next, group the terms containing the dot product $(\vec{v} \cdot \vec{a})\vec{a}$ together:

$$
\vec{v}' = \vec{v}\cos\theta + \Big[ (\vec{v} \cdot \vec{a})\vec{a} - (\vec{v} \cdot \vec{a})\vec{a}\cos\theta \Big] + (\vec{a} \times \vec{v})\sin\theta
$$

Factor out $(\vec{v} \cdot \vec{a})\vec{a}$ to get the intermediate vector form:

$$
\vec{v}' = \vec{v}\cos\theta + (\vec{v} \cdot \vec{a})\vec{a}(1 - \cos\theta) + (\vec{a} \times \vec{v})\sin\theta
$$

#### Sub-Step 2: Convert to Matrix Notation
To factor out the vector $\vec{v}$ so that a single rotation matrix can operate on it, convert each of the three terms into matrix-vector multiplications.

1. **The $\cos\theta$ term:**  
   Any vector multiplied by the identity matrix $\mathbf{I}$ remains unchanged ($\vec{v} = \mathbf{I}\vec{v}$).
   
$$
\vec{v}\cos\theta \implies \mathbf{I}\vec{v}\cos\theta
$$

2. **The $(1 - \cos\theta)$ term (Dot Product to Outer Product):**  
   The dot product of two column vectors can be written as a matrix multiplication using a transpose: $\vec{v} \cdot \vec{a} = \vec{a} \cdot \vec{v} = \vec{a}^T\vec{v}$. Substituting this back into the expression yields:
   
$$
(\vec{v} \cdot \vec{a})\vec{a} = \vec{a}(\vec{a}^T\vec{v}) = (\vec{a}\vec{a}^T)\vec{v}
$$
   
   Here, $\vec{a}\vec{a}^T$ is a $3 \times 3$ outer-product matrix:
   
$$
\vec{a}\vec{a}^T = \begin{bmatrix} a_x^2 & a_x a_y & a_x a_z \\\\ a_x a_y & a_y^2 & a_y a_z \\\\ a_x a_z & a_y a_z & a_z^2 \end{bmatrix}
$$
   
   Thus:
   
$$
(\vec{v} \cdot \vec{a})\vec{a}(1 - \cos\theta) \implies (\vec{a}\vec{a}^T)\vec{v}(1 - \cos\theta)
$$

3. **The $\sin\theta$ term (Cross Product to Skew-Symmetric Matrix):**  
   A cross product with a fixed vector $\vec{a}$ can be represented as a matrix-vector multiplication using the [[04_Cross_Product|cross-product matrix]] notation $[\vec{a}]_\times$ (a skew-symmetric matrix):
   
$$
\vec{a} \times \vec{v} \implies [\vec{a}]_\times\vec{v}
$$
   
   Where:
   
$$
[\vec{a}]_\times = \begin{bmatrix} 0 & -a_z & a_y \\\\ a_z & 0 & -a_x \\\\ -a_y & a_x & 0 \end{bmatrix}
$$

#### Sub-Step 3: Combine the Terms
Substitute the three matrix expressions back into the rearranged equation:

$$
\vec{v}' = \mathbf{I}\vec{v}\cos\theta + (\vec{a}\vec{a}^T)\vec{v}(1 - \cos\theta) + [\vec{a}]_\times\vec{v}\sin\theta
$$

Because $\vec{v}$ is now on the right side of every single term, you can cleanly factor it out to isolate the final $3 \times 3$ Rodrigues' rotation matrix:

$$
\vec{v}' = \Big( \mathbf{I}\cos\theta + (\vec{a}\vec{a}^T)(1 - \cos\theta) + [\vec{a}]_\times\sin\theta \Big) \vec{v}
$$

Writing this out in matrix component form:

$$
v' = \begin{bmatrix} 1 & 0 & 0 \\\\ 0 & 1 & 0 \\\\ 0 & 0 & 1 \end{bmatrix} \vec{v}\cos\theta + \begin{bmatrix} a_x^2 & a_x a_y & a_x a_z \\\\ a_x a_y & a_y^2 & a_y a_z \\\\ a_x a_z & a_y a_z & a_z^2 \end{bmatrix} \vec{v}(1 - \cos\theta) + \begin{bmatrix} 0 & -a_z & a_y \\\\ a_z & 0 & -a_x \\\\ -a_y & a_x & 0 \end{bmatrix} \vec{v}\sin\theta
$$

We can combine everything into a single matrix:

$$
M_{\text{rot}}(\theta, \vec{a}) = \begin{bmatrix} \cos\theta + (1 - \cos\theta)a_x^2 & (1 - \cos\theta)a_x a_y - \sin\theta a_z & (1 - \cos\theta)a_x a_z + \sin\theta a_y \\\\ (1 - \cos\theta)a_x a_y + \sin\theta a_z & \cos\theta + (1 - \cos\theta)a_y^2 & (1 - \cos\theta)a_y a_z - \sin\theta a_x \\\\ (1 - \cos\theta)a_x a_z - \sin\theta a_y & (1 - \cos\theta)a_y a_z + \sin\theta a_x & \cos\theta + (1 - \cos\theta)a_z^2 \end{bmatrix}
$$

---

## Code Implementation

*   **C++ Source Code:** [[03_Code/04_Transforms/Rotations.cppm|Rotations.cppm]]
