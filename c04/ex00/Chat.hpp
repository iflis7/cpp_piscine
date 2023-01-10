#ifndef CHAT_HPP
#define CHAT_HPP

#include "Animal.hpp"

class Chat : public Animal
{
public:
    Chat();
    Chat(std::string type);
    Chat(const Chat &other);
    Chat &operator=(const Chat &other);
    virtual ~Chat();

    virtual void makeSound() const;
};

#endif