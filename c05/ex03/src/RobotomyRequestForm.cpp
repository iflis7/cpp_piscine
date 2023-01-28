#include "../include/RobotomyRequestForm.hpp"
#include <stdlib.h>

/**
 * @brief Construct a new Robotomy Request Form:: Robotomy Request Form object
 *
 */
RobotomyRequestForm::RobotomyRequestForm()
    : Form("robotomy", "default", 72, 45)
{
}

/**
 * @brief Construct a new Robotomy Request Form:: Robotomy Request Form object
 *
 * @param target The target name
 */
RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
    : Form("robotomy", target, 72, 45)
{
}

/**
 * @brief Construct a new Robotomy Request Form:: Robotomy Request Form object
 *
 * @param other The target name
 */
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
    : Form(other)
{
}

/**
 * @brief Overloading the = op
 *
 * @param rhs
 * @return RobotomyRequestForm&
 */
RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs)
{
    this->Form::operator=(rhs);
    return *this;
}

/**
 * @brief Destroy the Robotomy Request Form:: Robotomy Request Form object
 *
 */
RobotomyRequestForm::~RobotomyRequestForm()
{
}

/**
 * @brief Tries to execute the form and returns an error if it can't
 *
 * @param executor The Bureaucrat executing it
 */
void RobotomyRequestForm::action(const Bureaucrat &executor) const
{
    this->Form::execute(executor);
    std::cout << "Makes some drilling noises" << std::endl;
    if (rand() < RAND_MAX / 2)
        std::cout << this->getTarget() << " has been robotomized successfully." << std::endl;
    else
        std::cout << "Robotomy on " << this->getTarget() << " has failed." << std::endl;
}
