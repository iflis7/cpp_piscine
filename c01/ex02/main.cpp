#include <iostream>
#include <string>

int main()
{
    std::string brain = "HI THIS IS BRAIN";

    // Declare a pointer to the string
    std::string *brainPtr = &brain;

    // Declare a reference to the string
    std::string &brainRef = brain;

    // Print the memory addresses
    std::cout << std::endl;
    std::cout << "Memory address of the string variable: " << (void *)&brain << std::endl;
    std::cout << "Memory address held by stringPTR: " << (void *)brainPtr << std::endl;
    std::cout << "Memory address held by stringREF: " << (void *)&brainRef << std::endl;

    // Print the values
    std::cout << std::endl;
    std::cout << "Value of the string variable: " << brain << std::endl;
    std::cout << "Value pointed to by stringPTR: " << *brainPtr << std::endl;
    std::cout << "Value pointed to by stringREF: " << brainRef << std::endl;

    return 0;
}

/*
    char* 'ptr = &s' is not the same as 'char* ptr = s.c_str()'.

The expression &s takes the address of the string object itself,
which is not the same as the memory address of the character array held by the string.


On the other hand, the c_str() member function returns a pointer to the underlying character
array of the string. This is the memory address of the actual string data.

std::cout << "1- Memory address of the string variable: " << (void *)&brain << std::endl;
std::cout << "2- Memory address of the string variable: " << (void *)brain.c_str() << std::endl;
1- Memory address of the string variable: 0x7ffee2fed780
2- Memory address of the string variable: 0x7ffee2fed781


std::cout << "1- Memory address held by stringREF: " << (void *)&brainRef << std::endl;
std::cout << "2- Memory address held by stringREF: " << (void *)brainRef.c_str() << std::endl;
1- Memory address held by stringREF: 0x7ffee2fed780
2- Memory address held by stringREF: 0x7ffee2fed781
*/
