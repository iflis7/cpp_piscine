#include "../include/Span.hpp"

/**
 * @brief Construct a new Span:: Span object
 *
 * @param N The size of the vector
 */
Span::Span(unsigned int N) : _v()
{
    this->_N = N;
};

/**
 * @brief Destroy the Span:: Span object
 *
 */
Span::~Span(){};

/**
 * @brief Add the number to the vector
 *
 * @param x The number to add
 */
void Span::addNumber(int x)
{
    if (_v.size() == _N)
    {
        throw std::runtime_error("Cannot add more numbers");
    }
    _v.push_back(x);
}

/**
 * @brief Finds the shortest Span and returns it
 *
 * @return int the shortest Span to return
 */
int Span::shortestSpan()
{
    if (_v.size() <= 1)
    {
        throw std::runtime_error("No span found");
    }
    std::vector<int> diff;
    std::sort(_v.begin(), _v.end());
    for (unsigned int i = 1; i < _v.size(); ++i)
    {
        diff.push_back(_v[i] - _v[i - 1]);
    }
    return (*std::min_element(diff.begin(), diff.end()));
}

/**
 * @brief Finds the longest Span and returns it
 *
 * @return int the longest Span to return
 */
int Span::longestSpan()
{
    if (_v.size() <= 1)
    {
        throw std::runtime_error("No span found");
    }
    return (*std::max_element(_v.begin(), _v.end()) - *std::min_element(_v.begin(), _v.end()));
}
