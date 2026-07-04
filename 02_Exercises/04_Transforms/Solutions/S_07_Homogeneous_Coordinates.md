---
topic: Transforms
tags: [exercise, solution, homogeneous-coordinates, projective-space, projective-geometry]
---

# Solution: Homogeneous Coordinates

This solution note details the step-by-step calculations and conceptual answers for the homogeneous coordinates exercise.

---

## Part 1: Calculation and Conversions

### 1. Homogeneous to Euclidean Conversion

We convert the following 4D homogeneous coordinates to 3D Euclidean coordinates by performing homogeneous division (dividing the first three components by the fourth component, $w$):

*   **Vector $\vec{a}_h$:**
    
    $$
    \vec{a}_h = \begin{bmatrix} 4 \\\\ -8 \\\\ 12 \\\\ 2 \end{bmatrix} \implies \vec{a}_E = \frac{1}{2}\begin{bmatrix} 4 \\\\ -8 \\\\ 12 \end{bmatrix} = \begin{bmatrix} 2 \\\\ -4 \\\\ 6 \end{bmatrix}
    $$

*   **Vector $\vec{b}_h$:**
    
    $$
    \vec{b}_h = \begin{bmatrix} -2 \\\\ 4 \\\\ -6 \\\\ -1 \end{bmatrix} \implies \vec{b}_E = \frac{1}{-1}\begin{bmatrix} -2 \\\\ 4 \\\\ -6 \end{bmatrix} = \begin{bmatrix} 2 \\\\ -4 \\\\ 6 \end{bmatrix}
    $$

*   **Vector $\vec{c}_h$:**
    
    $$
    \vec{c}_h = \begin{bmatrix} 5 \\\\ 3 \\\\ -1 \\\\ 0 \end{bmatrix}
    $$
    
    Since the $w$-coordinate is $0$, division by zero is undefined. This vector represents a **point at infinity** (or a directional vector) in the direction of the vector:
    
    $$
    \vec{v} = \begin{bmatrix} 5 \\\\ 3 \\\\ -1 \end{bmatrix}
    $$

#### Verification & Geometric Meanings
*   **Comparison of $\vec{a}_h$ and $\vec{b}_h$:** Both vectors represent the **same point** in 3D Euclidean space because they project to the exact same coordinates $\begin{bmatrix} 2 & -4 & 6 \end{bmatrix}^T$ after homogeneous division.
*   **Geometric Meaning of $\vec{c}_h$:** It represents a point at infinity, which geometrically behaves as a direction. As $w \to 0$, the Euclidean point moves infinitely far in the direction of the vector.

### 2. Euclidean to Homogeneous Representation
For the 3D Euclidean point $P(3, -2, 5)$, we can construct distinct 4D homogeneous coordinate vectors by multiplying the Euclidean coordinates and the $w$-coordinate by any non-zero scalar $k \in \mathbb{R}$:

$$
\vec{p}_h = \begin{bmatrix} 3k \\\\ -2k \\\\ 5k \\\\ k \end{bmatrix} \quad (k \neq 0)
$$

Three distinct representations are:
*   For $k=1$: $\vec{p}_1 = [3, -2, 5, 1]^T$
*   For $k=2$: $\vec{p}_2 = [6, -4, 10, 2]^T$
*   For $k=3$: $\vec{p}_3 = [9, -6, 15, 3]^T$
*   For $k=4$: $\vec{p}_4 = [12, -8, 20, 4]^T$

### 3. High-Dimensional Translation Calculation

Given a point $P$ with homogeneous coordinates $\vec{p}_h = [3, -6, 9, 3]^T$ and translation vector $\vec{t} = [2, -1, 4]^T$:

*   **Euclidean Coordinates of $P$:**
    
    $$
    \vec{p}_E = \frac{1}{3}\begin{bmatrix} 3 \\\\ -6 \\\\ 9 \end{bmatrix} = \begin{bmatrix} 1 \\\\ -2 \\\\ 3 \end{bmatrix}
    $$

