#include "../include/RPN.hpp"

RPN::RPN(const std::string rpn)
{
    if (!rpn.empty())
        this->_result = evaluate_rpn(rpn);
}

RPN::RPN()
{
}

RPN &RPN::operator=(const RPN &rhs)
{
    if (this != &rhs)
    {
    }
    return *this;
}

RPN::~RPN()
{
}

void RPN::setResult(int value)
{
    this->_result = value;
}

void RPN::getResult()
{
    std::cout << BOLD_YELLOW << "Result: " << RESET << this->_result << std::endl;
}

int RPN::perform_operation(char op, int num1, int num2)
{
    switch (op)
    {
        case '+':
            return num1 + num2;
        case '-':
            return num1 - num2;
        case '*':
            return num1 * num2;
        case '/':
            if (num2 == 0)
                throw std::invalid_argument("Division by zero");
            return num1 / num2;
        default:
            throw std::invalid_argument("Error: Invalid operator");
    }
}

int RPN::evaluate_rpn(std::string rpn)
{
    std::stack<int> stack;
    std::stringstream ss(rpn);
    std::string token;

    while (getline(ss, token, ' '))
    {
        if (token.length() == 1 && !isdigit(token[0]))
        {
            if (stack.size() < 2)
                throw std::invalid_argument("Error: Insufficient operands");
            int num2 = stack.top();
            stack.pop();
            int num1 = stack.top();
            stack.pop();
            int result = perform_operation(token[0], num1, num2);
            stack.push(result);
        }
        else if (isdigit(token[0]))
            stack.push(atoi(token.c_str()));
        else
            throw std::invalid_argument("Error: Invalid token");
    }

    if (stack.size() != 1)
        throw std::invalid_argument("Error: Invalid expression");

    return stack.top();
};
