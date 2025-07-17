/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalungo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 17:45:59 by fmalungo          #+#    #+#             */
/*   Updated: 2025/07/17 17:46:01 by fmalungo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "iter.hpp"

int main(void)
{
    std::cout << "*Integers*" << std::endl;
    int intArray[] = {1, 2, 3, 4, 5};
    size_t intLength = sizeof(intArray) / sizeof(int);
    
    std::cout << "Original array: ";
    iter(intArray, intLength, showElement<int>);
    std::cout << std::endl;

    std::cout << "\n*Doubles*" << std::endl;
    double doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    size_t doubleLength = sizeof(doubleArray) / sizeof(double);
    
    std::cout << "Original array: ";
    iter(doubleArray, doubleLength, showElement<double>);
    std::cout << std::endl;

    std::cout << "\n*strings*" << std::endl;
    std::string strArray[] = {"Ola", "Mundo", "!"};
    size_t strLength = sizeof(strArray) / sizeof(std::string);
    
    std::cout << "String array: ";
    iter(strArray, strLength, showElement<std::string>);
    std::cout << std::endl;

    std::cout << "\n*const array*" << std::endl;
    const int constArray[] = {10, 20, 30, 40, 50};
    size_t constLength = sizeof(constArray) / sizeof(int);
    
    std::cout << "Const array: ";
    iter(constArray, constLength, showElement<const int>);
    std::cout << std::endl;
    return (0);
}