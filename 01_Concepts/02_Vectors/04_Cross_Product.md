# Cross Product

The cross product of two 3D vectors is another 3D vector that is perpendicular (orthogonal) to both original vectors.

## Conceptual Understanding: "Perpendicular Generator"
Unlike the dot product which gives a number, the cross product gives a **new vector**.
- **Direction:** The result is always perpendicular to the "floor" or plane created by the two input vectors.
- **Magnitude:** The length of the resulting vector represents the **area** of the parallelogram formed by the two vectors.
- **Zero Result:** If the cross product is zero, the vectors are parallel (they don't form a plane).

## Definitions

### Algebraic Definition

$$
\vec{a} \times \vec{b} = (a_2b_3 - a_3b_2, a_3b_1 - a_1b_3, a_1b_2 - a_2b_1)
$$

### Geometric Definition

$$
\|\vec{a} \times \vec{b}\| = \|\vec{a}\| \|\vec{b}\| \sin(\theta)
$$

### Geometric Interpretation: Areas of Parallelograms and Triangles
The magnitude of the cross product $\|\vec{a} \times \vec{b}\|$ has a direct geometric interpretation:

1. **Area of a Parallelogram:**
   The magnitude of the cross product is exactly equal to the area of the parallelogram spanned by vectors $\vec{a}$ and $\vec{b}$:
   
   $$
   \text{Area}_{\text{parallelogram}} = \|\vec{a} \times \vec{b}\| = \|\vec{a}\| \|\vec{b}\| \sin(\theta)
   $$
   
   *Here, $\|\vec{b}\| \sin(\theta)$ represents the perpendicular height $h$ of the parallelogram, and $\|\vec{a}\|$ is the base length.*

2. **Area of a Triangle:**
   Since a triangle formed by the vectors $\vec{a}$ and $\vec{b}$ is exactly half of the parallelogram formed by those same vectors, the area of the triangle is:
   
   $$
   \text{Area}_{\text{triangle}} = \frac{1}{2} \|\vec{a} \times \vec{b}\|
   $$

## Key Properties
| Property | Formula / Description |
| :--- | :--- |
| **Anticommutative** | $\vec{a} \times \vec{b} = -(\vec{b} \times \vec{a})$ (Reversing order flips the vector) |
| **Distributive** | $\vec{a} \times (\vec{b} + \vec{c}) = \vec{a} \times \vec{b} + \vec{a} \times \vec{c}$ |
| **Vector Triple Product** | $\vec{a} \times (\vec{b} \times \vec{c}) = \vec{b}(\vec{a} \cdot \vec{c}) - \vec{c}(\vec{a} \cdot \vec{b})$ |

## Visualizing the Result (Right-Hand Rule)
Using your **right hand**, orient your fingers to find the direction of $\vec{a} \times \vec{b}$:
*   **Thumb:** Point in the direction of the first vector $\vec{a}$.
*   **Index Finger:** Point in the direction of the second vector $\vec{b}$.
*   **Middle Finger:** Points perpendicular to your palm, indicating the direction of the cross product vector $\vec{a} \times \vec{b}$.

*(For more details, see [[03_Coordinate_Systems|Coordinate Systems]]).*

## Matrix Representation of Cross Product (Skew-Symmetric Matrix)

A cross product of a fixed vector $\vec{a}$ with another vector $\vec{v}$ is a linear operation. Therefore, it can be represented as a matrix-vector multiplication using a **skew-symmetric matrix** (often denoted as $[\vec{a}]_\times$):

$$
\vec{a} \times \vec{v} = [\vec{a}]_\times \vec{v}
$$

### Proof of Equivalency

#### 1. The Standard Cross Product
Let's define two column vectors:

$$
\vec{a} = \begin{bmatrix} a_x \\\\ a_y \\\\ a_z \end{bmatrix} , \quad \vec{v} = \begin{bmatrix} v_x \\\\ v_y \\\\ v_z \end{bmatrix}
$$

Using standard linear algebra, the algebraic expansion of the cross product $\vec{a} \times \vec{v}$ yields the vector:

$$
\vec{a} \times \vec{v} = \begin{bmatrix} a_y v_z - a_z v_y \\\\ a_z v_x - a_x v_z \\\\ a_x v_y - a_y v_x \end{bmatrix}
$$

#### 2. The Matrix Multiplication Equivalency
Now, let's construct the cross-product matrix $[\vec{a}]_\times$ and multiply it by the column vector $\vec{v}$ using standard row-by-column multiplication:

$$
[\vec{a}]_\times \vec{v} = \begin{bmatrix} 0 & -a_z & a_y \\\\ a_z & 0 & -a_x \\\\ -a_y & a_x & 0 \end{bmatrix} \begin{bmatrix} v_x \\\\ v_y \\\\ v_z \end{bmatrix}
$$

Performing the row-by-column multiplication:

$$
[\vec{a}]_\times \vec{v} = \begin{bmatrix} (0 \cdot v_x) + (-a_z \cdot v_y) + (a_y \cdot v_z) \\\\ (a_z \cdot v_x) + (0 \cdot v_y) + (-a_x \cdot v_z) \\\\ (-a_y \cdot v_x) + (a_x \cdot v_y) + (0 \cdot v_z) \end{bmatrix} = \begin{bmatrix} a_y v_z - a_z v_y \\\\ a_z v_x - a_x v_z \\\\ a_x v_y - a_y v_x \end{bmatrix}
$$

This matches the algebraic cross-product equation $\vec{a} \times \vec{v}$ exactly, proving that matrix multiplication by $[\vec{a}]_\times$ is completely equivalent to performing the cross product.

### Why It's Useful
In graphics programming, game engines, and physics engines, representing the cross product as a matrix multiplication is extremely powerful:
* **Linearizing Operations:** It converts the vector-based cross-product operation into a standard $3 \times 3$ matrix multiplication.
* **Combining Transformations:** Because it is a matrix, it can be combined with rotation, scale, or projection matrices using simple matrix multiplication.
* **Rodrigues' Rotation Formula:** As used in 3D rotations, this skew-symmetric matrix represents the circular rotation step about an arbitrary axis $\vec{a}$ (in the term $[\vec{a}]_\times \sin\theta$).

---

## Code Implementation

*   **C++ Source Code:** [[03_Code/02_Vectors/Cross_Product.cppm|Cross_Product.cppm]]
