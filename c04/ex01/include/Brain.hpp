#ifndef BRAIN_HPP
# define BRAIN_HPP


// Header-protection
# pragma once

// Includes
# include <string>
# include <iostream>

class Brain
{
  private:
    // Private Members
    std::string ideas[100];

  public:
    // Constructors
    Brain();
    Brain(const Brain &copy);

    // Deconstructors
    ~Brain();

    // Overloaded Operators
    Brain &operator=(const Brain &src);

    // // Public Methods
    // std::string getIdea(int index) const;
    // void setIdea(int index, std::string idea);
};


#endif
