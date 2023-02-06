#pragma once

#include "../include/Form.hpp"
#include <string>

// /**
//  * @brief The intern class
//  *
//  */
// class Intern
// {
// public:
//     // Constructor
//     Intern();
//     // Destructor
//     ~Intern();
//     class InvalidFormException : public std::exception
//     {
//     public:
//         const char *what() const throw()
//         {
//             return ("invalid form type");
//         }
//     };
//     Form *makeForm(const std::string &formName, const std::string &target) const;
// };


class Intern {

public:
	Intern(void);
	Intern(Intern const & src);
	Intern & operator=(Intern const & rhs);
	~Intern(void);

	Form  *makeForm(std::string, std::string);
	int		checkForm(std::string);

	/* nested classes */
	class FormDoesntExist : public std::exception {
		public:
		virtual const char* what() const throw();
	};
};
