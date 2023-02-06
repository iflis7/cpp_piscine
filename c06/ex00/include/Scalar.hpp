
#pragma once

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
#include <sstream> 
#include <typeinfo> // get data type info
#include <cstdlib>
#include <limits.h>
#include "../../../doctest.hpp"

class Scalar
{
private:
    const std::string _str;
    std::string _type;
    char _char;
    int _int;
    float _float;
    double _double;

public:
    Scalar(const std::string str);
    Scalar(const Scalar &other);
    Scalar &operator=(const Scalar &rhs);
    ~Scalar();

    const std::string getStr() const;
    char getChar() const;
    void setChar(char c);

    int getInt() const;
    void setInt(int n);

    float getFloat() const;
    void setFloat(float f);

    double getDouble() const;
    void setDouble(double db);

    bool isChar(std::string str);
    bool isInt(std::string str);
    bool isFloat(std::string str);
    bool isDouble(std::string str);

    void findType(std::string type);
    const std::string getType() const;
    void setType(std::string input);

    void fromChar(std::string str);
    void fromInt(std::string str);
    void fromFloat(std::string str);
    void fromDouble(std::string str);
    void impossible(std::string str);

    // class InvalidInput : public std::exception
    // {
    // public:
    //     const char *what() const throw()
    //     {
    //         return ("Invalid input");
    //     }
    // };

    // class Impossible : public std::exception
    // {
    // public:
    //     const char *what() const throw()
    //     {
    //         return ("No way!");
    //     }
    // };

    // class NonDisplayable : public std::exception
    // {
    // public:
    //     const char *what() const throw()
    //     {
    //         return ("Non displayable");
    //     }
    // };
};

std::ostream &operator<<(std::ostream &out, const Scalar &rhs);