*   **$4 \times 4$ Translation Matrix $\mathbf{T}(\vec{t})$:**
    
    $$
    \mathbf{T}(\vec{t}) = \begin{bmatrix} 1 & 0 & 0 & 2 \\\\ 0 & 1 & 0 & -1 \\\\ 0 & 0 & 1 & 4 \\\\ 0 & 0 & 0 & 1 \end{bmatrix}
    $$

*   **Matrix-Vector Multiplication:**
    
    $$
    \vec{p}'_h = \mathbf{T}(\vec{t})\vec{p}_h = \begin{bmatrix} 1 & 0 & 0 & 2 \\\\ 0 & 1 & 0 & -1 \\\\ 0 & 0 & 1 & 4 \\\\ 0 & 0 & 0 & 1 \end{bmatrix} \begin{bmatrix} 3 \\\\ -6 \\\\ 9 \\\\ 3 \end{bmatrix} = \begin{bmatrix} 3 + 2(3) \\\\ -6 - 1(3) \\\\ 9 + 4(3) \\\\ 3 \end{bmatrix} = \begin{bmatrix} 9 \\\\ -9 \\\\ 21 \\\\ 3 \end{bmatrix}
    $$

*   **Homogeneous Division to Euclidean Coordinates:**
    
    $$
    \vec{p}'_E = \frac{1}{3}\begin{bmatrix} 9 \\\\ -9 \\\\ 21 \end{bmatrix} = \begin{bmatrix} 3 \\\\ -3 \\\\ 7 \end{bmatrix}
    $$

*   **Verification with Vector Addition:**
    
    $$
    P + \vec{t} = \begin{bmatrix} 1 \\\\ -2 \\\\ 3 \end{bmatrix} + \begin{bmatrix} 2 \\\\ -1 \\\\ 4 \end{bmatrix} = \begin{bmatrix} 3 \\\\ -3 \\\\ 7 \end{bmatrix}
    $$
    
    The results match exactly, showing that 4D homogeneous translation is equivalent to 3D vector addition.

---

## Part 2: Conceptual Understanding

### 1. Scale Invariance and 4D Rays
*   **Scale Invariance**: Under homogeneous coordinates, scaling all components by a non-zero factor $k$ ($[kx, ky, kz, kw]^T$) represents the exact same Euclidean coordinates, since:
    
    $$
    \begin{bmatrix} kx/kw \\\\ ky/kw \\\\ kz/kw \end{bmatrix} = \begin{bmatrix} x/w \\\\ y/w \\\\ z/w \end{bmatrix}
    $$
    
*   **Geometric Ray**: Geometrically, the set of all vectors of the form $k[x, y, z, w]^T$ (for $k \neq 0$) forms a **line (or ray) passing through the origin** in 4D space. Therefore, a single distinct point in 3D Euclidean space corresponds to a 1D ray in 4D projective space.

### 2. Distinguishing Points and Vectors
*   **Point ($w \neq 0$)**: Has a non-zero $w$-coordinate (typically normalized to $w = 1$). Translating a point changes its location in space.
*   **Direction Vector ($w = 0$)**: Has a $w$-coordinate of exactly $0$. Since it has no position (only direction and magnitude), it is unaffected by translation.
*   **Translation Invariance Proof**: Multiplying a translation matrix $\mathbf{T}$ by a direction vector $\vec{d} = [d_x, d_y, d_z, 0]^T$:
    
    $$
    \mathbf{T}\vec{d} = \begin{bmatrix} 1 & 0 & 0 & t_x \\\\ 0 & 1 & 0 & t_y \\\\ 0 & 0 & 1 & t_z \\\\ 0 & 0 & 0 & 1 \end{bmatrix} \begin{bmatrix} d_x \\\\ d_y \\\\ d_z \\\\ 0 \end{bmatrix} = \begin{bmatrix} d_x + t_x(0) \\\\ d_y + t_y(0) \\\\ d_z + t_z(0) \\\\ 0 \end{bmatrix} = \begin{bmatrix} d_x \\\\ d_y \\\\ d_z \\\\ 0 \end{bmatrix} = \vec{d}
    $$
    
    Since the translation terms are multiplied by $0$, the vector remains unchanged.

---
**Back to Question:** [[Q_07_Homogeneous_Coordinates]] | **Related Concepts:** [[07_Homogeneous_Coordinates]]
