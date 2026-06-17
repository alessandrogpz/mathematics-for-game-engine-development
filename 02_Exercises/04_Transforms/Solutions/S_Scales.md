---
topic: Transforms
tags: [exercise, solution, scaling, arbitrary-scale, uniform-scale]
---

# Solution: Scaling in 3D Space

This solution note provides the mathematical derivations, explicit matrix constructions, vector verifications, and conceptual operator connections for your practice exercises.

---

## Part 1: Calculation

### 1. Scale Matrix Construction

We start with the vector equation for arbitrary scaling by factor $s$ along a unit direction vector $\vec{a}$ (where $\|\vec{a}\| = 1$):

$$
\vec{v}' = s\vec{v}_{\parallel a} + \vec{v}_{\perp a}
$$

To represent this transformation in matrix form, we decompose the input vector $\vec{v}$ into:
*   **Parallel Component ($\vec{v}_{\parallel a}$):** The projection of $\vec{v}$ onto the unit vector $\vec{a}$:
    
$$
\vec{v}_{\parallel a} = \text{proj}_{\vec{a}}\vec{v} = (\vec{v} \cdot \vec{a})\vec{a}
$$
    
    Using matrix notation for the dot product of $3 \times 1$ column vectors $\vec{v}$ and $\vec{a}$:
    
$$
\vec{v} \cdot \vec{a} = \vec{a}^T\vec{v}
$$
    
    Substituting this back into the projection formula:
    
$$
\vec{v}_{\parallel a} = (\vec{a}^T\vec{v})\vec{a} = \vec{a}(\vec{a}^T\vec{v}) = (\vec{a}\vec{a}^T)\vec{v}
$$
    
*   **Perpendicular Component ($\vec{v}_{\perp a}$):** The component orthogonal to the scaling direction $\vec{a}$:
    
$$
\vec{v}_{\perp a} = \vec{v} - \vec{v}_{\parallel a} = \mathbf{I}\vec{v} - (\vec{a}\vec{a}^T)\vec{v} = (\mathbf{I} - \vec{a}\vec{a}^T)\vec{v}
$$

Substituting these back into the main scaling equation:

$$
\vec{v}' = s(\vec{a}\vec{a}^T)\vec{v} + (\mathbf{I} - \vec{a}\vec{a}^T)\vec{v}
$$

Factoring out the common vector $\vec{v}$:

$$
\vec{v}' = \big(s\vec{a}\vec{a}^T + \mathbf{I} - \vec{a}\vec{a}^T\big)\vec{v}
$$

$$
\vec{v}' = \big(\mathbf{I} + (s-1)\vec{a}\vec{a}^T\big)\vec{v}
$$

Since the transformation is represented by $\vec{v}' = \mathbf{M}_{\text{scale}}(s, \vec{a})\vec{v}$, this proves the **Arbitrary Scale Matrix**:

$$
\mathbf{M}_{\text{scale}}(s, \vec{a}) = \mathbf{I} + (s-1)\vec{a}\vec{a}^T
$$

From here, we expand this operator into explicit $3 \times 3$ coordinate form:

$$
\mathbf{M}_{\text{scale}}(s, \vec{a}) = \begin{bmatrix} 1 & 0 & 0 \\\\ 0 & 1 & 0 \\\\ 0 & 0 & 1 \end{bmatrix} + (s-1)\begin{bmatrix} a_x^2 & a_x a_y & a_x a_z \\\\ a_x a_y & a_y^2 & a_y a_z \\\\ a_x a_z & a_y a_z & a_z^2 \end{bmatrix}
$$

$$
\mathbf{M}_{\text{scale}}(s, \vec{a}) = \begin{bmatrix} (s-1)a_x^2 + 1 & (s-1)a_x a_y & (s-1)a_x a_z \\\\ (s-1)a_x a_y & (s-1)a_y^2 + 1 & (s-1)a_y a_z \\\\ (s-1)a_x a_z & (s-1)a_y a_z & (s-1)a_z^2 + 1 \end{bmatrix}
$$

Now we substitute our specific values, $s = 3$ and the unit vector:

$$
\vec{a} = \begin{bmatrix} 0 \\\\ \frac{\sqrt{2}}{2} \\\\ \frac{\sqrt{2}}{2} \end{bmatrix}
$$

