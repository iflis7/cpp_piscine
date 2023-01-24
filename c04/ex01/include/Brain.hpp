#ifndef BRAIN_HPP
# define BRAIN_HPP


// Header-protection
# pragma once

// Includes
# include <string>
# include <iostream>

class Brain
{
  protected:
    // Private Members
    std::string _ideas[100];

  public:
    // Constructors
    Brain();
    Brain(const Brain &other);

    // Deconstructors
    ~Brain();

    // Overloaded Operators
    Brain &operator=(const Brain &rhs);

    // // Public Methods
    const std::string getIdea(int index) const;
    // void setIdea(int index, std::string idea);
};


#endif
