#include "../include/Scalar.hpp"

Scalar::Scalar(const std::string str) : _str(str)
{
    if (str.empty())
        throw std::invalid_argument("Invalid input!");
    // this->findType(str);
    // std::cout << "Scalar::isInt:: " << Scalar::isInt(str) << std::endl;
    if(Scalar::isChar(str))
        Scalar::fromChar(str);
    else if(Scalar::isInt(str))
        Scalar::fromInt(str);

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

bool Scalar::isChar(std::string str)
{
    if (str.size() == 1 && std::isprint(str[0]))
        return(true);
    return(false);
}
bool Scalar::isInt(std::string str)
{
    for(int i = 0; i < (int)str.size(); i++)
        {
            if(!std::isdigit(str[i]))
                return false;
            
        }
    return(true);
}


void Scalar::fromChar(std::string str)
{
    // std::cout << "----------- :FromChar: -----------" << std::endl;
    this->setType("Char");
    this->setChar(str[0]);
    this->setInt(str[0]);
    // std::cout << "char: " << this->_char << std::endl;
    // std::cout << "int: " << static_cast<int>(str[0]) << std::endl;
    // std::cout << "float: " << static_cast<float>(str[0]) << ".0f" << std::endl;
    // std::cout << "double: " << static_cast<double>(str[0]) << ".0" << std::endl;
}

void Scalar::fromInt(std::string str)
{
    // std::cout << "----------- :FromInt: -----------" << std::endl;
    // std::cout << "int: " << this->_int << std::endl;
    // std::cout << "float: " << static_cast<float>(this->_int) << ".0f" << std::endl;
    // std::cout << "Malade:: " <<std::isprint(this->_int) << std::endl;
    if (std::isprint(str[0]))
    {
        // std::cout << "char:: " << static_cast<char>(this->_int) << std::endl;
        std::cout << std::endl;
    }
    else
        std::cout << "Non displayable!" << std::endl;
    this->setType("Int");
    this->setInt(this->_int);
    this->setFloat(static_cast<float>(this->_int));
    this->setDouble(static_cast<float>(this->_int));

    // std::cout << "int: " << this->_int << std::endl;
    // std::cout << "float: " << static_cast<float>(this->_int) << ".0f" << std::endl;
    // std::cout << "double: " << static_cast<double>(this->_int) << ".0" << std::endl;
}

void Scalar::findType(std::string input)
{
    if (input.size() == 1)
    {
        if (std::isdigit(input[0]))
        {
            this->setType("int");
            this->setInt(static_cast<int>(strtol(input.c_str(), NULL, 10)));
            // this->_int = static_cast<int>(strtol(input.c_str(), NULL, 10));
            // fromInt();
            // return ("int");
        }
        else if (std::isprint(input[0]))
        {
            this->setType("char");
            this->setChar(static_cast<char>(input[0]));

            // return ("char");
        }
        else
        {
            this->setType("Non displayable");
            throw std::invalid_argument("Non displayable!");
        }
    }
    else
    {
        for (int i = 0; i < (int)input.size(); i++)
        {
            if (!std::isdigit(input[i]) || input[i] != '.')
                throw std::invalid_argument("Invalid input while!");
        }
        if (std::isdigit(input[0]))
        {
            // return ("double");
        }
        else
        {
            // return ("string");
        }
    }
    // return (NULL);
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
