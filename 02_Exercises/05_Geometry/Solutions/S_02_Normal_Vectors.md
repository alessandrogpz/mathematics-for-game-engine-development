---
topic: Geometry
tags: [exercise, solution, normal-vector, cross-product, normal-transformation]
---

# Solution: Normal Vectors

This solution note details the calculations and derivations for computing and transforming normal vectors.

---

## Part 1: Calculation

A triangular mesh face lies entirely in the plane $x = 2$, with vertices:

$$
P_0 = (2, 0, 0), \quad P_1 = (2, 3, 0), \quad P_2 = (2, 0, 4)
$$

---

### Question 1: Edge Vectors $\vec{P_0P_1}$ and $\vec{P_0P_2}$

Calculating the displacement vectors from $P_0$:

$$
\vec{P_0P_1} = P_1 - P_0 = \begin{bmatrix} 2 \\ 3 \\ 0 \end{bmatrix} - \begin{bmatrix} 2 \\ 0 \\ 0 \end{bmatrix} = \begin{bmatrix} 0 \\ 3 \\ 0 \end{bmatrix}
$$

$$
\vec{P_0P_2} = P_2 - P_0 = \begin{bmatrix} 2 \\ 0 \\ 4 \end{bmatrix} - \begin{bmatrix} 2 \\ 0 \\ 0 \end{bmatrix} = \begin{bmatrix} 0 \\ 0 \\ 4 \end{bmatrix}
$$

---

### Question 2: Face Normal $\vec{N}$, Magnitude $\|\vec{N}\|$, and Unit Normal $\hat{n}$

Computing the face normal using the [[04_Cross_Product|cross product]]:

$$
\vec{N} = \vec{P_0P_1} \times \vec{P_0P_2} = \begin{bmatrix} 0 \\ 3 \\ 0 \end{bmatrix} \times \begin{bmatrix} 0 \\ 0 \\ 4 \end{bmatrix}
$$

$$
\vec{N} = \begin{bmatrix} (3)(4) - (0)(0) \\ (0)(0) - (0)(4) \\ (0)(0) - (3)(0) \end{bmatrix} = \begin{bmatrix} 12 \\ 0 \\ 0 \end{bmatrix}
$$

Calculating the magnitude of $\vec{N}$:

$$
\|\vec{N}\| = \sqrt{12^2 + 0^2 + 0^2} = \sqrt{144} = 12
$$

Normalizing to get the unit normal $\hat{n}$:

$$
\hat{n} = \frac{\vec{N}}{\|\vec{N}\|} = \frac{1}{12} \begin{bmatrix} 12 \\ 0 \\ 0 \end{bmatrix} = \begin{bmatrix} 1 \\ 0 \\ 0 \end{bmatrix}
$$

---

### Question 3: Area of the Triangle

The area of a triangle formed by two edge vectors is equal to half the magnitude of their cross product:

$$
\text{Area} = \frac{1}{2} \|\vec{N}\| = \frac{12}{2} = 6
$$

Thus, the area of the triangular face is **$6$ square units**.

---

### Question 4: Reversed Winding Order ($P_0, P_2, P_1$)

If the vertices are wound in the order $P_0, P_2, P_1$, the face normal is computed as:

$$
\vec{N}' = \vec{P_0P_2} \times \vec{P_0P_1} = \begin{bmatrix} 0 \\ 0 \\ 4 \end{bmatrix} \times \begin{bmatrix} 0 \\ 3 \\ 0 \end{bmatrix} = \begin{bmatrix} -12 \\ 0 \\ 0 \end{bmatrix}
$$

Corresponding unit normal:

$$
\hat{n}' = \begin{bmatrix} -1 \\ 0 \\ 0 \end{bmatrix}
$$

* **Demonstration / Significance:** Reversing the winding order flips the direction of the normal vector due to the anti-commutativity of the cross product ($\vec{a} \times \vec{b} = -(\vec{b} \times \vec{a})$). This demonstrates why maintaining a **consistent winding order** (e.g. counter-clockwise as seen from outside the mesh) is crucial across a 3D model—otherwise, half the surface normals will point inward into the mesh, causing backface culling errors and inverted lighting/shading.

