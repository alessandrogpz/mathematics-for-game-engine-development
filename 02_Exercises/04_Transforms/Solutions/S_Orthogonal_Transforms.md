---
topic: Transforms
tags: [exercise, solution, orthogonal-matrix, similarity-transform, change-of-basis]
---
# Solution: Orthogonal and Similarity Transformations

This solution contains the complete, step-by-step mathematical proofs and calculations transcribed from your derivations, formatted with LaTeX and corrected for grammar.

---

## Part 1: Orthogonal Transforms and Geometric Preservation

### 1. Orthonormality Proof
To prove that $\mathbf{M}$ is an orthogonal matrix, we verify two conditions:
1.  **Unit Length (Magnitude = 1):** The columns must be unit vectors.
2.  **Orthogonality (Angle = 90°):** The dot product between any two distinct columns must be $0$.
*(Note: As a property of any orthogonal matrix, its determinant will always be $\pm 1$)*.

Let the column vectors of $\mathbf{M}$ be:
$$\vec{u}_x = \begin{bmatrix} \frac{\sqrt{2}}{2} \\ \frac{\sqrt{2}}{2} \\ 0 \end{bmatrix}, \quad \vec{u}_y = \begin{bmatrix} -\frac{\sqrt{2}}{2} \\ \frac{\sqrt{2}}{2} \\ 0 \end{bmatrix}, \quad \vec{u}_z = \begin{bmatrix} 0 \\ 0 \\ 1 \end{bmatrix}$$

*   **Checking Magnitude:**
    $$\|\vec{u}_x\| = \sqrt{\sum_{i=1}^3 u_i^2} = \sqrt{\left(\frac{\sqrt{2}}{2}\right)^2 + \left(\frac{\sqrt{2}}{2}\right)^2 + 0^2} = \sqrt{\frac{2}{4} + \frac{2}{4} + 0} = \sqrt{\frac{1}{2} + \frac{1}{2}} = 1$$
    By symmetry, this result is identical for $\vec{u}_y$ and $\vec{u}_z$:
    $$\|\vec{u}_y\| = \sqrt{\left(-\frac{\sqrt{2}}{2}\right)^2 + \left(\frac{\sqrt{2}}{2}\right)^2 + 0^2} = \sqrt{\frac{1}{2} + \frac{1}{2}} = 1$$
    $$\|\vec{u}_z\| = \sqrt{0^2 + 0^2 + 1^2} = 1$$
    All columns are indeed unit vectors.

*   **Checking Angles (Dot Products):**
    Recall that the dot product of two vectors separated by $90^\circ$ is always $0$.
    $$\vec{u}_x \cdot \vec{u}_y = \left(\frac{\sqrt{2}}{2}\right)\left(-\frac{\sqrt{2}}{2}\right) + \left(\frac{\sqrt{2}}{2}\right)\left(\frac{\sqrt{2}}{2}\right) + (0)(0) = -\frac{2}{4} + \frac{2}{4} + 0 = 0$$
    $$\vec{u}_y \cdot \vec{u}_z = \left(-\frac{\sqrt{2}}{2}\right)(0) + \left(\frac{\sqrt{2}}{2}\right)(0) + (0)(1) = 0$$
    $$\vec{u}_z \cdot \vec{u}_x = (0)\left(\frac{\sqrt{2}}{2}\right) + (0)\left(\frac{\sqrt{2}}{2}\right) + (1)(0) = 0$$
    Since the columns are mutually perpendicular unit vectors, $\mathbf{M}$ is certified as an orthogonal matrix.

