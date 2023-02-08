#pragma once

#include "../../../doctest.hpp"
#include <iostream>
#include <vector>
#include <algorithm>

template <typename T>
typename T::iterator easyfind(T &container, int target)
{
    typename T::iterator it;
    for (it = container.begin(); it != container.end(); ++it)
    {
        if (*it == target)
        {
            break;
        }
    }
    if (it == container.end())
    {
        throw std::runtime_error("Value not found");
    }

    return it;
}

// template <typename T>
// typename T::iterator easyfind(T &container, int target)
// {
//     auto it = std::find(container.begin(), container.end(), target);
//     if (it == container.end())
//     {
//         throw std::runtime_error("Value not found");
//     }
//     return it;
// }
