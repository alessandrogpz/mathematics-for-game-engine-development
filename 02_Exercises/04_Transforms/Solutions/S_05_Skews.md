---
topic: Transforms
tags: [exercise, solution, skew, shear, linear-transformation]
---

# Solution: Skew (Shear) in 3D Space

This solution note is scaffolded to record your step-by-step derivations for the skew exercises in [[Q_05_Skews]].

---

## Part 1: Calculation

### 1. Skew Matrix Construction
We construct the $3 \times 3$ skew matrix $\mathbf{M}_{\text{skew}}(\theta, \vec{a}, \vec{b})$ using:

$$
\vec{a} = \begin{bmatrix} 1 \\\\ 0 \\\\ 0 \end{bmatrix}, \quad \vec{b} = \begin{bmatrix} 0 \\\\ 1 \\\\ 0 \end{bmatrix}, \quad \theta = 45^\circ
$$

Using the outer-product formulation:

$$
\mathbf{M}_{\text{skew}}(\theta, \vec{a}, \vec{b}) = \mathbf{I} + \tan\theta \, \vec{a}\vec{b}^T
$$

First, calculate the outer product $\vec{a}\vec{b}^T$:

$$
\vec{a}\vec{b}^T = \begin{bmatrix} a_x \\\\ a_y \\\\ a_z \end{bmatrix} \begin{bmatrix} b_x & b_y & b_z \end{bmatrix} = \begin{bmatrix} a_x b_x & a_x b_y & a_x b_z \\\\ a_y b_x & a_y b_y & a_y b_z \\\\ a_z b_x & a_z b_y & a_z b_z \end{bmatrix}
$$

This gives the general skew matrix form:

$$
\mathbf{M}_{\text{skew}}(\theta, \vec{a}, \vec{b}) = \begin{bmatrix} 1 + a_x b_x \tan\theta & a_x b_y \tan\theta & a_x b_z \tan\theta \\\\ a_y b_x \tan\theta & 1 + a_y b_y \tan\theta & a_y b_z \tan\theta \\\\ a_z b_x \tan\theta & a_z b_y \tan\theta & 1 + a_z b_z \tan\theta \end{bmatrix}
$$

For our given values, we have $\tan(45^\circ) = 1$. Substituting $\vec{a}$ and $\vec{b}$:

$$
\mathbf{M}_{\text{skew}}(45^\circ, \vec{a}, \vec{b}) = \begin{bmatrix} 1 + (1)(0)(1) & (1)(1)(1) & (1)(0)(1) \\\\ (0)(0)(1) & 1 + (0)(1)(1) & (0)(0)(1) \\\\ (0)(0)(1) & (0)(1)(1) & 1 + (0)(0)(1) \end{bmatrix} = \begin{bmatrix} 1 & 1 & 0 \\\\ 0 & 1 & 0 \\\\ 0 & 0 & 1 \end{bmatrix}
$$

#### Derivation of the Outer Product Formula (How to arrive at $\mathbf{I} + \tan\theta \, \vec{a}\vec{b}^T$)
From the geometry of a skew transformation:
*   The transformed vector is $\vec{v}' = \vec{v} + \text{displacement vector}$.
*   The height of the vector relative to the measurement axis $\vec{b}$ is its projection: $\vec{v}_{\parallel \vec{b}} = \text{Comp}_{\vec{b}} \vec{v} = (\vec{b} \cdot \vec{v})$.
*   The displacement is along the direction $\vec{a}$, proportional to the height and the skew factor $K = \tan\theta$:
    
$$
\text{displacement} = (\vec{b} \cdot \vec{v})\tan\theta \, \vec{a}
$$
    
*   Therefore:
    
$$
\vec{v}' = \vec{v} + (\vec{b} \cdot \vec{v})\tan\theta \, \vec{a}
$$
    
*   Using the algebraic identity $(\vec{b} \cdot \vec{v})\vec{a} = \vec{a}(\vec{b}^T \vec{v}) = (\vec{a}\vec{b}^T)\vec{v}$, we get:
    
$$
\vec{v}' = \vec{v} + (\vec{a}\vec{b}^T)\vec{v}\tan\theta = (\mathbf{I} + \tan\theta \, \vec{a}\vec{b}^T)\vec{v}
$$
    
    
$$
\mathbf{M}_{\text{skew}}(\theta, \vec{a}, \vec{b}) = \mathbf{I} + \tan\theta \, \vec{a}\vec{b}^T
$$

