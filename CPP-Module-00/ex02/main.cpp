/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalungo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 10:11:24 by fmalungo          #+#    #+#             */
/*   Updated: 2025/07/02 10:11:25 by fmalungo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int main(void)
{
    std::cout << "\n=========== 1* Test ===========\n";
    try
    {
        AForm * list = new ShrubberyCreationForm("list");
        Bureaucrat police("Isaac", 137);
        Bureaucrat Pr("Pr", 1);

        Pr.signForm(*list);
        police.executeForm(*list);
        std::cout << *list << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "\n=========== 2* Test ===========\n";
    try
    {
        AForm * phoneBook = new RobotomyRequestForm("book");
        Bureaucrat jury("Gonçalves", 45);
        Bureaucrat Professor("Pr", 72);

        Professor.signForm(*phoneBook);
        jury.executeForm(*phoneBook);
        std::cout << *phoneBook << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return 0;
}