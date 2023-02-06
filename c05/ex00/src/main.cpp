#include "../include/Bureaucrat.hpp"

int test1()
{
    Bureaucrat john("John", 2);
    Bureaucrat jim("Jim", 149);

    try
    {
        std::cout << john << std::endl;
        std::cout << jim << std::endl;
        john.incrementGrade();
        jim.decrementGrade();
        std::cout << john << std::endl;
        std::cout << jim << std::endl;
        john.incrementGrade();
        jim.decrementGrade();
        std::cout << john << std::endl;
        std::cout << jim << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    return (0);
}

int test2()
{
    try
    {
        Bureaucrat b("John Smith", 3);
        // Bureaucrat b("John Smith", 149);
        std::cout << b << std::endl;
        b.incrementGrade();
        b.incrementGrade();
        // b.incrementGrade();
        // std::cout << b << std::endl;
        // b.decrementGrade();
        // b.decrementGrade();
        std::cout << b << std::endl;
    }
    catch (Bureaucrat::GradeTooHighException &e)
    {
        std::cout << "Error: Grade is too high" << std::endl;
    }
    catch (Bureaucrat::GradeTooLowException &e)
    {
        std::cout << "Error: Grade is too low" << std::endl;
    }
    return 0;
}

int main()
{
    // test1();
    test2();
}

/*
// Let’s design an artificial nightmare of offices, corridors, forms, and waiting queues.
// Sounds fun? No? Too bad.
// First, start by the smallest cog in this vast bureaucratic machine: the Bureaucrat.
// A Bureaucrat must have:
// •A constant name.
// •And a grade that ranges from 1 (highest possible grade) to 150 (lowest possible
// grade).
// Any attempt to instantiate a Bureaucrat using an invalid grade must throw an ex-
// ception:
// either a Bureaucrat::GradeTooHighException or a Bureaucrat::GradeTooLowException.
// You will provide getters for both these attributes: getName() and getGrade(). Im-
// plement also two member functions to increment or decrement the bureaucrat grade. If
// the grade is out of range, both of them will throw the same exceptions as the constructor.
// The thrown exceptions must be catchable using try and catch blocks:
// You will implement an overload of the insertion («) operator to print something like
// (without the angle brackets):
// <name>, bureaucrat grade <grade>.
// As usual, turn in some tests to prove everything works as expected.
*/
