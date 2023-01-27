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
Bureaucrat::Bureaucrat(const std::string &name, int grade)
	: _name(name)
{
	if (grade > 150)
	{
		throw GradeTooLowException();
	}
	else if (grade < 1)
	{
		throw GradeTooHighException();
	}
	_grade = grade;
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
	{
		this->_name = rhs._name;
		this->_grade = rhs._grade;
	}
	return (*this);
}

// void operator<<(std::ostream &COUT, Bureaucrat &bureaucrat)
// {
//     COUT << bureaucrat.getName();
// }

/**
 * @brief Destroy the Bureaucrat:: Bureaucrat object
 *
 */
Bureaucrat::~Bureaucrat(){

};

void Bureaucrat::signForm(Form &form) const
{
	// if(form->get)
	std::cout << this->getName() << " has signed the Form: " << form.getName() << std::endl;
}

/**
 * @brief Set the Name attribute
 *
 * @param name The name of the Bureaucrat
 *  */
void Bureaucrat::setName(const std::string name)
{
	this->_name = name;
}

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
 * @brief Set the Grade attribute
 *
 * @param grade
 */
void Bureaucrat::setGrade(const int grade)
{
	this->_grade = grade;
}

/**
 * @brief Get the grade
 *
 * @return int the grade
 */
int Bureaucrat::getGrade() const
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
	this->_grade++;
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
