#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include "../../../doctest.hpp"
#include <iostream>
#include <iomanip>

/****************************************/
template <typename T>
void swap(T &x, T &y)
{
	T tmp;

	tmp = x;
	x = y;
	y = tmp;
}

template <typename T>
T min(T const &x, T const &y)
{
	return ((x < y) ? x : y);
}

template <typename T>
T max(T const &x, T const &y)
{
	return (x > y ? x : y);
}

template <typename T>
void ft_putvar(T x, T y)
{
	std::cout << "x = " << x << " y = " << y << std::endl;
}

#endif
