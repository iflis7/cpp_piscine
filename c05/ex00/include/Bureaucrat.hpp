
// Protect the header
#pragma once

#include <iostream>

class Bureaucrat
{
private:
    std::string _name;
    int _grade;

public:
    Bureaucrat();
    Bureaucrat(const std::string &name);
    Bureaucrat(const std::string &name, int grade);
    Bureaucrat(Bureaucrat const &src);
    Bureaucrat &operator=(const Bureaucrat &rhs);
    ~Bureaucrat();

    void setName(const std::string name);
    const std::string getName() const;

    void setGrade(const int grade);
    int getGrade() const;

    void incrementGrade();
    void decrementGrade();
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &fixe);

