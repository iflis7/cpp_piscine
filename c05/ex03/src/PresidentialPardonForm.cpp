#include "../include/PresidentialPardonForm.hpp"

/**
 * @brief Construct a new Presidential Pardon Form:: Presidential Pardon Form object
 *
 */
PresidentialPardonForm::PresidentialPardonForm()
	: Form("pardon", "default", 25, 5)
{
}

/**
 * @brief Construct a new Presidential Pardon Form:: Presidential Pardon Form object
 *
 * @param target The target name
 */
PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
	: Form("pardon", target, 25, 5)
{
}

/**
 * @brief Construct a new Presidential Pardon Form:: Presidential Pardon Form object
 *
 * @param other The rhs
 */
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
	: Form(other)
{
}

/**
 * @brief Overloading the = op
 *
 * @param rhs
 * @return PresidentialPardonForm&
 */
PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs)
{
	this->Form::operator=(rhs);
	return *this;
}

/**
 * @brief Destroy the Presidential Pardon Form:: Presidential Pardon Form object
 *
 */
PresidentialPardonForm::~PresidentialPardonForm()
{
}

/**
 * @brief Tries to execute the form and returns an error if it can't
 *
 * @param executor The Bureaucrat executing it
 */
void PresidentialPardonForm::action(const Bureaucrat &executor) const
{
	this->Form::execute(executor);
	std::cout << this->getTarget() << "has been pardoned by Zafod Beeblebrox." << std::endl;
}
