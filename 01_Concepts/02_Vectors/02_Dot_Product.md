# Dot Product

The dot product (also known as the scalar product) is an operation that takes two vectors and returns a scalar.

## Conceptual Understanding: "Measure of Alignment"
Think of the dot product as a measure of how much one vector "points" in the direction of another.
- **High Positive Value:** The vectors are pointing in roughly the same direction.
- **Zero:** The vectors are perfectly perpendicular (orthogonal).
- **High Negative Value:** The vectors are pointing in roughly opposite directions.

## Definitions
| Type | Formula |
| :--- | :--- |
| **Algebraic** | $\vec{a} \cdot \vec{b} = \sum a_i b_i = a_1b_1 + a_2b_2 + \dots$ |
| **Geometric** | $\vec{a} \cdot \vec{b} = \|\vec{a}\| \|\vec{b}\| \cos(\theta)$ |

## Common Applications
- **Checking Orthogonality:** The most common use is to check if two vectors are perpendicular (result = 0).
- **Finding Angles:** Rearranging the geometric formula allows us to find the angle between any two vectors: $\theta = \arccos\left(\frac{\vec{a} \cdot \vec{b}}{\|\vec{a}\|\|\vec{b}\|}\right)$.
- **Calculating Work (Physics):** Work is the dot product of the Force vector and the Displacement vector ($W = \vec{F} \cdot \vec{d}$).
- **Brightness/Lighting (Graphics):** In computer graphics, the dot product between a light direction and a surface normal determines how bright a surface appears.

## Key Properties
| Property | Formula |
| :--- | :--- |
| **Commutative** | $\vec{a} \cdot \vec{b} = \vec{b} \cdot \vec{a}$ |
| **Distributive** | $\vec{a} \cdot (\vec{b} + \vec{c}) = \vec{a} \cdot \vec{b} + \vec{a} \cdot \vec{c}$ |
| **Scalar Factorization** | $\vec{a} \cdot (s\vec{b}) = s(\vec{a} \cdot \vec{b})$ |
