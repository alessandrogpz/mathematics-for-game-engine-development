---
topic: Vectors
tags: [exercise, solution, projection, orthogonality, linearity, idempotency]
---

# Solution: Properties of Vector Projections

This solution note provides the step-by-step calculations and conceptual proofs for the vector projection properties exercise.

---

## Part 1: Calculation

Let the vector defining our line of projection be:

$$
\vec{u} = \begin{bmatrix} 1 \\\\ 2 \\\\ -1 \end{bmatrix}, \quad \|\vec{u}\|^2 = 1^2 + 2^2 + (-1)^2 = 6
$$

We want to project vectors:

$$
\vec{v} = \begin{bmatrix} 3 \\\\ 0 \\\\ 1 \end{bmatrix} \quad \text{and} \quad \vec{w} = \begin{bmatrix} -1 \\\\ 4 \\\\ 2 \end{bmatrix}
$$

### 1. Individual Projections ($\vec{p}_v = \text{proj}_{\vec{u}}\vec{v}$ and $\vec{p}_w = \text{proj}_{\vec{u}}\vec{w}$)

*   **Projection of $\vec{v}$:**
    
    $$
    \vec{v} \cdot \vec{u} = 3(1) + 0(2) + 1(-1) = 2
    $$
    
    $$
    \vec{p}_v = \text{proj}_{\vec{u}}\vec{v} = \frac{\vec{v} \cdot \vec{u}}{\|\vec{u}\|^2}\vec{u} = \frac{2}{6} \begin{bmatrix} 1 \\\\ 2 \\\\ -1 \end{bmatrix} = \begin{bmatrix} 1/3 \\\\ 2/3 \\\\ -1/3 \end{bmatrix}
    $$

*   **Projection of $\vec{w}$:**
    
    $$
    \vec{w} \cdot \vec{u} = -1(1) + 4(2) + 2(-1) = 5
    $$
    
    $$
    \vec{p}_w = \text{proj}_{\vec{u}}\vec{w} = \frac{\vec{w} \cdot \vec{u}}{\|\vec{u}\|^2}\vec{u} = \frac{5}{6} \begin{bmatrix} 1 \\\\ 2 \\\\ -1 \end{bmatrix} = \begin{bmatrix} 5/6 \\\\ 5/3 \\\\ -5/6 \end{bmatrix}
    $$

### 2. Linearity Verification ($\vec{p}_{v+w} = \vec{p}_v + \vec{p}_w$)

First, calculate the sum of vectors $\vec{v} + \vec{w}$:

$$
\vec{v} + \vec{w} = \begin{bmatrix} 3 \\\\ 0 \\\\ 1 \end{bmatrix} + \begin{bmatrix} -1 \\\\ 4 \\\\ 2 \end{bmatrix} = \begin{bmatrix} 2 \\\\ 4 \\\\ 3 \end{bmatrix}
$$

Next, calculate the projection of the sum:

$$
(\vec{v} + \vec{w}) \cdot \vec{u} = 2(1) + 4(2) + 3(-1) = 7
$$

$$
\vec{p}_{v+w} = \text{proj}_{\vec{u}}(\vec{v} + \vec{w}) = \frac{7}{6}\vec{u} = \begin{bmatrix} 7/6 \\\\ 7/3 \\\\ -7/6 \end{bmatrix}
$$

Now calculate the sum of individual projections:

$$
\vec{p}_v + \vec{p}_w = \begin{bmatrix} 1/3 \\\\ 2/3 \\\\ -1/3 \end{bmatrix} + \begin{bmatrix} 5/6 \\\\ 5/3 \\\\ -5/6 \end{bmatrix} = \begin{bmatrix} 2/6 + 5/6 \\\\ 4/6 + 10/6 \\\\ -2/6 - 5/6 \end{bmatrix} = \begin{bmatrix} 7/6 \\\\ 7/3 \\\\ -7/6 \end{bmatrix}
$$

Since $\vec{p}_{v+w} = \vec{p}_v + \vec{p}_w$, linearity is verified.

### 3. Double Projection / Idempotency ($\text{proj}_{\vec{u}}\vec{p}_v$)

Calculate the projection of $\vec{p}_v$ onto $\vec{u}$:

$$
\vec{p}_v \cdot \vec{u} = \begin{bmatrix} 1/3 \\\\ 2/3 \\\\ -1/3 \end{bmatrix} \cdot \begin{bmatrix} 1 \\\\ 2 \\\\ -1 \end{bmatrix} = \frac{1}{3} + \frac{4}{3} + \frac{1}{3} = 2
$$

$$
\text{proj}_{\vec{u}}\vec{p}_v = \frac{\vec{p}_v \cdot \vec{u}}{\|\vec{u}\|^2}\vec{u} = \frac{2}{6}\vec{u} = \frac{1}{3}\vec{u} = \vec{p}_v
$$

*   **Observation**: The projection of $\vec{p}_v$ onto $\vec{u}$ yields the exact same vector $\vec{p}_v$. Geometrically, this occurs because the vector $\vec{p}_v$ is already collinear (aligned) with the direction of projection vector $\vec{u}$, so projecting it again does not alter its direction or length.

---

## Part 2: Conceptual Understanding & Proofs

### 1. Scaling Invariance

#### Algebraic Proof
Let the projection of a vector $\vec{x}$ onto $\vec{y}$ be defined as:

$$
\text{proj}_{\vec{y}}\vec{x} = \frac{\vec{x} \cdot \vec{y}}{\|\vec{y}\|^2}\vec{y}
$$

If we scale the direction axis vector $\vec{y}$ by any non-zero scalar $c \in \mathbb{R}$ ($c \neq 0$):

