---
topic: Transforms
tags: [exercise, solution, reflections, plane-reflection, axis-reflection]
---
# Solution: Reflections in 3D Space

This note provides the step-by-step solutions to the exercises in [[Q_03_Reflections]].

---

## Part 1: Calculation

Given the vector to be reflected $\vec{v}$ and the unit normal of the reflection plane $\vec{a}$:

$$
\vec{v} = \begin{bmatrix} 2 \\\\ -1 \\\\ 3 \end{bmatrix} \quad \text{and} \quad \vec{a} = \begin{bmatrix} 0 \\\\ 0 \\\\ 1 \end{bmatrix}
$$

### 1. Plane Reflection Matrix
To construct the $3 \times 3$ plane reflection matrix $\mathbf{M}_{\text{reflect}}(\vec{a})$ representing a mirror reflection across the plane perpendicular to the normal $\vec{a}$, we use the projection-subtraction formula:

$$
\mathbf{M}_{\text{reflect}}(\vec{a}) = \mathbf{I} - 2\vec{a}\vec{a}^T
$$

First, compute the outer product $\vec{a}\vec{a}^T$:

$$
\vec{a}\vec{a}^T = \begin{bmatrix} 0 \\\\ 0 \\\\ 1 \end{bmatrix} \begin{bmatrix} 0 & 0 & 1 \end{bmatrix} = \begin{bmatrix} 0 & 0 & 0 \\\\ 0 & 0 & 0 \\\\ 0 & 0 & 1 \end{bmatrix}
$$

Now, substitute this into the matrix equation:

$$
\mathbf{M}_{\text{reflect}}(\vec{a}) = \begin{bmatrix} 1 & 0 & 0 \\\\ 0 & 1 & 0 \\\\ 0 & 0 & 1 \end{bmatrix} - 2 \begin{bmatrix} 0 & 0 & 0 \\\\ 0 & 0 & 0 \\\\ 0 & 0 & 1 \end{bmatrix}
$$

$$
\mathbf{M}_{\text{reflect}}(\vec{a}) = \begin{bmatrix} 1 & 0 & 0 \\\\ 0 & 1 & 0 \\\\ 0 & 0 & -1 \end{bmatrix}
$$

---

### 2. Plane Reflection Calculation
Multiply $\mathbf{M}_{\text{reflect}}(\vec{a})$ by the vector $\vec{v}$ to find the reflected vector $\vec{v}'_{\text{plane}}$:

$$
\vec{v}'_{\text{plane}} = \mathbf{M}_{\text{reflect}}(\vec{a})\vec{v} = \begin{bmatrix} 1 & 0 & 0 \\\\ 0 & 1 & 0 \\\\ 0 & 0 & -1 \end{bmatrix} \begin{bmatrix} 2 \\\\ -1 \\\\ 3 \end{bmatrix} = \begin{bmatrix} 2 \\\\ -1 \\\\ -3 \end{bmatrix}
$$

> [!NOTE]
> **Geometric Interpretation:**  
> Since the normal vector $\vec{a} = [0, 0, 1]^T$ points along the $z$-axis, the reflection plane is the $xy$-plane ($z = 0$). As expected, reflecting across this plane negates the $z$-component while leaving the $x$ and $y$ coordinates unchanged.

---

### 3. Axis Reflection Matrix
To construct the $3 \times 3$ axis reflection (involution) matrix $\mathbf{M}_{\text{invol}}(\vec{a})$ representing a reflection across the line defined by $\vec{a}$ (a $180^\circ$ rotation about $\vec{a}$), we use:

$$
\mathbf{M}_{\text{invol}}(\vec{a}) = 2\vec{a}\vec{a}^T - \mathbf{I}
$$

Substitute the outer product $\vec{a}\vec{a}^T$ calculated above:

$$
\mathbf{M}_{\text{invol}}(\vec{a}) = 2 \begin{bmatrix} 0 & 0 & 0 \\\\ 0 & 0 & 0 \\\\ 0 & 0 & 1 \end{bmatrix} - \begin{bmatrix} 1 & 0 & 0 \\\\ 0 & 1 & 0 \\\\ 0 & 0 & 1 \end{bmatrix}
$$

$$
\mathbf{M}_{\text{invol}}(\vec{a}) = \begin{bmatrix} -1 & 0 & 0 \\\\ 0 & -1 & 0 \\\\ 0 & 0 & 1 \end{bmatrix}
$$

---

### 4. Axis Reflection Calculation
Multiply $\mathbf{M}_{\text{invol}}(\vec{a})$ by the vector $\vec{v}$ to find the reflected vector $\vec{v}'_{\text{axis}}$:

$$
\vec{v}'_{\text{axis}} = \mathbf{M}_{\text{invol}}(\vec{a})\vec{v} = \begin{bmatrix} -1 & 0 & 0 \\\\ 0 & -1 & 0 \\\\ 0 & 0 & 1 \end{bmatrix} \begin{bmatrix} 2 \\\\ -1 \\\\ 3 \end{bmatrix} = \begin{bmatrix} -2 \\\\ 1 \\\\ 3 \end{bmatrix}
$$

> [!NOTE]
> **Geometric Interpretation:**  
> Reflecting across the $z$-axis ($180^\circ$ rotation about $z$) negates both the $x$ and $y$ components while preserving the $z$-component, which matches the computed result.

---

## Part 2: Conceptual Understanding

### 1. Determinant Intuition
To analyze the orientation-preserving properties of these transformations, we compute the determinants of the specific matrices constructed in Part 1 (where $\vec{a} = [0, 0, 1]^T$):

