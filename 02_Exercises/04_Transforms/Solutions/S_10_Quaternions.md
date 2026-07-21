---
topic: Transforms
tags: [exercise, solution, quaternions, rotation, sandwich-product, inverse]
---

# Solution: Quaternions

This solution note provides the step-by-step mathematical derivations, calculations, and conceptual answers for the quaternions exercise.

---

## Part 1: Calculation

### 1. Quaternion Multiplication (Grassmann Product)
Given the quaternions:

$$
q_1 = 1 + 2i - j + k \quad (s_1 = 1, \, \vec{v}_1 = [2, -1, 1]^T)
$$

$$
q_2 = 2 - i + 2j - k \quad (s_2 = 2, \, \vec{v}_2 = [-1, 2, -1]^T)
$$

- **Calculation of $q_1 q_2$:**
  First, compute the vector dot product $\vec{v}_1 \cdot \vec{v}_2$:
  
  $$
  \vec{v}_1 \cdot \vec{v}_2 = 2(-1) + (-1)(2) + 1(-1) = -2 - 2 - 1 = -5
  $$
  
  Next, compute the vector cross product $\vec{v}_1 \times \vec{v}_2$:
  
  $$
  \vec{v}_1 \times \vec{v}_2 = \begin{bmatrix} (-1)(-1) - (1)(2) \\\\ (1)(-1) - (2)(-1) \\\\ (2)(2) - (-1)(-1) \end{bmatrix} = \begin{bmatrix} 1 - 2 \\\\ -1 + 2 \\\\ 4 - 1 \end{bmatrix} = \begin{bmatrix} -1 \\\\ 1 \\\\ 3 \end{bmatrix} = -i + j + 3k
  $$
  
  Now, apply the Grassmann product formula:
  
  $$
  q_1 q_2 = (s_1 s_2 - \vec{v}_1 \cdot \vec{v}_2) + (s_1 \vec{v}_2 + s_2 \vec{v}_1 + \vec{v}_1 \times \vec{v}_2)
  $$
  
  $$
  q_1 q_2 = (1(2) - (-5)) + (1[-1, 2, -1]^T + 2[2, -1, 1]^T + [-1, 1, 3]^T)
  $$
  
  $$
  q_1 q_2 = (2 + 5) + \begin{bmatrix} -1 + 4 - 1 \\\\ 2 - 2 + 1 \\\\ -1 + 2 + 3 \end{bmatrix}
  $$
  
  $$
  q_1 q_2 = 7 + \begin{bmatrix} 2 \\\\ 1 \\\\ 4 \end{bmatrix} = 7 + 2i + j + 4k
  $$

- **Calculation of $q_2 q_1$:**
  Using $\vec{v}_2 \cdot \vec{v}_1 = -5$ and $\vec{v}_2 \times \vec{v}_1 = -(\vec{v}_1 \times \vec{v}_2) = [1, -1, -3]^T$:
  
  $$
  q_2 q_1 = (s_2 s_1 - \vec{v}_2 \cdot \vec{v}_1) + (s_2 \vec{v}_1 + s_1 \vec{v}_2 + \vec{v}_2 \times \vec{v}_1)
  $$
  
  $$
  q_2 q_1 = (2(1) - (-5)) + (2[2, -1, 1]^T + 1[-1, 2, -1]^T + [1, -1, -3]^T)
  $$
  
  $$
  q_2 q_1 = (2 + 5) + \begin{bmatrix} 4 - 1 + 1 \\\\ -2 + 2 - 1 \\\\ 2 - 1 - 3 \end{bmatrix}
  $$
  
  $$
  q_2 q_1 = 7 + \begin{bmatrix} 4 \\\\ -1 \\\\ -2 \end{bmatrix} = 7 + 4i - j - 2k
  $$

- **Comparison:**
  Since $q_1 q_2 = 7 + 2i + j + 4k$ and $q_2 q_1 = 7 + 4i - j - 2k$, we have:
  
  $$
  q_1 q_2 \neq q_2 q_1
  $$
  
  This demonstrates that quaternion multiplication is non-commutative.

### 2. Magnitude and Multiplicative Inverse
For the quaternion $q_1 = 1 + 2i - j + k$:

- **Calculation of $\|q_1\|$:**
  
  $$
  \|q_1\| = \sqrt{w^2 + x^2 + y^2 + z^2} = \sqrt{1^2 + 2^2 + (-1)^2 + 1^2} = \sqrt{1 + 4 + 1 + 1} = \sqrt{7}
  $$

- **Calculation of $q_1^{-1}$:**
  The conjugate of $q_1$ is $q_1^* = 1 - 2i + j - k$. The inverse is:
  
  $$
  q_1^{-1} = \frac{q_1^*}{\|q_1\|^2} = \frac{1 - 2i + j - k}{7} = \frac{1}{7} - \frac{2}{7}i + \frac{1}{7}j - \frac{1}{7}k
  $$

### 3. 3D Vector Rotation
We want to rotate $\vec{v} = [0, 1, 0]^T$ by $\theta = 90^\circ$ around the axis $\vec{u} = [0, 0, 1]^T$.

- **Rotation Quaternion Construction:**
  Since $\theta = 90^\circ$, we have $\frac{\theta}{2} = 45^\circ$.
  
  $$
  q = \cos(45^\circ) + \vec{u}\sin(45^\circ) = \frac{\sqrt{2}}{2} + \begin{bmatrix} 0 \\\\ 0 \\\\ 1 \end{bmatrix}\frac{\sqrt{2}}{2} = \frac{\sqrt{2}}{2} + \frac{\sqrt{2}}{2}k
  $$

