#pragma once
#include <iostream>
#include <iomanip>
#include <stdint.h>
#include <cstddef>

/**
 * @brief Class data
 *
 */
struct Data
{
private:
	std::string _value;
	int _integ;

public:
	Data(void);
	Data(std::string value);
	Data(int integ);
	Data(Data const &other);
	Data &operator=(Data const &rhs);
	~Data(void);

	/* 		Setters and Getters		*/
	std::string getValue(void);
	void setValue(std::string v);
};

/**
 * @brief Serialize the data
 */
uintptr_t serialize(Data *ptr);
Data *deserialize(uintptr_t raw);
