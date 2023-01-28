#include "../include/ShrubberyCreationForm.hpp"
#include <fstream>

/**
 * @brief Construct a new Shrubbery Creation Form:: Shrubbery Creation Form object
 *
 */
ShrubberyCreationForm::ShrubberyCreationForm()
    : Form("shrubbery", "default", 145, 137)
{
}

/**
 * @brief Construct a new Shrubbery Creation Form:: Shrubbery Creation Form object
 *
 * @param target The target name
 */
ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : Form("shrubbery", target, 145, 137)
{
}

/**
 * @brief Construct a new Shrubbery Creation Form:: Shrubbery Creation Form object
 *
 * @param other The rhs obj
 */
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
    : Form(other)
{
}

/**
 * @brief Overlaoding the = op
 *
 * @param rhs
 * @return ShrubberyCreationForm&
 */
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs)
{
    this->Form::operator=(rhs);
    return *this;
}

/**
 * @brief Destroy the Shrubbery Creation Form:: Shrubbery Creation Form object
 *
 */
ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

/**
 * @brief Tries to execute the form and returns an error if it can't
 *
 * @param executor The Bureaucrat executing it
 */
void ShrubberyCreationForm::action(const Bureaucrat &executor) const
{
    this->Form::execute(executor);
    std::ofstream ofs;
    std::string file = this->getTarget() + "_shrubbery";
    ofs.open(file.c_str());
    if (!ofs.is_open())
        throw "Not working!";
    // throw std::ofstream::failure(strerror(errno));
    ofs << "               ,@@@@@@@," << std::endl;
    ofs << "       ,,,.   ,@@@@@@/@@,  .oo8888o." << std::endl;
    ofs << "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o" << std::endl;
    ofs << "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'" << std::endl;
    ofs << "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'" << std::endl;
    ofs << "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'" << std::endl;
    ofs << "   `&%\\ ` /%&'    |.|        \\ '|8'" << std::endl;
    ofs << "       |o|        | |         | |" << std::endl;
    ofs << "       |.|        | |         | |" << std::endl;
    ofs << "    \\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_" << std::endl;
}