---

## Part 2: Conceptual Understanding

The mesh is transformed by the shear matrix:

$$
\mathbf{M} = \begin{bmatrix} 1 & 0 & 0 \\ 1 & 1 & 0 \\ 0 & 0 & 1 \end{bmatrix}
$$

---

### Question 1: Naive Normal Transformation Failure

Applying $\mathbf{M}$ directly to the original unit normal $\hat{n}_A = \begin{bmatrix} 1 \\ 0 \\ 0 \end{bmatrix}$:

$$
\hat{n}_{\text{naive}} = \mathbf{M}\hat{n}_A = \begin{bmatrix} 1 & 0 & 0 \\ 1 & 1 & 0 \\ 0 & 0 & 1 \end{bmatrix} \begin{bmatrix} 1 \\ 0 \\ 0 \end{bmatrix} = \begin{bmatrix} 1 \\ 1 \\ 0 \end{bmatrix}
$$

Transforming the face's vertices directly under $\mathbf{M}$:

$$
P_0' = \mathbf{M}P_0 = \begin{bmatrix} 1 & 0 & 0 \\ 1 & 1 & 0 \\ 0 & 0 & 1 \end{bmatrix}\begin{bmatrix} 2 \\ 0 \\ 0 \end{bmatrix} = \begin{bmatrix} 2 \\ 2 \\ 0 \end{bmatrix}
$$

$$
P_1' = \mathbf{M}P_1 = \begin{bmatrix} 1 & 0 & 0 \\ 1 & 1 & 0 \\ 0 & 0 & 1 \end{bmatrix}\begin{bmatrix} 2 \\ 3 \\ 0 \end{bmatrix} = \begin{bmatrix} 2 \\ 5 \\ 0 \end{bmatrix}
$$

$$
P_2' = \mathbf{M}P_2 = \begin{bmatrix} 1 & 0 & 0 \\ 1 & 1 & 0 \\ 0 & 0 & 1 \end{bmatrix}\begin{bmatrix} 2 \\ 0 \\ 4 \end{bmatrix} = \begin{bmatrix} 2 \\ 2 \\ 4 \end{bmatrix}
$$

Calculating the transformed face's edge vectors:

$$
\vec{P_0'P_1'} = P_1' - P_0' = \begin{bmatrix} 2 \\ 5 \\ 0 \end{bmatrix} - \begin{bmatrix} 2 \\ 2 \\ 0 \end{bmatrix} = \begin{bmatrix} 0 \\ 3 \\ 0 \end{bmatrix}
$$

$$
\vec{P_0'P_2'} = P_2' - P_0' = \begin{bmatrix} 2 \\ 2 \\ 4 \end{bmatrix} - \begin{bmatrix} 2 \\ 2 \\ 0 \end{bmatrix} = \begin{bmatrix} 0 \\ 0 \\ 4 \end{bmatrix}
$$

Recomputing the true face normal from the transformed edge vectors:

$$
\vec{N}' = \vec{P_0'P_1'} \times \vec{P_0'P_2'} = \begin{bmatrix} 0 \\ 3 \\ 0 \end{bmatrix} \times \begin{bmatrix} 0 \\ 0 \\ 4 \end{bmatrix} = \begin{bmatrix} 12 \\ 0 \\ 0 \end{bmatrix} \implies \hat{n}_{\text{true}} = \begin{bmatrix} 1 \\ 0 \\ 0 \end{bmatrix}
$$

Since $\hat{n}_{\text{true}} = \begin{bmatrix} 1 \\ 0 \\ 0 \end{bmatrix} \neq \begin{bmatrix} 1 \\ 1 \\ 0 \end{bmatrix} = \hat{n}_{\text{naive}}$, transforming the normal vector naively using $\mathbf{M}$ fails.

---

### Question 2: Correct Normal Transformation via Inverse-Transpose

