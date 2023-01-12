#include "Fixed.hpp"

/**
 * @brief Construct a new Fixed:: Fixed object
 *
 */
Fixed::Fixed(void)
	: _fixedPointValue(0)
{
	std::cout << "Default constructor called" << std::endl;
	// std::cout << std::endl;
}

/**
 * @brief Construct a new Fixed:: Fixed object
 *
 * @param value The value to set
 */
Fixed::Fixed(int const value)
	: _fixedPointValue(value << this->_fractionalBits)
{
	std::cout << "Int constructor called" << std::endl;
	// std::cout << std::endl;
}

/**
 * @brief Construct a new Fixed:: Fixed object
 *
 * @param value The value to set
 */
Fixed::Fixed(float const value)
	: _fixedPointValue(roundf(value * (1 << this->_fractionalBits)))
{
	std::cout << "Float constructor called" << std::endl;
	// std::cout << std::endl;
}

/**
 * @brief Construct a new Fixed:: Fixed object
 *
 * @param src The object to copy
 */
Fixed::Fixed(Fixed const &src)
{
	std::cout << "Copy constructor called" << std::endl;
	// std::cout << std::endl;
	*this = src;
}

/**
 * @brief Copy assignment operator
 *
 * @param rhs The object to copy
 * @return Fixed&
 */
Fixed &Fixed::operator=(Fixed const &rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_fixedPointValue = rhs.getRawBits();
	// std::cout << std::endl;
	return *this;
}

/**
 * @brief Destroy the Fixed:: Fixed object
 *
 */
Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
	// std::cout << std::endl;
}

/**
 * @brief Set the Raw Bits object
 *
 * @param raw The raw bits
 */
void Fixed::setRawBits(int const raw)
{
	this->_fixedPointValue = raw;
}

/**
 * @brief Get the Raw Bits object
 *
 * @return int The raw bits
 */
int Fixed::getRawBits(void) const
{
	// std::cout << "getRawBits member function called" << std::endl;

	return this->_fixedPointValue;
}

/**
 * @brief Convert the fixed-point value to a float
 *
 * @return float The float value
 */
float Fixed::toFloat(void) const
{
	return (float)this->_fixedPointValue / (1 << this->_fractionalBits);
}

/**
 * @brief Convert the fixed-point value to an integer
 *
 * @return int The integer value
 */
int Fixed::toInt(void) const
{
	return this->_fixedPointValue >> this->_fractionalBits;
}

// FUNCTIONS SUP ===============================================================

std::ostream &operator<<(std::ostream &out, const Fixed &fixe)
{
	out << fixe.toFloat();
	return (out);
}

/*
Shifting the bits of the integer value to the left by the number of fractional bits is a way
to convert the integer value to the corresponding fixed-point value.

In a fixed-point number system, the position of the binary point
(the point that separates the integer part from the fractional part) is fixed.
In this case, the number of fractional bits is fixed at 8, which means that the binary point
is positioned 8 bits to the right of the least significant bit (LSB).

By shifting the bits of the integer value to the left by the number of fractional bits,
the integer value is converted to a fixed-point value with the binary point positioned
at the correct location. For example, if the integer value is 3 (which is 00000011 in binary),
 then shifting the bits to the left by 8 places would give a fixed-point value of 768
 (which is 0000001100000000 in binary).

This is useful because it allows the integer value to be stored and manipulated as a fixed-point
number, with the fractional part being represented by the bits to the right of the binary point.
 This can be useful for tasks such as performing accurate decimal arithmetic, or representing
 non-integer values with a limited number of bits.
*/

/*
In a fixed-point number system, the number of bits is determined by the size of the data type used
to represent the value. For example, if the fixed-point value is represented using a short data type,
 which is typically 16 bits on most systems, then the number of bits in the fixed-point value would be 16.

| Data Type | Number of Bits |
|-----------|----------------|
| `char`    | 8              |
| `short`   | 16             |
| `int`     | 32             |
| `long`    | 32 or 64       |
| `float`   | 32             |
| `double`  | 64             |

*/
