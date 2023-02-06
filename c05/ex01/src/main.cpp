#include "../include/Bureaucrat.hpp"
#include "../include/Form.hpp"

int test_john()
{
	Bureaucrat john("John", 2);
	std::cout << john << std::endl; // Print John's info

	std::cout << " ===== Test 1 ===== " << std::endl;
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

	std::cout << std::endl <<  " ===== Test 2 ===== " << std::endl;
	try
	{
		Form test("test", 151, 42);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Cannot initialize test because " << e.what() << std::endl;
	}

	std::cout << std::endl << " ===== Test 3 ===== " << std::endl;

	Form b("b", 3, 3);
	std::cout << b << std::endl;
	john.signForm(b);
	john.execute(b);
	john.signForm(b); // Sould throw an error 

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