#pragma once

#include <exception>
#include <iostream>
#include <cmath>
#include "../../../doctest.hpp"

template <typename T>
class Array
{
private:
    unsigned int _size;
    T *_array;

public:
    Array() : _size(0), _array(new T[0]){};
    Array(unsigned int size) : _size(size), _array(new T[size]){};
    Array(const Array& other)
	{
		this->_size = other._size;
		this->_array = new T[other._size];
		for (unsigned int i = 0; i < other._size; i++)
			this->_array[i] = other._array[i];
	}
    ~Array()
    {
        delete[] _array;
    };

    T &operator[](size_t val)
    {
        if (val >= this->_size)
            throw Array::OutOfRangeException();
        return this->_array[val];
    }

    Array &operator=(const Array &rhs)
    {
        if (this == &rhs)
            return *this;

        this->_size = rhs._size;
        this->_array = new T[rhs._size];
        for (unsigned int i = 0; i < rhs._size; i++)
            this->_array[i] = rhs._array[i];
        return *this;
    };

    size_t getSize() const { return this->_size; };
    void printArr() const
    {
        std::cout << "Array: ";
        for (int i = 0; i < (int)this->_size; i++)
            std::cout << this->_array[i] << ' ';
        std::cout << std::endl;
    };

    class OutOfRangeException : public std::exception
	{
	public:
		const char* what() const throw()
		{
			return ("Element is out of range of array");
		}
	};
};
