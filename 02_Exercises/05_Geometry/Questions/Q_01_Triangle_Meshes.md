---
topic: Geometry
difficulty: Easy
tags: [exercise, question, triangle-mesh, euler-formula, triangulation]
---
# Question
## Part 1: Calculation
1. A closed, genus-0 triangle mesh representing a low-poly gemstone model has $V = 10$ vertices and $F = 16$ triangular faces. Use **Euler's formula** to compute the number of edges $E$.
2. A separate pyramid-shaped mesh has a square base (4 corner vertices) and 1 apex vertex, giving $V = 5$ total. The 4 triangular side faces already exist, and the square base is triangulated into 2 triangles by adding a single diagonal.
   *   State the total number of triangular faces $F$ for this mesh.
   *   Use Euler's formula to compute $E$.
   *   Verify your value of $E$ by counting the edges directly (base edges + base diagonal + edges to the apex).

## Part 2: Conceptual Understanding
1. Euler's formula $V - E + F = 2$ only applies to closed meshes of a specific topology. What is that topology called, and how must the formula be modified for a closed mesh shaped like a torus (donut)?
2. Suppose you inspect a mesh and find one edge that is used by only **1** triangle instead of 2. What does this tell you about the mesh, and what term describes a mesh with this property (as opposed to "closed")?
3. Real-time rendering hardware requires all polygons to be triangulated before rasterization. Name at least one geometric property that is guaranteed for a 3-vertex polygon but is **not** guaranteed for a polygon with 4 or more vertices, and explain why this matters for rendering.

---
**Check Answer:** [[S_01_Triangle_Meshes]] | **Related Concepts:** [[01_Triangle_Meshes]]
