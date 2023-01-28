#include "../include/Bureaucrat.hpp"
#include "../include/Form.hpp"

int test_john()
{
	Bureaucrat john("John", 2);
	std::cout << john << std::endl; // Print John's info

	try
	{
		john.incrementGrade();
		john.incrementGrade(); // Throw an exception
		std::cout << "Latest Stable Grade: " << john.getGrade() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Form test("test", 151, 42);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Cannot initialize test because " << e.what() << std::endl;
	}

	Form b("b", 3, 3);
	std::cout << john << std::endl;
	std::cout << b << std::endl;
	john.signForm(b);
	john.signForm(b);

	try
	{
		// john.decrementGrade();
		john.incrementGrade();
		std::cout << john << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << b << std::endl;
	return (0);
}

int main()
{
	test_john();
}