/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalungo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 19:30:22 by fmalungo          #+#    #+#             */
/*   Updated: 2025/07/17 19:30:23 by fmalungo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

#define MAX_VAL 750
int main(void)
{
    Array<int> numbers1(3);
    Array<int> numbers2(3);

    srand(time(NULL));
    std::cout << "Array 1: ";
    for (size_t i = 0; i < 3; i++)
    {
        numbers1.setElementValue((rand() % 5) ,i);
        numbers2.setElementValue((rand() % 5) ,i);
    }
    for (size_t i = 0; i < 3; i++)
        std::cout << numbers1.getElementValue(i) << " ";
    std::cout << "\nArray 2: ";
    for (size_t i = 0; i < 3; i++)
        std::cout << numbers2.getElementValue(i) << " ";    

    numbers1 = numbers2;
    Array<int> number3(numbers2);
    std::cout << "\nArray 1: ";
    for (size_t i = 0; i < 3; i++)
        std::cout << numbers1.getElementValue(i) << " ";
    std::cout << "\nArray 2: ";
    for (size_t i = 0; i < 3; i++)
        std::cout << numbers2.getElementValue(i) << " "; 
    std::cout << std::endl;
    return 0;
}