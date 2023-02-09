#pragma once

#include "../../doctest.hpp"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <stdexcept>
#include <vector>

/**
 * @brief The span Class
 * 
 */
class Span
{
private:
    unsigned int _N;
    std::vector<int> _v;

public:
    Span(unsigned int N);
    ~Span();

    void addNumber(int x);
    int shortestSpan();
    int longestSpan();
};
