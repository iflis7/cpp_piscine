#pragma once

#include "../include/Form.hpp"
#include <string>

/**
 * @brief The intern class
 *
 */
class Intern
{
public:
    // Constructor
    Intern();

    // Destructor
    ~Intern();

    class InvalidFormException : public std::exception
    {
    public:
        const char *what() const throw()
        {
            return ("invalid form type");
        }
    };

    Form *makeForm(const std::string &formName, const std::string &target) const;
};
