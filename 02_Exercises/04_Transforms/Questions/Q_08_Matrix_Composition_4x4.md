---
topic: Transforms
difficulty: Medium
tags: [exercise, question, matrix-composition, 4x4, mvp-pipeline]
---

# Question

## Part 1: Calculation
Suppose we want to construct a $4 \times 4$ Model Matrix $M$ for a 3D object that undergoes the following transformations in order:
1. **Scale:** Uniform scaling by a factor of $s = 2$.
2. **Rotation:** Rotation by $90^\circ$ around the vertical $k$-axis (z-axis).
3. **Translation:** Translation by $\vec{t} = [3, -1, 4]^T$.

1. Write down the individual $4 \times 4$ transformation matrices: the translation matrix $T$, the rotation matrix $R$, and the scaling matrix $S$.
2. Compute the combined Model Matrix:

$$
M = T \cdot R \cdot S
$$

3. Transform the vertex $\vec{v}$ (given in homogeneous coordinates) using your Model Matrix $M$:

$$
\vec{v} = \begin{bmatrix} 1 \\\\ 2 \\\\ -1 \\\\ 1 \end{bmatrix}
$$

## Part 2: Conceptual Understanding
1. Why is the Model Matrix composition order written right-to-left as $M = T \cdot R \cdot S$ when applying transformations? Explain what would happen geometrically to the object if we computed $M = S \cdot R \cdot T$ instead.
2. In game engines, vertex shaders process millions of vertices per frame. Explain how the Model-View-Projection (MVP) matrix composition ($M_{\text{Total}} = M_{\text{Projection}} \cdot M_{\text{View}} \cdot M_{\text{Model}}$) optimizes this process. Why is it more efficient than transforming vertices step-by-step?

---
**Check Answer:** [[S_08_Matrix_Composition_4x4]] | **Related Concepts:** [[08_Matrix_Composition_4x4]]
