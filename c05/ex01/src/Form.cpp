#include "../include/Form.hpp"

Form::Form(const std::string &name, int signGrade, int execGrade) : _name(name), _signGrade(signGrade),
    _execGrade(execGrade)
{
    std::cout << "Default Constructor Called On Form" << std::endl;
}

