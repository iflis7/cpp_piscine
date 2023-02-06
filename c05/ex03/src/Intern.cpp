#include "../include/Intern.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/PresidentialPardonForm.hpp"

Intern::Intern()
{
    std::cout << "Intern Default Constructor " << std::endl;
}

Intern::Intern(Intern const &src)
{
    std::cout << "Intern Copy Constructor " << this << std::endl;
    (void)src; // Nothing to copy!
}

Intern &Intern::operator=(Intern const &rhs)
{
    std::cout << "Intern Asignation Constructor " << this << std::endl;
    (void)rhs; // Nothing to copy!
    return (*this);
}

Intern::~Intern()
{
    std::cout << "Intern Destructor " << std::endl;
}

Form *Intern::makeForm(std::string form, std::string dest)
{
    Form *newForm;

    newForm = NULL;
    switch (checkForm(form))
    {
    case 1700: // robotomy request
        newForm = new RobotomyRequestForm(dest);
        break;
    case 1960: // presidential pardon
        newForm = new PresidentialPardonForm(dest);
        break;
    case 1867: // shrubbery creation
        newForm = new ShrubberyCreationForm(dest);
        break;
    default:
        throw Intern::FormDoesntExist();
        break;
    }
    return (newForm);
}

/**
 * @brief Throw an Exception
 *
 */
const char *Intern::FormDoesntExist::what() const throw()
{
    return "Form Doesn't Exist";
}

int Intern::checkForm(std::string form)
{
    int res;
    int i;

    res = 0;
    i = 0;
    if (!(form == "robotomy request" || form == "presidential pardon" || form == "shrubbery creation"))
        return (0);
    while (form[i] != '\0')
    {
        res += (int)form[i];
        i++;
    }
    return (res);
}