### 2. Transform a Vector
To calculate the transformed vector $\vec{v}'$ for the input vector $\vec{v} = [2, 3, 5]^T$:

$$
\vec{v}' = \mathbf{M}_{\text{skew}}(45^\circ, \vec{a}, \vec{b})\vec{v} = \begin{bmatrix} 1 & 1 & 0 \\\\ 0 & 1 & 0 \\\\ 0 & 0 & 1 \end{bmatrix} \begin{bmatrix} 2 \\\\ 3 \\\\ 5 \end{bmatrix} = \begin{bmatrix} 2 + 3 \\\\ 3 \\\\ 5 \end{bmatrix} = \begin{bmatrix} 5 \\\\ 3 \\\\ 5 \end{bmatrix}
$$

### 3. Geometric Verification
To geometrically verify the result using the vector equation:

$$
\vec{v}' = \vec{v} + (\vec{b} \cdot \vec{v})\tan\theta \, \vec{a}
$$

1. **Calculate the Dot Product (Projection Height):**
   
$$
\vec{b} \cdot \vec{v} = \begin{bmatrix} 0 \\\\ 1 \\\\ 0 \end{bmatrix} \cdot \begin{bmatrix} 2 \\\\ 3 \\\\ 5 \end{bmatrix} = (0)(2) + (1)(3) + (0)(5) = 3
$$

2. **Evaluate the Equation:**
   Substitute the components ($\vec{b} \cdot \vec{v} = 3$, $\tan(45^\circ) = 1$, and $\vec{a} = [1, 0, 0]^T$):
   
$$
\vec{v}' = \begin{bmatrix} 2 \\\\ 3 \\\\ 5 \end{bmatrix} + (3)(1)\begin{bmatrix} 1 \\\\ 0 \\\\ 0 \end{bmatrix} = \begin{bmatrix} 2 \\\\ 3 \\\\ 5 \end{bmatrix} + \begin{bmatrix} 3 \\\\ 0 \\\\ 0 \end{bmatrix} = \begin{bmatrix} 5 \\\\ 3 \\\\ 5 \end{bmatrix}
$$

Both the matrix multiplication result and the geometric formula yield the identical result:

$$
\vec{v}' = \begin{bmatrix} 5 \\\\ 3 \\\\ 5 \end{bmatrix}
$$

---

## Part 2: Conceptual Understanding

