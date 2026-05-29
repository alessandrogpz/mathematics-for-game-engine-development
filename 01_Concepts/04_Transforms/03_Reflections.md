# Reflections in 3D Space

In computer graphics, physics simulations, and geometric modeling, reflections are fundamental transformations used to mirror objects across planes or rotate them about axes. 

---

## 1. Reflection Across a Plane (Plane Reflection)

We first consider a plane that passes through the origin and is perpendicular to a given unit normal vector $\vec{a}$ (where $\|\vec{a}\| = 1$). 

To reflect any vector $\vec{v}$ across this plane, we decompose it into its components relative to the normal vector $\vec{a}$ and negate the component that lies parallel to the normal (while leaving the perpendicular component untouched).

### Geometric Setup and Decomposition
We decompose the vector $\vec{v}$ into:

$$v = v_{\parallel a} + v_{\perp a}$$
<center>
	<img src="../../98_Assets/Concepts/reflection_plane_decomposition.webp" width="400" height="300">
</center>

*   **Parallel Component ($\vec{v}_{\parallel a}$):** The vector projection of $\vec{v}$ onto the normal $\vec{a}$.
    $$\vec{v}_{\parallel a} = \text{proj}_{\vec{a}}\vec{v} = (\vec{v} \cdot \vec{a})\vec{a}$$
*   **Perpendicular Component ($\vec{v}_{\perp a}$):** The component lying parallel to the reflection plane (perpendicular to $\vec{a}$).
    $$\vec{v}_{\perp a} = \vec{v} - \vec{v}_{\parallel a} = \vec{v} - (\vec{v} \cdot \vec{a})\vec{a}$$

To mirror the vector across the plane, we negate the parallel component while keeping the perpendicular component intact:
$$\vec{v}' = \vec{v}_{\perp a} + (-\vec{v}_{\parallel a}) = \vec{v}_{\perp a} - \vec{v}_{\parallel a}$$


---

### Step-by-Step Derivation
Substituting the definitions for $\vec{v}_{\parallel a}$ and $\vec{v}_{\perp a}$ into the reflection equation:
$$\vec{v}' = \big(\vec{v} - (\vec{v} \cdot \vec{a})\vec{a}\big) - (\vec{v} \cdot \vec{a})\vec{a}$$
$$\vec{v}' = \vec{v} - 2(\vec{v} \cdot \vec{a})\vec{a}$$

---

### Transforming to Matrix Form
To convert this vector equation into a single transformation matrix, we replace the vector operations with their equivalent matrix-vector products:
1.  **Identity Matrix Substitution:** The original vector $\vec{v}$ is represented using the identity matrix $\mathbf{I}$:
    $$\vec{v} = \mathbf{I}\vec{v}$$
2.  **Outer Product Substitution:** The projection term $(\vec{v} \cdot \vec{a})\vec{a}$ is rewritten using the outer product matrix $\vec{a}\vec{a}^T$:
    $$(\vec{v} \cdot \vec{a})\vec{a} = (\vec{a}\vec{a}^T)\vec{v}$$

Substituting these back into the formula yields:
$$\vec{v}' = \mathbf{I}\vec{v} - 2(\vec{a}\vec{a}^T)\vec{v}$$
$$\vec{v}' = (\mathbf{I} - 2\vec{a}\vec{a}^T)\vec{v}$$

Expanding this into explicit $3 \times 3$ coordinate form:
$$\mathbf{M}_{\text{reflect}}(\vec{a}) = \begin{bmatrix} 1 & 0 & 0 \\\\ 0 & 1 & 0 \\\\ 0 & 0 & 1 \end{bmatrix} - 2 \begin{bmatrix} a_x^2 & a_x a_y & a_x a_z \\\\ a_x a_y & a_y^2 & a_y a_z \\\\ a_x a_z & a_y a_z & a_z^2 \end{bmatrix}$$

This yields the complete **Plane Reflection Matrix**:
$$\mathbf{M}_{\text{reflect}}(\vec{a}) = \begin{bmatrix} 1 - 2a_x^2 & -2a_x a_y & -2a_x a_z \\\\ -2a_x a_y & 1 - 2a_y^2 & -2a_y a_z \\\\ -2a_x a_z & -2a_y a_z & 1 - 2a_z^2 \end{bmatrix}$$

---

## 2. Determinants and Dimensionality

The determinant of any plane reflection matrix $\mathbf{M}_{\text{reflect}}(\vec{a})$ is **always $-1$**:
$$\det\big(\mathbf{M}_{\text{reflect}}(\vec{a})\big) = -1$$

### Intuitive Axis Alignment Approach
To understand why the determinant is always $-1$, we can align our coordinate system so that the normal vector points perfectly along a coordinate axis (e.g., the $x$-axis, $\vec{a} = [1, 0, 0]^T$). 
*   Reflecting across the plane perpendicular to the $x$-axis (the $yz$-plane) simply negates the $x$-coordinate while leaving the $y$ and $z$ coordinates untouched:
    $$\mathbf{M}_{\text{reflect}}(\vec{x}) = \begin{bmatrix} -1 & 0 & 0 \\\\ 0 & 1 & 0 \\\\ 0 & 0 & 1 \end{bmatrix}$$
