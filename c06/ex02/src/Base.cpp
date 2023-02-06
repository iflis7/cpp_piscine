#include "../include/Base.hpp"
#include "../include/A.hpp"
#include "../include/B.hpp"
#include "../include/C.hpp"

Base *generate()
{
    std::cout << "generate: ";
    int i = rand() % 3;
    if (!i)
    {
        std::cout << "A";
        return new A();
    }
    else if (i == 1)
    {
        std::cout << "B";
        return new B();
    }
    else if (i == 2)
    {
        std::cout << "C";
        return new C();
    }
    else
        return NULL;
}

void identify(Base *p)
{
    std::cout << "Identify by pointer: ";
    if (dynamic_cast<A *>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B *>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C *>(p))
        std::cout << "C" << std::endl;
    else
        std::cerr << "bad cast" << std::endl;
}

void identify(Base &p)
{
    try
    {
        std::cout << "Identify by reference: ";
        if (dynamic_cast<A *>(&p))
            std::cout << "A" << std::endl;
        else if (dynamic_cast<B *>(&p))
            std::cout << "B" << std::endl;
        else if (dynamic_cast<C *>(&p))
            std::cout << "C" << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
}