*   $a_x = 0$
*   $a_y = \frac{\sqrt{2}}{2} \implies a_y^2 = \frac{1}{2}$
*   $a_z = \frac{\sqrt{2}}{2} \implies a_z^2 = \frac{1}{2}$
*   $a_x a_y = 0 \cdot \frac{\sqrt{2}}{2} = 0$
*   $a_x a_z = 0 \cdot \frac{\sqrt{2}}{2} = 0$
*   $a_y a_z = \frac{\sqrt{2}}{2} \cdot \frac{\sqrt{2}}{2} = \frac{1}{2}$

Evaluating the matrix elements:
*   $(s-1)a_x^2 + 1 = 2(0) + 1 = 1$
*   $(s-1)a_x a_y = 2(0) = 0$
*   $(s-1)a_x a_z = 2(0) = 0$
*   $(s-1)a_y^2 + 1 = 2\left(\frac{1}{2}\right) + 1 = 2$
*   $(s-1)a_y a_z = 2\left(\frac{1}{2}\right) = 1$
*   $(s-1)a_z^2 + 1 = 2\left(\frac{1}{2}\right) + 1 = 2$

This yields the complete transformation matrix:

$$
\mathbf{M}_{\text{scale}}(3, \vec{a}) = \begin{bmatrix} 1 & 0 & 0 \\\\ 0 & 2 & 1 \\\\ 0 & 1 & 2 \end{bmatrix}
$$

This matrix represents a scaling transformation of scale $s = 3$ along the $\vec{a}$ axis.

---

### 2. Transform a Vector

We calculate the scaled vector $\vec{v}' = \mathbf{M}_{\text{scale}}(3, \vec{a})\vec{v}$ for the input vector:

$$
\vec{v} = \begin{bmatrix} 4 \\\\ 1 \\\\ -1 \end{bmatrix}
$$

$$
\vec{v}' = \begin{bmatrix} 1 & 0 & 0 \\\\ 0 & 2 & 1 \\\\ 0 & 1 & 2 \end{bmatrix} \begin{bmatrix} 4 \\\\ 1 \\\\ -1 \end{bmatrix}
$$

$$
\vec{v}' = \begin{bmatrix} 1(4) + 0(1) + 0(-1) \\\\ 0(4) + 2(1) + 1(-1) \\\\ 0(4) + 1(1) + 2(-1) \end{bmatrix}
$$

$$
\vec{v}' = \begin{bmatrix} 4 \\\\ 2 - 1 \\\\ 1 - 2 \end{bmatrix} = \begin{bmatrix} 4 \\\\ 1 \\\\ -1 \end{bmatrix}
$$

**Geometric Observation:** The resulting vector $\vec{v}'$ is exactly equal to the input vector $\vec{v}$. This is because the input vector $\vec{v}$ lies completely perpendicular (orthogonal) to the scaling direction $\vec{a}$, which we verify by their dot product:

$$
\vec{v} \cdot \vec{a} = 4(0) + 1\left(\frac{\sqrt{2}}{2}\right) - 1\left(\frac{\sqrt{2}}{2}\right) = 0
$$

Since $\vec{v}$ is perpendicular to $\vec{a}$, scaling space along $\vec{a}$ leaves $\vec{v}$ entirely unaffected.

---

### 3. Geometric Verification

We verify this result by decomposing the vector $\vec{v}$ into parallel and perpendicular components relative to the unit vector $\vec{a}$:

*   **Parallel Component ($\vec{v}_{\parallel a}$):**
    
$$
\vec{v}_{\parallel a} = (\vec{v} \cdot \vec{a})\vec{a}
$$
    
    Since the dot product $\vec{v} \cdot \vec{a} = 0$:
    
$$
\vec{v}_{\parallel a} = 0 \cdot \vec{a} = \begin{bmatrix} 0 \\\\ 0 \\\\ 0 \end{bmatrix}
$$
    
*   **Perpendicular Component ($\vec{v}_{\perp a}$):**
    
$$
\vec{v}_{\perp a} = \vec{v} - \vec{v}_{\parallel a} = \begin{bmatrix} 4 \\\\ 1 \\\\ -1 \end{bmatrix} - \begin{bmatrix} 0 \\\\ 0 \\\\ 0 \end{bmatrix} = \begin{bmatrix} 4 \\\\ 1 \\\\ -1 \end{bmatrix}
$$

*   **Decomposition Verification:**
    Applying the scale factor $s = 3$ to only the parallel component and adding the perpendicular component:
    
$$
\vec{v}' = s\vec{v}_{\parallel a} + \vec{v}_{\perp a}
$$
    
    
$$
\vec{v}' = 3\begin{bmatrix} 0 \\\\ 0 \\\\ 0 \end{bmatrix} + \begin{bmatrix} 4 \\\\ 1 \\\\ -1 \end{bmatrix} = \begin{bmatrix} 4 \\\\ 1 \\\\ -1 \end{bmatrix}
$$