*   Evaluating the determinant:
    $$\det\big(\mathbf{M}_{\text{reflect}}(\vec{x})\big) = (-1)(1)(1) - 0 = -1$$

<center>
	<img src="../../98_Assets/Concepts/reflection_intuitive_x.webp">
</center>

Because rotating a coordinate system does not alter the fundamental scale, lengths, or hand-orientation of space, the determinant remains $-1$ regardless of where the arbitrary normal axis $\vec{a}$ is positioned.

### Geometrical Significance of the Determinant
*   **Determinant of $+1$:** Confirms the transformation preserves orientation (like rotations).
*   **Determinant of $-1$:** Confirms the transformation **inverts** space, turning it "inside out" (mirror reflection). Hand-handedness is flipped (a right-handed coordinate frame becomes left-handed).

---

## 3. Reflection Across a Line (Axis Reflection / Involution)

Instead of reflecting across a plane, we can construct a transformation that reflects a vector across a line defined by the unit vector $\vec{a}$. Geometrically, this is achieved by **negating the perpendicular component** while leaving the parallel component completely unchanged.

### Geometric Setup and Decomposition
Using the same parallel and perpendicular decomposition:
$$\vec{v}' = \vec{v}_{\parallel a} + (-\vec{v}_{\perp a}) = \vec{v}_{\parallel a} - \vec{v}_{\perp a}$$

<center>
	<img src="../../98_Assets/Concepts/reflection_line_decomposition.webp" width="600" height="300">
</center>

---

### Step-by-Step Derivation
Substituting $\vec{v}_{\perp a} = \vec{v} - \vec{v}_{\parallel a}$:
$$\vec{v}' = \vec{v}_{\parallel a} - (\vec{v} - \vec{v}_{\parallel a})$$
$$\vec{v}' = 2\vec{v}_{\parallel a} - \vec{v}$$

Substituting $\vec{v}_{\parallel a} = (\vec{v} \cdot \vec{a})\vec{a}$:
$$\vec{v}' = 2(\vec{v} \cdot \vec{a})\vec{a} - \vec{v}$$

---

### Transforming to Matrix Form
Replacing vector operations with their equivalent matrix expressions:
$$\vec{v}' = 2(\vec{a}\vec{a}^T)\vec{v} - \mathbf{I}\vec{v}$$
$$\vec{v}' = (2\vec{a}\vec{a}^T - \mathbf{I})\vec{v}$$

This defines the **Axis Reflection (Involution) Matrix**:
$$\mathbf{M}_{\text{invol}}(\vec{a}) = 2\vec{a}\vec{a}^T - \mathbf{I}$$

Expanding this into coordinate form:
$$\mathbf{M}_{\text{invol}}(\vec{a}) = \begin{bmatrix} 2a_x^2 - 1 & 2a_x a_y & 2a_x a_z \\\\ 2a_x a_y & 2a_y^2 - 1 & 2a_y a_z \\\\ 2a_x a_z & 2a_y a_z & 2a_z^2 - 1 \end{bmatrix}$$

---

## 4. Dimensionality and Orientation Preservation

In 3D space, reflecting a vector across a line is geometrically identical to **rotating the vector by $180^\circ$ ($\pi$ radians) around that line**. Consequently, its determinant is **always $+1$** in 3D:
$$\det\big(\mathbf{M}_{\text{invol}}(\vec{a})\big) = +1$$

### Coordinate Inheritance and Flipped Dimensions
To understand why reflecting across a line preserves orientation (determinant $+1$) while reflecting across a plane reverses it (determinant $-1$), we look at how coordinates inherit dimensions:
1.  **3D Space Coordinates:** Space is defined by 3 independent coordinate directions ($x$, $y$, and $z$).
2.  **Parallel Component:** Lies along a 1D line ($\vec{a}$), meaning it inherits exactly **1 coordinate dimension**.
3.  **Perpendicular Component:** Lies in the 2D plane orthogonal to $\vec{a}$, meaning it inherits the remaining **2 coordinate dimensions**.

<center>
	<img src="../../98_Assets/Concepts/reflection_coordinate_inheritance.webp">
</center>

*   **Plane Reflection ($\mathbf{M}_{\text{reflect}}$):** Negates the parallel component (flipping exactly **1 dimension**). Since an **odd number** of dimensions is flipped, the transformation is orientation-reversing:
    $$\det(\mathbf{M}) = -1 \quad (\text{Mirror Reflection})$$
*   **Axis Reflection ($\mathbf{M}_{\text{invol}}$):** Negates the perpendicular component (flipping exactly **2 dimensions**). Since an **even number** of dimensions is flipped, the two signs cancel out in the spatial orientation, making it geometrically equivalent to a $180^\circ$ rotation:
    $$\det(\mathbf{M}) = +1 \quad (\text{Pure Rotation})$$

> [!IMPORTANT]
> **Summary of Dimensional Flips:**
> *   Any transformation that flips an **odd number of dimensions** is a orientation-reversing **mirror reflection** ($\det(\mathbf{M}) = -1$).
> *   Any transformation that flips an **even number of dimensions** is an orientation-preserving **rotation** ($\det(\mathbf{M}) = +1$).
