#pragma once
#include <iostream>
#include <iomanip>

/**
 * @brief Class data
 *
 */
struct Data
{
private:
	std::string _value;

public:
	Data(void);
	Data(std::string value);
	Data(Data const &other);
	Data &operator=(Data const &rhs);
	~Data(void);

	/* 		Setters and Getters		*/
	std::string getValue(void);
	void setValue(std::string v);
};
