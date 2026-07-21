# Normal Vectors

A **normal vector** is a vector that points orthogonally outward from a surface. Normals are essential in computer graphics and physics: lighting calculations (e.g. Lambertian/diffuse shading) depend on the angle between a surface normal and a light direction via the dot product, and collision response depends on the normal to determine which way to push objects apart. Normal vectors are almost always scaled down to **unit vectors** before use.

## Computing Face Normals

There are multiple ways to calculate a normal vector, and the best method depends on how the surface is mathematically described. For a **triangular face** with vertices $P_0$, $P_1$, and $P_2$, the normal $\vec{n}$ is given by the cross product of the two edge vectors emanating from $P_0$:

$$
\vec{n} = (P_1 - P_0) \times (P_2 - P_0)
$$

Because the cross product is anti-commutative (see [[04_Cross_Product]]), the **order** of the vertices determines which of the two possible directions $\vec{n}$ points in. A mesh is only usable for rendering if every triangle's vertices are wound **consistently** (e.g. always counter-clockwise as seen from outside the solid) so that every computed normal points outward.

### Worked Example

Reusing the front-face triangle from the cube in [[01_Triangle_Meshes]], with $P_0 = V_0 = (0,0,0)$, $P_1 = V_1 = (1,0,0)$, and $P_2 = V_5 = (1,0,1)$:

$$
P_1 - P_0 = \begin{bmatrix} 1 \\\\ 0 \\\\ 0 \end{bmatrix}, \quad P_2 - P_0 = \begin{bmatrix} 1 \\\\ 0 \\\\ 1 \end{bmatrix}
$$

$$
\vec{n} = \begin{bmatrix} 1 \\\\ 0 \\\\ 0 \end{bmatrix} \times \begin{bmatrix} 1 \\\\ 0 \\\\ 1 \end{bmatrix} = \begin{bmatrix} (0)(1) - (0)(0) \\\\ (0)(1) - (1)(1) \\\\ (1)(0) - (0)(1) \end{bmatrix} = \begin{bmatrix} 0 \\\\ -1 \\\\ 0 \end{bmatrix}
$$

This already has unit length and correctly points in the $-y$ direction — exactly the outward direction expected for the cube's front ($y=0$) face.

## Face Normals vs. Vertex Normals

The formula above produces one **face normal** per triangle, which is constant across the entire face. Rendering a mesh with only face normals produces a faceted, low-poly look (**flat shading**), since the normal jumps discontinuously at every edge.

To approximate a smoothly curved surface (**smooth shading**), a **vertex normal** is instead computed at each vertex as the (weighted) average of the face normals of every triangle that shares that vertex, re-normalized to unit length. These vertex normals are then interpolated across each triangle during rendering (e.g. Gouraud or Phong shading), producing smooth-looking gradients even though the underlying geometry is still flat triangles.

---

## Transforming Normal Vectors

When an object is transformed by a matrix $\mathbf{M}$, there is no guarantee that its normal vectors transform correctly by simply applying $\mathbf{M}$ to them directly — the naive transformed vector may end up neither orthogonal to the surface nor pointing in the right direction.

### The Problem: Why $\mathbf{M}$ Alone Fails

Consider a shear matrix acting on 2D vectors (shearing along $x$ proportionally to $y$), an edge $\vec{e}$, and a perpendicular (normal) vector $\vec{n}$:

$$
\mathbf{M} = \begin{bmatrix} 1 & 2 \\\\ 0 & 1 \end{bmatrix}, \quad \vec{e} = \begin{bmatrix} 0 \\\\ 1 \end{bmatrix}, \quad \vec{n} = \begin{bmatrix} 1 \\\\ 0 \end{bmatrix}
$$

Transforming the edge directly (edges/tangent vectors always transform correctly this way):

$$
\vec{e}' = \mathbf{M}\vec{e} = \begin{bmatrix} 1 & 2 \\\\ 0 & 1 \end{bmatrix}\begin{bmatrix} 0 \\\\ 1 \end{bmatrix} = \begin{bmatrix} 2 \\\\ 1 \end{bmatrix}
$$

But transforming the normal the same naive way gives:

$$
\vec{n}'_{\text{naive}} = \mathbf{M}\vec{n} = \begin{bmatrix} 1 & 2 \\\\ 0 & 1 \end{bmatrix}\begin{bmatrix} 1 \\\\ 0 \end{bmatrix} = \begin{bmatrix} 1 \\\\ 0 \end{bmatrix}
$$

Checking orthogonality: $\vec{e}' \cdot \vec{n}'_{\text{naive}} = (2)(1) + (1)(0) = 2 \neq 0$. The naively transformed vector is **no longer perpendicular** to the transformed edge.

### The General Rule: Inverse-Transpose

To find the correct transformation, we require that the transformed normal $\vec{n}' = \mathbf{A}\vec{n}$ stays orthogonal to every transformed tangent vector $\vec{t}' = \mathbf{M}\vec{t}$ lying in the surface, for any $\vec{t}$ satisfying $\vec{n} \cdot \vec{t} = 0$:

$$
\vec{n}'^T \vec{t}' = \vec{n}^T \mathbf{A}^T \mathbf{M} \vec{t} = 0
$$

