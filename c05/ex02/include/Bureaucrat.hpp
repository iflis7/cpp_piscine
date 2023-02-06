#pragma once
#include <string>
#include <iostream>

class Form;

/**
 * @brief The Bureaucrat Class
 *
 */
class Bureaucrat
{
private:
    std::string const _name;
    unsigned int _grade;

public:
    // Constructors
    Bureaucrat();
    Bureaucrat(std::string const name, unsigned int grade);
    Bureaucrat(const Bureaucrat &other);

    // Assignment operator overload
    Bureaucrat &operator=(const Bureaucrat &rhs);

    // Destructor
    ~Bureaucrat();

    // Getters
    std::string const getName() const;
    unsigned int getGrade() const;

    void incrementGrade();
    void decrementGrade();
    void signForm(Form &form) const;
    void executeForm(Form &form) const;

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
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &rhs);