*   **Alternative Proof ($\mathbf{M}^T\mathbf{M} = \mathbf{I}$):**
    For any orthogonal matrix, its inverse is equal to its transpose ($\mathbf{M}^{-1} = \mathbf{M}^T$). We compute:
    $$\mathbf{M}^T\mathbf{M} = \begin{bmatrix} \frac{\sqrt{2}}{2} & \frac{\sqrt{2}}{2} & 0 \\ -\frac{\sqrt{2}}{2} & \frac{\sqrt{2}}{2} & 0 \\ 0 & 0 & 1 \end{bmatrix} \begin{bmatrix} \frac{\sqrt{2}}{2} & -\frac{\sqrt{2}}{2} & 0 \\ \frac{\sqrt{2}}{2} & \frac{\sqrt{2}}{2} & 0 \\ 0 & 0 & 1 \end{bmatrix} = \begin{bmatrix} \vec{u}_x \cdot \vec{u}_x & \vec{u}_x \cdot \vec{u}_y & \vec{u}_x \cdot \vec{u}_z \\ \vec{u}_y \cdot \vec{u}_x & \vec{u}_y \cdot \vec{u}_y & \vec{u}_y \cdot \vec{u}_z \\ \vec{u}_z \cdot \vec{u}_x & \vec{u}_z \cdot \vec{u}_y & \vec{u}_z \cdot \vec{u}_z \end{bmatrix}$$
    Knowing that any dot product of a vector with itself is $1$, and any dot product of two distinct columns is $0$, we get:
    $$\mathbf{M}^T\mathbf{M} = \begin{bmatrix} 1 & 0 & 0 \\ 0 & 1 & 0 \\ 0 & 0 & 1 \end{bmatrix} = \mathbf{I}$$
    This proves that $\mathbf{M}$ is indeed orthogonal.

---

### 2. Vector Transformation
We calculate the transformed vectors $\vec{v}' = \mathbf{M}\vec{v}$ and $\vec{w}' = \mathbf{M}\vec{w}$ using matrix-vector multiplication:

*   **Transforming $\vec{v}$:**
    $$\vec{v}' = \begin{bmatrix} \frac{\sqrt{2}}{2} & -\frac{\sqrt{2}}{2} & 0 \\ \frac{\sqrt{2}}{2} & \frac{\sqrt{2}}{2} & 0 \\ 0 & 0 & 1 \end{bmatrix} \begin{bmatrix} 2 \\ 2 \\ 1 \end{bmatrix} = \begin{bmatrix} \left(\frac{\sqrt{2}}{2}\right)(2) + \left(-\frac{\sqrt{2}}{2}\right)(2) + (0)(1) \\ \left(\frac{\sqrt{2}}{2}\right)(2) + \left(\frac{\sqrt{2}}{2}\right)(2) + (0)(1) \\ (0)(2) + (0)(2) + (1)(1) \end{bmatrix} = \begin{bmatrix} \sqrt{2} - \sqrt{2} + 0 \\ \sqrt{2} + \sqrt{2} + 0 \\ 0 + 0 + 1 \end{bmatrix} = \begin{bmatrix} 0 \\ 2\sqrt{2} \\ 1 \end{bmatrix}$$

*   **Transforming $\vec{w}$:**
    $$\vec{w}' = \begin{bmatrix} \frac{\sqrt{2}}{2} & -\frac{\sqrt{2}}{2} & 0 \\ \frac{\sqrt{2}}{2} & \frac{\sqrt{2}}{2} & 0 \\ 0 & 0 & 1 \end{bmatrix} \begin{bmatrix} 0 \\ 4 \\ -3 \end{bmatrix} = \begin{bmatrix} \left(\frac{\sqrt{2}}{2}\right)(0) + \left(-\frac{\sqrt{2}}{2}\right)(4) + (0)(-3) \\ \left(\frac{\sqrt{2}}{2}\right)(0) + \left(\frac{\sqrt{2}}{2}\right)(4) + (0)(-3) \\ (0)(0) + (0)(4) + (1)(-3) \end{bmatrix} = \begin{bmatrix} 0 - 2\sqrt{2} + 0 \\ 0 + 2\sqrt{2} + 0 \\ 0 + 0 - 3 \end{bmatrix} = \begin{bmatrix} -2\sqrt{2} \\ 2\sqrt{2} \\ -3 \end{bmatrix}$$

---

