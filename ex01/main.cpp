#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    // Test 1: Create a form and a bureaucrat, attempt to sign the form
    try {
        Bureaucrat bob("Bob", 5);
        Form formA("FormA", 10, 20);
        std::cout << formA << std::endl; // Print form info before signing
        bob.signForm(formA); // Should succeed (grade 5 >= required 10)
        std::cout << formA << std::endl; // Print form info after signing
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    // Test 2: Bureaucrat with insufficient grade to sign the form
    try {
        Bureaucrat alice("Alice", 15);
        Form formB("FormB", 10, 20);
        std::cout << formB << std::endl;
        alice.signForm(formB); // Should fail (grade 15 < required 10)
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    // Test 3: Create a form with invalid grades (too high)
    try {
        Form invalidForm("InvalidForm", 0, 20); // Grade too high (0 < 1)
    } catch (std::exception& e) {
        std::cerr << "Error creating form: " << e.what() << std::endl;
    }

    // Test 4: Create a form with invalid grades (too low)
    try {
        Form invalidForm("InvalidForm", 151, 20); // Grade too low (> 150)
    } catch (std::exception& e) {
        std::cerr << "Error creating form: " << e.what() << std::endl;
    }

    // Test 5: Create a form with valid grades and print its info
    try {
        Form formC("FormC", 50, 100);
        Bureaucrat carol("Carol", 75);
        std::cout << formC << std::endl; // Print form info
        carol.signForm(formC); // Should fail (grade 75 < required 50)
        std::cout << formC << std::endl; // Print form info to confirm not signed
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}