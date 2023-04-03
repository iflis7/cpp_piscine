#pragma once

#include "../../doctest.hpp"
#include <iostream>
#include <stack>
#include <sstream>
#include <cstdlib>

#define RESET "\033[0m"
#define GREEN "\033[32m"
#define BOLD_GREEN "\033[1m\033[32m"
#define BOLD_YELLOW "\033[1m\033[33m"
#define BOLD_CYAN "\033[1m\033[36m"
#define BOLD_MAGENTA "\033[1m\033[35m"

/**
 * @brief The RPN Class
 *
 */
class RPN
{
private:
    int _result;

public:
    RPN();
    RPN(const std::string rpn);
    RPN &operator=(const RPN &rhs);
    ~RPN();

    int perform_operation(char op, int num1, int num2);
    int evaluate_rpn(std::string rpn);
    void setResult(int value);
    void getResult();
};
