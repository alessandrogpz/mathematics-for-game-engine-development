# Scalar Triple Product

The scalar triple product involves three vectors $\vec{a}$, $\vec{b}$, and $\vec{c}$, yielding a single scalar value.

## Conceptual Understanding: "3D Volume Measure"
Think of the scalar triple product as the 3D version of the cross-product's area.
- **What it calculates:** It finds the volume of the 3D "tilted box" (parallelepiped) formed by the three vectors.
- **The Logic:** You first find the area of the base (cross product $\vec{a} \times \vec{b}$) and then multiply it by the "height" using the dot product with $\vec{c}$.
- **Coplanarity:** If the result is **zero**, it means all three vectors lie in the same 2D plane (the box has no height).

## Formula

$$
[\vec{a}, \vec{b}, \vec{c}] = (\vec{a} \times \vec{b}) \cdot \vec{c}
$$

## Properties
| Property | Formula / Description |
| :--- | :--- |
| **Cyclic Order** | $(\vec{a} \times \vec{b}) \cdot \vec{c} = (\vec{b} \times \vec{c}) \cdot \vec{a} = (\vec{c} \times \vec{a}) \cdot \vec{b}$ |
| **Sign Change** | $[\vec{a}, \vec{b}, \vec{c}] = -[\vec{c}, \vec{b}, \vec{a}]$ (reversing any two vectors flips the sign) |
| **Coplanarity Check** | $[\vec{a}, \vec{b}, \vec{c}] = 0 \iff$ Vectors are in the same plane. |

---

## Code Implementation

*   **C++ Source Code:** [[03_Code/02_Vectors/Scalar_Triple_Product.cppm|Scalar_Triple_Product.cppm]]
