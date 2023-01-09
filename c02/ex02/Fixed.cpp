#include "Fixed.hpp"

/**
 * @brief Construct a new Fixed:: Fixed object
 *
 */
Fixed::Fixed(void)
	: _fixedPointValue(0)
{
	// std::cout << "Default constructor called" << std::endl;
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
	// std::cout << "Int constructor called" << std::endl;
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
	// std::cout << "Float constructor called" << std::endl;
	// std::cout << std::endl;
}

/**
 * @brief Construct a new Fixed:: Fixed object
 *
 * @param src The object to copy
 */
Fixed::Fixed(Fixed const &src)
{
	// std::cout << "Copy constructor called" << std::endl;
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
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->_fixedPointValue = rhs.getRawBits();
	std::cout << std::endl;
	return *this;
}

/**
 * @brief Destroy the Fixed:: Fixed object
 *
 */
Fixed::~Fixed(void)
{
	// std::cout << "Destructor called" << std::endl;
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

/**
 * @brief Overload the << operator
 *
 * @param out The output stream
 * @param fixe The Fixed object to output
 * @return std::ostream& The output stream
 */
std::ostream &operator<<(std::ostream &out, const Fixed &fixe)
{
	out << fixe.toFloat();
	return (out);
}

/**
 * @brief Overload  the + and Add two Fixed objects together and return the result as new obj
 *
 * @param rsh The right hand side of the operator
 * @return Fixed The object to return
 */
Fixed Fixed::operator+(const Fixed &rsh) const
{
	Fixed rtn;
	rtn.setRawBits(this->_fixedPointValue + rsh.getRawBits());
	return (rtn);
}

/**
 * @brief Overload the - and Subtract two Fixed objects together and return the result as new obj
 *
 * @param rsh The right hand side of the operator
 * @return Fixed The object to return
 */
Fixed Fixed::operator-(const Fixed &rsh) const
{
	Fixed rtn;
	rtn.setRawBits(this->_fixedPointValue - rsh.getRawBits());
	return (rtn);
}

/**
 * @brief Overload the * and Multiply two Fixed objects together and return the result as new obj
 *
 * @param rsh The right hand side of the operator
 * @return Fixed The object to return
 */
Fixed Fixed::operator*(const Fixed &rsh) const
{
	Fixed rtn;
	cout << "this->_fixedPointValue: " << this->_fixedPointValue << endl;
	cout << "rsh.getRawBits(): " << rsh.getRawBits() << endl;
	std::cout << "this->_fixedPointValue: " << (this->_fixedPointValue * rsh.getRawBits()) << endl;
	// std::cout << "this::: " << ((this->_fixedPointValue * rsh.getRawBits()) >> this->_fractionalBits) << endl;
	rtn.setRawBits((this->_fixedPointValue * rsh.getRawBits()) >> this->_fractionalBits);
	return (rtn);
}

/**
 * @brief Overload the / and Divide two Fixed objects together and return the result as new obj
 *
 * @param rsh The right hand side of the operator
 * @return Fixed The object to return
 */
Fixed Fixed::operator/(const Fixed &rsh) const
{
	Fixed rtn;
	rtn.setRawBits((this->_fixedPointValue << this->_fractionalBits) / rsh.getRawBits());
	return (rtn);
}

/**
 * @brief Overload the ++ and increment the Fixed object
 *
 * @return Fixed& The object to return
 */
Fixed &Fixed::operator++(void)
{
	this->_fixedPointValue++;
	return (*this);
}

/**
 * @brief Overload the -- and decrement the Fixed object
 *
 * @return Fixed& The object to return
 */
Fixed &Fixed::operator--(void)
{
	this->_fixedPointValue--;
	return (*this);
}

/**
 * @brief Overload the ++ and increment the Fixed object
 *
 * @return Fixed The object to return
 */
Fixed Fixed::operator++(int)
{
	Fixed rtn(*this);
	this->_fixedPointValue++;
	return (rtn);
}

/**
 * @brief Overload the -- and decrement the Fixed object
 *
 * @return Fixed The object to return
 */
Fixed Fixed::operator--(int)
{
	Fixed rtn(*this);
	this->_fixedPointValue--;
	return (rtn);
}

/**
 * @brief Overload the > and compare two Fixed objects
 *
 * @param rsh The right hand side of the operator
 * @return true The left hand side is greater than the right hand side
 * @return false The left hand side is not greater than the right hand side
 */
bool Fixed::operator>(const Fixed &rsh) const
{
	return (this->_fixedPointValue > rsh.getRawBits());
}

/**
 * @brief Overload the < and compare two Fixed objects
 *
 * @param rsh The right hand side of the operator
 * @return true The left hand side is less than the right hand side
 * @return false The right hand side is not less than the right hand side
 */
bool Fixed::operator<(const Fixed &rsh) const
{
	return (this->_fixedPointValue < rsh.getRawBits());
}

/**
 * @brief Overload the >= and compare two Fixed objects
 *
 * @param rsh The right hand side of the operator
 * @return true The left hand side is greater than or equal to the right hand side
 * @return false The left hand side is not greater than or equal to the right hand side
 */
bool Fixed::operator>=(const Fixed &rsh) const
{
	return (this->_fixedPointValue >= rsh.getRawBits());
}

/**
 * @brief Overload the <= and compare two Fixed objects
 *
 * @param rsh The right hand side of the operator
 * @return true The left hand side is less than or equal to the right hand side
 * @return false The left hand side is not less than or equal to the right hand side
 */
bool Fixed::operator<=(const Fixed &rsh) const
{
	return (this->_fixedPointValue <= rsh.getRawBits());
}