### 1. Determinant of Skew
Geometrically, a skew (shear) transformation is a volume-preserving operation (Cavalieri's Principle). 

In 3D space, the determinant of a matrix represents the volume scaling factor of any transformed object. A skew transformation shifts parallel layers of an object (like sliding a deck of cards) without changing the area of any cross-section or the perpendicular height between them. Since both the base area and the height remain constant, the volume of any 3D object is unchanged, and its orientation is preserved. Therefore, the volume scaling factor is exactly $1$, which means:

$$
\det(\mathbf{M}_{\text{skew}}) = 1
$$

### 2. Composition of Opposite Skews
To prove that performing a skew of angle $\theta$ followed by a skew of angle $-\theta$ (along the same vectors $\vec{a}$ and $\vec{b}$) yields the Identity matrix:

Let the two matrices be:

$$
\mathbf{M}_{\text{skew}}(\theta) = \mathbf{I} + \tan\theta \, \vec{a}\vec{b}^T
$$


$$
\mathbf{M}_{\text{skew}}(-\theta) = \mathbf{I} + \tan(-\theta) \, \vec{a}\vec{b}^T = \mathbf{I} - \tan\theta \, \vec{a}\vec{b}^T
$$

Multiplying them:

$$
\mathbf{M}_{\text{skew}}(\theta) \mathbf{M}_{\text{skew}}(-\theta) = (\mathbf{I} + \tan\theta \, \vec{a}\vec{b}^T)(\mathbf{I} - \tan\theta \, \vec{a}\vec{b}^T)
$$


$$
= \mathbf{I} - \tan\theta \, \vec{a}\vec{b}^T + \tan\theta \, \vec{a}\vec{b}^T - \tan^2\theta \, (\vec{a}\vec{b}^T)(\vec{a}\vec{b}^T)
$$


$$
= \mathbf{I} - \tan^2\theta \, \vec{a}(\vec{b}^T\vec{a})\vec{b}^T
$$

Since the slide direction $\vec{a}$ and the measurement axis $\vec{b}$ are perpendicular, their dot product is zero ($\vec{b}^T\vec{a} = \vec{b} \cdot \vec{a} = 0$). Substituting this in:

$$
\mathbf{M}_{\text{skew}}(\theta) \mathbf{M}_{\text{skew}}(-\theta) = \mathbf{I} - \tan^2\theta \, \vec{a}(0)\vec{b}^T = \mathbf{I}
$$

#### Concrete Example
Using the specific vectors from Part 1 ($\vec{a} = [1, 0, 0]^T$, $\vec{b} = [0, 1, 0]^T$):

$$
\mathbf{M}_{\text{skew}}(\theta) = \begin{bmatrix} 1 & \tan\theta & 0 \\\\ 0 & 1 & 0 \\\\ 0 & 0 & 1 \end{bmatrix}, \quad \mathbf{M}_{\text{skew}}(-\theta) = \begin{bmatrix} 1 & -\tan\theta & 0 \\\\ 0 & 1 & 0 \\\\ 0 & 0 & 1 \end{bmatrix}
$$


$$
\mathbf{M}_{\text{skew}}(\theta)\mathbf{M}_{\text{skew}}(-\theta) = \begin{bmatrix} 1 & -\tan\theta + \tan\theta & 0 \\\\ 0 & 1 & 0 \\\\ 0 & 0 & 1 \end{bmatrix} = \begin{bmatrix} 1 & 0 & 0 \\\\ 0 & 1 & 0 \\\\ 0 & 0 & 1 \end{bmatrix} = \mathbf{I}
$$

### 3. Orthogonality Constraint
It is mathematically and geometrically required that the slide direction $\vec{a}$ and the measurement axis $\vec{b}$ are perpendicular ($\vec{a} \cdot \vec{b} = 0$).

#### Geometrical Reason
A skew slides points parallel to the direction vector $\vec{a}$ by an amount proportional to their perpendicular distance from the measurement axis $\vec{b}$. If $\vec{a}$ and $\vec{b}$ were not perpendicular:
* Shifting points along $\vec{a}$ would also change their coordinate along the measurement axis $\vec{b}$.
* This would change their "height" relative to the axis *during* the transformation itself, resulting in a scaling (stretching/compression) effect rather than a pure parallel shear.
* If they were parallel ($\vec{a} = \vec{b}$), any shift along the slide direction would exponentially increase the distance from the plane, causing points to fly off to infinity or collapse.

#### Mathematical Reason
1. **Volume Preservation:**
   Mathematically, the determinant of a general matrix of the form $\mathbf{I} + \mathbf{u}\mathbf{v}^T$ is given by $1 + \mathbf{u} \cdot \mathbf{v}$. For our skew matrix:
   
$$
\det(\mathbf{I} + \tan\theta \, \vec{a}\vec{b}^T) = 1 + \tan\theta \, (\vec{a} \cdot \vec{b})
$$
   
   If $\vec{a} \cdot \vec{b} \neq 0$, the determinant is no longer $1$, meaning the transformation scales the volume of the space and is no longer a pure shear.
2. **Opposite Skew Inversion:**
   As shown in the algebraic proof above, the product of opposite skews is:
   
$$
\mathbf{M}_{\text{skew}}(\theta) \mathbf{M}_{\text{skew}}(-\theta) = \mathbf{I} - \tan^2\theta \, (\vec{a} \cdot \vec{b}) \, \vec{a}\vec{b}^T
$$
   
   If $\vec{a} \cdot \vec{b} \neq 0$, this does not simplify to the Identity matrix $\mathbf{I}$, meaning a skew of angle $-\theta$ would no longer act as the inverse operation.
3. **Parallel Limit:**
   If $\vec{a}$ and $\vec{b}$ are parallel (meaning $\vec{a} \cdot \vec{b} = 1$), the matrix becomes $\mathbf{I} + \tan\theta \, \vec{a}\vec{a}^T$, which is a scaling matrix along the axis of $\vec{a}$, rather than a shear matrix.

---

**Back to Question:** [[Q_05_Skews]] | **Related Concepts:** [[05_Skews]]
