# Coordinate Systems: Right-Hand vs Left-Hand

In 3D space, the orientation of the axes ($x, y, z$) can follow one of two conventions. This choice affects the direction of operations like the **Cross Product**.

## Right-Hand System (Standard)
The right-hand system is the standard convention used in physics and mathematics.
- **Rule:** If you curl the fingers of your right hand from the positive $x$-axis to the positive $y$-axis, your thumb points in the direction of the positive $z$-axis.
- **Cross Product:** $\vec{i} \times \vec{j} = \vec{k}$

## Left-Hand System
Commonly used in some computer graphics applications (like DirectX or Unity's default world space).
- **Rule:** If you curl the fingers of your left hand from the positive $x$-axis to the positive $y$-axis, your thumb points in the direction of the positive $z$-axis.
- **Cross Product:** In a left-hand system, the result of the standard cross product formula points in the opposite direction relative to the $z$-axis orientation.

## Why It Matters
When working with **Cross Products** (see [[04_Cross_Product]]), the resulting vector $\vec{a} \times \vec{b}$ is defined to follow the **Right-Hand Rule**. If you are working in a Left-Handed coordinate system, you must be careful as your visual intuition for "up" or "forward" might be inverted compared to the mathematical result.
