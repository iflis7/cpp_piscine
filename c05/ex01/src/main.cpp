#include "../include/Bureaucrat.hpp"
#include "../include/Form.hpp"

int test_john()
{
	Bureaucrat john("John", 3);
	std::cout << john << std::endl; // Print John's info

	std::cout << " ===== Test 1 ===== " << std::endl;
	try
	{
		john.incrementGrade();
		std::cout << "Latest Stable Grade: " << john.getGrade() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << " ===== Test 2 ===== " << std::endl;
	try
	{
		john.decrementGrade();
		john.decrementGrade(); // should return 4
		std::cout << "Latest Stable Grade: " << john.getGrade() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	// comment the john.decrementGrade(); above for the Bureaucrat to be able to sign
	std::cout << std::endl <<  " ===== Test 3 ===== " << std::endl;
	try
	{
		// Form test("test", 140, 0);
		// Form test("test", 151, 1);
		Form test("test", 149, 10);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Cannot initialize test because " << e.what() << std::endl;
	}

	std::cout << std::endl << " ===== Test 4 ===== " << std::endl << std::endl;
	Form b("b", 3, 3); // couldn’t sign 
	// Form b("b", 4, 3); // Can sign
	std::cout << "Print Form:: " << b << std::endl;
	john.signForm(b);
	john.signForm(b); // Sould throw an error  (Grade too low)

	try
	{
		std::cout << john << std::endl;
		john.decrementGrade();
		std::cout << john << std::endl;
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