### 3. Preservation Verification

#### a. Verify that $\vec{v} \cdot \vec{w} = \vec{v}' \cdot \vec{w}'$
*   **Original Dot Product:**
    $$\vec{v} \cdot \vec{w} = \sum_{i=1}^3 v_i w_i = (2)(0) + (2)(4) + (1)(-3) = 0 + 8 - 3 = 5$$
*   **Transformed Dot Product:**
    $$\vec{v}' \cdot \vec{w}' = \sum_{i=1}^3 v'_i w'_i = (0)(-2\sqrt{2}) + (2\sqrt{2})(2\sqrt{2}) + (1)(-3) = 0 + 4(2) - 3 = 8 - 3 = 5$$
Both are equal to $5$, verifying dot product preservation.

#### b. Verify that $\|\vec{v}\| = \|\vec{v}'\|$ and $\|\vec{w}\| = \|\vec{w}'\|$
Using the magnitude formula $\|\vec{a}\| = \sqrt{\sum_{i=1}^3 a_i^2}$:
*   **For Vector $\vec{v}$:**
    $$\|\vec{v}\| = \sqrt{2^2 + 2^2 + 1^2} = \sqrt{4 + 4 + 1} = \sqrt{9} = 3$$
    $$\|\vec{v}'\| = \sqrt{0^2 + (2\sqrt{2})^2 + 1^2} = \sqrt{0 + 4(2) + 1} = \sqrt{8 + 1} = \sqrt{9} = 3$$
*   **For Vector $\vec{w}$:**
    $$\|\vec{w}\| = \sqrt{0^2 + 4^2 + (-3)^2} = \sqrt{16 + 9} = \sqrt{25} = 5$$
    $$\|\vec{w}'\| = \sqrt{(-2\sqrt{2})^2 + (2\sqrt{2})^2 + (-3)^2} = \sqrt{4(2) + 4(2) + 9} = \sqrt{8 + 8 + 9} = \sqrt{25} = 5$$
Both lengths are perfectly preserved.

---

### 4. Orientation
We compute the determinant of $\mathbf{M}$ by expansion:
$$\det(\mathbf{M}) = \begin{vmatrix} \frac{\sqrt{2}}{2} & -\frac{\sqrt{2}}{2} & 0 \\ \frac{\sqrt{2}}{2} & \frac{\sqrt{2}}{2} & 0 \\ 0 & 0 & 1 \end{vmatrix}$$
Expanding along the third column/row:
$$\det(\mathbf{M}) = 1 \cdot \begin{vmatrix} \frac{\sqrt{2}}{2} & -\frac{\sqrt{2}}{2} \\ \frac{\sqrt{2}}{2} & \frac{\sqrt{2}}{2} \end{vmatrix} = \left(\frac{\sqrt{2}}{2}\right)\left(\frac{\sqrt{2}}{2}\right) - \left(-\frac{\sqrt{2}}{2}\right)\left(\frac{\sqrt{2}}{2}\right) = \frac{2}{4} - \left(-\frac{2}{4}\right) = \frac{1}{2} + \frac{1}{2} = 1$$

**Geometric Meaning:** Since $\det(\mathbf{M}) = 1$, it represents a **pure rotation** (preserving hand-orientation). A value of $-1$ would represent a reflection (or a rotation combined with a reflection).

---

## Part 2: Composition and Change of Basis (Similarity Transforms)

### 1. Similarity Transform Calculation
We are given:
$$\mathbf{M} = \begin{bmatrix} 0 & 1 & 0 \\ -1 & 0 & 0 \\ 0 & 0 & 1 \end{bmatrix}, \quad \mathbf{S}_A = \begin{bmatrix} 3 & 0 & 0 \\ 0 & 1 & 0 \\ 0 & 0 & 1 \end{bmatrix}$$

Since $\mathbf{M}$ is orthogonal, its inverse is its transpose: $\mathbf{M}^{-1} = \mathbf{M}^T$.
$$\mathbf{M}^T = \begin{bmatrix} 0 & -1 & 0 \\ 1 & 0 & 0 \\ 0 & 0 & 1 \end{bmatrix}$$

