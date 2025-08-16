/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalungo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 17:07:24 by fmalungo          #+#    #+#             */
/*   Updated: 2025/08/14 17:07:25 by fmalungo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <stack>
#include <string>
#include <sstream>
#include <iostream>
#include <stdexcept>

class RPN
{
    private:
        std::stack<int> _stack;
        std::string _expression;
        
        bool isAnOperator(char c);
        int makeOperation(int a, int b, char sign);

    public:
        RPN();
        RPN(std::string expression);
        ~RPN();
        RPN(const RPN& original);
        RPN& operator=(const RPN& original);

        void handleExpression();
        void processRPN();
};

#endif
