#include "../include/Base.hpp"

int main()
{
    srand(time(NULL));
    Base *ptr = generate();
    std::cout << " (pointer)" << std::endl;
    Base *tmp = generate();
    Base &ref = *tmp;
    std::cout << " (reference)" << std::endl;

    identify(ptr);
    identify(ref);

    delete ptr;
    delete tmp;
}
