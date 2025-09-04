# include "ShrubberyCreationForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"

/*int	main()
{
	Bureaucrat 				pepe("Pepe", 1);
	ShrubberyCreationForm	form1("home");
	PresidentialPardonForm	form2("Pepe Leches");
	RobotomyRequestForm		form3("Perro Sanchez");
	pepe.signForm(form1);
	form1.execute(pepe);
	pepe.signForm(form2);
	form2.execute(pepe);
	pepe.signForm(form3);
	form3.execute(pepe);
	form3.execute(pepe);
	form3.execute(pepe);
	form3.execute(pepe);
	form3.execute(pepe);
	form3.execute(pepe);
	form3.execute(pepe);
	form3.execute(pepe);
	form3.execute(pepe);
	RobotomyRequestForm		form4(form3);
	std::cout << "====From here is form4====" << std::endl;
	form4.execute(pepe);
	form4.execute(pepe);
	form4.execute(pepe);
	form4.execute(pepe);
	form4.execute(pepe);
	form4.execute(pepe);
	form4.execute(pepe);
	RobotomyRequestForm	form5("Luis");
	RobotomyRequestForm	form6("Sergio");
	RobotomyRequestForm	form7("Marta");
	RobotomyRequestForm	form8("Ana");
	RobotomyRequestForm	form9("Alba");
	RobotomyRequestForm	formA("Pacomio");
	pepe.signForm(form5);
	form5.execute(pepe);
	pepe.signForm(form6);
	form6.execute(pepe);
	pepe.signForm(form7);
	form7.execute(pepe);
	pepe.signForm(form8);
	form8.execute(pepe);
	pepe.signForm(form9);
	form9.execute(pepe);
	pepe.signForm(formA);
	formA.execute(pepe);
}*/

