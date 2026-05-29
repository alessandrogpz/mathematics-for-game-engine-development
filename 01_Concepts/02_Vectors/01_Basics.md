# Vector Basics

Vectors carry enough information to represent both **direction** and **magnitude**.

## Notation
A vector in $n$-dimensions is typically represented as:

$$
\vec{v} = (v_1, v_2, \dots, v_n)
$$

## Magnitude
The magnitude (or length) of a vector is calculated using the Euclidean norm formula, which is an extension of the Pythagorean theorem:

$$
\|\vec{v}\| = \sqrt{v_1^2 + v_2^2 + \dots + v_n^2}
$$

## Scalar Multiplication
Multiplying a vector by a scalar $s$ multiplies each component by that scalar:

$$
s\vec{v} = (sv_1, sv_2, \dots, sv_n)
$$

## Unit Vector & Normalization
A **unit vector** is a vector with a magnitude of 1.
To scale any vector to a unit vector, we divide it by its magnitude. This process is called **normalization**:

$$
\hat{u} = \frac{\vec{v}}{\|\vec{v}\|}
$$

## Addition & Subtraction
Vectors must have the same number of components to be added or subtracted.
- **Addition:** $\vec{a} + \vec{b} = (a_1 + b_1, a_2 + b_2, \dots, a_n + b_n)$
- **Subtraction:** $\vec{a} - \vec{b} = (a_1 - b_1, a_2 - b_2, \dots, a_n - b_n)$

## Basic Properties
| Property | Description | Formula |
| :--- | :--- | :--- |
| **Associative** | Vector addition | $(\vec{a} + \vec{b}) + \vec{c} = \vec{a} + (\vec{b} + \vec{c})$ |
| **Commutative** | Vector addition | $\vec{a} + \vec{b} = \vec{b} + \vec{a}$ |
| **Associative** | Scalar-vector | $s(t\vec{a}) = (st)\vec{a}$ |
| **Commutative** | Scalar-vector | $s\vec{a} = \vec{a}s$ |
| **Distributive** | Scalar-vector | $(s + t)\vec{a} = s\vec{a} + t\vec{a}$ |
