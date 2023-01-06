#include "Fixed.hpp"

/**
 * @brief Construct a new Fixed:: Fixed object
 *
 */
Fixed::Fixed(void)
	: _fixedPointValue(0)
{
	std::cout << "Default constructor called" << std::endl;
	std::cout << std::endl;
}

/**
 * @brief Construct a new Fixed:: Fixed object
 *
 * @param src The object to copy
 */
Fixed::Fixed(Fixed const &src)
{
	std::cout << "Copy constructor called" << std::endl;
	std::cout << std::endl;
	*this = src;
}

/**
 * @brief Destroy the Fixed:: Fixed object
 *
 */
Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
	std::cout << std::endl;
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
	std::cout << std::endl;
	return *this;
}

/**
 * @brief Get the Raw Bits object
 *
 * @return int The raw bits
 */
int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;

	return this->_fixedPointValue;
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
