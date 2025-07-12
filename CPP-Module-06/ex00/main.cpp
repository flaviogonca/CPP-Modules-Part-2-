/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalungo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 09:56:08 by fmalungo          #+#    #+#             */
/*   Updated: 2025/07/07 09:56:09 by fmalungo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << "Invalid Arguments. Please try: ./convert <any-value>" << std::endl;
        return 1;
    }
    ScalarConverter::convert(av[1]);
    return 0;
}
