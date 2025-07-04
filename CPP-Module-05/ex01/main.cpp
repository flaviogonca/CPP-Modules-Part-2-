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
    std::cout << "\n=========== 2* : Valid Form ===========\n";
    try
    {
        Form list("presença", 3, 3);
        Bureaucrat police("Isaac", 1);
        std::cout << list << std::endl;
        std::cout << "Bureaucrat " << police.getName() << " is trying to assign ..." << std::endl;
        police.signForm(list);
        std::cout << list << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Form Error: " << e.what() << '\n';
    }
    std::cout << "\n=========== 3* : Default Form ===========\n";
    try
    {
        Form list;
        std::cout << list << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Form Error: " << e.what() << '\n';
    }
    std::cout << "\n=========== 4* : Assign Form ===========\n";
    try
    {
        Form list1("List", 5, 10);
        Form list2;

        std::cout << list1 << std::endl;
        std::cout << list2 << std::endl;

        Bureaucrat police("Luvuvamo", 1);
        std::cout << "Bureaucrat " << police.getName() << " is trying to assign ..." << std::endl;
        police.signForm(list1);
        
        std::cerr << "Assigning form ..." << std::endl;
        list2 = list1;

        std::cout << list1 << std::endl;
        std::cout << list2 << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Form Error: " << e.what() << '\n';
    }
    return 0;
}
