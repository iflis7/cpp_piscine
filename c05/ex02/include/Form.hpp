#pragma once
#include <string>
#include <iostream>

class Bureaucrat;

/**
 * @brief The Form class
 *
 */
class Form
{
private:
    const std::string _name;
    const std::string _target;
    bool _signed;
    const unsigned int _gradeSign;
    const unsigned int _gradeExec;

public:
    // Constructor
    Form(const std::string &name);
    Form(const std::string &name, const std::string &target);
    Form(const std::string &name, const unsigned int gradeSign, const unsigned int gradeExec);
    Form(const std::string &name, const std::string &target, const unsigned int gradeSign, const unsigned int gradeExec);
    Form(const Form &other);

    // Assignment operator overload
    Form &operator=(const Form &rhs);

    // Destructor
    ~Form();

    // Getters
    unsigned int getGradeSign() const;
    unsigned int getGradeExec() const;
    std::string getName() const;
    std::string getTarget() const;
    bool isSigned() const;

    void beSigned(const Bureaucrat &candidate);
    void execute(const Bureaucrat &executor) const;
    virtual void action(const Bureaucrat &executor) const = 0;

    class GradeTooHighException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };

    class FormNotSignedException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };

    class FormAlreadySignedException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };
};

std::ostream &operator<<(std::ostream &o, const Form &rhs);
