# Vector Projection

Vector projection allows us to decompose one vector into a component that lies along the direction of another vector.

## Conceptual Understanding: "Shadow and Influence"
Think of vector projection as finding the "shadow" that vector $\vec{a}$ casts onto vector $\vec{b}$.
- **What it tells us:** It tells us how much of $\vec{a}$ is acting in the same direction as $\vec{b}$.
- **Components:**
  - **Scalar Projection (Length):** Just the magnitude of the shadow.
  - **Vector Projection (Vector):** The actual vector that represents that shadow.

## Formulas

### Scalar Projection (Component)
$$\text{comp}_{\vec{b}}\vec{a} = \frac{\vec{a} \cdot \vec{b}}{\|\vec{b}\|}$$

### Vector Projection
$$\text{proj}_{\vec{b}}\vec{a} = \frac{\vec{a} \cdot \vec{b}}{\|\vec{b}\|^2} \vec{b}$$

## Derivation of the Formula

To find the formula for the projection of $\vec{a}$ onto $\vec{b}$, we follow these logical steps:

### 1. The Geometric Setup
We want to find the component of $\vec{a}$ that lies in the direction of $\vec{b}$. Geometrically, this forms a right-angled triangle where:
- The hypotenuse is $\|\vec{a}\|$.
- The adjacent side (the shadow) is the **Scalar Projection** ($\text{comp}_{\vec{b}}\vec{a}$).
- The angle between the vectors is $\theta$.

From trigonometry:
$$\text{comp}_{\vec{b}}\vec{a} = \|\vec{a}\| \cos(\theta)$$

### 2. Connect to the Dot Product
We know the geometric definition of the dot product is:
$$\vec{a} \cdot \vec{b} = \|\vec{a}\| \|\vec{b}\| \cos(\theta)$$
Isolate the $\|\vec{a}\| \cos(\theta)$ part:
$$\|\vec{a}\| \cos(\theta) = \frac{\vec{a} \cdot \vec{b}}{\|\vec{b}\|}$$
This gives us the **Scalar Projection** formula.

### 3. Convert to a Vector
The **Vector Projection** ($\text{proj}_{\vec{b}}\vec{a}$) must have the magnitude we just found, but it must point in the direction of $\vec{b}$. To do this, we multiply the scalar magnitude by the **unit vector** of $\vec{b}$ ($\hat{u}_{\vec{b}}$):
$$\hat{u}_{\vec{b}} = \frac{\vec{b}}{\|\vec{b}\|}$$

Combine them:
$$\text{proj}_{\vec{b}}\vec{a} = \left( \text{comp}_{\vec{b}}\vec{a} \right) \cdot \hat{u}_{\vec{b}}$$
$$\text{proj}_{\vec{b}}\vec{a} = \left( \frac{\vec{a} \cdot \vec{b}}{\|\vec{b}\|} \right) \cdot \frac{\vec{b}}{\|\vec{b}\|}$$

### 4. Simplify
Multiplying the denominators ($\|\vec{b}\| \cdot \|\vec{b}\| = \|\vec{b}\|^2$):
$$\text{proj}_{\vec{b}}\vec{a} = \frac{\vec{a} \cdot \vec{b}}{\|\vec{b}\|^2} \vec{b}$$
