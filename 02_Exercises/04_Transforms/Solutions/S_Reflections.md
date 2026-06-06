---
topic: Transforms
tags: [exercise, solution, reflections, plane-reflection, axis-reflection]
---
# Solution: Reflections in 3D Space

This note provides the step-by-step solutions to the exercises in [[Q_Reflections]].

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
[Insert your determinant calculations and geometric orientation explanations here]

### 2. Composition of Reflections
[Insert your algebraic proof of the double-reflection product $\mathbf{M}_{\text{reflect}}^2$ here]

---

**Back to Question:** [[Q_Reflections]] | **Related Concepts:** [[03_Reflections]]
