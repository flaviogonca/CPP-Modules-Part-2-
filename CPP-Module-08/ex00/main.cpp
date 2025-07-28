/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalungo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 15:21:55 by fmalungo          #+#    #+#             */
/*   Updated: 2025/07/21 15:21:59 by fmalungo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main(void)
{
    std::vector<int> numbers;
    numbers.push_back(10);
    numbers.push_back(20);
    numbers.push_back(30);
    numbers.push_back(40);

    try
    {
        std::vector<int>::iterator it = easyfind(numbers, 30);
        std::cout << "Valor encontrado: " << *it << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Erro: " << e.what() << std::endl;
    }

    try
    {
        std::vector<int>::iterator it2 = easyfind(numbers, 99);
        std::cout << "Valor encontrado: " << *it2 << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Erro: " << e.what() << std::endl;
    }
    return 0;
}
