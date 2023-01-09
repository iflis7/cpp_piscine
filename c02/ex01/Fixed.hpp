#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

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
	Fixed(const int value);
	Fixed(const float value);
	Fixed(Fixed const &src);
	Fixed &operator=(Fixed const &rhs);
	~Fixed(void);

	/* Getters */
	void setRawBits(int const raw);

	/* Setters */
	int getRawBits(void) const;

	/* Converters */
	float toFloat(void) const;
	int toInt(void) const;
};

// FUNCTIONS PROTOYPES =========================================================
std::ostream &operator<<(std::ostream &out, const Fixed &fixe);
// =============================================================================

#endif