#### Plane Reflection Determinant:
$$
\det\big(\mathbf{M}_{\text{reflect}}(\vec{a})\big) = \det\begin{bmatrix} 1 & 0 & 0 \\\\ 0 & 1 & 0 \\\\ 0 & 0 & -1 \end{bmatrix} = (1)(1)(-1) = -1
$$

#### Axis Reflection (Involution) Determinant:
$$
\det\big(\mathbf{M}_{\text{invol}}(\vec{a})\big) = \det\begin{bmatrix} -1 & 0 & 0 \\\\ 0 & -1 & 0 \\\\ 0 & 0 & 1 \end{bmatrix} = (-1)(-1)(1) = 1
$$

#### Geometric Significance of the Signs in 3D Space:
*   **Determinant of $+1$ (Orientation-Preserving):** 
    An orthogonal matrix with a determinant of $+1$ preserves the chirality (handedness) of the coordinate system. A right-handed basis (like the standard $xyz$ coordinate axes) remains right-handed after the transformation. Geometrically, this corresponds to a **pure rigid rotation** in 3D space. For $\mathbf{M}_{\text{invol}}(\vec{a})$, the transformation is a $180^\circ$ rotation about the axis $\vec{a}$, which is a physical rotation that does not mirror or invert space.
*   **Determinant of $-1$ (Orientation-Reversing):** 
    An orthogonal matrix with a determinant of $-1$ reverses the chirality of the coordinate system, transforming a right-handed system into a left-handed one (and vice versa). Geometrically, this represents a **reflection** (or improper rotation). It is a transformation that cannot be achieved through physical rotation alone; it "flips" the space to its mirror image.

---

### 2. Composition of Reflections

#### Consecutive Plane Reflections (Double Reflection $\mathbf{M}_{\text{reflect}}^2$)
If we perform two plane reflections consecutively across the exact same plane, the second reflection cancels the first, returning the vector to its original position.

**Algebraic Proof:**
Using the definition $\mathbf{M}_{\text{reflect}}(\vec{a}) = \mathbf{I} - 2\vec{a}\vec{a}^T$, we compute the product:

$$
\mathbf{M}_{\text{reflect}}(\vec{a})\mathbf{M}_{\text{reflect}}(\vec{a}) = (\mathbf{I} - 2\vec{a}\vec{a}^T)(\mathbf{I} - 2\vec{a}\vec{a}^T)
$$

Expanding the terms:

$$
\mathbf{M}_{\text{reflect}}(\vec{a})\mathbf{M}_{\text{reflect}}(\vec{a}) = \mathbf{I}^2 - 2\vec{a}\vec{a}^T - 2\vec{a}\vec{a}^T + 4(\vec{a}\vec{a}^T)(\vec{a}\vec{a}^T)
$$

Since $\mathbf{I}^2 = \mathbf{I}$ and $(\vec{a}\vec{a}^T)(\vec{a}\vec{a}^T) = \vec{a}(\vec{a}^T\vec{a})\vec{a}^T$, and because $\vec{a}$ is a unit vector ($\vec{a}^T\vec{a} = 1$), we have:

$$
(\vec{a}\vec{a}^T)(\vec{a}\vec{a}^T) = \vec{a}(1)\vec{a}^T = \vec{a}\vec{a}^T
$$

Substituting this back in:

$$
\mathbf{M}_{\text{reflect}}(\vec{a})\mathbf{M}_{\text{reflect}}(\vec{a}) = \mathbf{I} - 4\vec{a}\vec{a}^T + 4\vec{a}\vec{a}^T = \mathbf{I}
$$

**Geometric Interpretation:** 
Two consecutive reflections across the same plane cancel each other out, yielding the identity transformation $\mathbf{I}$. This proves that plane reflections are self-inverse (involutions).

---

#### Product of Plane Reflection and Axis Reflection (Point Reflection / Inversion)
$$
\mathbf{M}_{\text{reflect}}(\vec{a})\mathbf{M}_{\text{invol}}(\vec{a})
$$

**Algebraic Proof:**
Using the matrix formulas:

$$
\mathbf{M}_{\text{reflect}}(\vec{a})\mathbf{M}_{\text{invol}}(\vec{a}) = (\mathbf{I} - 2\vec{a}\vec{a}^T)(2\vec{a}\vec{a}^T - \mathbf{I})
$$

Expanding the product:

$$
= 2\vec{a}\vec{a}^T - \mathbf{I} - 4(\vec{a}\vec{a}^T)(\vec{a}\vec{a}^T) + 2\vec{a}\vec{a}^T
$$

Using $(\vec{a}\vec{a}^T)(\vec{a}\vec{a}^T) = \vec{a}\vec{a}^T$:

$$
= 2\vec{a}\vec{a}^T - \mathbf{I} - 4\vec{a}\vec{a}^T + 2\vec{a}\vec{a}^T = -\mathbf{I}
$$

For our specific case:

$$
\begin{bmatrix} 1 & 0 & 0 \\\\ 0 & 1 & 0 \\\\ 0 & 0 & -1 \end{bmatrix} \begin{bmatrix} -1 & 0 & 0 \\\\ 0 & -1 & 0 \\\\ 0 & 0 & 1 \end{bmatrix} = \begin{bmatrix} -1 & 0 & 0 \\\\ 0 & -1 & 0 \\\\ 0 & 0 & -1 \end{bmatrix} = -\mathbf{I}
$$

**Geometric Interpretation:**
Applying a plane reflection followed by an axis reflection (with normal/axis along the same vector $\vec{a}$) results in $-\mathbf{I}$, which represents a **point reflection (inversion through the origin)**. In a 3D coordinate system, this reverses all three axes, mapping the original object to the diagonally opposite octant (the furthest quadrant from the original).

---

**Back to Question:** [[Q_03_Reflections]] | **Related Concepts:** [[03_Reflections]]
