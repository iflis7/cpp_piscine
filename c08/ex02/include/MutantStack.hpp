#pragma once

#include "../../doctest.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <algorithm>

// template <typename T>
// typename T::iterator easyfind(T &container, int target)
// {
//     typename T::iterator it;
//     for (it = container.begin(); it != container.end(); ++it)
//     {
//         if (*it == target)
//         {
//             break;
//         }
//     }
//     if (it == container.end())
//     {
//         throw std::runtime_error("Value not found");
//     }
//     return it;
// }

template <typename T>
class MutantStack : public std::stack<T>
{
public:
    MutantStack() : std::stack<T>() {}
    MutantStack(const MutantStack &other) : std::stack<T>(other) {}
    MutantStack &operator=(const MutantStack &rhs)
    {
        if (this == &rhs)
            return *this;
        std::stack<T>::operator=(rhs);
        return *this;
    }
    ~MutantStack() {}

    typedef typename std::stack<T>::container_type::iterator iterator;

    iterator begin()
    {
        return std::stack<T>::c.begin();
    }
    iterator end()
    {
        return std::stack<T>::c.end();
    }
};
