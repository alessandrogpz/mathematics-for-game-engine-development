#include <iostream>

// Import the single C++23 umbrella module
import linear_algebra;

int main() {
    std::cout << "==========================================" << std::endl;
    std::cout << "      Linear Algebra Module Suite         " << std::endl;
    std::cout << "==========================================" << std::endl;
    std::cout << "Running test functions for all concepts:\n" << std::endl;

    std::cout << "[Testing] ";
    systems::test_systems_linear_systems();
    
    std::cout << "[Testing] ";
    vectors::test_vectors_basics();
    
    std::cout << "[Testing] ";
    vectors::test_vectors_dot_product();
    
    std::cout << "[Testing] ";
    vectors::test_vectors_coordinate_systems();
    
    std::cout << "[Testing] ";
    vectors::test_vectors_cross_product();
    
    std::cout << "[Testing] ";
    vectors::test_vectors_scalar_triple_product();
    
    std::cout << "[Testing] ";
    vectors::test_vectors_projection();
    
    std::cout << "[Testing] ";
    matrices::test_matrices_basics();
    
    std::cout << "[Testing] ";
    matrices::test_matrices_multiplication();
    
    std::cout << "[Testing] ";
    matrices::test_matrices_determinants();
    
    std::cout << "[Testing] ";
    matrices::test_matrices_inversion();
    
    std::cout << "[Testing] ";
    matrices::test_matrices_orthogonal();
    
    std::cout << "[Testing] ";
    transforms::test_transforms_matrices();
    
    std::cout << "[Testing] ";
    transforms::test_transforms_rotations();
    
    std::cout << "[Testing] ";
    transforms::test_transforms_reflections();
    
    std::cout << "[Testing] ";
    transforms::test_transforms_scales();

    std::cout << "\nAll module tests completed successfully!" << std::endl;
    std::cout << "==========================================" << std::endl;
    return 0;
}
