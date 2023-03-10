#include "../include/Scalar.hpp"

Scalar::Scalar(const std::string str) : _str(str)
{
    if (str.empty())
        throw std::invalid_argument("Invalid input!");

    if (Scalar::isChar(str))
        Scalar::fromChar(str);
    else if (Scalar::isInt(str))
        Scalar::fromInt(str);
    else if (Scalar::isFloat(str))
        Scalar::fromFloat(str);
    else if (Scalar::isDouble(str))
        Scalar::fromDouble(str);
    else
        Scalar::impossible(str);
    // std::cout << "Scalar Constructor" << std::endl;
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
    if (str.size() == 1 && std::isprint(str[0]) && !std::isdigit(str[0]))
        return (true);
    return (false);
}
bool Scalar::isInt(std::string str)
{
    int j = 0;
    if (!std::isdigit(str[0]) && str[0] != '-')
        return (false);
    for (int i = 0; i < (int)str.size(); i++)
    {
        if (i == 0 && str[i] == '-')
        {
            i++;
            j++;
        }
        if (!std::isdigit(str[i]))
            return false;
    }
    if ((j == 1 && str.size() >= 11 && str[10] > '8') || (j == 0 && str.size() >= 10 && str[9] > '7'))
        throw std::invalid_argument("Invalid input! <INT_MIN or INT_MAX>");
    return (true);
}
bool Scalar::isFloat(std::string str)
{
    if (str[(int)str.size() - 1] != 'f' || !std::isdigit(str[(int)str.size() - 2]) ||
        str[(int)str.size() - 3] != '.')
        return (false);
    for (int i = 0; i < (int)str.size() - 3; i++)
    {
        if (str[i] == '-')
            i++;
        if (!std::isdigit(str[i]))
            return false;
    }
    return (true);
}
bool Scalar::isDouble(std::string str)
{
    if (!std::isdigit(str[(int)str.size() - 1]) || str[(int)str.size() - 2] != '.')
        return (false);
    for (int i = 0; i < (int)str.size() - 2; i++)
    {
        if (str[i] == '-')
            i++;
        if (!std::isdigit(str[i]))
            return false;
    }
    return (true);
}

void Scalar::fromChar(std::string str)
{
    // std::cout << "----------- :FromChar: -----------" << std::endl;
    this->setType("Char");
    this->setChar(str[0]);
    this->setInt(static_cast<int>(str[0]));
    this->setFloat(static_cast<float>(str[0]));
    this->setDouble(static_cast<double>(str[0]));
}
void Scalar::fromInt(std::string str)
{
    // std::cout << "----------- :FromInt: -----------" << std::endl;
    int nb = atol(str.c_str());
    this->setType("Int");
    this->setInt(nb);
    if (this->_int < 127 && this->_int > 31)
        this->setChar(static_cast<char>(this->_int));
    else
        this->setChar(0);
    this->setFloat(static_cast<float>(this->_int));
    this->setDouble(static_cast<float>(this->_int));
}
void Scalar::fromFloat(std::string str)
{
    // std::cout << "----------- :FromFloat: -----------" << std::endl;
    this->setType("Float");
    this->setInt(static_cast<int>(atof(str.c_str())));
    if (std::isprint(this->_int))
        this->setChar(static_cast<char>(this->_int));
    else
        this->setChar(0);
    this->setFloat(static_cast<float>(atof(str.c_str())));
    this->setDouble(static_cast<double>(atof(str.c_str())));
}
void Scalar::fromDouble(std::string str)
{
    // std::cout << "----------- :FromDouble: -----------" << std::endl;
    this->setType("Double");
    this->setInt(static_cast<int>(atof(str.c_str())));
    if (std::isprint(this->_int))
        this->setChar(static_cast<char>(this->_int));
    else
        this->setChar(0);
    this->setFloat(static_cast<float>(atof(str.c_str())));
    this->setDouble(static_cast<double>(atof(str.c_str())));
}

void Scalar::impossible(std::string str)
{
    if (str == "-inff" || str == "-inf")
    {
        this->setFloat(-INFINITY); // Use the macro Infinity to assogn the value
        this->setDouble(-INFINITY);
        this->setType("Impossible");
    }
    else if (str == "+inff" || str == "+inf")
    {

        this->setFloat(INFINITY);
        this->setDouble(INFINITY);
        this->setType("Impossible");
    }
    else if (str == "nan" || str == "nanf")
    {

        this->setFloat(NAN);
        this->setDouble(NAN);
        this->setType("Impossible");
    }
    else
        throw std::invalid_argument("Invalid input!");
}

std::ostream &operator<<(std::ostream &out, const Scalar &rhs)
{
    std::cout << std::endl;
    out << "The String:     " << rhs.getStr() << std::endl;
    out << "The Type:       " << rhs.getType() << std::endl;
    out << std::endl
        << std::right << std::setw(30) << "  *-*-*-*-*-*-*-*-*-*  " << std::endl
        << std::endl;

    if (rhs.getType() == "Impossible")
    {
        out << "The Char:       impossible" << std::endl;
        out << "The Int:        impossible" << std::endl;
    }
    else
    {
        out << "The Char:       |";
        if (rhs.getChar())
            out << rhs.getChar() << "|" <<std::endl;
        else
            out << "Non displayable!" << std::endl;

        out << "The Integer:    " << rhs.getInt() << std::endl;
    }
    out << "The Float:      ";
    std::stringstream stream;
    stream << std::fixed << std::setprecision(1) << rhs.getFloat() << "f";
    std::cout << stream.str() << std::endl;

    out << "The Double:     ";
    std::cout << std::fixed << std::setprecision(1) << rhs.getDouble() << std::endl;

    return (out);
}
