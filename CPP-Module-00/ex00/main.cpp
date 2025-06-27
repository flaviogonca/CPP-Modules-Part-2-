/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalungo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 12:31:59 by fmalungo          #+#    #+#             */
/*   Updated: 2025/06/25 12:32:00 by fmalungo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
    std::cout << "\n=========== 1* : Valid Bureaucrat ===========\n";
    try
    {
        Bureaucrat police("Isaac", 3);
        std::cout << police << std::endl;
        std::cout << "Incrementing grade..." << std::endl;
        police.increment();
        std::cout << police << std::endl;
        std::cout << "Decrementing grade..." << std::endl;
        police.decrement();
        std::cout << police << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n=========== 2* : Invalid Bureaucrat ===========\n";
    try
    {
        Bureaucrat nurse("Maria", 0);
        std::cout << nurse << std::endl;
        std::cout << "decrementing grade..." << std::endl;
        nurse.decrement();
        std::cout << nurse << std::endl;
        std::cout << "Decrementing grade..." << std::endl;
        nurse.increment();
        std::cout << nurse << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n=========== 3* : Copy Bureaucrat ===========\n";
    try
    {
        Bureaucrat police("Isaac", 10);
        Bureaucrat nurse(police);
        std::cout << nurse << std::endl;
        std::cout << "decrementing grade..." << std::endl;
        nurse.decrement();
        std::cout << nurse << std::endl;
        std::cout << "Decrementing grade..." << std::endl;
        nurse.increment();
        std::cout << nurse << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n=========== 4* : Assigning Bureaucrat ===========\n";
    try
    {
        Bureaucrat nurse("Maria", 42);
        std::cout << nurse << std::endl;
        Bureaucrat police("Isaac", 10);
        std::cout << police << std::endl;

        police = nurse;
        std::cout << police << std::endl;
        std::cout << nurse << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
    return 0;
}
