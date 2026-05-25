---
topic: Vectors
tags: [exercise, solution, dot-product, angle, orthogonality]
---
# Solution: Angle and Dot Product

---

## Part 1: Calculation

We are given two vectors:
$$\vec{a} = \begin{bmatrix} 2 \\ -1 \\ 2 \end{bmatrix} \quad \text{and} \quad \vec{b} = \begin{bmatrix} 1 \\ 1 \\ 0 \end{bmatrix}$$

### 1. Calculate the dot product $\vec{a} \cdot \vec{b}$
Using the algebraic definition of the dot product:
$$\vec{a} \cdot \vec{b} = \sum_{i=1}^3 a_i b_i = (2)(1) + (-1)(1) + (2)(0) = 2 - 1 + 0 = 1$$
Thus, $\vec{a} \cdot \vec{b} = 1$.

---

### 2. Calculate the magnitudes $\|\vec{a}\|$ and $\|\vec{b}\|$
Using the vector magnitude formula $\|\vec{v}\| = \sqrt{\sum_{i=1}^n v_i^2}$:

*   **For Vector $\vec{a}$:**
    $$\|\vec{a}\| = \sqrt{2^2 + (-1)^2 + 2^2} = \sqrt{4 + 1 + 4} = \sqrt{9} = 3$$
*   **For Vector $\vec{b}$:**
    $$\|\vec{b}\| = \sqrt{1^2 + 1^2 + 0^2} = \sqrt{1 + 1 + 0} = \sqrt{2}$$

---

### 3. Find the angle $\theta$ between $\vec{a}$ and $\vec{b}$
We use the geometric definition of the dot product:
$$\vec{a} \cdot \vec{b} = \|\vec{a}\| \|\vec{b}\| \cos\theta$$

Substitute our calculated values into the formula:
$$1 = 3\sqrt{2} \cos\theta$$
$$\cos\theta = \frac{1}{3\sqrt{2}} = \frac{\sqrt{2}}{6}$$
$$\theta = \cos^{-1}\left(\frac{\sqrt{2}}{6}\right) \approx 76.37^\circ$$

The angle between the vectors is approximately **$76.37^\circ$** (or $1.33$ radians).

---

## Part 2: Conceptual Understanding

### 1. Dot Product Sign and Angle Relationships
**Question:** Without calculating, what does the sign of $\vec{a} \cdot \vec{b}$ tell you about the angle $\theta$ (is it acute, obtuse, or right)?

**Answer:**
The sign of the dot product $\vec{a} \cdot \vec{b}$ indicates the geometric alignment between the two vectors:
1.  **Positive ($\vec{a} \cdot \vec{b} > 0$):** The angle $\theta$ between the vectors is **acute** ($0^\circ \le \theta < 90^\circ$). Geometrically, this means they point in the same general direction.
2.  **Zero ($\vec{a} \cdot \vec{b} = 0$):** The angle $\theta$ is exactly a **right angle** ($\theta = 90^\circ$). The vectors are **orthogonal** (perpendicular) to each other.
3.  **Negative ($\vec{a} \cdot \vec{b} < 0$):** The angle $\theta$ between the vectors is **obtuse** ($90^\circ < \theta \le 180^\circ$). Geometrically, this means they point in opposite general directions.

---

### 2. Orthogonality Condition
**Question:** If we replaced $\vec{b}$ with a vector $\vec{c}$ such that $\vec{a} \cdot \vec{c} = 0$, what is the geometric relationship between $\vec{a}$ and $\vec{c}$?

**Answer:**
If $\vec{a} \cdot \vec{c} = 0$, the geometric relationship is that **$\vec{a}$ and $\vec{c}$ are orthogonal (perpendicular)** to each other, forming a right angle ($\theta = 90^\circ$).

---

### 3. Relation to Projection
**Question:** How does the dot product relate to the concept of "projection"?

**Answer:**
The scalar projection of vector $\vec{a}$ onto vector $\vec{b}$ (often denoted as $\text{comp}_{\vec{b}}\vec{a}$) represents the length of the shadow cast by $\vec{a}$ onto $\vec{b}$:
$$\text{comp}_{\vec{b}}\vec{a} = \|\vec{a}\|\cos\theta$$

Comparing this with the geometric definition of the dot product:
$$\vec{a} \cdot \vec{b} = \|\vec{a}\| \|\vec{b}\| \cos\theta$$

We can rewrite the dot product as:
$$\vec{a} \cdot \vec{b} = \text{comp}_{\vec{b}}\vec{a} \cdot \|\vec{b}\|$$

**Geometric Interpretation:** The dot product is the scalar projection of $\vec{a}$ onto $\vec{b}$, scaled by the magnitude of $\vec{b}$. If $\vec{b}$ is a unit vector ($\|\vec{b}\| = 1$), the dot product is exactly equal to the scalar projection of $\vec{a}$ onto $\vec{b}$.

---
## Code Implementation
```cpp
// Optional C++ snippet here
```


---

**Back to Question:** [[Q_Angle_Dot_Product]] | **Related Concepts:** [[02_Dot_Product]]