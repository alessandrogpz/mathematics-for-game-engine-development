---
topic: Vectors
tags: [exercise, solution, projection, orthogonality]
---

# Solution: Projection Orthogonality

This solution note details the step-by-step calculations and conceptual answers for the projection orthogonality exercise.

---

## Part 1: Calculation

We are given the vectors:

$$
\vec{a} = \begin{bmatrix} 3 \\\\ -1 \\\\ 2 \end{bmatrix} \quad \text{and} \quad \vec{b} = \begin{bmatrix} 1 \\\\ 2 \\\\ 2 \end{bmatrix}
$$

### 1. Scalar Projection of $\vec{a}$ onto $\vec{b}$ ($\text{comp}_{\vec{b}}\vec{a}$)

The scalar projection is computed as:

$$
\text{comp}_{\vec{b}}\vec{a} = \frac{\vec{a} \cdot \vec{b}}{\|\vec{b}\|}
$$

First, find the dot product $\vec{a} \cdot \vec{b}$:

$$
\vec{a} \cdot \vec{b} = (3)(1) + (-1)(2) + (2)(2) = 3 - 2 + 4 = 5
$$

Next, find the magnitude of $\vec{b}$:

$$
\|\vec{b}\| = \sqrt{1^2 + 2^2 + 2^2} = \sqrt{1 + 4 + 4} = \sqrt{9} = 3
$$

Thus, the scalar projection is:

$$
\text{comp}_{\vec{b}}\vec{a} = \frac{5}{3} \approx 1.667
$$

### 2. Vector Projection of $\vec{a}$ onto $\vec{b}$ ($\text{proj}_{\vec{b}}\vec{a}$)

The vector projection is computed by multiplying the scalar projection by the unit vector of $\vec{b}$:

$$
\text{proj}_{\vec{b}}\vec{a} = \left(\text{comp}_{\vec{b}}\vec{a}\right) \frac{\vec{b}}{\|\vec{b}\|} = \frac{\vec{a} \cdot \vec{b}}{\|\vec{b}\|^2}\vec{b}
$$

$$
\text{proj}_{\vec{b}}\vec{a} = \frac{5}{9} \begin{bmatrix} 1 \\\\ 2 \\\\ 2 \end{bmatrix} = \begin{bmatrix} 5/9 \\\\ 10/9 \\\\ 10/9 \end{bmatrix}
$$

### 3. Find Vector $\vec{c} = \vec{a} - \text{proj}_{\vec{b}}\vec{a}$

Subtract the projection vector from the original vector $\vec{a}$:

$$
\vec{c} = \begin{bmatrix} 3 \\\\ -1 \\\\ 2 \end{bmatrix} - \begin{bmatrix} 5/9 \\\\ 10/9 \\\\ 10/9 \end{bmatrix} = \begin{bmatrix} 27/9 \\\\ -9/9 \\\\ 18/9 \end{bmatrix} - \begin{bmatrix} 5/9 \\\\ 10/9 \\\\ 10/9 \end{bmatrix} = \begin{bmatrix} 22/9 \\\\ -19/9 \\\\ 8/9 \end{bmatrix}
$$

Thus, vector $\vec{c}$ is:

$$
\vec{c} = \begin{bmatrix} 22/9 \\\\ -19/9 \\\\ 8/9 \end{bmatrix} \approx \begin{bmatrix} 2.444 \\\\ -2.111 \\\\ 0.889 \end{bmatrix}
$$

---

## Part 2: Conceptual Understanding

### 1. Mathematical Proof of Orthogonality

To show that $\vec{c}$ is orthogonal to $\vec{b}$, we compute their dot product and verify that it equals zero:

$$
\vec{c} \cdot \vec{b} = \begin{bmatrix} 22/9 \\\\ -19/9 \\\\ 8/9 \end{bmatrix} \cdot \begin{bmatrix} 1 \\\\ 2 \\\\ 2 \end{bmatrix} = \left(\frac{22}{9}\right)(1) + \left(-\frac{19}{9}\right)(2) + \left(\frac{8}{9}\right)(2)
$$

$$
\vec{c} \cdot \vec{b} = \frac{22}{9} - \frac{38}{9} + \frac{16}{9} = \frac{22 - 38 + 16}{9} = \frac{0}{9} = 0
$$

Since $\vec{c} \cdot \vec{b} = 0$, the vector $\vec{c}$ is mathematically orthogonal to $\vec{b}$.

Additionally, we can confirm the decomposition holds because the sum of the projection and rejection vectors returns the original vector $\vec{a}$:

$$
\text{proj}_{\vec{b}}\vec{a} + \vec{c} = \begin{bmatrix} 5/9 \\\\ 10/9 \\\\ 10/9 \end{bmatrix} + \begin{bmatrix} 22/9 \\\\ -19/9 \\\\ 8/9 \end{bmatrix} = \begin{bmatrix} 27/9 \\\\ -9/9 \\\\ 18/9 \end{bmatrix} = \begin{bmatrix} 3 \\\\ -1 \\\\ 2 \end{bmatrix} = \vec{a}
$$

### 2. Geometric Interpretation
The vector $\vec{c}$ is the **vector rejection** of $\vec{a}$ onto $\vec{b}$ (often denoted as $\text{rej}_{\vec{b}}\vec{a}$). 
*   Geometrically, it represents the component of the vector $\vec{a}$ that is **orthogonal (perpendicular)** to the direction of $\vec{b}$. Together, the projection ($\text{proj}_{\vec{b}}\vec{a}$) and the rejection ($\vec{c}$) decompose $\vec{a}$ into two perpendicular vectors that sum to $\vec{a}$.

### 3. Negative Dot Product ($\vec{a} \cdot \vec{b} < 0$)
If the dot product is negative, the angle $\theta$ between vectors $\vec{a}$ and $\vec{b}$ is obtuse ($90^\circ < \theta \le 180^\circ$).
*   This implies that the "shadow" or projection vector will point in the **exact opposite direction** (turned $180^\circ$) relative to the vector $\vec{b}$ (i.e. along the direction of $-\vec{b}$).

---
**Back to Question:** [[Q_06_Projection_Orthogonality]] **Related Concepts:** [[06_Vector_Projection]], [[02_Dot_Product]]