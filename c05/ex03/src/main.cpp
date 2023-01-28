#include "../include/Form.hpp"
#include "../include/Bureaucrat.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/Intern.hpp"
#include <math.h>

int main()
{
	srand(time(NULL));

	Bureaucrat john("John", 5);
	Bureaucrat jim("Jim", 45);
	Bureaucrat jane("Jane", 137);

	std::cout << john << std::endl;
	std::cout << jim << std::endl;
	std::cout << jane << std::endl;

// Test the Intern class
	Intern intern;

	Form* formA;
	Form* formB;
	Form* formC;
	Form* formD;

	try
	{
		formA = intern.makeForm("shrubbery creation", "home");
		formB = intern.makeForm("robotomy request", "Bender");
		formC = intern.makeForm("presidential pardon", "Stephen Bannon");
		formD = intern.makeForm("test", "test");
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	std::cout << std::endl;
	john.executeForm(*formA);
	jim.executeForm(*formA);
	jane.executeForm(*formA);
	std::cout << std::endl;
	john.signForm(*formA);
	jim.signForm(*formA);
	jane.signForm(*formA);
	std::cout << std::endl;
	john.executeForm(*formA);
	jim.executeForm(*formA);
	jane.executeForm(*formA);
	std::cout << std::endl;
	std::cout << "-------------------------------------------------------" << std::endl;
	std::cout << std::endl;
	john.executeForm(*formB);
	jim.executeForm(*formB);
	jane.executeForm(*formB);
	std::cout << std::endl;
	john.signForm(*formB);
	jim.signForm(*formB);
	jane.signForm(*formB);
	std::cout << std::endl;
	john.executeForm(*formB);
	jim.executeForm(*formB);
	jane.executeForm(*formB);
	std::cout << std::endl;
	std::cout << "-------------------------------------------------------" << std::endl;
	std::cout << std::endl;
	john.executeForm(*formC);
	jim.executeForm(*formC);
	jane.executeForm(*formC);
	std::cout << std::endl;
	john.signForm(*formC);
	jim.signForm(*formC);
	jane.signForm(*formC);
	std::cout << std::endl;
	john.executeForm(*formC);
	jim.executeForm(*formC);
	jane.executeForm(*formC);
}
