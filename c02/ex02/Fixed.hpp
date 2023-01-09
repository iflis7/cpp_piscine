#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

using namespace std;

/**
 * @brief Fixed point number class
 *
 */
class Fixed
{
private:
	int _fixedPointvalue;
	static const int _fractionalBits = 8;

public:
	Fixed(void);
	Fixed(const int val1ue);
	Fixed(const float val1ue);
	Fixed(Fixed const &src);
	~Fixed(void);

	// Assignment operators
	Fixed &operator=(Fixed const &rhs);

	// Arithmetic operators
	Fixed operator+(Fixed const &rhs) const;
	Fixed operator-(Fixed const &rhs) const;
	Fixed operator*(Fixed const &rhs) const;
	Fixed operator/(Fixed const &rhs) const;

	// Comparison operators
	bool operator>(Fixed const &rhs) const;
	bool operator<(Fixed const &rhs) const;
	bool operator>=(Fixed const &rhs) const;
	bool operator<=(Fixed const &rhs) const;
	bool operator==(Fixed const &rhs) const;
	bool operator!=(Fixed const &rhs) const;

	// Incrementations and decrementations
	Fixed &operator++(void);
	Fixed operator++(int);
	Fixed &operator--(void);
	Fixed operator--(int);

	// Min and max overloading
	static Fixed &min(Fixed &val1, Fixed &val2);
	const static Fixed &min(const Fixed &val1, const Fixed &val2);

	static Fixed &max(Fixed &val1, Fixed &val2);
	const static Fixed &max(const Fixed &val1, const Fixed &val2);

	/* Setters */
	void setRawBits(int const raw);

	/* Getters */
	int getRawBits(void) const;

	/* Converters */
	float toFloat(void) const;
	int toInt(void) const;
};

// FUNCTIONS PROTOYPES =========================================================
Fixed &min(Fixed &val1, Fixed &val2);
Fixed &max(Fixed &val1, Fixed &val2);
std::ostream &operator<<(std::ostream &out, const Fixed &fixe);

#endif
