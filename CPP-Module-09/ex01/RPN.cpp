/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalungo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 17:07:30 by fmalungo          #+#    #+#             */
/*   Updated: 2025/08/14 17:07:32 by fmalungo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(std::string expression): _expression(expression){}

RPN::~RPN() {}

RPN::RPN(const RPN& original) { *this = original; }

RPN& RPN::operator=(const RPN& original)
{ 
    if (this != &original)
        this->_stack = original._stack;
    return *this; 
}

bool RPN::isAnOperator(char c) { return (c == '*' || c == '/' || c == '+' || c == '-'); }

int RPN::makeOperation(int a, int b, char sign)
{
    if (sign == '*')
        return a * b;
    else if (sign == '/')
    {
        if (a == 0)
            throw std::runtime_error("Error");
        return a / b;
    }
    else if (sign == '+')
        return a + b;
    return a - b;
}

void RPN::handleExpression()
{
    if (_expression.empty())
        throw std::runtime_error("Error");
    size_t i = -1;
    while (_expression[++i])
    {
        if (!std::isspace(_expression[i]))
            return ;
    }
    throw std::runtime_error("Error");
}

void RPN::processRPN()
{
    int val1;
    int val2;
    char elemet;

    std::stringstream ss(_expression);

    handleExpression();
    while (ss >> elemet)
    {
        if (ss && std::isdigit(elemet))
        {
            _stack.push(static_cast<int> (elemet) - 48);
        }
        else if (isAnOperator(elemet) && _stack.size() != 1 && !_stack.empty())
        {
            val2 = _stack.top();
            _stack.pop();
            val1 = _stack.top();
            _stack.pop();
            _stack.push(makeOperation(val1, val2, elemet));
        }
        else
            throw std::runtime_error("Error");
    }
    std::cout << _stack.top() << std::endl;
}
