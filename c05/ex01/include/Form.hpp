
#pragma once

#include <iostream>

class Bureaucrat;

class Form
{
private:
    std::string _name;
    bool _is_signed = false;
    int _signGrade;
    int _execGrade;

public:
    Form();
    Form(const std::string &name, int signGrade, int execGrade);
    Form(const Form &rhs);
    Form &operator=(const Form &rhs);
    ~Form();

    class GradeTooHighException : public std::exception
    {
    public:
        const char *what() const throw()
        {
            return ("Grade too high");
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

    void setName(const std::string _is_signed);
    const std::string getName() const;

    void setName(const std::string _sign_grade);
    const std::string getName() const;

    void setGrade(const int _exec_grade);
    int getGrade() const;

    void incrementGrade();
    void decrementGrade();
};

std::ostream &operator<<(std::ostream &out, const Form &rhs);
