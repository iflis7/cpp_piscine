#pragma once

#include "../../../doctest.hpp"
#include <iostream>
#include <iomanip>

/****************************************/
// template <typename T, size_t N>
// void iter(T (&arr)[N], size_t len, void (*func)(T &))
// {
//     for (size_t i = 0; i < len; ++i)
//     {
//         func(arr[i]);
//     }
// }
template <typename T, typename F>
void iter(T &arr, int len, F func)
{
    for (int i = 0; i < len; i++)
    {
        func(arr[i]);
    }
}

template <typename T>
void print(T &value)
{
    std::cout << value << "*-*";
}

template <typename T>
struct Adder
{
    T value;
    Adder(T value) : value(value) {}
    void operator()(T &val) const
    {
        val += value;
    }
};

/****************************************/
/*
In C++, "array decay to pointer" is a term used to describe the process by which an array
is implicitly converted to a pointer when passed as an argument to a function.

When an array is passed as an argument to a function, it is automatically converted to a pointer
to its first element. This process is known as array decay. The result is that the function can
only manipulate the array through the pointer, and not as an array, which can lead to unexpected
behavior if the function modifies the elements of the array.
*/

/*
The [N] in T(&arr)[N] is not strictly necessary in the sense that the function template would
still work without it. However, including the size of the array N in the function parameter
allows for additional type checking at compile-time. With the size specified, the compiler
can ensure that the correct number of elements are passed to the function and can provide
more informative error messages in the case of a mismatch.

Additionally, including the size of the array N in the function parameter can make the code
more readable and self-documenting, since it clearly states the expected size of the array
that is being passed to the function.

In general, including the size of the array N in the function parameter is a good practice
for array parameters, especially for function templates that should work with arrays of any size.
*/