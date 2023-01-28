#include "../include/Form.hpp"
#include "../include/Bureaucrat.hpp"

Form::Form(const std::string name) : _name(name), _is_signed(false),
                                     _signGrade(1), _execGrade(1)
{
    std::cout << "Default Constructor Called On Form" << std::endl;
}

/**
 * @brief Construct a new Form:: Form object
 *
 * @param name The name of the Form
 * @param signGrade The sign grade number
 * @param execGrade
 */
Form::Form(const std::string name, int signGrade, int execGrade)
    : _name(name), _is_signed(false),
      _signGrade(signGrade), _execGrade(execGrade)
{
    std::cout << "Default Constructor Called On Form" << std::endl;
}

Form::Form(const Form &other) : _name(other._name), _is_signed(other._is_signed),
                                _signGrade(other._signGrade), _execGrade(other._execGrade)
{
    std::cout << "Default Copy Constructor Called On Form" << std::endl;
}

Form &Form::operator=(const Form &rhs)
{
    this->_name = rhs._name;
    this->_is_signed = rhs._is_signed;
    this->_signGrade = rhs._signGrade;
    this->_execGrade = rhs._execGrade;
    return (*this);
}

Form::~Form()
{
    std::cout << "Default Copy Constructor Called On Form" << std::endl;
}

/**
 * @brief Set the name
 *
 * @param name The name to set
 */
void Form::setName(const std::string name)
{
    this->_name = name;
}

/**
 * @brief get the name
 *
 * @return const std::string the name returned
 */
const std::string Form::getName() const
{
    return (this->_name);
}

/**
 * @brief Set the is_signed flag
 *
 * @param isSigned True or False to set
 */
void Form::setSigned(bool isSigned)
{
    this->_is_signed = isSigned;
}

/**
 * @brief get The is_signed status  of the form
 *
 * @return true if the form is signed
 * @return false if not signed
 */
bool Form::getSigned() const
{
    return (this->_is_signed);
}

/**
 * @brief Set the Sign Grade object
 *
 * @param signGrade The grade to give
 */
void Form::setSignGrade(const int signGrade)
{
    this->_signGrade = signGrade;
}

/**
 * @brief get the sign grade of the form
 *
 * @return int the grade
 */
int Form::getSignGrade() const
{
    return (this->_signGrade);
}

/**
 * @brief Set the grade
 *
 * @param execGrade the
 */
void Form::setExecGrade(const int execGrade)
{
    this->_execGrade = execGrade;
}

/**
 * @brief get the exec Grade
 *
 * @return int the exec grade
 */
int Form::getExecGrade() const
{
    return (this->_execGrade);
}

/**
 * @brief Overloadin << operator
 *
 * @param out The ostream
 * @param rhs The Form to print out
 * @return std::ostream& the new obj to return
 */
std::ostream &operator<<(std::ostream &out, const Form &rhs)
{
    out << "Name: " << rhs.getName() << std::endl;
    out << "Signed: " << rhs.getSigned() << std::endl;
    out << "SignGrade: " << rhs.getSignGrade() << std::endl;
    out << "SignGrade: " << rhs.getExecGrade() << std::endl;
    return (out);
}

/**
 * @brief Sign the form and change its status
 *
 * @param rhs The right hand side obj!
 */
void Form::beSigned(const Bureaucrat &rhs)
{
    if (!this->_is_signed)
    {
        if (rhs.getGrade() <= this->_signGrade)
            this->setSigned(true);
        else
            throw Form::GradeTooLowException();
    }
    else
        throw Form::FormAlreadySignedException();
}
