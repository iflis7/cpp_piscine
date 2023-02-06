
// Protect the header
#pragma once

#include <iostream>
class Form;

class Bureaucrat
{
private:
    std::string const _name;
    int _grade;

public:
    Bureaucrat();
    Bureaucrat(const std::string &name);
    Bureaucrat(const std::string &name, int grade);
    Bureaucrat(Bureaucrat const &src);
    Bureaucrat &operator=(const Bureaucrat &rhs);
    ~Bureaucrat();

    void signForm(Form &form) const;

    // void setName(const std::string name);
    const std::string getName() const;

    void setGrade(const int grade);
    int getGrade() const;

    void incrementGrade();
    void decrementGrade();

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
