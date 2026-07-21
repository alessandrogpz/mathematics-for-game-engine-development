# Triangle Meshes

Nearly every object rendered by a game engine or 3D application is built out of triangles. A **triangle mesh** is a collection of triangles that fit together edge-to-edge to approximate the surface of a solid volume. Understanding how meshes are structured is the foundation for everything that follows in this section, including how surface normals are computed and transformed.

## Why Triangles?

Modern graphics hardware rasterizes triangles natively rather than arbitrary polygons, for two reasons rooted directly in linear algebra:

*   **Guaranteed Planarity:** Any 3 non-collinear points define exactly one plane. A polygon with 4 or more vertices is not guaranteed to be planar (its vertices can be twisted out of a common plane), which makes shading and rasterization ambiguous.
*   **Guaranteed Convexity:** A triangle is always convex, which simplifies rasterization (determining which pixels lie inside it) and interpolation of vertex attributes (color, normals, texture coordinates) via barycentric coordinates.

Because hardware cannot rasterize polygons with more than 3 sides directly, any higher-order polygon (quads, pentagons, etc.) must first be broken down into triangles. This process is called **triangulation**.

### Triangulation of an $n$-gon

Any simple (non-self-intersecting) planar polygon with $n$ vertices can be triangulated into exactly $n - 2$ triangles, since each triangle "uses up" one vertex's worth of interior angle while sharing an edge with its neighbor. The simplest case is a quadrilateral ($n = 4$): cutting it along one diagonal splits it into exactly $2$ triangles.

---

## Mesh Structure: Vertices, Edges, and Faces

A triangle mesh is described by three fundamental sets:

| Element | Symbol | Description |
| :--- | :--- | :--- |
| **Vertex** | $V$ | A point in 3D space, $(x, y, z)$. |
| **Edge** | $E$ | A line segment connecting two vertices. |
| **Face** | $F$ | A triangle formed by 3 vertices (and consequently 3 edges). |

A single vertex is typically **shared** by many triangles, and a single edge is typically shared by exactly two triangles (see [Closed Meshes](#closed-manifold-meshes) below). This sharing is precisely why meshes are not stored as independent lists of triangles in practice.

### Indexed Mesh Representation

Storing full vertex coordinates for every triangle independently would duplicate the position of every shared vertex many times over. Instead, graphics APIs represent a mesh with two arrays:

1.  **Vertex Buffer:** A flat list of unique vertex positions (and other per-vertex data, such as normals).
2.  **Index Buffer:** A list of integer triplets, where each triplet references 3 entries in the vertex buffer to form one triangular face.

This indexed scheme is what allows a shared vertex to be stored exactly once while still being referenced by every triangle that touches it.

---

## Example: A Triangulated Cube

Consider a unit cube with 8 vertices. Each of its 6 square faces is split along one diagonal into 2 triangles, giving $6 \times 2 = 12$ triangles in total.

$$
V_0 = (0,0,0), \quad V_1 = (1,0,0), \quad V_2 = (1,1,0), \quad V_3 = (0,1,0)
$$

$$
V_4 = (0,0,1), \quad V_5 = (1,0,1), \quad V_6 = (1,1,1), \quad V_7 = (0,1,1)
$$

Winding each face **counter-clockwise as viewed from outside the cube** (so that the outward normal falls out of the vertex order naturally, see [[02_Normal_Vectors]]), the 12 triangles (index buffer) are:

| Face | Outward Direction | Triangles (vertex indices) |
| :--- | :--- | :--- |
| Bottom ($z=0$) | $(0,0,-1)$ | $(3,2,1)$, $(3,1,0)$ |
| Top ($z=1$) | $(0,0,+1)$ | $(4,5,6)$, $(4,6,7)$ |
| Front ($y=0$) | $(0,-1,0)$ | $(0,1,5)$, $(0,5,4)$ |
| Back ($y=1$) | $(0,+1,0)$ | $(7,6,2)$, $(7,2,3)$ |
| Left ($x=0$) | $(-1,0,0)$ | $(4,7,3)$, $(4,3,0)$ |
| Right ($x=1$) | $(+1,0,0)$ | $(1,2,6)$, $(1,6,5)$ |

Each of the cube's 12 original edges is shared by the 2 triangles on either side of its face, plus each face contributes 1 new diagonal edge shared by its own 2 triangles: $12 + 6 = 18$ edges total.

---

## Closed (Manifold) Meshes

A triangle mesh is called **closed** (or *watertight*) if every edge is shared by **exactly 2** triangles — meaning the surface has no holes or boundary edges and fully encloses a volume. If an edge is used by only 1 triangle, the mesh has a boundary (e.g. a single flat sheet of triangles is not closed); if an edge is shared by 3 or more triangles, the surface is non-manifold and not physically well-formed.

### Euler's Formula

For any **closed mesh that is topologically equivalent to a sphere** (i.e. it has no "handles" or holes running through it, formally called *genus 0*), the counts of vertices, edges, and faces always satisfy:

$$
V - E + F = 2
$$

Verifying this against the cube example above: $V = 8$, $E = 18$, $F = 12$, so $8 - 18 + 12 = 2$. ✓

> [!IMPORTANT]
> Euler's formula in this exact form only holds for genus-0 surfaces (topologically a sphere). A closed mesh shaped like a torus (a donut, genus $g=1$) or any surface with $g$ "handles" instead satisfies the more general relation:
> $$
> V - E + F = 2 - 2g
> $$

### A Useful Shortcut for Triangle Counts

Because every triangular face has exactly 3 edges, and every edge on a closed mesh is shared by exactly 2 faces, counting edges "from the face side" gives $3F = 2E$, so $E = \tfrac{3}{2}F$. Substituting into Euler's formula ($V - E + F = 2$) and solving for $F$ in terms of $V$ alone gives two handy relations for any closed, genus-0 triangle mesh:

$$
F = 2V - 4, \qquad E = 3V - 6
$$

Checking against the cube ($V = 8$): $F = 2(8) - 4 = 12$ and $E = 3(8) - 6 = 18$, matching exactly. This is why closed meshes are often described as having "roughly twice as many triangles as vertices."

---

*(For how the normal vector of each triangular face is computed from its vertices, see [[02_Normal_Vectors]].)*
