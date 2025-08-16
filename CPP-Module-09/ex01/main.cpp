/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalungo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 17:07:13 by fmalungo          #+#    #+#             */
/*   Updated: 2025/08/14 17:07:14 by fmalungo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char **av)
{
    try
    {
        if (ac != 2)
            throw std::runtime_error("Please try ./RPN < A reverse polish notation eg.: \"7 7 +\" >");
        RPN rpn(av[1]);
        rpn.processRPN();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    
    return 0;
}