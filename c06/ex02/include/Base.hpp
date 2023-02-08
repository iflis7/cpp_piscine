#pragma once

#include <iostream>
#include <cmath>

/**
 * @brief The Base class
 *
 */
class Base
{
public:
    Base() {}
    virtual ~Base() {}
};

Base *generate(void);
void identify(Base *p);
void identify(Base &p);
