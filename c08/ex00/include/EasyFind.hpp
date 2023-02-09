#pragma once

#include "../../doctest.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

/**
 * @brief Finds the target in the container and returns it
 *
 * @tparam T The template type
 * @param container The Container
 * @param target The target int
 * @return T::iterator the Iterator
 */
template <typename T>
typename T::iterator easyfind(T &container, int target)
{
    typename T::iterator i;
    for (i = container.begin(); i != container.end(); ++i)
    {
        if (*i == target)
        {
            break;
        }
    }
    if (i == container.end())
    {
        throw std::runtime_error("Value not found");
    }

    return i;
}
