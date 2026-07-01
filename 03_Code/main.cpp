#include <iostream>
#include <format>

// Import the single C++23 umbrella module containing all vector/matrix modules
import linear_algebra;

int main() {
    std::cout << "========================================" << std::endl;
    std::cout << "       LINEAR ALGEBRA TEST SUITE        " << std::endl;
    std::cout << "========================================" << std::endl;

    // --- 1. Basic Matrix Operations ---
    std::cout << "\n1. --- Basic Matrix Operations ---" << std::endl;
    matrices::Matrix3x3 A;
    A[0, 0] = 1.0; A[0, 1] = 2.0; A[0, 2] = 3.0;
    A[1, 0] = 4.0; A[1, 1] = 5.0; A[1, 2] = 6.0;
    A[2, 0] = 7.0; A[2, 1] = 8.0; A[2, 2] = 9.0;

    std::cout << "Matrix A:" << std::endl;
    matrices::print(A);

    // Identity Matrix
    matrices::Matrix3x3 I = matrices::Matrix3x3::identity();
    std::cout << "Identity Matrix I:" << std::endl;
    matrices::print(I);

    // Matrix Addition & Subtraction
    std::cout << "Matrix Addition (A + I):" << std::endl;
    matrices::print(A + I);

    std::cout << "Matrix Subtraction (A - I):" << std::endl;
    matrices::print(A - I);

    // Scalar Multiplication
    std::cout << "Scalar Multiplication (A * 2.5):" << std::endl;
    matrices::print(A * 2.5);

    // Transposition
    std::cout << "Transposition transpose(A):" << std::endl;
    matrices::Matrix3x3 A_transposed = matrices::transpose(A);
    matrices::print(A_transposed);

    // Trace
    std::cout << "Trace of A: " << matrices::trace(A) << " (Expected: 15)" << std::endl;
    std::cout << "Trace of I: " << matrices::trace(I) << " (Expected: 3)" << std::endl;


    // --- 2. Matrix Multiplication ---
    std::cout << "\n2. --- Matrix Multiplication ---" << std::endl;
    std::cout << "A * I (Should be equal to A):" << std::endl;
    matrices::print(matrices::matrixMultiplication3x3(A, I));

    std::cout << "A * A (Matrix Squared):" << std::endl;
    matrices::print(matrices::matrixMultiplication3x3(A, A));


    // --- 3. Determinants ---
    std::cout << "\n3. --- Determinant Tests ---" << std::endl;
    std::cout << "Determinant of A (Singular): " << matrices::determinant(A) << " (Expected: 0)" << std::endl;
    std::cout << "Determinant of I (Identity): " << matrices::determinant(I) << " (Expected: 1)" << std::endl;

    matrices::Matrix3x3 B;
    B[0, 0] = 1.0; B[0, 1] = 0.0; B[0, 2] = 2.0;
    B[1, 0] = 0.0; B[1, 1] = 3.0; B[1, 2] = 0.0;
    B[2, 0] = 4.0; B[2, 1] = 0.0; B[2, 2] = 5.0;

    std::cout << "Matrix B:" << std::endl;
    matrices::print(B);
    std::cout << "Determinant of B: " << matrices::determinant(B) << " (Expected: -9)" << std::endl;


    // --- 4. Matrix Inversion ---
    std::cout << "\n4. --- Matrix Inversion Tests ---" << std::endl;
    std::cout << "Inverse of B (Invertible):" << std::endl;
    matrices::Matrix3x3 B_inv = matrices::inverse(B);
    matrices::print(B_inv);

    std::cout << "Verification B * B_inv (Should equal I):" << std::endl;
    matrices::print(matrices::matrixMultiplication3x3(B, B_inv));

    std::cout << "Inverse of I (Identity):" << std::endl;
    matrices::print(matrices::inverse(I));

    std::cout << "Inverse of A (Singular, should print error and return zero matrix):" << std::endl;
    matrices::print(matrices::inverse(A));


    // --- 5. Vector Projections & Rejections ---
    std::cout << "\n5. --- Vector Projections & Rejections ---" << std::endl;
    vectors::vector3 v{3.0, 4.0, 5.0};
    vectors::vector3 axis{1.0, 0.0, 0.0}; // X-axis

    std::cout << "Vector v: (" << v.x << ", " << v.y << ", " << v.z << ")" << std::endl;
    std::cout << "Axis of projection: (" << axis.x << ", " << axis.y << ", " << axis.z << ")" << std::endl;

    // Scalar Projection
    double s_proj = vectors::scalarProj(v, axis);
    std::cout << "Scalar Projection: " << s_proj << " (Expected: 3)" << std::endl;

    // Algebraic Projection & Rejection
    vectors::vector3 p_alg = vectors::vecProj(v, axis);
    vectors::vector3 r_alg = vectors::vecRej(v, axis);
    std::cout << "Algebraic Projection: (" << p_alg.x << ", " << p_alg.y << ", " << p_alg.z << ") (Expected: 3, 0, 0)" << std::endl;
    std::cout << "Algebraic Rejection:  (" << r_alg.x << ", " << r_alg.y << ", " << r_alg.z << ") (Expected: 0, 4, 5)" << std::endl;

    // Matrix-based Projection & Rejection
    matrices::Matrix3x3 P = matrices::projMatrix(axis);
    matrices::Matrix3x3 P_perp = matrices::orthogonalRejMatrix(axis);

    std::cout << "\nProjection Matrix P:" << std::endl;
    matrices::print(P);
    std::cout << "Orthogonal Rejection Matrix P_perp:" << std::endl;
    matrices::print(P_perp);

    // Overloaded Matrix-Vector Projection & Rejection
    vectors::vector3 p_mat = matrices::vecProj(P, v);
    vectors::vector3 r_mat = matrices::vecRej(P_perp, v);
    std::cout << "Matrix-based Proj (P * v):      (" << p_mat.x << ", " << p_mat.y << ", " << p_mat.z << ") (Expected: 3, 0, 0)" << std::endl;
    std::cout << "Matrix-based Rej (P_perp * v): (" << r_mat.x << ", " << r_mat.y << ", " << r_mat.z << ") (Expected: 0, 4, 5)" << std::endl;

    // --- 6. 3D Coordinate Axis Rotations ---
    std::cout << "\n6. --- 3D Coordinate Axis Rotations ---" << std::endl;
    vectors::vector3 test_vec{0.0, 1.0, 0.0}; // Pointing along Y-axis
    std::cout << "Original Vector: (" << test_vec.x << ", " << test_vec.y << ", " << test_vec.z << ")" << std::endl;

    // Rotate 90 degrees about X-axis -> sweeps Y-axis into Z-axis
    vectors::vector3 rotX_90 = transforms::rotationX(test_vec, 90.0);
    std::cout << "Rotated 90° about X: (" << rotX_90.x << ", " << rotX_90.y << ", " << rotX_90.z << ") (Expected: 0, 0, 1)" << std::endl;

    // Rotate 90 degrees about Y-axis -> remains unchanged
    vectors::vector3 rotY_90 = transforms::rotationY(test_vec, 90.0);
    std::cout << "Rotated 90° about Y: (" << rotY_90.x << ", " << rotY_90.y << ", " << rotY_90.z << ") (Expected: 0, 1, 0)" << std::endl;

    // Rotate 90 degrees about Z-axis -> sweeps Y-axis into negative X-axis (right-handed convention)
    vectors::vector3 rotZ_90 = transforms::rotationZ(test_vec, 90.0);
    std::cout << "Rotated 90° about Z: (" << rotZ_90.x << ", " << rotZ_90.y << ", " << rotZ_90.z << ") (Expected: -1, 0, 0)" << std::endl;

    // Rotate 90 degrees about arbitrary axis (0, 0, 1) -> should match Z-axis rotation
    vectors::vector3 arb_axis{0.0, 0.0, 1.0};
    vectors::vector3 rotArb_90 = transforms::rotationArbitraryAxis(test_vec, arb_axis, 90.0);
    std::cout << "Rotated 90° about Arb (0,0,1): (" << rotArb_90.x << ", " << rotArb_90.y << ", " << rotArb_90.z << ") (Expected: -1, 0, 0)" << std::endl;

    // --- 7. 3D Reflections ---
    std::cout << "\n7. --- 3D Reflections ---" << std::endl;
    vectors::vector3 ref_v{2.0, -1.0, 3.0};
    vectors::vector3 ref_normal{0.0, 0.0, 1.0}; // Z-axis normal

    vectors::vector3 ref_plane = transforms::reflection(ref_normal, ref_v);
    vectors::vector3 ref_axis = transforms::involution(ref_normal, ref_v);

    std::cout << "Original Vector: (" << ref_v.x << ", " << ref_v.y << ", " << ref_v.z << ")" << std::endl;
    std::cout << "Plane Reflection (Normal Z): (" << ref_plane.x << ", " << ref_plane.y << ", " << ref_plane.z << ") (Expected: 2, -1, -3)" << std::endl;
    std::cout << "Axis Reflection (Z-axis):    (" << ref_axis.x << ", " << ref_axis.y << ", " << ref_axis.z << ") (Expected: -2, 1, 3)" << std::endl;

    // --- 8. 3D Scales ---
    std::cout << "\n8. --- 3D Scales ---" << std::endl;
    vectors::vector3 scale_v{1.0, 2.0, 3.0};
    vectors::vector3 scale_axis{0.0, 1.0, 0.0}; // Y-axis

    vectors::vector3 sc_uniform = transforms::scaleUniform(scale_v, 2.5);
    vectors::vector3 sc_nonuniform = transforms::scaleNonuniform(scale_v, 2.0, 0.5, 3.0);
    vectors::vector3 sc_arbitrary = transforms::scaleArbitraryAxis(scale_v, scale_axis, 4.0);

    std::cout << "Original Vector: (" << scale_v.x << ", " << scale_v.y << ", " << scale_v.z << ")" << std::endl;
    std::cout << "Uniform Scale (s=2.5):       (" << sc_uniform.x << ", " << sc_uniform.y << ", " << sc_uniform.z << ") (Expected: 2.5, 5.0, 7.5)" << std::endl;
    std::cout << "Nonuniform Scale (2, 0.5, 3): (" << sc_nonuniform.x << ", " << sc_nonuniform.y << ", " << sc_nonuniform.z << ") (Expected: 2.0, 1.0, 9.0)" << std::endl;
    std::cout << "Arbitrary Scale (s=4 along Y): (" << sc_arbitrary.x << ", " << sc_arbitrary.y << ", " << sc_arbitrary.z << ") (Expected: 1.0, 8.0, 3.0)" << std::endl;

    // --- 9. 3D Skews ---
    std::cout << "\n9. --- 3D Skews ---" << std::endl;
    vectors::vector3 skew_v{2.0, 3.0, 5.0};
    vectors::vector3 skew_dir{1.0, 0.0, 0.0};   // slide along X-axis
    vectors::vector3 skew_meas{0.0, 1.0, 0.0};  // relative to Y-axis

    // Skew of 45 degrees (tan(45) = 1)
    vectors::vector3 sk_res = transforms::skew(skew_dir, skew_meas, skew_v, 45.0);
    std::cout << "Original Vector: (" << skew_v.x << ", " << skew_v.y << ", " << skew_v.z << ")" << std::endl;
    std::cout << "Skew (45° along X relative to Y): (" << sk_res.x << ", " << sk_res.y << ", " << sk_res.z << ") (Expected: 5, 3, 5)" << std::endl;

    // --- 10. Quaternion Rotations ---
    std::cout << "\n10. --- Quaternion Rotations ---" << std::endl;
    vectors::vector3 q_axis{0.0, 0.0, 1.0}; // Z-axis
    vectors::vector3 q_v{0.0, 1.0, 0.0};    // Pointing along Y
    transforms::Quaternion q = transforms::qRotationAxisAngle(q_axis, 90.0);
    vectors::vector3 q_rotated = transforms::qRotateVector(q_v, q);
    std::cout << "Original Vector: (" << q_v.x << ", " << q_v.y << ", " << q_v.z << ")" << std::endl;
    std::cout << "Rotated 90° about Z via Quaternion: (" << q_rotated.x << ", " << q_rotated.y << ", " << q_rotated.z << ") (Expected: -1, 0, 0)" << std::endl;

    return 0;
}
