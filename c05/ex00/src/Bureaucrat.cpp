#include "../include/Bureaucrat.hpp"

/**
 * @brief Construct a new Bureaucrat:: Bureaucrat object
 *
 */
Bureaucrat::Bureaucrat()
{
    std::cout << "Bureaucrat Created by Default!" << std::endl;
}

/**
 * @brief Construct a new Bureaucrat:: Bureaucrat object
 *
 * @param name The name
 */
Bureaucrat::Bureaucrat(const std::string &name) : _name(name)
{
}

/**
 * @brief Construct a new Bureaucrat:: Bureaucrat object
 *
 * @param name The name of
 * @param grade The grade to initilized at
 */
Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name), _grade(grade)
{
}

/**
 * @brief Construct a new Bureaucrat:: Bureaucrat object
 *
 * @param src
 */
Bureaucrat::Bureaucrat(Bureaucrat const &src)
{
    *this = src;
    // return this;
}

// /**
//  * @brief Construct a new Bureaucrat:: Bureaucrat object
//  *
//  * @param other
//  */
// Bureaucrat::Bureaucrat(const std::string &other)
// {
//     *this = other;
//     // return *this;
// }

/**
 * @brief Overload = operator
 *
 * @param rhs The right hand side obj
 * @return Bureaucrat&  The oj to return
 */
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rhs)
{
    if (this != &rhs)
    {
        this->_name = rhs._name;
        this->_grade = rhs._grade;
    }
    return *this;
}

// void operator<<(std::ostream &COUT, Bureaucrat &bureaucrat)
// {
//     COUT << bureaucrat.getName();
// }

/**
 * @brief Destroy the Bureaucrat:: Bureaucrat object
 *
 */
Bureaucrat::~Bureaucrat(){

};

/**
 * @brief Set the Name attribute
 *
 * @param name The name of the Bureaucrat
 */
void Bureaucrat::setName(const std::string name)
{
    this->_name = name;
}

/**
 * @brief Set the Grade attribute
 *
 * @param grade
 */
void Bureaucrat::setGrade(const int grade)
{
    this->_grade = grade;
}

/**
 * @brief Get the name
 *
 * @return const std::string
 */
const std::string Bureaucrat::getName() const
{
    return (this->_name);
};

int Bureaucrat::getGrade() const
{
    return (this->_grade);
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat)
{
    out << bureaucrat.getName();
    out << bureaucrat.getGrade();
    // operator<<(out, bureaucrat);
    return (out);
};
