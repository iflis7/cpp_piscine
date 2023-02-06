#include "../include/Bureaucrat.hpp"
#include "../include/Form.hpp"

/**
 * @brief Construct a new Bureaucrat:: Bureaucrat object
 *
 */
Bureaucrat::Bureaucrat()
	: _name("Default"), _grade(150)
{
	std::cout << "Bureaucrat Created by Default!" << std::endl;
}

/**
 * @brief Construct a new Bureaucrat:: Bureaucrat object
 *
 * @param name The name of
 * @param grade The grade to initilized at
 */
Bureaucrat::Bureaucrat(const std::string name, unsigned int grade)
	: _name(name)
{
	if (grade > 150)
		throw GradeTooLowException();
	else if (grade < 1)
		throw GradeTooHighException();
	else
		this->_grade = grade;
}

/**
 * @brief Construct a new Bureaucrat:: Bureaucrat object
 *
 * @param src
 */
Bureaucrat::Bureaucrat(Bureaucrat const &src)
{
	*this = src;
	// return (this);
}

/**
 * @brief Overload = operator
 *
 * @param rhs The right hand side obj
 * @return Bureaucrat&  The oj to return
 */
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rhs)
{
	if (this != &rhs)
		this->_grade = rhs._grade;
	return (*this);
}

/**
 * @brief Destroy the Bureaucrat:: Bureaucrat object
 *
 */
Bureaucrat::~Bureaucrat(){

};

/**
 * @brief Get the name
 *
 * @return const std::string
 */
const std::string Bureaucrat::getName() const
{
	return (this->_name);
};

/**
 * @brief Get the grade
 *
 * @return int the grade
 */
unsigned int Bureaucrat::getGrade() const
{
	return (this->_grade);
};

/**
 * @brief Increases the grade
 *
 */
void Bureaucrat::incrementGrade()
{
	if (this->_grade <= 1)
		throw GradeTooHighException();
	else
		this->_grade--;
}

/**
 * @brief Decreases the grade
 *
 */
void Bureaucrat::decrementGrade()
{
	if (this->_grade >= 150)
		throw GradeTooLowException();
	else
		this->_grade++;
}

/**
 * @brief Sign a form by the bureaucrat
 *
 * @param form The form to sign
 */
void Bureaucrat::signForm(Form &form) const
{
	try
	{
		form.beSigned(*this);
		std::cout << *this << " SIGNED " << form << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << *this << " COULDN'T SIGN " << form
				  << " BECAUSE " << e.what() << std::endl;
	}
}

/**
 * @brief Execute a form by the bureaucrat
 *
 * @param form The form to Execute
 */
void Bureaucrat::executeForm(Form &form) const
{
	try
	{
		form.action(*this);
		std::cout << *this << " EXECUTED " << form << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << *this << " COULDN'T EXECUTE " << form << " BECAUSE " << e.what() << std::endl;
	}
}

/**
 * @brief Throw an Exception
 *
 */
const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

/**
 * @brief Throw an Exception
 *
 */
const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}

/**
 * @brief
 *
 * @param out
 * @param bureaucrat
 * @return std::ostream&
 */
std::ostream &operator<<(std::ostream &out, const Bureaucrat &rhs)
{
	out << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
	return (out);
};
