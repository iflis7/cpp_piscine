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
	~Fixed(void);

	// Assignment operators
	Fixed &operator=(Fixed const &rhs) const;

	// Arithmetic operators
	Fixed operator+(Fixed const &rhs) const;
	Fixed operator-(Fixed const &rhs) const;
	Fixed operator*(Fixed const &rhs) const;
	Fixed operator/(Fixed const &rhs) const;

	// Comparison operators
	Fixed operator>(Fixed const &rhs) const;
	Fixed operator<(Fixed const &rhs) const;
	Fixed operator>=(Fixed const &rhs) const;
	Fixed operator<=(Fixed const &rhs) const;
	Fixed operator==(Fixed const &rhs) const;
	Fixed operator!=(Fixed const &rhs) const;

	// Incrementations and decrementations
	Fixed &operator++(void);
	Fixed operator++(void);
	Fixed &operator--(void);
	Fixed operator--(void);

	// Min and max overloading
	static Fixed &min(Fixed &val, Fixed &val1);
	const static Fixed &min(const Fixed &val, const Fixed &val1);

	static Fixed &max(Fixed &val, Fixed &val1);
	const static Fixed &max(const Fixed &val, const Fixed &val1);

	/* Setters */
	void setRawBits(int const raw);

	/* Getters */
	int getRawBits(void) const;

	/* Converters */
	float toFloat(void) const;
	int toInt(void) const;
};

Fixed &min(Fixed &val, Fixed &val1);
Fixed &max(Fixed &val, Fixed &val1);

// FUNCTIONS PROTOYPES =========================================================
std::ostream &operator<<(std::ostream &out, const Fixed &fixe);
// =============================================================================

#endif
