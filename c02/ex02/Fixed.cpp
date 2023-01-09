#include "Fixed.hpp"

/**
 * @brief Construct a new Fixed:: Fixed object
 *
 */
Fixed::Fixed(void)
	: _fixedPointval1ue(0)
{
	// std::cout << "Default constructor called" << std::endl;
	// std::cout << std::endl;
}

/**
 * @brief Construct a new Fixed:: Fixed object
 *
 * @param val1ue The val1ue to set
 */
Fixed::Fixed(int const val1ue)
	: _fixedPointval1ue(val1ue << this->_fractionalBits)
{
	// std::cout << "Int constructor called" << std::endl;
	// std::cout << std::endl;
}

/**
 * @brief Construct a new Fixed:: Fixed object
 *
 * @param val1ue The val1ue to set
 */
Fixed::Fixed(float const val1ue)
	: _fixedPointval1ue(roundf(val1ue * (1 << this->_fractionalBits)))
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
		this->_fixedPointval1ue = rhs.getRawBits();
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
	this->_fixedPointval1ue = raw;
}

/**
 * @brief Get the Raw Bits object
 *
 * @return int The raw bits
 */
int Fixed::getRawBits(void) const
{
	// std::cout << "getRawBits member function called" << std::endl;

	return this->_fixedPointval1ue;
}

/**
 * @brief Convert the fixed-point val1ue to a float
 *
 * @return float The float val1ue
 */
float Fixed::toFloat(void) const
{
	return (float)this->_fixedPointval1ue / (1 << this->_fractionalBits);
}

/**
 * @brief Convert the fixed-point val1ue to an integer
 *
 * @return int The integer val1ue
 */
int Fixed::toInt(void) const
{
	return this->_fixedPointval1ue >> this->_fractionalBits;
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
	rtn.setRawBits(this->_fixedPointval1ue + rsh.getRawBits());
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
	rtn.setRawBits(this->_fixedPointval1ue - rsh.getRawBits());
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
	rtn.setRawBits((this->_fixedPointval1ue * rsh.getRawBits()) >> this->_fractionalBits);
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
	rtn.setRawBits((this->_fixedPointval1ue << this->_fractionalBits) / rsh.getRawBits());
	return (rtn);
}

/**
 * @brief Overload the ++ and increment the Fixed object
 *
 * @return Fixed& The object to return
 */
Fixed &Fixed::operator++(void)
{
	this->_fixedPointval1ue++;
	return (*this);
}

/**
 * @brief Overload the -- and decrement the Fixed object
 *
 * @return Fixed& The object to return
 */
Fixed &Fixed::operator--(void)
{
	this->_fixedPointval1ue--;
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
	this->_fixedPointval1ue++;
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
	this->_fixedPointval1ue--;
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
	return (this->_fixedPointval1ue > rsh.getRawBits());
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
	return (this->_fixedPointval1ue < rsh.getRawBits());
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
	return (this->_fixedPointval1ue >= rsh.getRawBits());
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
	return (this->_fixedPointval1ue <= rsh.getRawBits());
}

/**
 * @brief Overload the == and compare two Fixed objects
 *
 * @param rsh The right hand side of the operator
 * @return true The objects are equal
 * @return false The objects are not equal
 */
bool Fixed::operator==(const Fixed &rsh) const
{
	return (this->_fixedPointval1ue == rsh.getRawBits());
}

/**
 * @brief Overload the != and compare two Fixed objects
 *
 * @param rsh The right hand side of the operator
 * @return true The objects are not equal
 * @return false The objects are equal
 */
bool Fixed::operator!=(const Fixed &rsh) const
{
	return (this->_fixedPointval1ue != rsh.getRawBits());
}

/**
 * @brief Compares between two Fixed objs and returns the smallet
 *
 * @param val1 The first obj to compare
 * @param val2 The second obj to compare
 * @return Fixed& A refrence to the smallest obj
 */
Fixed &Fixed::min(Fixed &val1, Fixed &val2)
{
	return (val1 < val2 ? val1 : val2);
}

/**
 * @brief Compares between two Fixed objs and returns the smallet
 *
 * @param val1 The first obj to compare
 * @param val2 The second obj to compare
 * @return const Fixed& The (const) refrenced obj to return
 */
const Fixed &Fixed::min(const Fixed &val1, const Fixed &val2)
{
	return (val1 < val2 ? val1 : val2);
}

/**
 * @brief Compares between two Fixed objs and returns the largest
 *
 * @param val1 The first obj to compare
 * @param val2 The second obj to compare
 * @return Fixed& The largest obj
 */
Fixed &Fixed::max(Fixed &val1, Fixed &val2)
{
	return (val1 > val2 ? val1 : val2);
}

/**
 * @brief Compares between two Fixed objs and returns the largest
 *
 * @param val1 The first obj to compare
 * @param val2 The second obj to compare
 * @return const Fixed& The (const) refrenced obj to return
 */
const Fixed &Fixed::max(const Fixed &val1, const Fixed &val2)
{
	return (val1 > val2 ? val1 : val2);
}

/**
 * @brief Compares between two Fixed objs and returns the smallet
 *
 * @param val1 The first obj to compare
 * @param val2 The second obj to compare
 * @return Fixed& A refrence to the smallest obj
 */
Fixed &min(Fixed &val1, Fixed &val2)
{
	return (val1 < val2 ? val1 : val2);
}

/**
 * @brief Compares between two Fixed objs and returns the largest
 *
 * @param val1 The first obj to compare
 * @param val2 The second obj to compare
 * @return Fixed& The largest obj
 */
Fixed &max(Fixed &val1, Fixed &val2)
{
	return (val1 > val2 ? val1 : val2);
}
