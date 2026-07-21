# Scaling in 3D Space

In computer graphics, physical simulations, and geometric modeling, scaling transformations are used to resize objects. Scaling can be applied uniformly in all directions, independently along the coordinate axes, or along an arbitrary 3D direction.

---

## 1. Uniform Scaling

A uniform scale changes the size of an object equally in every direction. 

### Algebraic Setup
Uniform scaling just multiplies all components of the input vector $\vec{v}$ by a single scalar factor $s$:

$$
\vec{v}' = s\vec{v}
$$

### Matrix Representation
To represent this as a linear transformation matrix, we multiply the main diagonal of the identity matrix by the scalar value $s$:

$$
\vec{v}' = \begin{bmatrix} s & 0 & 0 \\\\ 0 & s & 0 \\\\ 0 & 0 & s \end{bmatrix} \vec{v}
$$

---

## 2. Non-Uniform Scaling

A non-uniform scale changes the size of an object by different factors along each of the primary coordinate axes ($x$, $y$, and $z$).

### Algebraic Setup
Each coordinate component is scaled by its own independent scaling factor ($s_x$, $s_y$, and $s_z$):

$$
v'_x = s_x v_x, \quad v'_y = s_y v_y, \quad v'_z = s_z v_z
$$

### Matrix Representation
This is represented by a diagonal matrix with the individual scaling factors along the main diagonal:

$$
\mathbf{M}_{\text{scale}}(s_x, s_y, s_z) = \begin{bmatrix} s_x & 0 & 0 \\\\ 0 & s_y & 0 \\\\ 0 & 0 & s_z \end{bmatrix}
$$

---

## 3. Scaling Along an Arbitrary Direction

We can scale an object along a single arbitrary direction defined by a unit vector $\vec{a}$ (where $\|\vec{a}\| = 1$) with a scale factor $s$, while preserving the object's size in every direction orthogonal to $\vec{a}$. 

Geometrically, this is achieved by decomposing a vector $\vec{v}$ into its parallel and perpendicular components relative to $\vec{a}$, and scaling only the parallel component.

### Geometric Setup and Decomposition
Using the parallel and perpendicular [[06_Vector_Projection|vector projections]]:
1. **Parallel Component ($\vec{v}_{\parallel a}$):** The component of $\vec{v}$ along the scaling direction $\vec{a}$.
   
$$
\vec{v}_{\parallel a} = (\vec{v} \cdot \vec{a})\vec{a}
$$
   
2. **Perpendicular Component ($\vec{v}_{\perp a}$):** The component of $\vec{v}$ orthogonal to the scaling direction $\vec{a}$ (which must remain unscaled).
   
$$
\vec{v}_{\perp a} = \vec{v} - \vec{v}_{\parallel a} = \vec{v} - (\vec{v} \cdot \vec{a})\vec{a}
$$

<center>
	<img src="../../98_Assets/Concepts/scale_arbitrary.webp" height="300">
</center>

To scale only the parallel component by factor $s$, we formulate the transformed vector $\vec{v}'$ as:

$$
\vec{v}' = s\vec{v}_{\parallel a} + \vec{v}_{\perp a}
$$

---

## 4. Arbitrary Scale Matrix Derivation

We can express the vector scaling equation in matrix form using the outer product operator $\vec{a}\vec{a}^T$.

### Step-by-Step Derivation
1. **Substitute Matrix Equivalents:** 
   We rewrite the parallel component using the outer product projection matrix ($\vec{a}\vec{a}^T$) and the perpendicular component using the orthogonal rejection matrix ($\mathbf{I} - \vec{a}\vec{a}^T$) from [[06_Projection_Matrices]]:
   
$$
\vec{v}' = s(\vec{a}\vec{a}^T)\vec{v} + (\mathbf{I} - \vec{a}\vec{a}^T)\vec{v}
$$
   
2. **Factor Out the Vector $\vec{v}$:**
   
$$
\vec{v}' = \big(s\vec{a}\vec{a}^T + \mathbf{I} - \vec{a}\vec{a}^T\big)\vec{v}
$$
   
3. **Combine Outer Product Terms:**
   
$$
\vec{v}' = \big(\mathbf{I} + (s-1)\vec{a}\vec{a}^T\big)\vec{v}
$$

Thus, the general **Arbitrary Scale Matrix** is:

$$
\mathbf{M}_{\text{scale}}(s, \vec{a}) = \mathbf{I} + (s-1)\vec{a}\vec{a}^T
$$

### Explicit Matrix Expansion
Expanding $\mathbf{I} + (s-1)\vec{a}\vec{a}^T$ row-by-row:

$$
\mathbf{M}_{\text{scale}}(s, \vec{a}) = \begin{bmatrix} 1 & 0 & 0 \\\\ 0 & 1 & 0 \\\\ 0 & 0 & 1 \end{bmatrix} + (s-1) \begin{bmatrix} a_x^2 & a_x a_y & a_x a_z \\\\ a_x a_y & a_y^2 & a_y a_z \\\\ a_x a_z & a_y a_z & a_z^2 \end{bmatrix}
$$

This generates the exact $3 \times 3$ grid:

$$
\mathbf{M}_{\text{scale}}(s, \vec{a}) = \begin{bmatrix} (s-1)a_x^2 + 1 & (s-1)a_x a_y & (s-1)a_x a_z \\\\ (s-1)a_x a_y & (s-1)a_y^2 + 1 & (s-1)a_y a_z \\\\ (s-1)a_x a_z & (s-1)a_y a_z & (s-1)a_z^2 + 1 \end{bmatrix}
$$

---

## 5. Properties of Scaling Matrices

* **Determinant:** 
  The determinant of a scaling matrix represents the volume scaling factor of the transformation.
  * For **uniform scaling**, $\det(\mathbf{M}) = s^3$.
  * For **non-uniform scaling**, $\det(\mathbf{M}) = s_x s_y s_z$.
  * For **arbitrary scaling**, $\det\big(\mathbf{M}_{\text{scale}}(s, \vec{a})\big) = s$.
* **Inverse Matrix:** 
  To undo a scale, we scale by the reciprocal of the scale factor(s):
  * For uniform scaling, $\mathbf{M}^{-1} = \mathbf{M}(1/s)$.
  * For non-uniform scaling, the diagonal entries become $1/s_x$, $1/s_y$, and $1/s_z$.
  * For arbitrary scaling, $\mathbf{M}_{\text{scale}}(s, \vec{a})^{-1} = \mathbf{M}_{\text{scale}}(1/s, \vec{a})$.

---

## Code Implementation

*   **C++ Source Code:** [[03_Code/04_Transforms/Scales.cppm|Scales.cppm]]
