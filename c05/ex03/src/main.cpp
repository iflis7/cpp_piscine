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

	Form *formA;
	Form *formB;
	Form *formC;
	// Form *formD;

	std::cout << "-------------------------- Test the Intern class -----------------------------" << std::endl;
	Intern intern;

	try
	{
		formB = intern.makeForm("robotomy request", "Bender");
		formC = intern.makeForm("presidential pardon", "Stephen Bannon");
		formA = intern.makeForm("shrubbery creation", "home");
		// formD = intern.makeForm("test", "test"); // Should throw an error!
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "-------------------------- Testing Intern class Done √-----------------------------" << std::endl;
	std::cout << std::endl;
	std::cout << "-----------------------------AAA--------------------------" << std::endl;
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

	std::cout << "---------------------------BBB----------------------------" << std::endl;
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

	std::cout << "---------------------------CCC----------------------------" << std::endl;
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

	std::cout << "----------------------- DELETE ----------------------" << std::endl;
	delete formA;
	delete formB;
	delete formC;

	// delete formD;
}
