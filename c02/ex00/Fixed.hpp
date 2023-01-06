#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

/**
 * @brief Fixed point number class
 *
 */
class Fixed
{
  private:
	int _fixedPointValue;
	static const int _fractionalBits = 8;

  public:
	Fixed(void);
	Fixed(Fixed const &src);
	Fixed &operator=(Fixed const &rhs);
	~Fixed(void);
    
    /* Getters */
	int getRawBits(void) const;
    
    /* Setters */
	void setRawBits(int const raw);
};

#endif
