---
topic: Vectors
tags: [exercise, solution, projection]
---

# Solution: Vector Projection

This solution note provides the mathematical derivations, calculations, and conceptual answers for the vector projection exercise.

---

## Part 1: Calculation

*   **Input Velocity Vector:**
    
$$
\vec{v} = \begin{bmatrix} 4 \\\\ -3 \\\\ 1 \end{bmatrix}
$$
    
*   **Surface Normal Vector (Unit Vector):**
    
$$
\vec{n} = \begin{bmatrix} 0 \\\\ 1 \\\\ 0 \end{bmatrix} \implies \|\vec{n}\| = 1
$$

#### 1. Scalar Projection
The scalar projection $\text{comp}_{\vec{n}}\vec{v}$ of $\vec{v}$ onto $\vec{n}$ is computed as:

$$
\text{comp}_{\vec{n}}\vec{v} = \frac{\vec{v} \cdot \vec{n}}{\|\vec{n}\|}
$$

Calculate the dot product:

$$
\vec{v} \cdot \vec{n} = 4(0) + (-3)(1) + 1(0) = -3
$$

Since $\|\vec{n}\| = 1$, the scalar projection is:

$$
\text{comp}_{\vec{n}}\vec{v} = \frac{-3}{1} = -3
$$

#### 2. Vector Projection
Since $\vec{n}$ is a unit vector, the vector projection $\text{proj}_{\vec{n}}\vec{v}$ is:

$$
\text{proj}_{\vec{n}}\vec{v} = \left(\text{comp}_{\vec{n}}\vec{v}\right)\vec{n} = -3 \begin{bmatrix} 0 \\\\ 1 \\\\ 0 \end{bmatrix} = \begin{bmatrix} 0 \\\\ -3 \\\\ 0 \end{bmatrix}
$$

---

## Part 2: Conceptual Understanding

### 1. Physical Representation in 3D Space
*   **Orthogonal Shadow:** Geometrically, the vector projection $\text{proj}_{\vec{n}}\vec{v}$ represents the orthogonal projection (or the "vector shadow") of the velocity vector $\vec{v}$ along the axis of the normal vector $\vec{n}$.
*   **Perpendicular Velocity:** Because the normal vector $\vec{n}$ points perpendicular to (out from) the surface, the vector projection represents the **component of velocity directed entirely perpendicular to the surface** (i.e., the speed at which the object is moving directly toward or away from the surface). 
*   **Scalar vs. Vector:** The scalar projection $\text{comp}_{\vec{n}}\vec{v}$ represents the signed speed of this perpendicular motion, while the vector projection represents it as a full 3D direction vector.

### 2. General Non-Unit Normal Vector
If the normal vector $\vec{n}$ is not a unit vector, the actual geometric projection does not change because the direction of projection is independent of the length of the vector. 

However, the mathematical formula must be modified to normalize the vector explicitly. We divide by $\|\vec{n}\|$ once to get the correct scalar magnitude and a second time to define the unit direction vector $\hat{n} = \frac{\vec{n}}{\|\vec{n}\|}$:

$$
\text{proj}_{\vec{n}}\vec{v} = \left(\text{comp}_{\vec{n}}\vec{v}\right)\frac{\vec{n}}{\|\vec{n}\|} = \left(\frac{\vec{v} \cdot \vec{n}}{\|\vec{n}\|}\right)\frac{\vec{n}}{\|\vec{n}\|} = \left(\frac{\vec{v} \cdot \vec{n}}{\|\vec{n}\|^2}\right)\vec{n}
$$

If $\vec{n}$ is a unit vector, $\|\vec{n}\|^2 = 1$, and the formula simplifies back to $(\vec{v} \cdot \vec{n})\vec{n}$.

### 3. Component Parallel to the Surface
Any 3D vector $\vec{v}$ can be orthogonally decomposed into two components relative to a surface normal $\vec{n}$:

$$
\vec{v} = \vec{v}_{\text{normal}} + \vec{v}_{\text{parallel}}
$$

Where:
*   $\vec{v}_{\text{normal}}$ is perpendicular to the surface (parallel to $\vec{n}$). This is exactly the vector projection:
    
$$
\vec{v}_{\text{normal}} = \text{proj}_{\vec{n}}\vec{v}
$$
    
*   $\vec{v}_{\text{parallel}}$ is parallel to the surface (perpendicular to $\vec{n}$). 

To isolate this parallel component (the velocity vector lying along the surface itself), we subtract the vector projection from the original vector:

$$
\vec{v}_{\text{parallel}} = \vec{v} - \text{proj}_{\vec{n}}\vec{v}
$$

This parallel component is known as the **orthogonal rejection** of $\vec{v}$ from $\vec{n}$.

---

**Back to Question:** [[Q_Vector_Projection]] | **Related Concepts:** [[06_Vector_Projection]]