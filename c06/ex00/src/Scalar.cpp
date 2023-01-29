#include "../include/Scalar.hpp"

Scalar::Scalar(const std::string str) : _str(str), _char('D'), _int(0), _float(0), _double(0)
{
    if (str.empty())
        throw std::invalid_argument("Invalid input!");
    this->findType(str);
    // else if (str.size() == 1)
    // {
    //     if (std::isdigit(str[0]))
    //     {
    //         std::cout << "Fusil: " << static_cast<int>(strtol(str.c_str(), NULL, 10)) << std::endl;
    //         this->_char = static_cast<int>(strtol(str.c_str(), NULL, 10));
    //     }
    //     else
    //     {
    //     }
    // }

    // std::cout << "Scalar Constructor Called!" << std::endl;
}

Scalar::~Scalar()
{
    // std::cout << "Scalar Destructor" << std::endl;
}

const std::string Scalar::getStr() const
{
    return (this->_str);
}

char Scalar::getChar() const
{
    return (this->_char);
}

void Scalar::setChar(char c)
{
    this->_char = c;
}

int Scalar::getInt() const
{
    return (this->_int);
}
void Scalar::setInt(int n)
{
    this->_int = n;
}

float Scalar::getFloat() const
{
    return (this->_float);
}
void Scalar::setFloat(float f)
{
    this->_float = f;
}

double Scalar::getDouble() const
{
    return (this->_double);
}

void Scalar::setDouble(double db)
{
    this->_double = db;
}

const std::string Scalar::getType() const
{
    return (this->_type);
}

void Scalar::setType(std::string type)
{
    this->_type = type;
}

void Scalar::fromChar() const
{
    std::cout << "char: " << this->_char << std::endl;
    std::cout << "int: " << static_cast<int>(this->_char) << std::endl;
    std::cout << "float: " << static_cast<float>(this->_char) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(this->_char) << ".0" << std::endl;
}

void Scalar::fromInt() const
{
    std::cout << "char: ";
    if (std::isprint(this->_int))
        std::cout << static_cast<char>(this->_int) << std::endl;
    else
        std::cout << "Non displayable" << std::endl;
    std::cout << "int: " << this->_int << std::endl;
    std::cout << "float: " << static_cast<float>(this->_int) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(this->_int) << ".0" << std::endl;
}

const std::string Scalar::findType(std::string input) 
{
    if (input.size() == 1)
    {
        if (std::isdigit(input[0]))
        {
            this->setType("int");
            this->_int = static_cast<int>(strtol(input.c_str(), NULL, 10));
            fromInt();
            return ("int");
        }
        else if (std::isprint(input[0]))
        {
            this->setType("char");
            this->setChar(static_cast<char>(input[0]));
            
            return ("char");
        }
        else
        {
            this->setType("Non displayable");
            throw std::invalid_argument("Non displayable!");
        }
    }
    else
    {
        for(int i = 0; i < (int)input.size(); i++)
        {
            if(!std::isdigit(input[i]) || input[i] != '.')
                throw std::invalid_argument("Invalid input while!");
            
        }
        if (std::isdigit(input[0]))
        {
            return ("double");
        }
        else
        {
            return ("string");
        }
    }
    return (NULL);
}

std::ostream &operator<<(std::ostream &out, const Scalar &rhs)
{
    std::cout << std::endl;
    out << "The String: " + rhs.getStr() << std::endl;
    out << "The Char: ";
    out << rhs.getChar() << std::endl;
    out << "The Integer: ";
    out << rhs.getInt() << std::endl;
    out << "The Float: ";
    out << rhs.getFloat() << std::endl;
    out << "The Double: ";
    out << rhs.getDouble() << std::endl;

    out << "The Type: ";
    out << rhs.getType() << std::endl;

    std::cout << std::endl;
    return (out);
}
