#include "../include/Bureaucrat.hpp"

int main()
{
    // try
    // {
        Bureaucrat b("John Smith", 100);
        // std::cout << b;
        // operator<<(std::cout, b);
        std::cout << std::endl;
        std::cout << b.getName() << std::endl;
        std::cout << std::endl;
        
        //     b.incrementGrade();
        //     cout << b;
        //     b.decrementGrade();
        //     b.decrementGrade();
        //     cout << b;
        // } catch (Bureaucrat::GradeTooHighException &e) {
        //     cout << "Error: Grade is too high" << endl;
        // } catch (Bureaucrat::GradeTooLowException &e) {
        //     cout << "Error: Grade is too low" << endl;
        // }
        // return 0;
    }

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