Since this must hold for every $\vec{t}$ in the (codimension-1) tangent plane defined by $\vec{n} \cdot \vec{t} = 0$, the matrix $\mathbf{A}^T \mathbf{M}$ must reduce to a scalar multiple of the identity. Taking that scalar to be $1$:

$$
\mathbf{A}^T \mathbf{M} = \mathbf{I} \quad \implies \quad \mathbf{A} = (\mathbf{M}^{-1})^T
$$

This gives the general normal-transformation rule:

$$
\vec{n}_B = (\mathbf{M}^{-1})^T \vec{n}_A
$$

Re-checking the shear example with this corrected formula:

$$
\mathbf{M}^{-1} = \begin{bmatrix} 1 & -2 \\\\ 0 & 1 \end{bmatrix}, \quad (\mathbf{M}^{-1})^T = \begin{bmatrix} 1 & 0 \\\\ -2 & 1 \end{bmatrix}
$$

giving:

$$
\vec{n}'_{\text{correct}} = \begin{bmatrix} 1 & 0 \\\\ -2 & 1 \end{bmatrix}\begin{bmatrix} 1 \\\\ 0 \end{bmatrix} = \begin{bmatrix} 1 \\\\ -2 \end{bmatrix}
$$

Checking orthogonality: $\vec{e}' \cdot \vec{n}'_{\text{correct}} = (2)(1) + (1)(-2) = 0$. ✓ Correctly perpendicular.

### Special Case: Rotations and Translations

For a pure rotation, $\mathbf{M}$ is orthogonal, so $\mathbf{M}^{-1} = \mathbf{M}^T$ (see [[05_Orthogonal_Matrices]]), which means $(\mathbf{M}^{-1})^T = (\mathbf{M}^T)^T = \mathbf{M}$. Rotations can therefore transform normals with the same matrix used for positions:

$$
\vec{n}_B = \mathbf{M}\vec{n}_A \qquad \text{(rotations only)}
$$

Translations have no linear part acting on directions at all (only positions are shifted), so normal vectors are completely unaffected by translation.

### Reflections: An Extra Sign Correction

Reflections also use $(\mathbf{M}^{-1})^T$, but with one additional subtlety. There is a general identity relating the cross product of two transformed vectors to the inverse-transpose of their original cross product:

$$
(\mathbf{M}\vec{a}) \times (\mathbf{M}\vec{b}) = \det(\mathbf{M}) \cdot (\mathbf{M}^{-1})^T (\vec{a} \times \vec{b})
$$

Since a face normal is itself defined as a cross product ($\vec{n} = (P_1 - P_0) \times (P_2 - P_0)$), whenever $\det(\mathbf{M}) < 0$ — which happens exactly when $\mathbf{M}$ includes a reflection — the term $(\mathbf{M}^{-1})^T \vec{n}$ points **opposite** to the true, freshly-recomputed normal of the reflected triangle. Correcting for this requires multiplying by the sign of the determinant:

$$
\vec{n}_B = \text{sign}(\det(\mathbf{M})) \cdot (\mathbf{M}^{-1})^T \vec{n}_A
$$

**Worked example:** Reflect the triangle $A=(0,0,0)$, $B=(2,0,0)$, $C=(0,1,0)$ (lying in the $z=0$ plane, with face normal $\vec{n} = (B-A)\times(C-A) = (0,0,2)$) across the $xz$-plane using $\mathbf{M} = \text{diag}(1,-1,1)$, which is its own inverse and transpose, and has $\det(\mathbf{M}) = -1$.

*   **Recomputing from scratch:** $A' = (0,0,0)$, $B' = (2,0,0)$, $C' = (0,-1,0)$, giving $\vec{n}' = (B'-A') \times (C'-A') = (0,0,-2)$.
*   **Naive $(\mathbf{M}^{-1})^T\vec{n}$:** Since $\mathbf{M}$ is symmetric and self-inverse, $(\mathbf{M}^{-1})^T\vec{n} = \mathbf{M}\vec{n} = (0,0,2)$ — the **wrong** (inward-flipped) sign.
*   **Corrected:** $\text{sign}(\det(\mathbf{M})) \cdot (\mathbf{M}^{-1})^T\vec{n} = (-1)(0,0,2) = (0,0,-2)$, matching the true recomputed normal. ✓

### Renormalization

Except for pure rotations and translations, none of the transformations above preserve length: a unit normal transformed by $(\mathbf{M}^{-1})^T$ (with or without the sign correction) will generally no longer have unit length after scaling, shearing, or reflecting. The transformed normal must therefore be **re-normalized** after applying any of these transformations.

| Transformation | Formula for $\vec{n}_B$ | Renormalize? |
| :--- | :--- | :--- |
| Translation | $\vec{n}_A$ (unchanged) | No |
| Rotation | $\mathbf{M}\vec{n}_A$ | No |
| Scale / Shear | $(\mathbf{M}^{-1})^T \vec{n}_A$ | Yes |
| Reflection | $\text{sign}(\det(\mathbf{M}))\,(\mathbf{M}^{-1})^T \vec{n}_A$ | Yes |