#### 1. Inverting $\mathbf{M}$ via Row Operations
Setting up the augmented matrix $[\mathbf{M} | \mathbf{I}]$:

$$
\begin{bmatrix}
1 & 0 & 0 & | & 1 & 0 & 0 \\\\
1 & 1 & 0 & | & 0 & 1 & 0 \\\\
0 & 0 & 1 & | & 0 & 0 & 1
\end{bmatrix}
$$

Perform $R_2 \leftarrow R_2 - R_1$:

$$
\begin{bmatrix}
1 & 0 & 0 & | & 1 & 0 & 0 \\\\
0 & 1 & 0 & | & -1 & 1 & 0 \\\\
0 & 0 & 1 & | & 0 & 0 & 1
\end{bmatrix}
$$

Thus, the inverse matrix is:

$$
\mathbf{M}^{-1} = \begin{bmatrix} 1 & 0 & 0 \\ -1 & 1 & 0 \\ 0 & 0 & 1 \end{bmatrix}
$$

#### 2. Transpose $(\mathbf{M}^{-1})^T$

$$
(\mathbf{M}^{-1})^T = \begin{bmatrix} 1 & -1 & 0 \\ 0 & 1 & 0 \\ 0 & 0 & 1 \end{bmatrix}
$$

#### 3. Correctly Transformed Normal $\hat{n}_B$

$$
\hat{n}_B = (\mathbf{M}^{-1})^T \hat{n}_A = \begin{bmatrix} 1 & -1 & 0 \\ 0 & 1 & 0 \\ 0 & 0 & 1 \end{bmatrix} \begin{bmatrix} 1 \\ 0 \\ 0 \end{bmatrix} = \begin{bmatrix} 1 \\ 0 \\ 0 \end{bmatrix}
$$

This matches the true recomputed normal $\hat{n}_{\text{true}} = \begin{bmatrix} 1 \\ 0 \\ 0 \end{bmatrix}$.

#### 4. Proving Orthogonality
Checking the dot product of $\hat{n}_B$ with both transformed edge vectors:

$$
\vec{P_0'P_1'} \cdot \hat{n}_B = \begin{bmatrix} 0 \\ 3 \\ 0 \end{bmatrix} \cdot \begin{bmatrix} 1 \\ 0 \\ 0 \end{bmatrix} = (0)(1) + (3)(0) + (0)(0) = 0 \quad \checkmark
$$

$$
\vec{P_0'P_2'} \cdot \hat{n}_B = \begin{bmatrix} 0 \\ 0 \\ 4 \end{bmatrix} \cdot \begin{bmatrix} 1 \\ 0 \\ 0 \end{bmatrix} = (0)(1) + (0)(0) + (4)(0) = 0 \quad \checkmark
$$

Since both dot products equal $0$, the transformed normal $\hat{n}_B$ is proven to be orthogonal to both transformed edge vectors.

---

### Question 3: Reflection & Determinant Sign Correction

For reflection matrix $\mathbf{M} = \text{diag}(1, -1, 1)$:

$$
\det(\mathbf{M}) = (1)(-1)(1) = -1
$$

* **Justification:** Yes, the $\text{sign}(\det(\mathbf{M}))$ correction is **necessary**.
* When an object undergoes a reflection ($\det(\mathbf{M}) < 0$), space is inverted and spatial handedness is flipped. Applying $(\mathbf{M}^{-1})^T$ alone produces a vector pointing in the **opposite direction** of the true outward normal of the reflected surface.
* To correct for this, we must include the sign of the determinant:

$$
\hat{n}_B = \text{sign}(\det(\mathbf{M})) (\mathbf{M}^{-1})^T \hat{n}_A
$$

In our case, $\text{sign}(\det(\mathbf{M})) = -1$, so:

$$
\hat{n}_B = -(\mathbf{M}^{-1})^T \hat{n}_A
$$

This flips the normal vector back so that it points outwards from the newly reflected face.

---

**Back to Question:** [[Q_02_Normal_Vectors]] | **Related Concepts:** [[02_Normal_Vectors]]