This perfectly matches the matrix multiplication result from Step 2!

---

## Part 2: Conceptual Understanding

### 1. Determinant of Scaling

*   **Geometric Representation of the Determinant:**
    The determinant of any transformation matrix represents the volume scaling factor of the transformation on the 3D space.
*   **1D Stretch:**
    Arbitrary scaling along the axis $\vec{a}$ stretches (or compresses) space by a factor of exactly $s$ in a single 1D direction.
*   **Orthogonal Preservation:**
    In the 2D plane orthogonal to $\vec{a}$, space is completely untouched—meaning the scale factors in the two perpendicular directions are both exactly $1$.
*   **Net Volume Change:**
    The net change in volume for any 3D region is the product of the scaling factors along three mutually perpendicular axes (the scaling axis $\vec{a}$ and two orthogonal axes):
    
$$
\text{Volume scaling factor} = s \cdot 1 \cdot 1 = s
$$

Therefore, the determinant of the arbitrary scaling matrix is exactly $s$:

$$
\det\big(\mathbf{M}_{\text{scale}}(s, \vec{a})\big) = s
$$

---

### 2. Operator Unification ($s = 0$)

Setting the scale factor $s = 0$ in the general arbitrary scaling matrix:

$$
\mathbf{M}_{\text{scale}}(0, \vec{a}) = \mathbf{I} + (0-1)\vec{a}\vec{a}^T = \mathbf{I} - \vec{a}\vec{a}^T
$$

Expanding this into coordinate components:

$$
\mathbf{M}_{\text{scale}}(0, \vec{a}) = \begin{bmatrix} 1 - a_x^2 & -a_x a_y & -a_x a_z \\\\ -a_x a_y & 1 - a_y^2 & -a_y a_z \\\\ -a_x a_z & -a_y a_z & 1 - a_z^2 \end{bmatrix}
$$

*   **Geometric Transformation:**
    Setting $s = 0$ completely flattens (projects) all 3D vectors onto the 2D plane passing through the origin perpendicular to $\vec{a}$. 
*   **Relationship to Projections:**
    This matrix is exactly the **Orthogonal Rejection Matrix** (often denoted as $\text{Rej}_{\vec{a}}\vec{v} = \mathbf{I} - \vec{a}\vec{a}^T$). Geometrically, it represents an orthogonal projection onto the plane perpendicular to the normal vector $\vec{a}$:
    
$$
\vec{v}' = 0\vec{v}_{\parallel a} + \vec{v}_{\perp a} = \vec{v}_{\perp a} = \text{proj}_{\perp a}\vec{v}
$$
    
    This elegantly unifies arbitrary scaling with **vector projections**.

---

### 3. Operator Unification ($s = -1$)

Setting the scale factor $s = -1$ in the general arbitrary scaling matrix:

$$
\mathbf{M}_{\text{scale}}(-1, \vec{a}) = \mathbf{I} + (-1-1)\vec{a}\vec{a}^T = \mathbf{I} - 2\vec{a}\vec{a}^T
$$

Expanding this into coordinate components:

$$
\mathbf{M}_{\text{scale}}(-1, \vec{a}) = \begin{bmatrix} 1 - 2a_x^2 & -2a_x a_y & -2a_x a_z \\\\ -2a_x a_y & 1 - 2a_y^2 & -2a_y a_z \\\\ -2a_x a_z & -2a_y a_z & 1 - 2a_z^2 \end{bmatrix}
$$

*   **Geometric Transformation:**
    Setting $s = -1$ negates (reverses) only the component of a vector that lies parallel to the axis $\vec{a}$ while leaving the perpendicular component completely untouched:
    
$$
\vec{v}' = -1\vec{v}_{\parallel a} + \vec{v}_{\perp a} = \vec{v}_{\perp a} - \vec{v}_{\parallel a}
$$
    
*   **Relationship to Reflections:**
    This formula is identical to the **Plane Reflection Matrix** $\mathbf{M}_{\text{reflect}}(\vec{a})$ which mirrors vectors across the plane passing through the origin perpendicular to the normal vector $\vec{a}$. 
    This reveals that a mirror reflection is simply a **special case of non-uniform scaling** where the scale factor in the direction orthogonal to the mirror plane is exactly $-1$.

---

**Back to Question:** [[Q_Scales]] | **Related Concepts:** [[04_Scales]]