$$
\text{proj}_{c\vec{y}}\vec{x} = \frac{\vec{x} \cdot (c\vec{y})}{\|c\vec{y}\|^2}(c\vec{y}) = \frac{c(\vec{x} \cdot \vec{y})}{c^2 \|\vec{y}\|^2}(c\vec{y}) = \frac{c^2(\vec{x} \cdot \vec{y})}{c^2 \|\vec{y}\|^2}\vec{y} = \frac{\vec{x} \cdot \vec{y}}{\|\vec{y}\|^2}\vec{y} = \text{proj}_{\vec{y}}\vec{x}
$$

#### Concrete Verification Example
Let $\vec{x} = [3, 0, 1]^T$, $\vec{y} = [2, 2, 1]^T$ and let scalar $c=2$, so $c\vec{y} = [4, 4, 2]^T$:
*   **Projection onto $\vec{y}$:**
    
    $$
    \text{proj}_{\vec{y}}\vec{x} = \frac{3(2) + 0(2) + 1(1)}{2^2 + 2^2 + 1^2}\vec{y} = \frac{7}{9}\begin{bmatrix} 2 \\\\ 2 \\\\ 1 \end{bmatrix} = \begin{bmatrix} 14/9 \\\\ 14/9 \\\\ 7/9 \end{bmatrix}
    $$
    
*   **Projection onto $2\vec{y}$:**
    
    $$
    \text{proj}_{2\vec{y}}\vec{x} = \frac{3(4) + 0(4) + 1(2)}{4^2 + 4^2 + 2^2}(2\vec{y}) = \frac{14}{36}\begin{bmatrix} 4 \\\\ 4 \\\\ 2 \end{bmatrix} = \frac{7}{18}\begin{bmatrix} 4 \\\\ 4 \\\\ 2 \end{bmatrix} = \begin{bmatrix} 14/9 \\\\ 14/9 \\\\ 7/9 \end{bmatrix}
    $$

#### Geometric Intuition
The vector $\vec{y}$ defines a line of projection. Scaling $\vec{y}$ by a non-zero scalar changes its length (and flips its direction if $c < 0$), but it **does not alter the line itself**. Since the line of projection is invariant, the shadow (projection) cast onto it remains identical.

### 2. Orthogonal Decomposition Proof

Let $\vec{e} = \vec{v} - \text{proj}_{\vec{u}}\vec{v}$. We show $\vec{e} \cdot \vec{u} = 0$:

$$
\vec{e} \cdot \vec{u} = \left(\vec{v} - \text{proj}_{\vec{u}}\vec{v}\right) \cdot \vec{u} = \vec{v} \cdot \vec{u} - \left(\text{proj}_{\vec{u}}\vec{v}\right) \cdot \vec{u}
$$

Substitute the projection formula:

$$
\vec{e} \cdot \vec{u} = \vec{v} \cdot \vec{u} - \left(\frac{\vec{v} \cdot \vec{u}}{\|\vec{u}\|^2}\vec{u}\right) \cdot \vec{u} = \vec{v} \cdot \vec{u} - \frac{\vec{v} \cdot \vec{u}}{\|\vec{u}\|^2}(\vec{u} \cdot \vec{u})
$$

Since $\vec{u} \cdot \vec{u} = \|\vec{u}\|^2$:

$$
\vec{e} \cdot \vec{u} = \vec{v} \cdot \vec{u} - \frac{\vec{v} \cdot \vec{u}}{\|\vec{u}\|^2}\|\vec{u}\|^2 = \vec{v} \cdot \vec{u} - \vec{v} \cdot \vec{u} = 0
$$

This proves the orthogonality of the error vector $\vec{e}$.

#### Importance in Vector Approximation & Regression
This property (known as the **Orthogonal Projection Theorem**) ensures that the vector projection $\text{proj}_{\vec{u}}\vec{v}$ is the **closest possible point** on the line spanned by $\vec{u}$ to the vector $\vec{v}$. Any other point would form a right triangle where the distance to $\vec{v}$ would be the hypotenuse, which is strictly longer. This is the foundation of Least Squares approximation and linear regression.

### 3. Idempotency Proof

Let $P(\vec{x}) = \frac{\vec{x} \cdot \vec{u}}{\|\vec{u}\|^2}\vec{u}$. We calculate $P(P(\vec{x}))$:

$$
P(P(\vec{x})) = P\left(\frac{\vec{x} \cdot \vec{u}}{\|\vec{u}\|^2}\vec{u}\right) = \frac{\left(\frac{\vec{x} \cdot \vec{u}}{\|\vec{u}\|^2}\vec{u}\right) \cdot \vec{u}}{\|\vec{u}\|^2}\vec{u}
$$

Factor out the scalar terms:

$$
P(P(\vec{x})) = \frac{\vec{x} \cdot \vec{u}}{\|\vec{u}\|^2} \cdot \frac{\vec{u} \cdot \vec{u}}{\|\vec{u}\|^2}\vec{u}
$$

Substitute $\vec{u} \cdot \vec{u} = \|\vec{u}\|^2$:

$$
P(P(\vec{x})) = \frac{\vec{x} \cdot \vec{u}}{\|\vec{u}\|^2} \cdot \frac{\|\vec{u}\|^2}{\|\vec{u}\|^2}\vec{u} = \frac{\vec{x} \cdot \vec{u}}{\|\vec{u}\|^2}\vec{u} = P(\vec{x})
$$

This completes the algebraic proof of idempotency ($P^2 = P$).

---
**Back to Question:** [[Q_06_Projection_Properties]] | **Related Concepts:** [[06_Vector_Projection]]