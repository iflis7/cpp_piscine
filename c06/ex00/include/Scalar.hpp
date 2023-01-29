
#pragma once

#include <iostream>
#include <cmath>

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

    const std::string findType(std::string type);
    const std::string getType() const;
    void setType(std::string input);

    void fromChar() const;
    void fromInt() const;
    void fromFloat() const;
    void fromDouble() const;

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
