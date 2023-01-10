#include "Chat.hpp"

/**
 * @brief Construct a new Chat:: Chat object
 *
 */
Chat::Chat()
{
    std::cout << "Chat constructor called" << std::endl;
}

/**
 * @brief Construct a new Chat:: Chat object
 *
 * @param type The type pf Animal
 */
Chat::Chat(std::string type) : Animal(type)
{
    std::cout << "Chat constructor called" << std::endl;
}

/**
 * @brief Construct a new Chat:: Chat object
 *
 * @param other
 */
Chat::Chat(const Chat &other)
{
    std::cout << "Chat copy constructor called" << std::endl;
    *this = other;
}

/**
 * @brief Construct by assignment the object Overload
 *
 * @param other The rsh
 * @return Chat& The obj returned
 */
Chat &Chat::operator=(const Chat &other)
{
    std::cout << "Chat Assignation operator called" << std::endl;
    this->_type = other._type;
    return (*this);
}

/**
 * @brief Destroy the Chat:: Chat object
 *
 */
Chat::~Chat()
{
    std::cout << "Chat destructor called" << std::endl;
}

/**
 * @brief Make sound method
 *
 */
void Chat::makeSound() const
{
    std::cout << "Miaou" << std::endl;
}