int main(void)
{
    std::cout << "=== Testing Bureaucrat Creation and Exceptions ===" << std::endl;
    try {
        Bureaucrat tooHigh("TooHigh", 0);
    } catch (std::exception& e) {
        std::cout << "Expected: Cannot create Bureaucrat with grade 0: " << e.what() << std::endl;
    }
    try {
        Bureaucrat tooLow("TooLow", 151);
    } catch (std::exception& e) {
        std::cout << "Expected: Cannot create Bureaucrat with grade 151: " << e.what() << std::endl;
    }

    Bureaucrat bob("Bob", 1);
    Bureaucrat alice("Alice", 150);
    std::cout << "Created: " << bob << std::endl;
    std::cout << "Created: " << alice << std::endl;

    std::cout << "\n=== Testing Bureaucrat Upgrade/Downgrade ===" << std::endl;
    try {
        bob.upgrade();
    } catch (std::exception& e) {
        std::cout << "Expected: Cannot upgrade Bob beyond grade 1: " << e.what() << std::endl;
    }
    try {
        alice.downgrade();
    } catch (std::exception& e) {
        std::cout << "Expected: Cannot downgrade Alice beyond grade 150: " << e.what() << std::endl;
    }
    try {
        alice.upgrade(); // 150 -> 149
        std::cout << "After upgrade: " << alice << std::endl;
    } catch (std::exception& e) {
        std::cout << "Unexpected: Failed to upgrade Alice: " << e.what() << std::endl;
    }
    try {
        bob.downgrade(); // 1 -> 2
        std::cout << "After downgrade: " << bob << std::endl;
    } catch (std::exception& e) {
        std::cout << "Unexpected: Failed to downgrade Bob: " << e.what() << std::endl;
    }

    std::cout << "\n=== Testing ShrubberyCreationForm ===" << std::endl;
    ShrubberyCreationForm shrub("home");
    std::cout << "Created: " << shrub << std::endl;

    // Test signing with insufficient grade
    try {
        alice.signForm(shrub); // Grade 149, needs 145 or lower
    } catch (std::exception& e) {
        std::cout << "Expected: Alice cannot sign ShrubberyCreationForm: " << e.what() << std::endl;
    }
    // Test signing with sufficient grade
    try {
        bob.signForm(shrub); // Grade 2, needs 145 or lower
    } catch (std::exception& e) {
        std::cout << "Unexpected: Bob failed to sign ShrubberyCreationForm: " << e.what() << std::endl;
    }
    std::cout << "After signing: " << shrub << std::endl;

    // Test executing unsigned form
    ShrubberyCreationForm unsignedShrub("unsigned_home");
    try {
        alice.executeForm(unsignedShrub); // Should fail (not signed)
    } catch (std::exception& e) {
        std::cout << "Expected: Alice cannot execute unsigned ShrubberyCreationForm: " << e.what() << std::endl;
    }
    // Test executing with insufficient grade
    try {
        alice.executeForm(shrub); // Grade 149, needs 137 or lower
    } catch (std::exception& e) {
        std::cout << "Expected: Alice cannot execute ShrubberyCreationForm: " << e.what() << std::endl;
    }
    // Test executing with sufficient grade
    try {
        bob.executeForm(shrub); // Grade 2, needs 137 or lower
    } catch (std::exception& e) {
        std::cout << "Unexpected: Bob failed to execute ShrubberyCreationForm: " << e.what() << std::endl;
    }

    // Verify file creation
    std::ifstream shrubFile("home_shrubbery");
    if (shrubFile.is_open()) {
        std::cout << "Shrubbery file created successfully." << std::endl;
        std::string line;
        std::cout << "File content preview:" << std::endl;
        int lines = 0;
        while (std::getline(shrubFile, line) && lines < 5) {
            std::cout << line << std::endl;
            lines++;
        }
        shrubFile.close();
    } else {
        std::cout << "Unexpected: Shrubbery file not created!" << std::endl;
    }

    std::cout << "\n=== Testing RobotomyRequestForm ===" << std::endl;
    RobotomyRequestForm robo("Arthur");
    std::cout << "Created: " << robo << std::endl;

    // Test signing with insufficient grade
    try {
        alice.signForm(robo); // Grade 149, needs 72 or lower
    } catch (std::exception& e) {
        std::cout << "Expected: Alice cannot sign RobotomyRequestForm: " << e.what() << std::endl;
    }
    // Test signing with sufficient grade
    try {
        bob.signForm(robo); // Grade 2, needs 72 or lower
    } catch (std::exception& e) {
        std::cout << "Unexpected: Bob failed to sign RobotomyRequestForm: " << e.what() << std::endl;
    }
    std::cout << "After signing: " << robo << std::endl;

    // Test executing unsigned form
    RobotomyRequestForm unsignedRobo("UnsignedArthur");
    try {
        bob.executeForm(unsignedRobo); // Should fail (not signed)
    } catch (std::exception& e) {
        std::cout << "Expected: Bob cannot execute unsigned RobotomyRequestForm: " << e.what() << std::endl;
    }
    // Test executing with insufficient grade
    try {
        alice.executeForm(robo); // Grade 149, needs 45 or lower
    } catch (std::exception& e) {
        std::cout << "Expected: Alice cannot execute RobotomyRequestForm: " << e.what() << std::endl;
    }
    // Test executing with sufficient grade (multiple times for alternating success)
    std::cout << "Testing RobotomyRequestForm execution (expect alternating success/failure):" << std::endl;
    try {
        bob.executeForm(robo); // Should succeed
    } catch (std::exception& e) {
        std::cout << "Unexpected: Bob failed to execute RobotomyRequestForm: " << e.what() << std::endl;
    }
    try {
        bob.executeForm(robo); // Should fail
    } catch (std::exception& e) {
        std::cout << "Unexpected: Bob failed to execute RobotomyRequestForm: " << e.what() << std::endl;
    }

    std::cout << "\n=== Testing PresidentialPardonForm ===" << std::endl;
    PresidentialPardonForm pardon("Marvin");
    std::cout << "Created: " << pardon << std::endl;

    // Test signing with insufficient grade
    try {
        alice.signForm(pardon); // Grade 149, needs 25 or lower
    } catch (std::exception& e) {
        std::cout << "Expected: Alice cannot sign PresidentialPardonForm: " << e.what() << std::endl;
    }
    // Test signing with sufficient grade
    try {
        bob.signForm(pardon); // Grade 2, needs 25 or lower
    } catch (std::exception& e) {
        std::cout << "Unexpected: Bob failed to sign PresidentialPardonForm: " << e.what() << std::endl;
    }
    std::cout << "After signing: " << pardon << std::endl;

    // Test executing unsigned form
    PresidentialPardonForm unsignedPardon("UnsignedMarvin");
    try {
        bob.executeForm(unsignedPardon); // Should fail (not signed)
    } catch (std::exception& e) {
        std::cout << "Expected: Bob cannot execute unsigned PresidentialPardonForm: " << e.what() << std::endl;
    }
    // Test executing with insufficient grade
    try {
        alice.executeForm(pardon); // Grade 149, needs 5 or lower
    } catch (std::exception& e) {
        std::cout << "Expected: Alice cannot execute PresidentialPardonForm: " << e.what() << std::endl;
    }
    // Test executing with sufficient grade
    try {
        bob.executeForm(pardon); // Grade 2, needs 5 or lower
    } catch (std::exception& e) {
        std::cout << "Unexpected: Bob failed to execute PresidentialPardonForm: " << e.what() << std::endl;
    }

    std::cout << "\n=== Testing Polymorphism ===" << std::endl;
    // Test ShrubberyCreationForm
    {
        AForm* formPtr = new ShrubberyCreationForm("poly_home");
        try {
            bob.signForm(*formPtr);
            bob.executeForm(*formPtr);
            std::cout << "Polymorphism test for shrubbery creation completed." << std::endl;
        } catch (std::exception& e) {
            std::cout << "Unexpected: Polymorphism test failed for ShrubberyCreationForm: " << e.what() << std::endl;
        }
        delete formPtr;
    }

    // Test RobotomyRequestForm (donde ocurrió el error anterior)
    {
        AForm* formPtr = new RobotomyRequestForm("poly_arthur");
        try {
            bob.signForm(*formPtr);
            bob.executeForm(*formPtr);
            std::cout << "Polymorphism test for robotomy request completed." << std::endl;
        } catch (std::exception& e) {
            std::cout << "Unexpected: Polymorphism test failed for RobotomyRequestForm: " << e.what() << std::endl;
        }
        delete formPtr;
    }

    // Test PresidentialPardonForm
    {
        AForm* formPtr = new PresidentialPardonForm("poly_marvin");
        try {
            bob.signForm(*formPtr);
            bob.executeForm(*formPtr);
            std::cout << "Polymorphism test for presidential pardon completed." << std::endl;
        } catch (std::exception& e) {
            std::cout << "Unexpected: Polymorphism test failed for PresidentialPardonForm: " << e.what() << std::endl;
        }
        delete formPtr;
    }

    std::cout << "\n=== Testing Copy and Assignment ===" << std::endl;
    try {
        ShrubberyCreationForm shrubCopy(shrub);
        std::cout << "Copy of ShrubberyCreationForm: " << shrubCopy << std::endl;
        ShrubberyCreationForm shrubAssign("assign_home");
        shrubAssign = shrub;
        std::cout << "Assigned ShrubberyCreationForm: " << shrubAssign << std::endl;
    } catch (std::exception& e) {
        std::cout << "Unexpected: Copy/Assignment failed for ShrubberyCreationForm: " << e.what() << std::endl;
    }

    try {
        RobotomyRequestForm roboCopy(robo);
        std::cout << "Copy of RobotomyRequestForm: " << roboCopy << std::endl;
        RobotomyRequestForm roboAssign("assign_arthur");
        roboAssign = robo;
        std::cout << "Assigned RobotomyRequestForm: " << roboAssign << std::endl;
    } catch (std::exception& e) {
        std::cout << "Unexpected: Copy/Assignment failed for RobotomyRequestForm: " << e.what() << std::endl;
    }

    try {
        PresidentialPardonForm pardonCopy(pardon);
        std::cout << "Copy of PresidentialPardonForm: " << pardonCopy << std::endl;
        PresidentialPardonForm pardonAssign("assign_marvin");
        pardonAssign = pardon;
        std::cout << "Assigned PresidentialPardonForm: " << pardonAssign << std::endl;
    } catch (std::exception& e) {
        std::cout << "Unexpected: Copy/Assignment failed for PresidentialPardonForm: " << e.what() << std::endl;
    }

    std::cout << "\n=== Testing Additional Grade Scenarios ===" << std::endl;
    Bureaucrat midGrade("MidGrade", 50);
    ShrubberyCreationForm shrubMid("mid_home");
    try {
        midGrade.signForm(shrubMid); // Grade 50, needs 145 or lower
        std::cout << "MidGrade signed ShrubberyCreationForm: " << shrubMid << std::endl;
    } catch (std::exception& e) {
        std::cout << "Unexpected: MidGrade failed to sign ShrubberyCreationForm: " << e.what() << std::endl;
    }
    try {
        midGrade.executeForm(shrubMid); // Grade 50, needs 137 or lower
    } catch (std::exception& e) {
        std::cout << "Unexpected: MidGrade failed to execute ShrubberyCreationForm: " << e.what() << std::endl;
    }

    RobotomyRequestForm roboMid("mid_arthur");
    try {
        midGrade.signForm(roboMid); // Grade 50, needs 72 or lower
    } catch (std::exception& e) {
        std::cout << "Expected: MidGrade cannot sign RobotomyRequestForm: " << e.what() << std::endl;
    }
    try {
        midGrade.executeForm(roboMid); // Grade 50, needs 45 or lower
    } catch (std::exception& e) {
        std::cout << "Expected: MidGrade cannot execute RobotomyRequestForm: " << e.what() << std::endl;
    }

    PresidentialPardonForm pardonMid("mid_marvin");
    try {
        midGrade.signForm(pardonMid); // Grade 50, needs 25 or lower
    } catch (std::exception& e) {
        std::cout << "Expected: MidGrade cannot sign PresidentialPardonForm: " << e.what() << std::endl;
    }
    try {
        midGrade.executeForm(pardonMid); // Grade 50, needs 5 or lower
    } catch (std::exception& e) {
        std::cout << "Expected: MidGrade cannot execute PresidentialPardonForm: " << e.what() << std::endl;
    }

    std::cout << "\n=== Testing Restricted Access to procede() ===" << std::endl;
    // Intentar acceder a procede() directamente (esto no compilará)
    // shrub.procede(); // Error: procede() is private in ShrubberyCreationForm
    std::cout << "Confirmed: procede() is private and cannot be called directly from main." << std::endl;
    std::cout << "procede() is only accessible through Bureaucrat::executeForm via AForm::execute." << std::endl;

    std::cout << "\n=== End of Tests ===" << std::endl;
    return 0;
}