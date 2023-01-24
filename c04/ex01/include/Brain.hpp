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
<<<<<<< HEAD
    const std::string getIdea(int index) const;
=======
    // std::string getIdea(int index) const;
>>>>>>> ad1befb088b1786556af918d454ee3a8ca9d1dfc
    // void setIdea(int index, std::string idea);
};


#endif