We calculate $\mathbf{S}_B = \mathbf{M}\mathbf{S}_A\mathbf{M}^T$:
1.  **Multiply $\mathbf{M}\mathbf{S}_A$ first:**
    $$\mathbf{M}\mathbf{S}_A = \begin{bmatrix} 0 & 1 & 0 \\ -1 & 0 & 0 \\ 0 & 0 & 1 \end{bmatrix} \begin{bmatrix} 3 & 0 & 0 \\ 0 & 1 & 0 \\ 0 & 0 & 1 \end{bmatrix} = \begin{bmatrix} (0)(3)+(1)(0)+(0)(0) & (0)(0)+(1)(1)+(0)(0) & (0)(0)+(1)(0)+(0)(1) \\ (-1)(3)+(0)(0)+(0)(0) & (-1)(0)+(0)(1)+(0)(0) & (-1)(0)+(0)(0)+(0)(1) \\ (0)(3)+(0)(0)+(1)(0) & (0)(0)+(0)(1)+(1)(0) & (0)(0)+(0)(0)+(1)(1) \end{bmatrix} = \begin{bmatrix} 0 & 1 & 0 \\ -3 & 0 & 0 \\ 0 & 0 & 1 \end{bmatrix}$$

2.  **Multiply by $\mathbf{M}^T$:**
    $$\mathbf{S}_B = (\mathbf{M}\mathbf{S}_A)\mathbf{M}^T = \begin{bmatrix} 0 & 1 & 0 \\ -3 & 0 & 0 \\ 0 & 0 & 1 \end{bmatrix} \begin{bmatrix} 0 & -1 & 0 \\ 1 & 0 & 0 \\ 0 & 0 & 1 \end{bmatrix} = \begin{bmatrix} (0)(0)+(1)(1)+(0)(0) & (0)(-1)+(1)(0)+(0)(0) & (0)(0)+(1)(0)+(0)(1) \\ (-3)(0)+(0)(1)+(0)(0) & (-3)(-1)+(0)(0)+(0)(0) & (-3)(0)+(0)(0)+(0)(1) \\ (0)(0)+(0)(1)+(1)(0) & (0)(-1)+(0)(0)+(1)(0) & (0)(0)+(0)(0)+(1)(1) \end{bmatrix} = \begin{bmatrix} 1 & 0 & 0 \\ 0 & 3 & 0 \\ 0 & 0 & 1 \end{bmatrix}$$

---

### 2. Geometric Intuition

To explain the geometric meaning of our result $\mathbf{S}_B$, we first need to undo the $-90^\circ$ rotation, since we are working on a local scale ($A$) and our world ($B$) is rotated by $-90^\circ$. By doing so, the $A$ and $B$ axes are aligned, allowing us to apply the desired scaling and then convert back to the original $-90^\circ$ rotation.

This change-of-basis operation is composed of three sequential steps (read right-to-left):
*   **Undo ($\mathbf{M}^{-1}$):** Un-rotate to temporarily align the local and world axes.
*   **Apply ($\mathbf{S}_A$):** Perform the stretch on the isolated local axis.
*   **Redo ($\mathbf{M}$):** Re-apply the rotation to put the object back into the world.

Because System $A$ is rotated $-90^\circ$ relative to System $B$, System $A$'s local x-axis physically points in the same direction as System $B$'s y-axis. Therefore, applying a scale to the local x-axis geometrically manifests as a scale along the world y-axis. This is verified mathematically by the entry $3$ on the main diagonal in $\mathbf{S}_B$ at the $(2, 2)$ index, which corresponds directly to the y-axis scaling factor.

---
## Code Implementation
```cpp
// Optional C++ snippet here
```

---

**Back to Question:** [[Q_Orthogonal_Transforms]] | **Related Concepts:** [[01_Transformation_Matrices]]

