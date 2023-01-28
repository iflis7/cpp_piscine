#include "../include/Form.hpp"
#include "../include/Bureaucrat.hpp"

/**
 * @brief Construct a new Form:: Form object
 *
 * @param name The name of the form
 */
Form::Form(const std::string &name)
    : _name(name), _target(""), _signed(false), _gradeSign(1), _gradeExec(1)
{
}

/**
 * @brief Construct a new Form:: Form object
 *
 * @param name The name of the form
 * @param target Assigned to?
 */
Form::Form(const std::string &name, const std::string &target)
    : _name(name), _target(target), _signed(false), _gradeSign(1), _gradeExec(1)
{
}

/**
 * @brief Construct a new Form:: Form object
 *
 * @param name The name of the Form
 * @param gradeSign  The sign Grade
 * @param gradeExec  The exec Grade
 */
Form::Form(const std::string &name, const unsigned int gradeSign, const unsigned int gradeExec)
    : _name(name), _target(""), _signed(false), _gradeSign(gradeSign), _gradeExec(gradeExec)
{
    if (gradeSign < 1 || gradeExec < 1)
        throw Form::GradeTooHighException();
    else if (gradeSign > 150 || gradeExec > 150)
        throw Form::GradeTooLowException();
}

/**
 * @brief Construct a new Form:: Form object
 *
 * @param name The name of the form
 * @param target  The Target of the form
 * @param gradeSign  The Sign Grade
 * @param gradeExec The Exec Grade
 */
Form::Form(const std::string &name, const std::string &target, const unsigned int gradeSign, const unsigned int gradeExec)
    : _name(name), _target(target), _signed(false), _gradeSign(gradeSign), _gradeExec(gradeExec)
{
    if (gradeSign < 1 || gradeExec < 1)
        throw Form::GradeTooHighException();
    else if (gradeSign > 150 || gradeExec > 150)
        throw Form::GradeTooLowException();
}

/**
 * @brief Construct a new Form:: Form object
 *
 * @param other the RHS obj
 */
Form::Form(const Form &other)
    : _name(other._name), _signed(other._signed), _gradeSign(other._gradeSign), _gradeExec(other._gradeExec)
{
    std::cout << "Copy Constructor Called!" << std::endl;
}

/**
 * @brief Overloading the = operator
 *
 * @param rhs The rhs obj
 * @return Form& The returned obj
 */
Form &Form::operator=(const Form &rhs)
{
    (void)rhs;
    return *this;
}

/**
 * @brief Destroy the Form:: Form object
 *
 */
Form::~Form()
{
}

/**
 * @brief Get the _gradeSign
 *
 * @return unsigned int The _gradeSign
 */
unsigned int Form::getGradeSign() const
{
    return this->_gradeSign;
}

/**
 * @brief Get the Exec grade
 *
 * @return unsigned int the Exec grade
 */
unsigned int Form::getGradeExec() const
{
    return this->_gradeExec;
}

/**
 * @brief get The Name
 *
 * @return std::string The Name
 */
std::string Form::getName() const
{
    return this->_name;
}

/**
 * @brief get the Target
 *
 * @return std::string The target name
 */
std::string Form::getTarget() const
{
    return this->_target;
}

/**
 * @brief get the Status
 *
 * @return true if True
 * @return false otherwise
 */
bool Form::isSigned() const
{
    return this->_signed;
}

/**
 * @brief Sign the status
 *
 * @param candidate For wich candidate
 */
void Form::beSigned(const Bureaucrat &candidate)
{
    if (!this->_signed)
    {
        if (candidate.getGrade() <= this->_gradeSign)
            this->_signed = true;
        else
            throw Form::GradeTooLowException();
    }
    else
        throw Form::FormAlreadySignedException();
}

/**
 * @brief Execute a
 *
 * @param executor
 */
void Form::execute(const Bureaucrat &executor) const
{
    if (!this->isSigned())
        throw Form::FormNotSignedException();
    if (executor.getGrade() > this->getGradeExec())
        throw Form::GradeTooLowException();
    std::cout << "Form Signed" << std::endl;
}

/**
 * @brief Overloading the << operator to print out
 *
 * @param o The out std obj
 * @param rhs The rhs obj to print
 * @return std::ostream& The new overlaoded obj
 */
std::ostream &operator<<(std::ostream &o, const Form &rhs)
{
    o << "Form " << rhs.getName() << ": ";
    o << "{signed: " << std::boolalpha << rhs.isSigned() << ", gradeSign: " << rhs.getGradeSign() << ", gradeExec: " << rhs.getGradeExec() << "}";
    return o;
}
