---
topic: Geometry
tags: [exercise, solution, triangle-mesh, euler-formula, triangulation]
---

# Solution: Triangle Meshes

This solution note provides the step-by-step calculations and conceptual explanations for the triangle meshes exercise.

---

## Part 1: Calculation

### Question 1: Gemstone Mesh Edges

A closed, genus-0 triangle mesh has:
* Vertices: $V = 10$
* Triangular Faces: $F = 16$
* Genus: $g = 0$

Using the general **Euler-Poincaré formula** for closed surfaces ($V - E + F = 2 - 2g$):

$$
V - E + F = 2 - 2(0)
$$

$$
10 - E + 16 = 2
$$

$$
26 - E = 2
$$

$$
E = 24
$$

Thus, the mesh has **$E = 24$ edges**.

---

### Question 2: Pyramid-Shaped Mesh Edges

A pyramid has a square base and $1$ apex vertex:
* Base vertices: $4$ corner vertices
* Apex vertex: $1$ top vertex
* Total vertices: $V = 5$

#### 1. Total Triangular Faces ($F$)
* The pyramid has $4$ triangular side faces.
* The square base is split along $1$ diagonal into $2$ triangular faces.
* Total faces: $F = 4 + 2 = 6$.

#### 2. Euler's Formula Calculation
Since the triangulated pyramid forms a closed, watertight genus-0 volume ($g = 0$):

$$
V - E + F = 2 - 2(0)
$$

$$
5 - E + 6 = 2
$$

$$
11 - E = 2
$$

$$
E = 9
$$

#### 3. Direct Edge Count Verification
Counting the edges directly:
* **Base edges:** $4$ edges forming the square boundary.
* **Base diagonal:** $1$ internal edge splitting the square base into 2 triangles.
* **Apex side edges:** $4$ edges connecting each of the 4 base corners to the apex.

$$
\text{Total Edges } E = 4 + 1 + 4 = 9
$$

The direct count matches Euler's formula result perfectly ($E = 9$).

---

## Part 2: Conceptual Understanding

### 1. Topology & Euler's Formula for a Torus

* **Topology Name:** Euler's formula in its basic form ($V - E + F = 2$) applies to **closed (watertight) manifold surfaces of genus 0** (topologically equivalent to a sphere or a convex polyhedron). On such surfaces, every edge is shared by **exactly 2 triangles**.
* **Modification for a Torus (Donut):** A torus has $1$ through-hole, meaning its genus is $g = 1$. The general Euler-Poincaré formula is:

$$
V - E + F = 2 - 2g
$$

For a torus ($g = 1$):

$$
V - E + F = 2 - 2(1) = 0
$$

---

### 2. Edges Shared by 1 Triangle & Open Meshes

* **Implication:** If an edge is used by only **1** triangle instead of 2, it is a **boundary edge**. This indicates that the surface has an opening or missing faces (there is a boundary hole in the mesh).
* **Term:** This is called an **open mesh** (or a non-watertight mesh with boundaries).
* **Formula Modification:** For an open mesh with $h$ boundary loops:

$$
V - E + F = 2 - 2g - h
$$

---

### 3. Guaranteed Geometric Property of Triangles (Planarity)

* **Guaranteed Property:** **Planarity**. Triangles always define a 2D plane in 3D space—a 3-vertex polygon is **100% planar**.
* **Failure for $n$-gons ($4+$ vertices):** With 4 or more vertices (such as a quad), one or more vertices can be twisted, pushed, or pulled out of the plane formed by the other vertices, making the polygon non-planar.
* **Why it matters for rendering:**
  1. **Surface Normals & Lighting:** Light calculations depend on computing a single, orthogonal surface normal vector $\vec{n} = (P_1 - P_0) \times (P_2 - P_0)$. On a non-planar polygon, the normal vector changes depending on which vertices are chosen, leading to shading artifacts and ambiguous rendering.
  2. **Convexity & GPU Rasterization:** Triangles are guaranteed to be convex, which allows GPU hardware to perform fast half-space rasterization tests. Polygons with 4+ vertices can be non-convex or self-intersecting, which breaks standard hardware rasterizers.

---

**Back to Question:** [[Q_01_Triangle_Meshes]] | **Related Concepts:** [[01_Triangle_Meshes]]