- **Pure Quaternion Representation:**
  Represent $\vec{v} = [0, 1, 0]^T$ as:
  
  $$
  p = 0 + 0i + 1j + 0k = j
  $$

- **Sandwich Product Multiplication:**
  Since $\|q\| = 1$, we have $q^{-1} = q^* = \frac{\sqrt{2}}{2} - \frac{\sqrt{2}}{2}k$.
  We evaluate $p' = q p q^*$:
  First, calculate $p q^*$:
  
  $$
  p q^* = j \left( \frac{\sqrt{2}}{2} - \frac{\sqrt{2}}{2}k \right) = \frac{\sqrt{2}}{2}j - \frac{\sqrt{2}}{2}jk = \frac{\sqrt{2}}{2}j - \frac{\sqrt{2}}{2}i
  $$
  
  Now, pre-multiply by $q$:
  
  $$
  q (p q^*) = \left( \frac{\sqrt{2}}{2} + \frac{\sqrt{2}}{2}k \right) \left( \frac{\sqrt{2}}{2}j - \frac{\sqrt{2}}{2}i \right)
  $$
  
  $$
  q p q^* = \frac{2}{4}j - \frac{2}{4}i + \frac{2}{4}kj - \frac{2}{4}ki
  $$
  
  Since $kj = -i$ and $ki = j$:
  
  $$
  q p q^* = \frac{1}{2}j - \frac{1}{2}i - \frac{1}{2}i - \frac{1}{2}j = -i
  $$

- **Verification & Extraction:**
  The resulting quaternion is $p' = 0 - 1i + 0j + 0k$. The real scalar part is exactly $0$.
  Extracting the vector part gives:
  
  $$
  \vec{v}' = \begin{bmatrix} -1 \\\\ 0 \\\\ 0 \end{bmatrix}
  $$

---

## Part 2: Conceptual Understanding

### 1. Hamilton's Identities & Cyclic Rules
Hamilton's fundamental formula states:
$$
i^2 = j^2 = k^2 = ijk = -1
$$

*   **Proof that $ij = k$:**
    Multiply both sides of $ijk = -1$ by $k$ on the right:
    $$
    (ijk)k = -1(k) \implies ij(k^2) = -k
    $$
    Since $k^2 = -1$:
    $$
    ij(-1) = -k \implies -ij = -k \implies ij = k
    $$

*   **Proof that $ji = -k$:**
    First, observe that from $ij = k$, we can find $jk$ and $ki$. 
    Multiply $ijk = -1$ by $i$ on the left:
    $$
    i(ijk) = i(-1) \implies (i^2)j(k) = -i \implies -jk = -i \implies jk = i
    $$
    Now, multiply $jk = i$ by $j$ on the left:
    $$
    j(jk) = j(i) \implies (j^2)k = ji \implies -k = ji \implies ji = -k
    $$

This demonstrates the non-commutative, anti-symmetric nature of quaternion basis units.

### 2. Why Single Multiplication Fails
Let $q = \cos\phi + \vec{u}\sin\phi$ be a unit quaternion, and $p = 0 + \vec{v}$ be a pure vector quaternion.

*   **Algebraic Explanation:**
    If we attempt a single-sided multiplication $p' = qp$, we compute:
    $$
    qp = (\cos\phi, \vec{u}\sin\phi)(0, \vec{v}) = ( -\vec{u}\cdot\vec{v}\sin\phi, \, \vec{v}\cos\phi + \vec{u}\times\vec{v}\sin\phi )
    $$
    Unless $\vec{u}$ and $\vec{v}$ are perpendicular (so $\vec{u}\cdot\vec{v} = 0$), the scalar part of the result $p'$ is **non-zero** ($-\vec{u}\cdot\vec{v}\sin\phi \neq 0$). This means the resulting quaternion no longer represents a pure 3D physical vector, failing to remain in the 3D subspace.

*   **Geometric Explanation:**
    Quaternions act in 4D space $\mathbb{R}^4$. Single-sided multiplication by $q$ performs a **4D rotation** (specifically, a left-isoclinic rotation) which rotates the 3D vector out of the 3D hyperplane (where $w = 0$) and projects it into the 4th dimension.
    By using the double-sided sandwich product $p' = qpq^{-1}$, the right-isoclinic rotation of $q^{-1}$ exactly cancels out the out-of-plane projection of the left rotation, keeping the scalar component of $p'$ at exactly $0$ and ensuring the rotated vector remains inside 3D space.

### 3. The Half-Angle Origin
When we apply the sandwich product $p' = qpq^{-1}$, both multiplications contribute to the rotation. 

Specifically, in 4D space, the left-multiplication by $q$ rotates the vector by the angle $\phi$ in the plane of rotation, and the right-multiplication by $q^{-1}$ rotates the vector by another angle $\phi$ in the same direction. 
The net effect is a total rotation angle of:
$$
\theta_{\text{net}} = 2\phi
$$

Therefore, to achieve a desired physical 3D rotation of $\theta$, we must construct the quaternion using a half-angle:
$$
\phi = \frac{\theta}{2}
$$
This ensures the combined sandwich multiplication yields exactly the expected physical rotation angle $\theta$.

---
**Back to Question:** [[Q_10_Quaternions]] | **Related Concepts:** [[10_Quaternions]]
