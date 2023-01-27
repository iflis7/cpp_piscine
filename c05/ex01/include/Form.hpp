
#pragma once

#include <iostream>

class Bureaucrat;

class Form
{
private:
    std::string _name;
    bool _is_signed;
    int _signGrade;
    int _execGrade;

public:
    Form();
    Form(const std::string name);
    Form(const std::string name, int signGrade, int execGrade);
    Form(const Form &rhs);
    Form &operator=(const Form &rhs);
    ~Form();

    class GradeTooHighException : public std::exception
    {
    public:
        const char *what() const throw()
        {
            return ("Exception: Grade too high!");
        }
    };

    class GradeTooLowException : public std::exception
    {
    public:
        const char *what() const throw()
        {
            return ("Grade too low");
        }
    };

    void beSigned(const Bureaucrat &rhs) const;

    void setName(const std::string name);
    const std::string getName() const;

    void setSigned(bool isSigned);
    bool getSigned() const;

    void setSignGrade(const int signGrade);
    int getSignGrade() const;

    void setExecGrade(const int execGrade);
    int getExecGrade() const;

    void incrementGrade();
    void decrementGrade();
};

std::ostream &operator<<(std::ostream &out, const Form &rhs);
