#include "../include/Data.hpp"

/**
 * @brief Prints the string provided
 *
 * @param s
 */
void putStr(std::string str)
{
    std::cout << str << std::endl;
}

/**
 * @brief Construct a new Data:: Data object
 *
 */
Data::Data() : _value("NoValue")
{
    putStr("Data Default Constructor!");
}

/**
 * @brief Construct a new Data:: Data object
 *
 * @param value The value to set
 */
Data::Data(std::string value) : _value(value)
{
    putStr("Initialize The Constructor!");
}

/**
 * @brief Construct a new Data:: Data object
 *
 * @param value The value to set
 */
Data::Data(int integ) : _integ(integ)
{
    putStr("Initialize <Int> The Constructor!");
}

/**
 * @brief Construct a new Data:: Data object
 *
 * @param other the rhs obj
 */
Data::Data(Data const &other)
{
    putStr("Data copy Constructor ");
    this->_value = other._value;
}

/**
 * @brief Overloading the = op
 *
 * @param rhs The rhs object to use
 * @return Data& the return class ptr
 */
Data &Data::operator=(Data const &rhs)
{
    this->_value = rhs._value;
    putStr("Data Assignation Constructor!");
    return (*this);
}

/**
 * @brief Destroy the Data:: Data object
 *
 */
Data::~Data()
{
    putStr("Data Deconstructor! ");
}

/**
 * @brief Get the Value object
 *
 * @return std::string
 */
std::string Data::getValue(void)
{
    return (this->_value);
}

/**
 * @brief Set the Value object
 *
 * @param value
 */
void Data::setValue(std::string value)
{
    this->_value = value;
}

/**
 * @brief Serialize the given ptr
 *
 * @param ptr The ptr to Serialize
 * @return uintptr_t The number returned
 */
uintptr_t serialize(Data *ptr)
{
    uintptr_t r;

    r = reinterpret_cast<uintptr_t>(ptr);
    return (r);
};

/**
 * @brief Deserialize the given number
 *
 * @return uintptr_t The number to convert into ptr
 * @param ptr The ptr to return
 */
Data *deserialize(uintptr_t raw)
{
    Data *ptr;
    ptr = reinterpret_cast<Data *>(raw);
    return (ptr);
};
